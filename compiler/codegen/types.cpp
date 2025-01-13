#include "types.hpp"
#include "rtl.hpp"
#include "../semantics.hpp"


method_record* operatorToMethod(expr_node* node, struct_record* record, rtl_type* type) {
    method_record* method = nullptr;
    if (node->type == expr_type::AddOp) {
        method = type->record->resolveMethod("add");
    }
    else if (node->type == expr_type::AndAlsoOp) {
        method = type->record->resolveMethod("andAlso");
    }
    else if (node->type == expr_type::AndOp) {
        method = type->record->resolveMethod("and");
    }
    else if (node->type == expr_type::DivOp) {
        method = type->record->resolveMethod("div");
    }
    else if (node->type == expr_type::FloorDivOp) {
        method = type->record->resolveMethod("floorDiv");
    }
    else if (node->type == expr_type::MulOp) {
        method = type->record->resolveMethod("mul");
    }
    else if (node->type == expr_type::ExpOp) {
        method = type->record->resolveMethod("add");
    }
    else if (node->type == expr_type::DivOp) {
        method = type->record->resolveMethod("div");
    }
    else if (node->type == expr_type::OrOp) {
        method = type->record->resolveMethod("or");
    }
    else if (node->type == expr_type::OrElseOp) {
        method = type->record->resolveMethod("orElse");
    }
    else if (node->type == expr_type::ModOp) {
        method = type->record->resolveMethod("mod");
    }
    else if (node->type == expr_type::UnaryPlusOp) {
        method = type->record->resolveMethod("unaryPlus");
    }
    else if (node->type == expr_type::UnaryMinusOp) {
        method = type->record->resolveMethod("unaryMinus");
    }
    else if (node->type == expr_type::NotOp) {
        method = type->record->resolveMethod("not");
    }
    else if (node->type == expr_type::LshiftOp) {
        method = type->record->resolveMethod("lshift");
    }
    else if (node->type == expr_type::RshiftOp) {
        method = type->record->resolveMethod("rshift");
    }
    else if (node->type == expr_type::LteOp) {
        method = type->record->resolveMethod("lte");
    }
    else if (node->type == expr_type::GteOp) {
        method = type->record->resolveMethod("gte");
    }
    else if (node->type == expr_type::LtOp) {
        method = type->record->resolveMethod("lt");
    }
    else if (node->type == expr_type::GtOp) {
        method = type->record->resolveMethod("gt");
    }
    else if (node->type == expr_type::IsOp) {
        method = type->record->resolveMethod("is");
    }
    else if (node->type == expr_type::IsNotOp) {
        method = type->record->resolveMethod("isNot");
    }
    else if (node->type == expr_type::EqOp) {
        method = type->record->resolveMethod("equals");
    }
    else if (node->type == expr_type::XorOp) {
        method = type->record->resolveMethod("xor");
    }
    else if (node->type == expr_type::NeqOp) {
        method = type->record->resolveMethod("notEquals");
    }
    if (method != nullptr) {
        record->addConstantBy(method);
    }
    return method;
}

bool type::operator==(const type& t) const
{
    return t.jvmDescriptor() == jvmDescriptor();
}

bool type::operator!=(const type& t) const
{
    return t.jvmDescriptor() != jvmDescriptor();
}

bool type::isValueType() const
{
    return dynamic_cast<const sized_rtl_type*>(this) != nullptr;
}

bool type::isAssignableFrom(type * t, semantic_context& context) const
{
    jvm_array_type* arr = dynamic_cast<jvm_array_type*>(t);
    rtl_type* rtl = dynamic_cast<rtl_type*>(t);
    const struct_type* s = dynamic_cast<const struct_type*>(t);

    if (this == rtl_class_record::Object->type || *this == *rtl_class_record::Object->type) {
        return true;
    }
    if (t == rtl_class_record::Number->type && dynamic_cast<const sized_rtl_type*>(this) != nullptr) {
        return true;
    }
    if (dynamic_cast<nullptr_reference*>(t) != nullptr && !t->isValueType() && dynamic_cast<const nullptr_reference*>(this) == nullptr) {
        return true;
    }
    else if (dynamic_cast<unknown_type*>(t) != nullptr && dynamic_cast<const unknown_type*>(this) == nullptr) {
        return true;
    }

    if (t != nullptr && (t == this || *t == *this)) {
        return true;
    }

    if (arr != nullptr) {
        type* arrType = arr->valueType;
        const jvm_array_type* arrThis = dynamic_cast<const jvm_array_type*>(this);
        if (arrThis != nullptr) {
            if (dynamic_cast<struct_type*>(arrType) != nullptr && dynamic_cast<const struct_type*>(arrThis->valueType) != nullptr
                || dynamic_cast<rtl_type*>(arrType) != nullptr && dynamic_cast<const rtl_type*>(arrThis->valueType) != nullptr
                ) {
                return arrThis->valueType->isAssignableFrom(arrType, context);
            }
        }
    } 
    else if (rtl != nullptr) {
        if (this == rtl_class_record::Number->type && dynamic_cast<sized_rtl_type*>(rtl) != nullptr) {
            return true;
        }

        if (dynamic_cast<const int_rtl_type*>(this) != nullptr && dynamic_cast<int_rtl_type*>(rtl) != nullptr
            || dynamic_cast<const int_rtl_type*>(this) != nullptr && dynamic_cast<bool_rtl_type*>(rtl) != nullptr
            || dynamic_cast<const float_rtl_type*>(this) != nullptr && dynamic_cast<bool_rtl_type*>(rtl) != nullptr
            || dynamic_cast<const bool_rtl_type*>(this) != nullptr && dynamic_cast<int_rtl_type*>(rtl) != nullptr
            || dynamic_cast<const bool_rtl_type*>(this) != nullptr && dynamic_cast<float_rtl_type*>(rtl) != nullptr
            || dynamic_cast<const int_rtl_type*>(this) != nullptr && dynamic_cast<char_rtl_type*>(rtl) != nullptr
            || dynamic_cast<const float_rtl_type*>(this) != nullptr && dynamic_cast<int_rtl_type*>(rtl) != nullptr
            || dynamic_cast<const int_rtl_type*>(this) != nullptr && dynamic_cast<float_rtl_type*>(rtl) != nullptr
            ) {
            return true;
        }
    }
    else if (s != nullptr) {
        if (*s == *this) {
            return true;
        }
        struct_record* parent = s->record->parent;

        while (parent != nullptr) {
            if (*(parent->type) == *this) {
                return true;
            }
            if (dynamic_cast<struct_type*>(parent->type) != nullptr) {
                parent = dynamic_cast<struct_type*>(parent->type)->record->parent;
            }
            else {
                parent = nullptr;
            }
        }
    }
    return false;
}

type* inferType(expr_node* val, struct_record* context, method_record* methodContext, semantic_context& semanticContext)
{
    if (val->type == expr_type::Id) {
        if (methodContext != nullptr && methodContext->locals.count(val->String)) {
            return methodContext->locals[val->String]->type;
        }
        else if (methodContext != nullptr && methodContext->allLocals.count(val->localvarNum)) {
            return methodContext->allLocals[val->localvarNum]->type;
        }
        else if (context != nullptr && context->resolveField(val->String) != nullptr) {
            return context->resolveField(val->String)->type;
        }
        else if (semanticContext.classes.count(val->String)) {
            return semanticContext.classes[val->String]->type;
        }
    }
    else if (val->type == expr_type::Me) {
        return context->type;
    }
    else if (val->type == expr_type::Nothing) {
        return new nullptr_reference();
    }
    else if (val->type == expr_type::CallOrIndex) {
        semanticContext.processCallOrIndex(val, context, methodContext);
        if (val->type == expr_type::CallOrIndex) {
            type_error("Failed to convert ");
            return new unknown_type();
        }
        return inferType(val, context, methodContext, semanticContext);
    }
    else if (val->type == expr_type::MyBase) {
        if (context != nullptr) {
            return context->parent->type;
        }
    }
    else if (val->type == expr_type::Call) {
        if (context != nullptr && context->resolveMethod(val->String) != nullptr) {
            method_record* method = context->resolveMethod(val->String);
            if (method->args.size() != val->arg_list->size()) {
                name_error("Invalid argument count in '%s'", method->name.c_str());
            }
            for (size_t i = 0; i < method->args.size(); i++) {
                if (!method->args[i]->type->isAssignableFrom(inferType(val->arg_list->get(i), context, methodContext, semanticContext), semanticContext)) {
                    name_error("Invalid type given at call argument %d of '%s'", i, method->name.c_str());
                }
            }
            return context->resolveMethod(val->String)->returnType;
        }
        else {
            name_error("'%s' method wasn't found in '%s'", val->String.c_str(), context == nullptr ? "Unknown Context" : context->name.c_str());
        }
    }
    else if (val->type == expr_type::MethodCall) {
        method_record * method = (method_record *) semanticContext.resolveMemberAccess(val, context, methodContext).first;
        if (method != nullptr) {
            if (method->args.size() != val->arg_list->size()) {
                name_error("Invalid argument count in '%s'", method->name.c_str());
                return new unknown_type();
            }
            for (size_t i = 0; i < method->args.size(); i++) {
                if (!method->args[i]->type->isAssignableFrom(inferType(val->arg_list->get(i), context, methodContext, semanticContext), semanticContext)) {
                    name_error("Invalid type given at call argument %d of '%s'", i, method->name.c_str());
                }
            }
            return method->returnType;
        } else {
            name_error("'%s' method wasn't found in '%s'", val->String, context == nullptr ? "Unknown Context" : context->name);
        }
    }
    else if (val->type == expr_type::MemberAccess
            || val->type == expr_type::MyClassMemberAccess) {
        field_record* record = (field_record*)semanticContext.resolveMemberAccess(val, context, methodContext).first;
        if (record != nullptr) {
            return record->type;
        }
    } else if (val->type == expr_type::String) {
        return rtl_class_record::String->type;
    }
    else if (val->type == expr_type::Int) {
        if (val->numericType != nullptr) {
            return inferType(val->numericType, semanticContext, context->typeMap);
        }
        else {
            size_t size = intSizeOf(val->Int);
            if (size == 1) {
                return val->Int > 0 ? rtl_class_record::Byte->type : rtl_class_record::SByte->type;
            } else if (size == 2) {
                return val->Int < 0 ? rtl_class_record::Short->type : rtl_class_record::UShort->type;
            } else if (size == 4) {
                return val->Int < 0 ? rtl_class_record::Integer->type : rtl_class_record::UInteger->type;
            } else if (size == 8) {
                return val->Int < 0 ? rtl_class_record::Long->type : rtl_class_record::ULong->type;
            }
        }
    }
    else if (val->type == expr_type::Float) {
        if (val->numericType != nullptr) {
            return inferType(val->numericType, semanticContext, context->typeMap);
        }
        else {
            return rtl_class_record::Double->type;
        }
    }
    else if (val->type == expr_type::Bool) {
        return rtl_class_record::Boolean->type;
    }
    else if (val->type == expr_type::Char) {
        return rtl_class_record::Char->type;
    }
    else if (val->type == expr_type::Datetime) {
        return rtl_class_record::DateTime->type;
    }
    else if (val->type == expr_type::New) {
        return inferType(val->datatype, semanticContext, context->typeMap);
    }
    else if (val->type == expr_type::Cast) {
        type* castType = inferType(val->datatype, semanticContext, context->typeMap);
        type* exprType = inferType(val->argument, context, methodContext, semanticContext);
        if (castType == rtl_class_record::String->type || 
            castType == rtl_class_record::Object->type || 
            dynamic_cast<nullptr_reference*>(exprType) != nullptr ||
            exprType == rtl_class_record::Object->type ||
            (dynamic_cast<sized_rtl_type*>(castType) != nullptr && exprType == rtl_class_record::String->type)
          ) {
            // любой тип может быть к ним приведен
            // в любой тип можно привести Object
            // строки можно преобразовать в числа, символы или логический тип
        }
        else if (
            dynamic_cast<unknown_type*>(castType) != nullptr ||
            dynamic_cast<unknown_type*>(exprType) != nullptr ||
            dynamic_cast<jvm_array_type*>(castType) != nullptr && dynamic_cast<jvm_array_type*>(exprType) == nullptr  ||
            dynamic_cast<jvm_array_type*>(castType) == nullptr && dynamic_cast<jvm_array_type*>(exprType) != nullptr  ||
            dynamic_cast<sized_rtl_type*>(castType) == nullptr && dynamic_cast<sized_rtl_type*>(exprType) != nullptr  ||
            dynamic_cast<sized_rtl_type*>(castType) != nullptr && dynamic_cast<sized_rtl_type*>(exprType) == nullptr  ||
            !castType->isAssignableFrom(exprType, semanticContext) && !exprType->isAssignableFrom(castType, semanticContext) ||
            !exprType->isAssignableFrom(castType, semanticContext) && !castType->isAssignableFrom(exprType, semanticContext) ||
            // проверка ковариантности массивов
            (dynamic_cast<jvm_array_type*>(castType) != nullptr && dynamic_cast<jvm_array_type*>(exprType) != nullptr && (
                !dynamic_cast<jvm_array_type*>(castType)->valueType->isAssignableFrom(dynamic_cast<jvm_array_type*>(exprType)->valueType, semanticContext) ||
                !dynamic_cast<jvm_array_type*>(exprType)->valueType->isAssignableFrom(dynamic_cast<jvm_array_type*>(castType)->valueType, semanticContext)
                ))
        ) {
            type_error("Cast unsupported from '%s' to '%s'", exprType->readableName().c_str(), castType->readableName().c_str());
        }
        return castType;
    }
    else if (val->type == expr_type::ArrayNew) {
        return new jvm_array_type(inferType(val->datatype, semanticContext, context->typeMap));
    } 
    else if (val->type == expr_type::Collection) {
        list<type*> types;
        for (expr_node* el : *val->arg_list) {
            types.add(inferType(el, context, methodContext, semanticContext));
        }
        type* generalType = nullptr;
        size_t maxCount = 0;
        for (size_t i = 0; i < types.size(); i++) {
            size_t currentCount = 0;
            for (size_t j = 0; j < types.size(); j++) {
                if (types.get(i)->isAssignableFrom(types.get(j), semanticContext)) {
                    currentCount++;
                }
            }
            if (currentCount > maxCount) {
                maxCount = currentCount;
                generalType = types.get(i);
            }
        }
        if (maxCount == types.size()) {
            return new jvm_array_type(generalType);
        }
        else {
            return new jvm_array_type(rtl_class_record::Object->type);
        }
        
    }
    else if (val->type == expr_type::AddOp 
        || val->type == expr_type::MulOp
        || val->type == expr_type::SubOp
        || val->type == expr_type::ExpOp
        || val->type == expr_type::DivOp
        || val->type == expr_type::FloorDivOp
        || val->type == expr_type::ModOp
        || val->type == expr_type::XorOp
        || val->type == expr_type::LshiftOp
        || val->type == expr_type::RshiftOp
        || val->type == expr_type::AndAlsoOp
        || val->type == expr_type::OrElseOp
        || val->type == expr_type::OrOp
        || val->type == expr_type::AndOp
        || val->type == expr_type::GteOp
        || val->type == expr_type::LteOp
        || val->type == expr_type::LtOp
        || val->type == expr_type::GtOp
    ) {
        type* leftT = inferType(val->left, context, methodContext, semanticContext);
        type* rightT = inferType(val->right, context, methodContext, semanticContext);
        
        int_rtl_type* leftInt = dynamic_cast<int_rtl_type*>(leftT);
        int_rtl_type* rightInt = dynamic_cast<int_rtl_type*>(rightT);
        float_rtl_type* leftFloat = dynamic_cast<float_rtl_type*>(leftT);
        float_rtl_type* rightFloat = dynamic_cast<float_rtl_type*>(rightT);
        bool_rtl_type* leftBool = dynamic_cast<bool_rtl_type*>(leftT);
        bool_rtl_type* rightBool = dynamic_cast<bool_rtl_type*>(leftT);
        char_rtl_type* leftChar = dynamic_cast<char_rtl_type*>(leftT);
        char_rtl_type* rightChar = dynamic_cast<char_rtl_type*>(leftT);

        list<sized_rtl_type*> cmp;
        if (leftFloat != nullptr || rightFloat != nullptr) {
            cmp = { (sized_rtl_type*)leftFloat, (sized_rtl_type*)rightFloat };
        }
        else {
            cmp = { (sized_rtl_type*)leftInt, (sized_rtl_type*)rightInt, 
                (sized_rtl_type*)leftFloat, (sized_rtl_type*)rightFloat,
                (sized_rtl_type*)leftBool, (sized_rtl_type*)rightBool,
                (sized_rtl_type*)leftChar, (sized_rtl_type*)rightChar
            };
        }

        if ((cmp.size() - cmp.countNotNull()) == cmp.size()) {
            type_error("Incompatible types for arithmetic or logical operator, '%s' and '%s'", leftT->readableName().c_str(), rightT->readableName().c_str());
            return new unknown_type();
        }
        sized_rtl_type* maxT = nullptr;
        for (sized_rtl_type* t : cmp) {
            if ((t != nullptr && maxT == nullptr) || (maxT != nullptr && t != nullptr && maxT->byteSize() < t->byteSize())) {
                maxT = t;
            }
        }
        operatorToMethod(val, context, maxT);
        if (val->type == expr_type::AndAlsoOp
            || val->type == expr_type::OrElseOp
            || val->type == expr_type::OrOp
            || val->type == expr_type::AndOp
            || val->type == expr_type::GteOp
            || val->type == expr_type::LteOp
            || val->type == expr_type::LtOp
            || val->type == expr_type::GtOp)
        {
            return rtl_class_record::Boolean->type;
        }
        else {
            return maxT;
        }
        
    }
    else if (val->type == expr_type::NeqOp || val->type == expr_type::EqOp) {
        operatorToMethod(val, context, (rtl_type*) rtl_class_record::Object->type);
        return rtl_class_record::Boolean->type;
    }
    else if (val->type == expr_type::If) {
        type* cond = inferType(val->condition, context, methodContext, semanticContext);
        type* trueBranch = inferType(val->then_expr, context, methodContext, semanticContext);
        type* falseBranch = inferType(val->else_expr, context, methodContext, semanticContext);
        if (!rtl_class_record::Boolean->type->isAssignableFrom(cond, semanticContext)) {
            type_error("Condition of If expression must be convertable to boolean");
        }
        if (trueBranch->isAssignableFrom(falseBranch, semanticContext) || falseBranch->isAssignableFrom(trueBranch, semanticContext)) {
            type_error("Branch exprs must have the same or assignable types in If expression");
        }
    }
    else if (val->type == expr_type::Index) {
        type * t = inferType(val->left, context, methodContext, semanticContext);
        if (dynamic_cast<jvm_array_type*>(t) == nullptr && t != rtl_class_record::String->type
            ) {
            type_error("Index is valid only for arrays and strings");
        }
        if (t == rtl_class_record::String->type) {
            return rtl_class_record::Char->type;
        }
        return dynamic_cast<jvm_array_type*>(t)->valueType;
    }
    else if (val->type == expr_type::StrConcatOp) {
        if (
            !rtl_class_record::String->type->isAssignableFrom(inferType(val->left, context, methodContext, semanticContext), semanticContext) ||
            !rtl_class_record::String->type->isAssignableFrom(inferType(val->left, context, methodContext, semanticContext), semanticContext))
        {
            type_error("Invalid type of string concat. Required all strings");
        }
        return rtl_class_record::String->type;
    }
    else if (val->type == expr_type::IsNotOp || val->type == expr_type::IsOp) {
        return rtl_class_record::Boolean->type;
    }
    else if (val->type == expr_type::UnaryMinusOp || val->type == expr_type::UnaryPlusOp || val->type == expr_type::NotOp) {
        type* argT = inferType(val->argument, context, methodContext, semanticContext);

        int_rtl_type* intT = dynamic_cast<int_rtl_type*>(argT);
        float_rtl_type* floatT = dynamic_cast<float_rtl_type*>(argT);
        bool_rtl_type* boolT = dynamic_cast<bool_rtl_type*>(argT);

        list<sized_rtl_type*> cmp = { (sized_rtl_type*) intT, (sized_rtl_type*)boolT, (sized_rtl_type*)floatT };

        if ((cmp.size() - cmp.countNotNull()) == cmp.size()) {
            type_error("Incompatible type for unary operator, '%s'", argT->readableName().c_str());
            return new unknown_type();
        }
        sized_rtl_type* maxT = nullptr;
        for (sized_rtl_type* t : cmp) {
            if ((t != nullptr && maxT == nullptr) || (maxT != nullptr && t != nullptr && maxT->byteSize() < t->byteSize())) {
                maxT = t;
            }
        }
        operatorToMethod(val, context, maxT);
        return maxT;

    }
    return new unknown_type();
}

type* inferType(type_node* type, semantic_context& context, std::map<std::string, struct type*>* typeMap)
{
    if (type == nullptr) {
        return rtl_class_record::Object->type;
    }
    if (type->isArray) {
        type->isArray = false;
        auto * t = inferType(type, context, typeMap);
        type->isArray = true;
        return new jvm_array_type(t);
    }

    if (type->value == datatype_type::Byte) {
        return rtl_class_record::Byte->type;
    }
    else if (type->value == datatype_type::Char) {
        return rtl_class_record::Char->type;
    } else if (type->value == datatype_type::Integer) {
        return rtl_class_record::Integer->type;
    } else if (type->value == datatype_type::UInteger) {
        return rtl_class_record::UInteger->type;
    } else if (type->value == datatype_type::SByte) {
        return rtl_class_record::SByte->type;
    } else if (type->value == datatype_type::Object) {
        return rtl_class_record::Object->type;
    } else if (type->value == datatype_type::Long) {
        return rtl_class_record::Long->type;
    } else if (type->value == datatype_type::ULong) {
        return rtl_class_record::ULong->type;
    } else if (type->value == datatype_type::UShort) {
        return rtl_class_record::UShort->type;
    } else if (type->value == datatype_type::Short) {
        return rtl_class_record::Short->type;
    } else if (type->value == datatype_type::Boolean) {
        return rtl_class_record::Boolean->type;
    } else if (type->value == datatype_type::String) {
        return rtl_class_record::String->type;
    } else if (type->value == datatype_type::Date) {
        return rtl_class_record::DateTime->type;
    } else if (type->value == datatype_type::Single) {
        return rtl_class_record::Single->type;
    } else if (type->value == datatype_type::Double) {
        return rtl_class_record::Double->type;
    } else if (type->value == datatype_type::UserType) {
        if (!type->generics->isEmpty()) {
            return context.specializeType(type);
        }
        if (typeMap != nullptr && typeMap->count(type->Id)) {
            return (*typeMap)[type->Id];
        }
        else {
            if (context.classes.count(type->Id)) {
                return context.classes[type->Id]->type;
            }
            else {
                type_error("Unknown type '%s'", type->Id.c_str());
            }
        }
    }
    return new unknown_type();
}


size_t intSizeOf(long long num)
{
    num = abs(num);
    if (num < pow(2, 16) / 2) {
        return 2;
    }
    else if (num < pow(2, 32) / 2) {
        return 4;
    }
    else if (num < pow(2, 64) / 2) {
        return 8;
    }
}

struct_record* arrayStructRecord(jvm_array_type * arr, type* valueType) {
    struct_record * record = new struct_record();
    record->name = valueType->readableName() + "()";
    record->type = arr;
    record->parent = rtl_class_record::Object;
    record->fields["Length"] = new field_record("Length", false, rtl_class_record::UInteger->type, record);
    return record;
}

jvm_array_type::jvm_array_type(type* valueType) : valueType(valueType), struct_type(arrayStructRecord(this, valueType))
{
}

std::string struct_type::qualifiedName() const
{
    return "brookit/vb/code/" + record->name;
}
