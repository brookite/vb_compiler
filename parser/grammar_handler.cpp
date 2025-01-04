#include "../compiler/nodes.hpp"
#include "../compiler/utils.hpp"
#include "grammar.tab.h"

program_node* create_program() {
	program_node* node = new program_node();
	return node;
}

expr_node* create_id(std::string * value) {
	expr_node* node = new expr_node(expr_type::Id);
	node->String = *value;
	delete value;
	return node;
}

expr_node* create_id(const char * value) {
	expr_node* node = new expr_node(expr_type::Id);
	node->String = value;
	return node;
}

expr_node* create_string(std::string * value) {
	expr_node* node = new expr_node(expr_type::String);
	node->String = *value;
	delete value;
	return node;
}

expr_node* create_string(const char * value) {
	expr_node* node = new expr_node(expr_type::String);
	node->String = value;
	return node;
}

expr_node* create_float(FloatLiteral * value) {
	expr_node* node = new expr_node(expr_type::Float);
	node->Float = value->Float;
	node->numericType = nullptr;
	if (value->type == FloatType::DOUBLE_MOD) {
		node->numericType = new type_node(datatype_type::Double);
	}
	if (value->type == FloatType::FLOAT_MOD) {
		node->numericType = new type_node(datatype_type::Single);
	}
	else if (value->type == FloatType::DECIMAL_MOD) {
		node->numericType = new type_node(datatype_type::Decimal);
	}
	return node;
}

expr_node* create_bool(bool value) {
	expr_node* node = new expr_node(expr_type::Bool);
	node->Bool = value;
	return node;
}

expr_node* create_datetime(DateTime* value) {
	expr_node* node = new expr_node(expr_type::Datetime);
	node->DateTime = value;
	return node;
}

expr_node* create_char(char value) {
	expr_node* node = new expr_node(expr_type::Char);
	node->Char = value;
	return node;
}

expr_node* create_nothing() {
	expr_node* node = new expr_node(expr_type::Nothing);
	return node;
}

expr_node* create_me() {
	expr_node* node = new expr_node(expr_type::Me);
	return node;
}


expr_node* create_binary(expr_node* left, expr_node * right, expr_type type) {
	expr_node* node = new expr_node(type);
	node->left = left;
	node->right = right;
	return node;
}

expr_node* create_int(IntLiteral * value) {
	expr_node* node = new expr_node(expr_type::Int);
	node->Int = value->Int;
	node->numericType = nullptr;
	if (value->type == IntType::LONG_MOD) {
		if (value->isUnsigned) {
			node->numericType = new type_node(datatype_type::ULong);
		}
		else {
			node->numericType = new type_node(datatype_type::Long);
		}
	}
	else if (value->type == IntType::SHORT_MOD) {
		if (value->isUnsigned) {
			node->numericType = new type_node(datatype_type::UShort);
		}
		else {
			node->numericType = new type_node(datatype_type::Short);
		}
	}
	else {
		if (value->isUnsigned) {
			node->numericType = new type_node(datatype_type::UInteger);
		}
		else {
			node->numericType = new type_node(datatype_type::Integer);
		}
	}
	return node;
}

expr_node* create_unary(expr_node* expr, expr_type type) {
	expr_node* node = new expr_node(type);
	node->argument = expr;
	return node;
}

expr_node* create_call_expr(expr_node* call, list<expr_node *>* expr_list) {
	expr_node* node = new expr_node(expr_type::CallOrIndex);
	node->left = call;
	node->arg_list = expr_list;
	return node;
}

expr_node* create_call_expr(expr_node* call) {
	expr_node* node = new expr_node(expr_type::CallOrIndex);
	node->left = call;
	node->arg_list = new list<expr_node*>();
	return node;
}

expr_node* create_cast(type_node* type, expr_node* expr) {
	expr_node* node = new expr_node(expr_type::Cast);
	node->datatype = type;
	node->argument = expr;
	return node;
}

expr_node* create_if_expr(expr_node* expr1, expr_node* expr2, expr_node* expr3) {
	expr_node* node = new expr_node(expr_type::If);
	node->condition = expr1;
	node->then_expr = expr2;
	node->else_expr = expr3;
	return node;
}

expr_node* create_if_expr(expr_node* expr2, expr_node* expr3) {
	expr_node* node = new expr_node(expr_type::If);
	node->condition = create_binary(expr2, create_nothing(), expr_type::IsNotOp);;
	node->then_expr = expr2;
	node->else_expr = expr3;
	return node;
}

expr_node* create_member_access(expr_node* expr, expr_node* id) {
	expr_node* node = new expr_node(expr_type::MemberAccess);
	node->left = expr;
	node->String = id->String;
	return node;
}

expr_node* create_mybase_access(expr_node* id) {
	expr_node* node = new expr_node(expr_type::MyBaseMemberAccess);
	node->String = id->String;
	node->left = new expr_node(expr_type::MyBase);
	return node;
}

expr_node* create_myclass_access(expr_node* id) {
	expr_node* node = new expr_node(expr_type::MyClassMemberAccess);
	node->String = id->String;
	return node;
}

expr_node* create_new_expr(type_node* type) {
	expr_node* node = new expr_node(expr_type::New);
	node->datatype = type;
    node->arg_list = new list<expr_node*>();
	return node;
}

expr_node* create_new_expr(type_node* type, list<expr_node*>* expr_list) {
	expr_node* node = new expr_node(expr_type::New);
	node->datatype = type;
	node->arg_list = expr_list;
	return node;
}

expr_node* create_array_literal(list<expr_node*>* expr_list) {
	expr_node* node = new expr_node(expr_type::Collection);
	node->arg_list = expr_list;
	return node;
}

stmt_node* create_call_stmt(expr_node* expr) {
	stmt_node* node = new stmt_node(stmt_type::Call);
	node->target_expr = expr;
	return node;
}

stmt_node* create_call_stmt(expr_node* call, list<expr_node*>* expr_list) {
	expr_node* node = new expr_node(expr_type::CallOrIndex);
	node->left = call;
	node->arg_list = expr_list;
	return create_call_stmt(node);
}


stmt_node* create_redim(list<redim_clause_node*>* redim_clause) {
	stmt_node* node = new stmt_node(stmt_type::Redim);
	node->redim = redim_clause;
	return node;
}

stmt_node* create_erase(list<expr_node*>* expr_list) {
	stmt_node* node = new stmt_node(stmt_type::Erase);
	node->expr_list = expr_list;
	return node;
}

stmt_node* create_if_stmt(expr_node* expr, block* blk, list<stmt_node*>* else_if_stmts, block* else_block) {
	stmt_node* node = new stmt_node(stmt_type::If);
	node->condition = expr;
	node->block = blk;
	node->condition_nodes = else_if_stmts;
	node->else_block = else_block;
	return node;
}

stmt_node* create_select_stmt(expr_node* expr, list<stmt_node*>* case_stmts) {
	stmt_node* node = new stmt_node(stmt_type::Select);
	node->target_expr = expr;
	node->condition_nodes = case_stmts;
	return node;
}

stmt_node* create_for_stmt(type_node* type, std::string id, 
	expr_node * value, expr_node* to_expr, 
	expr_node* step, block* block) {

	stmt_node* node = new stmt_node(stmt_type::For);
	node->id_type = type;
	node->Id = id;
	node->to_expr = to_expr;
	node->step_node = step;
	node->target_expr = value;
	node->block = block;
	return node;
}

stmt_node* create_foreach_stmt(type_node* type, std::string id, expr_node* expr, block* block) {
	stmt_node* node = new stmt_node(stmt_type::ForEach);
	node->id_type = type;
	node->Id = id;
	node->container_expr = expr;
	node->block = block;
	return node;
}

stmt_node* create_do_infinite_loop(block* block) {
	stmt_node* node = new stmt_node(stmt_type::DoWhile);
    node->condition = create_bool(true);
	node->block = block;
	return node;
}

stmt_node* create_do_while_stmt(block* block, expr_node* expr) {
	stmt_node* node = new stmt_node(stmt_type::DoWhile);
	node->block = block;
	node->condition = expr;
	return node;
}

stmt_node* create_do_until_stmt(block* block, expr_node* expr) {
	stmt_node* node = new stmt_node(stmt_type::DoUntil);
	node->block = block;
	node->condition = expr;
	return node;
}

stmt_node* create_while_stmt(expr_node* expr, block* block) {
	stmt_node* node = new stmt_node(stmt_type::While);
	node->condition = expr;
	node->block = block;
	return node;
}

stmt_node* create_var_declaration(typed_value* var) {
	stmt_node* node = new stmt_node(stmt_type::VarDecl);
	node->var_decl = var;
	node->var_type = var_type::DIM;
	return node;
}

stmt_node* create_var_declaration(typed_value* var, var_type type) {
	stmt_node* node = new stmt_node(stmt_type::VarDecl);
	node->var_decl = var;
	node->var_type = type;
	return node;
}

stmt_node* create_assign(expr_node* expr1, expr_node* expr2, assignment_type type) {
	stmt_node* node = new stmt_node(stmt_type::Assignment);
	node->lvalue = expr1;
	node->rvalue = expr2;
	node->assign_type = type;
	return node;
}

stmt_node* create_return() {
	stmt_node* node = new stmt_node(stmt_type::Return);
	return node;
}

stmt_node* create_return(expr_node* expr) {
	stmt_node* node = new stmt_node(stmt_type::Return);
	node->target_expr = expr;
	return node;
}

stmt_node* create_continue(stmt_type type) {
	if (type == stmt_type::ContinueDo || type == stmt_type::ContinueWhile || type == stmt_type::ContinueFor) {
		stmt_node* node = new stmt_node(type);
		return node;
	}
	else {
		internal_error("Invalid continue type");
	}
}

stmt_node* create_exit(stmt_type type) {
	if (type == stmt_type::ExitFor || type == stmt_type::ExitWhile || type == stmt_type::ExitSelect || type == stmt_type::ExitDo) {
		stmt_node* node = new stmt_node(type);
		return node;
	}
	else {
		internal_error("Invalid continue type");
	}
}

expr_node* create_arraynew_expr(type_node* type, list<expr_node*>* size) {
    expr_node* node = new expr_node(expr_type::ArrayNew);
    node->datatype = type;
    node->arg_list = size;
	node->collection = new list<expr_node*>();
    return node;
}

expr_node* create_arraynew_expr(type_node* type, list<expr_node*>* size, list<expr_node*>* collection) {
	expr_node* node = new expr_node(expr_type::ArrayNew);
	node->datatype = type;
	node->arg_list = size;
	node->collection = collection;
	return node;
}

redim_clause_node* create_redim_clause(std::string * id, list<expr_node*>* expr_list) {
    redim_clause_node* node = new redim_clause_node();
	node->Id = *id;
    node->arg = expr_list;
    return node;
}

type_node* create_type(datatype_type type) {
	type_node* node = new type_node(type);
	node->value = type;
	return node;
}

type_node* create_array_type(type_node * type) {
	type->isArray = true;
	return type;
}

type_node* create_type(datatype_type type, std::string * id) {
	type_node* node = new type_node(type);
	node->value = type;
	node->Id = *id;
	return node;
}

type_node* create_type(datatype_type type, std::string* id, list<type_node*>* generics) {
	type_node* node = new type_node(type);
	node->value = type;
	node->Id = *id;
	node->generics = generics;
	return node;
}

type_node* create_type(datatype_type type, const char * id) {
	type_node* node = new type_node(type);
	node->value = type;
	node->Id = id;
	return node;
}

list<expr_node*>* create_expr_list() {
	return new list<expr_node*>();
}

list<redim_clause_node*>* create_redim_clause_list() {
	return new list<redim_clause_node*>();
}

stmt_node* create_case_condition_branch(expr_node * expr, block * block) {
	stmt_node* node = new stmt_node(stmt_type::Case);
	node->condition = expr;
	node->block = block;
	return node;
}

stmt_node* create_case_range_branch(expr_node * expr, expr_node * to_expr, block * block) {
	stmt_node* node = new stmt_node(stmt_type::CaseRange);
	node->condition = expr;
	node->block = block;
	node->to_expr = to_expr;
	return node;
}

stmt_node* create_case_else_stmt(block* block) {
	stmt_node* node = new stmt_node(stmt_type::CaseElse);
	node->block = block;
	return node;
}

block* create_block() {
	return new block();
}

stmt_node* create_elseif(expr_node * expr, block * block) {
	stmt_node* node = new stmt_node(stmt_type::ElseIf);
	node->condition = expr;
	node->block = block;
	return node;
}

typed_value* create_var_declarator(std::string* id) {
	typed_value* node = new typed_value();
	node->varName = *id;
	node->type = new type_node(datatype_type::Object);
	return node;
}

typed_value* create_array_var_declarator(std::string* id) {
	typed_value* node = new typed_value();
	node->varName = *id;
	node->isArray = true;
	node->type = new type_node(datatype_type::Object);
	node->type->isArray = true;
	return node;
}

typed_value* create_array_var_declarator(std::string* id, expr_node * size) {
	typed_value* node = new typed_value();
	node->varName = *id;
	node->isArray = true;
	node->array_size = size;
	node->type = new type_node(datatype_type::Object);
	node->type->isArray = true;
	return node;
}

typed_value* create_var_declarator(type_node* type, std::string * id) {
	typed_value* node = new typed_value();
	node->varName = *id;
	if (type == nullptr) {
		node->type = new type_node(datatype_type::Object);
	}
	else {
		node->type = type;
	}
	return node;
}

typed_value* append_var_declarator(typed_value* var, type_node* node, expr_node* value) {
	if (node == nullptr) {
		node = new type_node(datatype_type::Object);
	}
	var->type = node;
	var->value = value;
	if (var->isArray && var->type != nullptr) {
		var->type->isArray = true;
	}
	if (var->value == nullptr && var->isArray && var->array_size != nullptr) {
		type_node* valueType = var->type->clone();
		valueType->isArray = false;
		var->value = create_arraynew_expr(valueType, new list<expr_node*>({ var->array_size }));
	}
	return var;
}

list<type_node*>* create_type_list() {
	return new list<type_node*>();
}

list<std::string>* create_id_list() {
	return new list<std::string>();
}

procedure_node* create_function(std::string * name,
	list<typed_value*>* params, type_node* type, bool isProcedure) {
	procedure_node* node = new procedure_node();
	node->name = *name;
	node->arguments = params == nullptr ? new list<typed_value*>() : params;
	node->returnType = type;
	node->isProcedure = isProcedure;
	return node;
}


struct_node* create_struct(std::string * name,
	list<std::string>* generics,
	std::string* parent
) {
	struct_node* node = new struct_node();
	node->name = *name;
	node->generics = generics == nullptr ? new list<std::string>() : generics;
	node->fields = new list<field_node*>();
	node->methods = new list<procedure_node*>();
	if (parent != nullptr) node->parent_class = create_type(datatype_type::UserType, parent);
	return node;
}

struct_node* create_class(std::string * name,
	list<std::string>* generics,
	std::string* parent
) {
	struct_node* node = new struct_node();
	node->name = *name;
	if (parent != nullptr) node->parent_class = create_type(datatype_type::UserType, parent);
	node->generics = generics == nullptr ? new list<std::string>() : generics;
	node->fields = new list<field_node*>();
	node->methods = new list<procedure_node*>();
	return node;
}

struct_node* parse_struct_body(struct_node* s, list<node*>* nodes) {
	for (node* node : *nodes) {
		if (dynamic_cast<procedure_node*>(node) != nullptr) {
			s->methods->add((procedure_node*)node);
		} else if (dynamic_cast<field_node*>(node) != nullptr) {
			s->fields->add((field_node*)node);
		}
	}
	return s;
}

list<node*>* create_node_list() {
	return new list<node*>();
}

field_node* create_field(typed_value* val, bool isStatic, bool isConst) {
	field_node* field = new field_node();
	field->decl = val;
	field->isStatic = isStatic;
	field->type = isConst ? var_type::CONST : var_type::DIM;
	return field;
}

type_node* object_type() {
	return create_type(datatype_type::Object, "Object");
}