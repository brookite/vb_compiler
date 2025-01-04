#include "record.hpp"
#include "types.hpp"
#include "constants.hpp"


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

constant_record* struct_record::constantAt(uint16_t num)
{
    return constant.count(num) ? constant[num] : nullptr;
}

constant_record* struct_record::addConstant(constant_record* record)
{
    constant_record* found = findConstant(record);
    if (found == nullptr) {
        record->number = ++constantCounter;
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
    record->currentConstant = cls;
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
    record->constant = fref;
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
    record->constant = mref;
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
    return addConstant(new constant_long(value));
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

field_record* struct_record::addField(field_node* node, semantic_context & context)
{
    field_record* field = new field_record();
    field->isStatic = field->isStatic;
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
    return method;
}

method_record* struct_record::resolveMethod(std::string id)
{
    method_record * method = methods.count(id) ? methods[id]: nullptr;
    if (method == nullptr && this->parent != nullptr) {
        method = this->parent->resolveMethod(id);
    }
    return method;
}

field_record* struct_record::resolveField(std::string id)
{
    field_record * field = fields.count(id) ? fields[id] : nullptr;
    if (field == nullptr && this->parent != nullptr) {
        field = this->parent->resolveField(id);
    }
    return field;
}

method_record* struct_record::resolveStaticMethod(std::string id)
{
    method_record * record = methods.count(id) && methods[id]->isStatic ? methods[id] : nullptr;
    if (record == nullptr && this->parent != nullptr) {
        record = this->parent->resolveStaticMethod(id);
    }
    return record;
}

field_record* struct_record::resolveStaticField(std::string id)
{
    field_record * record = fields.count(id) && fields[id]->isStatic ? fields[id] : nullptr;
    if (record == nullptr && this->parent != nullptr) {
        record = this->parent->resolveStaticField(id);
    }
    return record;
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

std::string printableConstant(std::string name, std::map<uint16_t, constant_record*> map)
{
    std::string s = name + ":\n\n";
    for (auto& pair : map) {
        s += pair.second->printable();
        s += "\n\n";
    }
    return s;
}
