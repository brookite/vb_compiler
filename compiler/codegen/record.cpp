#include "record.hpp"
#include "types.hpp"
#include "constants.hpp"
#include "bytecode.hpp"


method_record::method_record()
{
}

method_record::method_record(std::string s, struct_record* owner, type* retType, bool isStatic, list<parameter_record*> args)
{
    this->name = s;
    this->owner = owner;
    this->returnType = retType;
    this->isStatic = isStatic;
    this->args = args;
    for (parameter_record* rec : args) {
        rec->owner = this;
    }
    this->node = new procedure_node();
    this->node->name = s;
    this->node->block = new list<stmt_node*>();
    this->node->record = this;
}

localvar_record* method_record::resolveLocal(std::string id)
{
    for (const auto& pair : locals) {
        if (pair.second->name == id) {
            return pair.second;
        }
    }
    return nullptr;
}

constant_methodref* method_record::getConstantFor(struct_record* record, struct_type* trueOwner)
{
    return (constant_methodref*) record->addConstantBy(this, trueOwner != nullptr ? trueOwner->record : nullptr);
}

std::string method_record::jvmDescriptor()
{
    std::string descr = "(";
    for (parameter_record* record : args) {
        descr += record->jvmDescriptor();
    }
    descr += ")";
    descr += returnType->jvmDescriptor();
    return descr;
}

bytearray_t method_record::bytecode(semantic_context * ctx, Bytecode ** bytecode)
{
    Bytecode * code = new Bytecode(ctx, this);
    if (name == "<init>") {
        constant_methodref * parentCall = this->owner->parent->getConstructorConstant({}, this->owner);
        code->loadThis();
        code->invokespecial(parentCall->number);
    }
    bytecodeBlock(node->block, code, nullptr);
    if (node->block->isEmpty() || node->block->last()->type != stmt_type::Return) {
        if (dynamic_cast<void_type*>(this->returnType) == nullptr) {
            code->nullLoad();
            code->areturn();
        }
        else {
            code->returnVoid();
        }
    }

    if (bytecode != nullptr) {
        *bytecode = code;
    }

    return code->writer->getByteArray();
}

bytearray_t method_record::toBytes(semantic_context * ctx)
{
    Bytecode * bytecodeObj = nullptr;
    byte_writer* writer = new byte_writer();
    writer->addInt16((this->name == "<clinit>" ? 0x0 : 0x0001) |
        (isStatic ? 0x0008 : 0)
    );
    writer->addInt16(owner->utf8ConstantOf(name)->number);
    writer->addInt16(owner->utf8ConstantOf(jvmDescriptor())->number);
    writer->addInt16(1);

    byte_writer* codeWriter = new byte_writer();
    codeWriter->addInt16(1000);
    codeWriter->addInt16(localvarCounter);
    bytearray_t bytecode = this->bytecode(ctx, &bytecodeObj);
    codeWriter->addInt32((uint32_t) bytecode.length);
    codeWriter->addBytes(bytecode);
    codeWriter->addInt16(0);
    codeWriter->addInt16(0); // stack map решено не делать

    bytearray_t code = codeWriter->getByteArray();

    writer->addInt16(1); // Code constant always 1
    if (code.length == 0) {
        internal_error("Empty code");
    }
    writer->addInt32(code.length);
    codegen_print("%s Code length: %d, offset=%d", name.c_str(), code.length, writer->offset());
    writer->addBytes(code);

    return writer->getByteArray();
}

struct_record::struct_record()
{
    addConstant(utf8ConstantOf("Code"));
}

constant_record* struct_record::constantAt(uint16_t num)
{
    return constant.count(num) ? constant[num] : nullptr;
}

constant_record* struct_record::addConstant(constant_record* record)
{
    constant_record* found = findConstant(record);
    if (found == nullptr) {
        record->number = constantCounter;
        constantCounter++;
        if (dynamic_cast<constant_double*>(record) != nullptr || dynamic_cast<constant_long*>(record) != nullptr) {
            constantCounter++;
        }
        constant[record->number] = record;
        return record;
    }
    return found;
}

constant_record * struct_record::findConstant(constant_record* record)
{
    for (const auto& pair : constant) {
        if (*pair.second == *record) {
            return pair.second;
        }
    }
    return nullptr;
}

constant_record* struct_record::addConstantBy(struct_record* record)
{
    if (dynamic_cast<jvm_array_type*>(record->type) != nullptr) {
        return nullptr;
    }
    constant_class* cls = new constant_class(utf8ConstantOf(record->type->qualifiedName()));
    cls = (constant_class *) addConstant(cls);
    return cls;
}

constant_record* struct_record::addConstantBy(field_record* record, struct_record* strct)
{
    constant_nameandtype * nt = new constant_nameandtype(utf8ConstantOf(record->name), utf8ConstantOf(record->type->jvmDescriptor()));
    constant_class* cls = (constant_class*)addConstantBy(strct == nullptr ? record->owner : strct);
    if (nt == nullptr || cls == nullptr) {
        return nullptr;
    }
    constant_fieldref* fref = new constant_fieldref((constant_nameandtype*)addConstant(nt), (constant_class*)addConstant(cls));
    fref = (constant_fieldref*) addConstant(fref);
    return fref;
}

constant_utf8* struct_record::utf8ConstantOf(std::string name) {
    return (constant_utf8*) addConstant(new constant_utf8(name));
}

constant_record* struct_record::addConstantBy(method_record* record, struct_record * strct)
{
    constant_nameandtype* nt = new constant_nameandtype(utf8ConstantOf(record->name), utf8ConstantOf(record->jvmDescriptor()));
    constant_class* cls = (constant_class*) addConstantBy(strct == nullptr ? record->owner : strct);
    constant_methodref* mref = new constant_methodref((constant_nameandtype*)addConstant(nt), (constant_class*)addConstant(cls));
    mref = (constant_methodref*)addConstant(mref);
    return mref;
}

constant_record* struct_record::addConstantBy(struct type* type)
{
    if (dynamic_cast<jvm_array_type*>(type) != nullptr) {
        return addConstantBy(dynamic_cast<jvm_array_type*>(type)->valueType);
    }
    if (dynamic_cast<struct_type*>(type) != nullptr) {
        return addConstantBy(dynamic_cast<struct_type*>(type)->record);
    }
    return addConstant(new constant_class(utf8ConstantOf(type->readableName())));
}

constant_record* struct_record::addLiteralConstant(long long value)
{
    constant_record* rec;
    if (intSizeOf(value) > 4) {
        rec = new constant_long(value);
    }
    else {
        rec = new constant_int(value);
    }
    return addConstant(rec);
}


constant_record* struct_record::addLiteralConstant(double value)
{
    return addConstant(new constant_double(value));
}

constant_record* struct_record::addLiteralConstant(float value)
{
    return addConstant(new constant_float(value));
}

constant_record* struct_record::addLiteralConstant(std::string value)
{
    return addConstant(new constant_string(utf8ConstantOf(value)));
}

constant_methodref* struct_record::getConstructorConstant(list<std::string> descriptors, struct_record * dst)
{
    std::string descr = "(";
    for (std::string arg : descriptors) {
        descr += arg;
    }
    descr += ")";
    descr += "V";
    constant_nameandtype* nt = new constant_nameandtype(dst->utf8ConstantOf("<init>"), dst->utf8ConstantOf(descr));
    constant_class* cls = (constant_class*)dst->addConstantBy(type);
    constant_methodref* mref = new constant_methodref((constant_nameandtype*)dst->addConstant(nt), (constant_class*)dst->addConstant(cls));
    mref = (constant_methodref*)dst->addConstant(mref);
    return mref;
}

constant_methodref* struct_record::getStaticConstructorConstant(struct_record* dst)
{
    std::string descr = "()V";
    constant_nameandtype* nt = new constant_nameandtype(dst->utf8ConstantOf("<clinit>"), dst->utf8ConstantOf(descr));
    constant_class* cls = (constant_class*)dst->addConstantBy(type);
    constant_methodref* mref = new constant_methodref((constant_nameandtype*)dst->addConstant(nt), (constant_class*)dst->addConstant(cls));
    mref = (constant_methodref*)dst->addConstant(mref);
    return mref;
}

constant_class* struct_record::getConstantFor(struct_record* record)
{
   return (constant_class*) record->addConstantBy(this->type);
}

void struct_record::makeInit(semantic_context & ctx)
{
    procedure_node* proc = new procedure_node();
    proc->name = "<clinit>";
    proc->returnType = nullptr;
    proc->isStatic = true;
    proc->isProcedure = true;
    proc->block = new list<stmt_node*>();

    procedure_node* insproc = new procedure_node();
    insproc->name = "<init>";
    insproc->returnType = nullptr;
    insproc->isStatic = false;
    insproc->isProcedure = true;
    insproc->block = new list<stmt_node*>();

    for (auto& pair : fields) {
        expr_node* lvalue = new expr_node(expr_type::Id);
        lvalue->String = pair.first;
        stmt_node* assign = new stmt_node(stmt_type::FieldAssign);
        assign->lvalue = lvalue;
        assign->rvalue = pair.second->valueNode->value;
        if (pair.second->isStatic) {
            proc->block->add(assign);
        }
        else {
            insproc->block->add(assign);
        }
        
    }
    addMethod(proc, ctx);
    addMethod(insproc, ctx);
}

field_record* struct_record::addField(field_node* node, semantic_context & context)
{
    field_record* field = new field_record();
    field->isStatic = node->isStatic;
    field->name = node->decl->varName;
    if (field->name == "") {
        internal_error("Empty varName passed");
    }
    field->owner = this;
    field->node = node;
    field->node->record = field;
    field->valueNode = node->decl;
    field->type = inferType(node->decl->type, context, typeMap);
    if (dynamic_cast<struct_type*>(field->type) != nullptr) {
        addConstantBy(dynamic_cast<struct_type*>(field->type)->record);
    }
    if (resolveMethod(field->name) != nullptr) {
        name_error("'%s' member already declared as method in %s", field->name.c_str(), this->type->readableName().c_str());
        return nullptr;
    }
    fields[field->name] = field;
    return field;
}

method_record* struct_record::addMethod(procedure_node* procNode, semantic_context& context)
{
    method_record* method = new method_record();
    method->name = procNode->name;
    if (method->name == "") {
        internal_error("Empty method name passed");
    }
    method->owner = this;
    method->node = procNode;
    method->node->record = method;
    method->isStatic = procNode->isStatic;
    method->localvarCounter = method->isStatic ? 0 : 1;
    if (procNode->isProcedure) {
        method->returnType = new void_type();
    }
    else {
        method->returnType = inferType(procNode->returnType, context, typeMap);
        if (dynamic_cast<struct_type*>(method->returnType) != nullptr) {
            addConstantBy(dynamic_cast<struct_type*>(method->returnType)->record);
        }
    }
    for (typed_value * val : *procNode->arguments) {
        parameter_record* param = new parameter_record();
        param->name = val->varName;
        param->type = inferType(val->type, context, typeMap);
        if (dynamic_cast<struct_type*>(param->type) != nullptr) {
            addConstantBy(dynamic_cast<struct_type*>(param->type)->record);
        }
        param->valueNode = val;
        param->owner = method;
        method->args.add(param);
    }
    if (resolveField(method->name) != nullptr) {
        name_error("'%s' member already declared as field in %s", method->name.c_str(), this->type->readableName().c_str());
        return nullptr;
    }
    methods[method->name] = method;
    if (method->name == "tostring") {
        method->name = "ToString";
    }
    return method;
}

method_record* struct_record::resolveMethod(std::string id)
{
    method_record * method = methods.count(id) ? methods[id]: nullptr;
    std::string origId = id;
    if (method == nullptr) {
        toLower(&id);
        method = methods.count(id) ? methods[id] : nullptr;
    }
    if (method == nullptr) {
        capitalize(&id);
        method = methods.count(id) ? methods[id] : nullptr;
    }
    if (method == nullptr && this->parent != nullptr) {
        method = this->parent->resolveMethod(origId);
    }
    return method;
}

field_record* struct_record::resolveField(std::string id)
{
    std::string origId = id;
    field_record * field = fields.count(id) ? fields[id] : nullptr;
    if (field == nullptr) {
        toLower(&id);
        field = fields.count(id) ? fields[id] : nullptr;
    }
    if (field == nullptr) {
        capitalize(&id);
        field = fields.count(id) ? fields[id] : nullptr;
    }
    if (field == nullptr && this->parent != nullptr) {
        field = this->parent->resolveField(origId);
    }
    return field;
}

method_record* struct_record::resolveStaticMethod(std::string id)
{
    std::string origId = id;
    method_record * method = methods.count(id) && methods[id]->isStatic ? methods[id] : nullptr;
    if (method == nullptr) {
        toLower(&id);
        method = methods.count(id) ? methods[id] : nullptr;
    }
    if (method == nullptr) {
        capitalize(&id);
        method = methods.count(id) ? methods[id] : nullptr;
    }
    if (method == nullptr && this->parent != nullptr) {
        method = this->parent->resolveStaticMethod(origId);
    }
    return method;
}

field_record* struct_record::resolveStaticField(std::string id)
{
    std::string origId = id;
    field_record * field = fields.count(id) && fields[id]->isStatic ? fields[id] : nullptr;
    if (field == nullptr) {
        toLower(&id);
        field = fields.count(id) ? fields[id] : nullptr;
    }
    if (field == nullptr) {
        capitalize(&id);
        field = fields.count(id) ? fields[id] : nullptr;
    }
    if (field == nullptr && this->parent != nullptr) {
        field = this->parent->resolveStaticField(origId);
    }
    return field;
}

bytearray_t struct_record::toBytes(semantic_context * ctx)
{
    byte_writer* writer = new byte_writer();
    bytearray_t fields = asBytes(&this->fields);
    bytearray_t methods = asBytes(&this->methods, ctx);

    uint16_t currentConst = getConstantFor(this)->number;
    uint16_t parentConst = parent == nullptr ? 0 : parent->getConstantFor(this)->number;

    writer->addInt32((uint32_t)0xCAFEBABE);
    writer->addInt32((uint32_t)0x00000041);
    writer->addBytes(asBytes(&this->constant, this->constantCounter));
    writer->addInt16(0x0001 | 0x0020);
    writer->addInt16(currentConst);
    writer->addInt16(parentConst);
    writer->addInt16(0);
    codegen_print("Fields offset=%d", writer->offset());
    writer->addBytes(fields);
    codegen_print("Methods offset=%d", writer->offset());
    writer->addBytes(methods);
    codegen_print("End of methods offset=%d", writer->offset());
    writer->addInt16(0);
    return writer->getByteArray();
}

std::string var_record::jvmDescriptor()
{
    return type->jvmDescriptor();
}

localvar_record::localvar_record()
{
}

localvar_record::localvar_record(std::string name, struct type* type, method_record* owner)
{
    this->name = name;
    this->type = type;
    this->owner = owner;
}

field_record::field_record()
{
}

field_record::field_record(std::string name, bool isStatic, struct type* type, struct_record* owner)
{
    this->name = name;
    this->type = type;
    this->owner = owner;
    this->isConst = false;
    this->isStatic = isStatic;
    this->node = new field_node();
    this->node->decl = new typed_value();
    this->node->decl->varName = name;
    this->node->isStatic = isStatic;
    this->node->record = this;
}

constant_fieldref* field_record::getConstantFor(struct_record* record, struct_type* trueOwner)
{
    return (constant_fieldref*)record->addConstantBy(this, trueOwner != nullptr ? trueOwner->record : nullptr);
}

bytearray_t asBytes(std::map<uint16_t, constant_record*>* table, uint16_t count)
{
    byte_writer* writer = new byte_writer();
    writer->addInt16(count);
    for (auto& pair : *table) {
        if (pair.first != pair.second->number) {
            internal_error("Inconsistent constant numbers");
        }
        writer->addBytes(pair.second->toBytes());
    }
    return writer->getByteArray();
}

std::string printableConstant(std::string name, std::map<uint16_t, constant_record*> map)
{
    std::string s = name + ":\n\n";
    for (auto& pair : map) {
        s += pair.second->printable();
        s += "\n\n";
    }
    return s;
}

bytearray_t asBytes(std::map<std::string, field_record*>* table) {
    byte_writer* writer = new byte_writer();
    writer->addInt16(table->size());
    for (auto& pair : *table) {
        writer->addInt16(0x0001 |
            (pair.second->isStatic ? 0x0008 : 0) |
            (pair.second->isConst ? 0x0010 : 0)
        );
        writer->addInt16(pair.second->getConstantFor(pair.second->owner)->nt->name->number);
        writer->addInt16(pair.second->getConstantFor(pair.second->owner)->nt->type->number);
        writer->addInt16(0);
    }
    return writer->getByteArray();
}

bytearray_t asBytes(std::map<std::string, method_record*>* table, semantic_context * ctx) {
    byte_writer* writer = new byte_writer();
    writer->addInt16(table->size());
    for (auto& pair : *table) {
        codegen_print("%s method offset = %d", pair.first.c_str(), writer->offset());
        writer->addBytes(pair.second->toBytes(ctx));
    }
    return writer->getByteArray();
}