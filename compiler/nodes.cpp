#include "nodes.hpp"
#include "dot.hpp"

std::string expr_node::getName() {
    switch (type) {
    case expr_type::String:
        return "string";
    case expr_type::Id:
        return "id";
    case expr_type::Int:
        return "int";
    case expr_type::Bool:
        return "bool";
    case expr_type::Float:
        return "float";
    case expr_type::Nothing:
        return "nothing";
    case expr_type::Me:
        return "me";
    case expr_type::Char:
        return "char";
    case expr_type::Datetime:
        return "datetime";
    case expr_type::AddOp:
        return "add";
    case expr_type::SubOp:
        return "sub";
    case expr_type::MulOp:
        return "mul";
    case expr_type::DivOp:
        return "div";
    case expr_type::FloorDivOp:
        return "floordiv";
    case expr_type::ExpOp:
        return "exp";
    case expr_type::StrConcatOp:
        return "strconcat";
    case expr_type::LtOp:
        return "lt";
    case expr_type::GtOp:
        return "gt";
    case expr_type::GteOp:
        return "gte";
    case expr_type::LteOp:
        return "lte";
    case expr_type::EqOp:
        return "eq";
    case expr_type::NeqOp:
        return "noteq";
    case expr_type::AndOp:
        return "and";
    case expr_type::AndAlsoOp:
        return "andalso";
    case expr_type::OrOp:
        return "or";
    case expr_type::OrElseOp:
        return "orelse";
    case expr_type::LeqOp:
        return "leq";
    case expr_type::GeqOp:
        return "geq";
    case expr_type::XorOp:
        return "xor";
    case expr_type::ModOp:
        return "mod";
    case expr_type::LshiftOp:
        return "lshift";
    case expr_type::RshiftOp:
        return "rshift";
    case expr_type::IsOp:
        return "is";
    case expr_type::IsNotOp:
        return "isnot";
    case expr_type::UnaryMinusOp:
        return "unaryminus";
    case expr_type::UnaryPlusOp:
        return "unaryplus";
    case expr_type::NotOp:
        return "not";
    case expr_type::MemberAccess:
        return "member_access";
    case expr_type::MyClassMemberAccess:
        return "myclass_access";
    case expr_type::MyBaseMemberAccess:
        return "mybase_access";
    case expr_type::CallOrIndex:
        return "call/index";
    case expr_type::Cast:
        return "cast";
    case expr_type::If:
        return "if_expr";
    case expr_type::New:
        return "new";
    case expr_type::Collection:
        return "collection";
    case expr_type::ArrayNew:
        return "arraynew";
    case expr_type::Index:
        return "index";
    case expr_type::Call:
        return "call";
    default:
        return "expr";
    }
}

void expr_node::dot(DotWriter * out) {
    size_t litId;

    switch (type) {
    case expr_type::String:
        out->addNodeLabel(this);
        litId = getNewId();
        out->label(litId, this->String);
        out->link(this->id, litId, "");
        break;
    case expr_type::Id:
        out->addNodeLabel(this);
        litId = getNewId();
        out->label(litId, this->String);
        out->link(this->id, litId, "");
        break;
    case expr_type::Int:
        out->addNodeLabel(this);
        litId = getNewId();
        out->label(litId, std::to_string(this->Int));
        out->link(this->id, litId, "");
        break;
    case expr_type::Bool:
        out->label(this->id, this->Bool ? "true" : "false");
        break;
    case expr_type::Float:
        out->addNodeLabel(this);
        litId = getNewId();
        out->label(litId, std::to_string(this->Float));
        out->link(this->id, litId, "");
        break;
    case expr_type::Nothing:
        out->label(this->id, "Nothing");
        break;
    case expr_type::Me:
        out->label(this->id, "Me");
        break;
    case expr_type::Char:
        out->label(this->id, std::to_string(this->Char));
        break;
    case expr_type::Datetime:
        out->addNodeLabel(this);
        litId = getNewId();
        out->label(litId, this->DateTime->str());
        out->link(this->id, litId, "");
        break;
    case expr_type::UnaryMinusOp:
        out->addNodeLabel(this);
        out->addNode(this->argument);
        out->linkNodes(this, this->argument, "argument");
        break;
    case expr_type::UnaryPlusOp:
        out->addNodeLabel(this);
        out->addNode(this->argument);
        out->linkNodes(this, this->argument, "argument");
        break;
    case expr_type::NotOp:
        out->addNodeLabel(this);
        out->addNode(this->argument);
        out->linkNodes(this, this->argument, "argument");
        break;
    case expr_type::MyClassMemberAccess:
        out->addNodeLabel(this);
        out->addNode(this->right);
        out->linkNodes(this, this->right, "right");
        break;
    case expr_type::MyBaseMemberAccess:
        out->addNodeLabel(this);
        out->addNode(this->right);
        out->linkNodes(this, this->right, "right");
        break;
    case expr_type::CallOrIndex:
        out->addNodeLabel(this);
        out->addNode(this->left);
        out->linkNodes(this, this->left, "left");
        out->addList(this->arg_list);
        out->linkList(this, this->arg_list, "arg_list");
        break;
    case expr_type::Cast:
        out->addNodeLabel(this);
        out->addNode(this->datatype);
        out->linkNodes(this, this->datatype, "datatype");
        out->addNode(this->argument);
        out->linkNodes(this, this->argument, "argument");
        break;
    case expr_type::If:
        out->addNodeLabel(this);
        out->addNode(this->condition);
        out->linkNodes(this, this->condition, "cond");
        out->addNode(this->then_expr);
        out->linkNodes(this, this->then_expr, "then");
        out->addNode(this->else_expr);
        out->linkNodes(this, this->else_expr, "else");
        break;
    case expr_type::New:
        out->addNodeLabel(this);
        out->addNode(this->datatype);
        out->linkNodes(this, this->datatype, "datatype");
        out->addList(this->arg_list);
        out->linkList(this, this->arg_list, "arg_list");
        break;
    case expr_type::Collection:
        out->addNodeLabel(this);
        out->addList(this->arg_list);
        out->linkList(this, this->arg_list, "arg_list");
        break;
    case expr_type::ArrayNew:
        out->addNodeLabel(this);
        out->addNode(this->datatype);
        out->linkNodes(this, this->datatype, "datatype");
        out->addList(this->arg_list);
        out->linkList(this, this->arg_list, "arg_list");
        out->addList(this->collection);
        out->linkList(this, this->collection, "collection");
        break;
    case expr_type::Index:
        out->addNodeLabel(this);
        out->addNode(this->left);
        out->linkNodes(this, this->left, "left");
        out->addList(this->arg_list);
        out->linkList(this, this->arg_list, "arg_list");
        break;
    case expr_type::Call:
        out->addNodeLabel(this);
        out->addNode(this->left);
        out->linkNodes(this, this->left, "left");
        out->addList(this->arg_list);
        out->linkList(this, this->arg_list, "right");
        break;
    default:
        out->addNodeLabel(this);
        out->addNode(this->left);
        out->linkNodes(this, this->left, "left");
        out->addNode(this->right);
        out->linkNodes(this, this->right, "right");
        break;
    }
}

std::string stmt_node::getName() {
    std::string prefix = "";
    switch (type) {
    case stmt_type::Call:
        return "call_stmt";
    case stmt_type::If:
        return "if_stmt";
    case stmt_type::ElseIf:
        return "else_if_stmt";
    case stmt_type::For:
        return "for_stmt";
    case stmt_type::ForEach:
        return "foreach_stmt";
    case stmt_type::Select:
        return "select_stmt";
    case stmt_type::Case:
        return "case_stmt";
    case stmt_type::CaseRange:
        return "case_range_stmt";
    case stmt_type::CaseElse:
        return "case_else_stmt";
    case stmt_type::While:
        return "while_stmt";
    case stmt_type::DoWhile:
        return "dowhile_stmt";
    case stmt_type::DoUntil:
        return "dountil_stmt";
    case stmt_type::Label:
        return "label_stmt";
    case stmt_type::VarDecl:
        return "var_decl_stmt";
    case stmt_type::Assignment:
        switch (assign_type) {
            case assignment_type::AddAssign:
                prefix = "add";
                break;
            case assignment_type::SubAssign:
                prefix = "sub";
                break;
            case assignment_type::MulAssign:
                prefix = "mul";
                break;
            case assignment_type::DivAssign:
                prefix = "div";
                break;
            case assignment_type::FloorDivAssign:
                prefix = "floordiv";
                break;
            case assignment_type::ExpAssign:
                prefix = "exp";
                break;
            case assignment_type::StrConcatAssign:
                prefix = "dot";
                break;
            case assignment_type::LshiftAssign:
                prefix = "lshift";
                break;
            case assignment_type::RshiftAssign:
                prefix = "rshift";
                break;
            default:
                break;
        }
        return prefix + "_" + "assignment_stmt";
    case stmt_type::ContinueDo:
        return "continue_do";
    case stmt_type::ContinueWhile:
        return "continue_while";
    case stmt_type::ContinueFor:
        return "continue_for";
    case stmt_type::ExitDo:
        return "exit_do";
    case stmt_type::ExitWhile:
        return "exit_while";
    case stmt_type::ExitFor:
        return "exit_for";
    case stmt_type::ExitSelect:
        return "exit_select";
    case stmt_type::Redim:
        return "redim_stmt";
    case stmt_type::Erase:
        return "erase_stmt";
    case stmt_type::Return:
        return "return_stmt";
    default:
        return "stmt";
    }
}

void stmt_node::dot(DotWriter* out) {
    size_t nameId, modId;
    const char* var;

    switch (type) {
    case stmt_type::Call:
        out->addNodeLabel(this);
        out->addNode(target_expr);
        out->linkNodes(this, target_expr);
        break;
    case stmt_type::If:
        out->addNodeLabel(this);
        out->addNode(condition);
        out->linkNodes(this, condition, "cond");
        out->addList(block);
        out->linkList(this, block, "if_block");
        out->addList(condition_nodes);
        out->linkList(this, condition_nodes, "branches");
        out->addList(else_block);
        out->linkList(this, else_block, "else_block");
        break;
    case stmt_type::ElseIf:
        out->addNodeLabel(this);
        out->addNode(condition);
        out->linkNodes(this, condition, "condition");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::For:
        out->addNodeLabel(this);
        nameId = out->addStringNode(Id);
        out->link(((node *)this)->id, nameId, "varname");
        out->addNode(to_expr);
        out->linkNodes(this, to_expr, "to");
        out->addNode(target_expr);
        out->linkNodes(this, target_expr, "init_val");
        out->addNode(step_node);
        out->linkNodes(this, step_node, "step");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::ForEach:
        out->addNodeLabel(this);
        nameId = getNewId();
        out->label(nameId, Id);
        out->link(((node*)this)->id, nameId, "varname");
        out->addNode(container_expr);
        out->linkNodes(this, container_expr, "container");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::Select:
        out->addNodeLabel(this);
        out->addNode(target_expr);
        out->linkNodes(this, target_expr, "target");
        out->addList(condition_nodes);
        out->linkList(this, condition_nodes, "branches");
        break;
    case stmt_type::Case:
        out->addNodeLabel(this);
        out->addNode(condition);
        out->linkNodes(this, condition, "cond");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::CaseRange:
        out->addNodeLabel(this);
        out->addNode(condition);
        out->linkNodes(this, condition, "from");
        out->addNode(to_expr);
        out->linkNodes(this, to_expr, "to");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::CaseElse:
        out->addNodeLabel(this);
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::While:
        out->addNodeLabel(this);
        out->addNode(condition);
        out->linkNodes(this, condition, "cond");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::DoWhile:
        out->addNodeLabel(this);
        out->addNode(condition);
        out->linkNodes(this, condition, "cond");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::DoUntil:
        out->addNodeLabel(this);
        out->addNode(condition);
        out->linkNodes(this, condition, "cond");
        out->addList(block);
        out->linkList(this, block, "block");
        break;
    case stmt_type::VarDecl:
        out->addNodeLabel(this);
        out->addNode(var_decl);
        out->linkNodes(this, var_decl, "decl");
        var = "dim";
        modId = out->addStringNode(var);
        out->link(((node*)this)->id, modId, "modifier");
        break;
    case stmt_type::Assignment:
        out->addNodeLabel(this);
        out->addNode(lvalue);
        out->linkNodes(this, lvalue, "lval");
        out->addNode(rvalue);
        out->linkNodes(this, rvalue, "rval");
        break;
    case stmt_type::ContinueDo:
        out->addNodeLabel(this);
        break;
    case stmt_type::ContinueWhile:
        out->addNodeLabel(this);
        break;
    case stmt_type::ContinueFor:
        out->addNodeLabel(this);
        break;
    case stmt_type::ExitDo:
        out->addNodeLabel(this);
        break;
    case stmt_type::ExitWhile:
        out->addNodeLabel(this);
        break;
    case stmt_type::ExitFor:
        out->addNodeLabel(this);
        break;
    case stmt_type::ExitSelect:
        out->addNodeLabel(this);
        break;
    case stmt_type::Redim:
        out->addNodeLabel(this);
        out->addList(redim);
        out->linkList(this, redim);
        break;
    case stmt_type::Erase:
        out->addNodeLabel(this);
        out->addList(expr_list);
        out->linkList(this, expr_list);
        break;
    case stmt_type::Return:
        out->addNodeLabel(this);
        out->addNode(target_expr);
        out->linkNodes(this, target_expr, "val");
        break;
    default:
        std::cerr << "Unknown stmt type\n";
        break;
    }
}

void procedure_node::dot(DotWriter* out) {
    out->addNodeLabel(this);
    out->addNode(returnType);
    out->linkNodes(this, returnType, "ret_type");
    out->addStringList(generics);
    out->linkList(this, generics, "generic");
    size_t nameId = out->addStringNode(name);
    out->link(this->id, nameId, "name");
    out->addList(arguments);
    out->linkList(this, arguments, "args");
    out->addList(block);
    out->linkList(this, block, "body");
}

void struct_node::dot(DotWriter* out) {
    out->addNodeLabel(this);
    out->addStringList(generics);
    out->linkList(this, generics, "generic");
    size_t nameId = out->addStringNode(name);
    out->link(this->id, nameId, "name");
    out->addNode(parent_class);
    out->linkNodes(this, parent_class, "parent");
    out->addList(fields);
    out->linkList(this, fields, "fields");
    out->addList(methods);
    out->linkList(this, fields, "methods");
}

std::string type_node::getName() {
    switch (value) {
    case datatype_type::Byte:
        return "byte_type";
    case datatype_type::Object:
        return "object_type";
    case datatype_type::Integer:
        return "int_type";
    case datatype_type::Boolean:
        return "bool_type";
    case datatype_type::SByte:
        return "sbyte_type";
    case datatype_type::UShort:
        return "ushort_type";
    case datatype_type::Short:
        return "short_type";
    case datatype_type::UInteger:
        return "uint_type";
    case datatype_type::Long:
        return "long_type";
    case datatype_type::ULong:
        return "ulong_type";
    case datatype_type::Date:
        return "date_type";
    case datatype_type::Char:
        return "char_type";
    case datatype_type::String:
        return "string_type";
    case datatype_type::Decimal:
        return "decimal_type";
    case datatype_type::Single:
        return "float_single_type";
    case datatype_type::Double:
        return "double_type";
    case datatype_type::UserType:
        return this->Id + "_type";
    default:
        return "unknown_type";
    }
}

void type_node::dot(DotWriter* out) {
    out->addNodeLabel(this);
    out->addList(generics);
    out->linkList(this, generics, "generics");
    out->addList(dimensions, true, !isArray);
    out->linkList(this, dimensions, "array_dimensions", !isArray);
}

void typed_value::dot(DotWriter* out) {
    out->addNodeLabel(this);
    size_t nameId = out->addStringNode(varName);
    out->link(this->id, nameId, "name");
    out->addNode(type);
    out->linkNodes(this, type, "type");
    out->addNode(value);
    out->linkNodes(this, value, "value");
}

void redim_clause_node::dot(DotWriter* out) {
    out->addNodeLabel(this);
    size_t id = out->addStringNode(Id);
    out->link(this->id, id, "id");
    out->addList(arg);
    out->linkList(this, arg, "args");
}

void program_node::dot(DotWriter* out) {
    out->addNodeLabel(this);
    int i = 0;
    for (node* node : *nodes) {
        out->addNode(node);
        out->linkNodes(this, node, std::to_string(i));
        i++;
    }
}

void field_node::dot(DotWriter* out) {
    out->addNodeLabel(this);
    out->addNode(decl);
    out->linkNodes(this, decl, "decl");
}