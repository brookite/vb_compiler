#include "../compiler/nodes.hpp"

expr_node* create_binary(expr_node* left, expr_node * right, expr_type type) {
	expr_node* node = new expr_node(type);
	node->left = left;
	node->right = right;
	return node;
}

expr_node* create_int(long long value) {
	expr_node* node = new expr_node(Int);
	node->Int = value;
	return node;
}

expr_node* create_unary(expr_node* expr, expr_type type) {
	expr_node* node = new expr_node(type);
	node->expr = expr;
	return node;
}

expr_node* create_call_expr(expr_node* call, expr_list* expr_list) {
	expr_node* node = new expr_node(CallExpr);
	node->call = call;
	node->expr_list = expr_list;
	return node;
}

expr_node* create_cast(type_node* type, expr_node* expr) {
	expr_node* node = new expr_node(CastExpr);
	node->type = type;
	node->expr = expr;
	return node;
}

expr_node* create_if_expr(expr_node* expr1, expr_node* expr2, expr_node* expr3) {
	expr_node* node = new expr_node(IfExpr);
	node->expr1 = expr1;
	node->expr2 = expr2;
	node->expr3 = expr3;
	return node;
}

expr_node* create_member_access(expr_node* expr, id_node* id) {
	expr_node* node = new expr_node(MemberAccess);
	node->expr = expr;
	node->id = id;
	return node;
}

expr_node* create_mybase_access(id_node* id) {
	expr_node* node = new expr_node(MyBaseAccess);
	node->id = id;
	return node;
}

expr_node* create_myclass_access(id_node* id) {
	expr_node* node = new expr_node(MyClassAccess);
	node->id = id;
	return node;
}

expr_node* create_new_expr(id_node* id) {
	expr_node* node = new expr_node(NewExpr);
	node->id = id;
	return node;
}

expr_node* create_new_expr(id_node* id, expr_list* expr_list) {
	expr_node* node = new expr_node(NewExpr);
	node->id = id;
	node->expr_list = expr_list;
	return node;
}

expr_node* create_new_expr(id_node* id, expr_node* expr) {
	expr_node* node = new expr_node(NewExpr);
	node->id = id;
	node->expr = expr;
	return node;
}

expr_node* create_new_expr(id_node* id, expr_list* expr_list, expr_node* collection_initializer) {
	expr_node* node = new expr_node(NewExpr);
	node->id = id;
	node->expr_list = expr_list;
	node->collection_initializer = collection_initializer;
	return node;
}

expr_node* create_array_literal(expr_list* expr_list) {
	expr_node* node = new expr_node(ArrayLiteral);
	node->expr_list = expr_list;
	return node;
}

stmt_node* create_call_stmt(expr_node* expr) {
	stmt_node* node = new stmt_node(CallStmt);
	node->expr = expr;
	return node;
}

stmt_node* create_redim(redim_clause_list* redim_clause_list) {
	stmt_node* node = new stmt_node(RedimStmt);
	node->redim_clause_list = redim_clause_list;
	return node;
}

stmt_node* create_erase(expr_list* expr_list) {
	stmt_node* node = new stmt_node(EraseStmt);
	node->expr_list = expr_list;
	return node;
}

stmt_node* create_if_stmt(expr_node* expr, block_node* block, else_if_stmts* else_if_stmts, block_node* else_block) {
	stmt_node* node = new stmt_node(IfStmt);
	node->expr = expr;
	node->block = block;
	node->else_if_stmts = else_if_stmts;
	node->else_block = else_block;
	return node;
}

stmt_node* create_select_stmt(expr_node* expr, case_stmts* case_stmts) {
	stmt_node* node = new stmt_node(SelectStmt);
	node->expr = expr;
	node->case_stmts = case_stmts;
	return node;
}

stmt_node* create_label_stmt(id_node* id) {
	stmt_node* node = new stmt_node(LabelStmt);
	node->id = id;
	return node;
}

stmt_node* create_for_stmt(id_node* id, expr_node* expr1, expr_node* expr2, block_node* block) {
	stmt_node* node = new stmt_node(ForStmt);
	node->id = id;
	node->expr1 = expr1;
	node->expr2 = expr2;
	node->block = block;
	return node;
}

stmt_node* create_foreach_stmt(id_node* id, expr_node* expr, block_node* block) {
	stmt_node* node = new stmt_node(ForEachStmt);
	node->id = id;
	node->expr = expr;
	node->block = block;
	return node;
}

stmt_node* create_do_infinite_loop(block_node* block) {
	stmt_node* node = new stmt_node(DoInfiniteLoop);
	node->block = block;
	return node;
}

stmt_node* create_do_while_stmt(block_node* block, expr_node* expr) {
	stmt_node* node = new stmt_node(DoWhileStmt);
	node->block = block;
	node->expr = expr;
	return node;
}

stmt_node* create_do_until_stmt(block_node* block, expr_node* expr) {
	stmt_node* node = new stmt_node(DoUntilStmt);
	node->block = block;
	node->expr = expr;
	return node;
}

stmt_node* create_while_stmt(expr_node* expr, block_node* block) {
	stmt_node* node = new stmt_node(WhileStmt);
	node->expr = expr;
	node->block = block;
	return node;
}

stmt_node* create_var_declaration(var_declarator* var_declarator) {
	stmt_node* node = new stmt_node(VarDeclaration);
	node->var_declarator = var_declarator;
	return node;
}

stmt_node* create_assign(expr_node* expr1, expr_node* expr2, assign_type type) {
	stmt_node* node = new stmt_node(AssignStmt);
	node->expr1 = expr1;
	node->expr2 = expr2;
	node->type = type;
	return node;
}

stmt_node* create_return() {
	stmt_node* node = new stmt_node(ReturnStmt);
	return node;
}

stmt_node* create_return(expr_node* expr) {
	stmt_node* node = new stmt_node(ReturnStmt);
	node->expr = expr;
	return node;
}

stmt_node* create_continue(continue_type type) {
	stmt_node* node = new stmt_node(ContinueStmt);
	node->type = type;
	return node;
}

stmt_node* create_exit(exit_type type) {
	stmt_node* node = new stmt_node(ExitStmt);
	node->type = type;
	return node;
}

stmt_node* create_stop() {
	stmt_node* node = new stmt_node(StopStmt);
	return node;
}

stmt_node* create_end() {
	stmt_node* node = new stmt_node(EndStmt);
	return node;
}

id_node* create_goto_label(id_node* id) {
	id_node
}
