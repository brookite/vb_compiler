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

// Создание корневой программы
program_node* create_program() {
    program_node* node = new program_node();
    return node;
}


// Узлы для ENDL
stmt_node* create_endl_node() {
    stmt_node* node = new stmt_node(EndlNode);
    return node;
}

stmt_node* create_stmt_endl_node() {
    stmt_node* node = new stmt_node(StmtEndlNode);
    return node;
}

stmt_node* create_stmt_endl_colon_node() {
    stmt_node* node = new stmt_node(StmtEndlColonNode);
    return node;
}

// Узлы для opt_endl
stmt_node* create_opt_endl_node() {
    stmt_node* node = new stmt_node(OptEndlNode);
    return node;
}

stmt_node* create_empty_node() {
    stmt_node* node = new stmt_node(EmptyNode);
    return node;
}

// Узлы для идентификаторов, строк и других типов
expr_node* create_id(const std::string& value) {
    expr_node* node = new expr_node(IdType);
    node->value = value;
    return node;
}

expr_node* create_string(const std::string& value) {
    expr_node* node = new expr_node(StringType);
    node->value = value;
    return node;
}

expr_node* create_float(double value) {
    expr_node* node = new expr_node(FloatType);
    node->value = value;
    return node;
}

expr_node* create_bool(bool value) {
    expr_node* node = new expr_node(BoolType);
    node->value = value;
    return node;
}

expr_node* create_datetime(DateTime* value) {
    expr_node* node = new expr_node(DateTimeType);
    node->value = value;
    return node;
}

expr_node* create_char(char value) {
    expr_node* node = new expr_node(CharType);
    node->value = value;
    return node;
}

expr_node* create_nothing() {
    expr_node* node = new expr_node(NothingType);
    return node;
}

expr_node* create_me() {
    expr_node* node = new expr_node(MeType);
    return node;
}

// Узлы для сложных выражений
expr_node* create_arraynew_expr(expr_node* type, expr_node* size) {
    expr_node* node = new expr_node(ArrayNewExpr);
    node->type = type;
    node->size = size;
    return node;
}

type_node* create_primitive_type(PrimitiveType type) {
    type_node* node = new type_node(PrimitiveTypeNode);
    node->primitive_type = type;
    return node;
}

type_node* create_ref_type(ReferenceType type, const std::string& name) {
    type_node* node = new type_node(RefTypeNode);
    node->ref_type = type;
    node->name = name;
    return node;
}

// Узлы для ReDim
stmt_node* create_redim_clause(const std::string& id, expr_node* expr_list) {
    stmt_node* node = new stmt_node(RedimClauseNode);
    node->id = id;
    node->expr_list = expr_list;
    return node;
}

stmt_node* create_redim_clause_list(stmt_node* clause) {
    stmt_node* node = new stmt_node(RedimClauseListNode);
    node->clauses.push_back(clause);
    return node;
}

// Узлы для select и case
stmt_node* create_select_case_stmt(expr_node* expr, stmt_node* case_stmts) {
    stmt_node* node = new stmt_node(SelectCaseStmt);
    node->expr = expr;
    node->case_stmts = case_stmts;
    return node;
}

stmt_node* create_case_condition_branch(expr_node* condition, stmt_node* block) {
    stmt_node* node = new stmt_node(CaseConditionBranch);
    node->condition = condition;
    node->block = block;
    return node;
}

stmt_node* create_case_range_branch(expr_node* start, expr_node* end, stmt_node* block) {
    stmt_node* node = new stmt_node(CaseRangeBranch);
    node->start = start;
    node->end = end;
    node->block = block;
    return node;
}

stmt_node* create_case_condition_branches(stmt_node* branch) {
    stmt_node* node = new stmt_node(CaseConditionBranches);
    node->branches.push_back(branch);
    return node;
}

stmt_node* create_case_else_stmt(stmt_node* block) {
    stmt_node* node = new stmt_node(CaseElseStmt);
    node->block = block;
    return node;
}

stmt_node* create_case_stmts(stmt_node* branches) {
    stmt_node* node = new stmt_node(CaseStmts);
    node->branches = branches;
    return node;
}

stmt_node* create_case_stmts_else(stmt_node* branches, stmt_node* else_stmt) {
    stmt_node* node = new stmt_node(CaseStmtsElse);
    node->branches = branches;
    node->else_stmt = else_stmt;
    return node;
}

// Узлы для модификаторов
stmt_node* create_shared_modifier() {
    stmt_node* node = new stmt_node(SharedModifierNode);
    return node;
}

stmt_node* create_empty_modifier() {
    stmt_node* node = new stmt_node(EmptyModifierNode);
    return node;
}

stmt_node* create_empty_while_stmt(expr_node* condition) {
    stmt_node* node = new stmt_node(WhileStmtNode);
    node->condition = condition;
    node->block = nullptr;
    return node;
}

stmt_node* create_while_stmt(expr_node* condition, stmt_node* block) {
    stmt_node* node = new stmt_node(WhileStmtNode);
    node->condition = condition;
    node->block = block;
    return node;
}

stmt_node* create_simple_for_stmt(expr_node* variable, expr_node* start, expr_node* end) {
    stmt_node* node = new stmt_node(ForStmtNode);
    node->variable = variable;
    node->start = start;
    node->end = end;
    node->step = nullptr;
    node->block = nullptr;
    return node;
}

stmt_node* create_step_for_stmt(expr_node* variable, expr_node* start, expr_node* end, expr_node* step, stmt_node* block) {
    stmt_node* node = new stmt_node(ForStmtNode);
    node->variable = variable;
    node->start = start;
    node->end = end;
    node->step = step;
    node->block = block;
    return node;
}

stmt_node* create_simple_foreach_stmt(expr_node* variable, expr_node* collection, stmt_node* block) {
    stmt_node* node = new stmt_node(ForeachStmtNode);
    node->variable = variable;
    node->collection = collection;
    node->block = block;
    return node;
}

stmt_node* create_while_do_stmt(expr_node* condition, stmt_node* block) {
    stmt_node* node = new stmt_node(DoWhileStmtNode);
    node->condition = condition;
    node->block = block;
    return node;
}

stmt_node* create_until_do_stmt(expr_node* condition, stmt_node* block) {
    stmt_node* node = new stmt_node(DoUntilStmtNode);
    node->condition = condition;
    node->block = block;
    return node;
}

stmt_node* create_typed_var_declarator(expr_node* variable, type_node* type) {
    stmt_node* node = new stmt_node(TypedVarDeclaratorNode);
    node->variable = variable;
    node->type = type;
    return node;
}

stmt_node* create_initialized_var_declarator(expr_node* variable, expr_node* value) {
    stmt_node* node = new stmt_node(InitializedVarDeclaratorNode);
    node->variable = variable;
    node->value = value;
    return node;
}

stmt_node* create_typed_initialized_var_declarator(expr_node* variable, type_node* type, expr_node* value) {
    stmt_node* node = new stmt_node(TypedInitializedVarDeclaratorNode);
    node->variable = variable;
    node->type = type;
    node->value = value;
    return node;
}

stmt_node* create_static_var_declaration(stmt_node* declarator) {
    stmt_node* node = new stmt_node(StaticVarDeclarationNode);
    node->declarator = declarator;
    return node;
}

stmt_node* create_dim_var_declaration(stmt_node* declarator) {
    stmt_node* node = new stmt_node(DimVarDeclarationNode);
    node->declarator = declarator;
    return node;
}

stmt_node* create_const_var_declaration(stmt_node* declarator) {
    stmt_node* node = new stmt_node(ConstVarDeclarationNode);
    node->declarator = declarator;
    return node;
}

type_node* create_simple_type(const std::string& name) {
    type_node* node = new type_node(SimpleTypeNode);
    node->name = name;
    return node;
}

type_node* create_generic_type(const std::string& name, std::vector<type_node*> type_list) {
    type_node* node = new type_node(GenericTypeNode);
    node->name = name;
    node->type_list = type_list;
    return node;
}

type_node* create_type_list(type_node* type) {
    type_node* node = new type_node(TypeListNode);
    node->type_list.push_back(type);
    return node;
}

type_node* append_to_type_list(type_node* list, type_node* type) {
    list->type_list.push_back(type);
    return list;
}

stmt_node* create_id_list(expr_node* id) {
    stmt_node* node = new stmt_node(IdListNode);
    node->ids.push_back(id);
    return node;
}

stmt_node* append_to_id_list(stmt_node* list, expr_node* id) {
    list->ids.push_back(id);
    return list;
}

stmt_node* create_function_signature(const std::string& name, stmt_node* parameters, type_node* return_type) {
    stmt_node* node = new stmt_node(FunctionSignatureNode);
    node->name = name;
    node->parameters = parameters;
    node->return_type = return_type;
    return node;
}


stmt_node* create_simple_function_declaration(stmt_node* signature) {
    stmt_node* node = new stmt_node(FunctionDeclarationNode);
    node->signature = signature;
    node->block = nullptr;
    return node;
}

stmt_node* create_simple_sub_declaration(stmt_node* signature) {
    stmt_node* node = new stmt_node(SubDeclarationNode);
    node->signature = signature;
    node->block = nullptr;
    return node;
}

stmt_node* create_function_parameters(std::vector<stmt_node*> parameters) {
    stmt_node* node = new stmt_node(FunctionParametersNode);
    node->parameters = parameters;
    return node;
}

stmt_node* create_class_declaration(const std::string& name, stmt_node* base_class, stmt_node* body) {
    stmt_node* node = new stmt_node(ClassDeclarationNode);
    node->name = name;
    node->base_class = base_class;
    node->body = body;
    return node;
}

stmt_node* create_class_declaration_no_inheritance(const std::string& name, stmt_node* body) {
    stmt_node* node = new stmt_node(ClassDeclarationNode);
    node->name = name;
    node->base_class = nullptr;
    node->body = body;
    return node;
}

stmt_node* create_generic_class_declaration(const std::string& name, stmt_node* generic_params, stmt_node* base_class, stmt_node* body) {
    stmt_node* node = new stmt_node(GenericClassDeclarationNode);
    node->name = name;
    node->generic_params = generic_params;
    node->base_class = base_class;
    node->body = body;
    return node;
}

stmt_node* create_generic_class_declaration_no_inheritance(const std::string& name, stmt_node* generic_params, stmt_node* body) {
    stmt_node* node = new stmt_node(GenericClassDeclarationNode);
    node->name = name;
    node->generic_params = generic_params;
    node->base_class = nullptr;
    node->body = body;
    return node;
}

stmt_node* create_field_modifiers(std::vector<stmt_node*> modifiers) {
    stmt_node* node = new stmt_node(FieldModifiersNode);
    node->modifiers = modifiers;
    return node;
}

stmt_node* create_dim_modifier() {
    stmt_node* node = new stmt_node(DimModifierNode);
    return node;
}

stmt_node* create_readonly_modifier() {
    stmt_node* node = new stmt_node(ReadonlyModifierNode);
    return node;
}

// Узлы для блоков
stmt_node* create_empty_block() {
    stmt_node* node = new stmt_node(BlockNode);
    node->block_stmts = {};
    return node;
}

stmt_node* create_block(stmt_node* stmt) {
    stmt_node* node = new stmt_node(BlockNode);
    node->block_stmts.push_back(stmt);
    return node;
}

// Узлы для переменных
expr_node* create_variable_name(const std::string& name) {
    expr_node* node = new expr_node(VariableNode);
    node->value = name;
    return node;
}

expr_node* create_array_variable(const std::string& name, stmt_node* modifier) {
    expr_node* node = new expr_node(ArrayVariableNode);
    node->value = name;
    node->array_modifier = modifier;
    return node;
}

stmt_node* create_array_modifier() {
    stmt_node* node = new stmt_node(ArrayModifierNode);
    return node;
}

stmt_node* create_empty_array_modifier() {
    stmt_node* node = new stmt_node(EmptyArrayModifierNode);
    return node;
}


expr_node* create_call(expr_node* callee) {
    expr_node* node = new expr_node(CallNode);
    node->callee = callee;
    node->arguments = nullptr;
    return node;
}

list<expr_node*>* create_expr_list() {
    return new list<expr_node*>();
}

list<expr_node*>* create_empty_else_if_stmts() {
    return new list<expr_node*>();
}

variable_node* create_variable_node(std::string* name) {
    variable_node* node = new variable_node();
    node->name = *name;
    return node;
}

variable_node* create_typed_variable_node(std::string* name, type_node* type) {
    variable_node* node = create_variable_node(name);
    node->type = type;
    return node;
}


var_declarator_node* create_var_declarator(variable_node* variable) {
    var_declarator_node* node = new var_declarator_node();
    node->variable = variable;
    node->type = nullptr;
    node->value = nullptr;
    return node;
}

var_declarator_node* create_typed_var_declarator(variable_node* variable, type_node* type) {
    var_declarator_node* node = create_var_declarator(variable);
    node->type = type;
    return node;
}

var_declarator_node* create_initialized_var_declarator(variable_node* variable, expr_node* value) {
    var_declarator_node* node = create_var_declarator(variable);
    node->value = value;
    return node;
}

var_declarator_node* create_typed_initialized_var_declarator(variable_node* variable, type_node* type, expr_node* value) {
    var_declarator_node* node = create_typed_var_declarator(variable, type);
    node->value = value;
    return node;
}


function_signature_node* create_function_signature(
    std::string* name,
    list<parameter_node*>* parameters,
    type_node* return_type
) {
    function_signature_node* node = new function_signature_node();
    node->name = *name;
    node->parameters = parameters;
    node->return_type = return_type;
    return node;
}

function_signature_node* create_function_signature_no_params(std::string* name, type_node* return_type) {
    return create_function_signature(name, nullptr, return_type);
}

function_signature_node* create_function_signature_simple(std::string* name) {
    return create_function_signature(name, nullptr, nullptr);
}

function_signature_node* create_generic_function_signature(
    std::string* name,
    list<type_node*>* generic_params,
    list<parameter_node*>* parameters,
    type_node* return_type
) {
    function_signature_node* node = create_function_signature(name, parameters, return_type);
    node->generic_params = generic_params;
    return node;
}

expr_node* create_call(expr_node* callee) {
    expr_node* node = new expr_node(CallNode);
    node->callee = callee;
    node->arguments = nullptr;
    return node;
}

list<expr_node*>* create_expr_list() {
    return new list<expr_node*>();
}

list<expr_node*>* create_empty_else_if_stmts() {
    return new list<expr_node*>();
}

variable_node* create_variable_node(std::string* name) {
    variable_node* node = new variable_node();
    node->name = *name;
    return node;
}

variable_node* create_typed_variable_node(std::string* name, type_node* type) {
    variable_node* node = create_variable_node(name);
    node->type = type;
    return node;
}



var_declarator_node* create_var_declarator(variable_node* variable) {
    var_declarator_node* node = new var_declarator_node();
    node->variable = variable;
    node->type = nullptr;
    node->value = nullptr;
    return node;
}

var_declarator_node* create_typed_var_declarator(variable_node* variable, type_node* type) {
    var_declarator_node* node = create_var_declarator(variable);
    node->type = type;
    return node;
}

var_declarator_node* create_initialized_var_declarator(variable_node* variable, expr_node* value) {
    var_declarator_node* node = create_var_declarator(variable);
    node->value = value;
    return node;
}

var_declarator_node* create_typed_initialized_var_declarator(variable_node* variable, type_node* type, expr_node* value) {
    var_declarator_node* node = create_typed_var_declarator(variable, type);
    node->value = value;
    return node;
}


type_node* create_simple_type(std::string* type_name) {
    type_node* node = new type_node(SimpleType);
    node->name = *type_name;
    return node;
}

type_node* create_generic_type(std::string* type_name, list<type_node*>* type_list) {
    type_node* node = new type_node(GenericType);
    node->name = *type_name;
    node->generic_args = type_list;
    return node;
}

list<type_node*>* create_type_list(type_node* type) {
    list<type_node*>* list = new list<type_node*>();
    list->push_back(type);
    return list;
}

list<type_node*>* append_to_type_list(list<type_node*>* type_list, type_node* type) {
    type_list->push_back(type);
    return type_list;
}

list<std::string>* create_id_list(std::string* id) {
    list<std::string>* list = new list<std::string>();
    list->push_back(*id);
    return list;
}

list<std::string>* append_to_id_list(list<std::string>* id_list, std::string* id) {
    id_list->push_back(*id);
    return id_list;
}

function_signature_node* create_function_signature(
    std::string* name,
    list<parameter_node*>* parameters,
    type_node* return_type
) {
    function_signature_node* node = new function_signature_node();
    node->name = *name;
    node->parameters = parameters;
    node->return_type = return_type;
    return node;
}

function_signature_node* create_function_signature_no_params(std::string* name, type_node* return_type) {
    return create_function_signature(name, nullptr, return_type);
}

function_signature_node* create_function_signature_simple(std::string* name) {
    return create_function_signature(name, nullptr, nullptr);
}

function_signature_node* create_generic_function_signature(
    std::string* name,
    list<type_node*>* generic_params,
    list<parameter_node*>* parameters,
    type_node* return_type
) {
    function_signature_node* node = create_function_signature(name, parameters, return_type);
    node->generic_params = generic_params;
    return node;
}


sub_signature_node* create_sub_signature(std::string* name, list<parameter_node*>* parameters) {
    sub_signature_node* node = new sub_signature_node();
    node->name = *name;
    node->parameters = parameters;
    return node;
}

sub_signature_node* create_sub_signature_no_params(std::string* name) {
    return create_sub_signature(name, nullptr);
}

sub_signature_node* create_sub_signature_simple(std::string* name) {
    return create_sub_signature(name, nullptr);
}

class_node* create_class_declaration(
    std::string* name,
    std::string* inherits,
    list<structure_member_node*>* body
) {
    class_node* node = new class_node();
    node->name = *name;
    node->inherits = inherits ? *inherits : "";
    node->body = body;
    return node;
}

class_node* create_class_declaration_no_inheritance(
    std::string* name,
    list<structure_member_node*>* body
) {
    return create_class_declaration(name, nullptr, body);
}

struct_node* create_struct_declaration(
    std::string* name,
    std::string* inherits,
    list<structure_member_node*>* body
) {
    struct_node* node = new struct_node();
    node->name = *name;
    node->inherits = inherits ? *inherits : "";
    node->body = body;
    return node;
}

struct_node* create_struct_declaration_no_inheritance(
    std::string* name,
    list<structure_member_node*>* body
) {
    return create_struct_declaration(name, nullptr, body);
}


list<structure_member_node*>* create_structure_body(structure_member_node* member) {
    list<structure_member_node*>* body = new list<structure_member_node*>();
    body->push_back(member);
    return body;
}

list<structure_member_node*>* append_to_structure_body(
    list<structure_member_node*>* body,
    structure_member_node* member
) {
    body->push_back(member);
    return body;
}

list<structure_member_node*>* create_empty_structure_body() {
    return new list<structure_member_node*>();
}

var_declaration_node* create_static_var_declaration(var_declarator_node* declarator) {
    var_declaration_node* node = new var_declaration_node();
    node->declarator = declarator;
    node->is_static = true;
    return node;
}

var_declaration_node* create_dim_var_declaration(var_declarator_node* declarator) {
    var_declaration_node* node = new var_declaration_node();
    node->declarator = declarator;
    node->is_static = false;
    return node;
}

var_declaration_node* create_const_var_declaration(var_declarator_node* declarator) {
    var_declaration_node* node = create_dim_var_declaration(declarator);
    node->is_constant = true;
    return node;
}create_callcreate_expr_list

//////////

expr_node* create_array_type(type_node* type, array_modifier_node* modifier) {
    debug_print("Creating array type");
    array_type_node* node = new array_type_node();
    node->base_type = type;
    node->modifier = modifier;
    return node;
}

function_signature_node* create_generic_function_signature_no_params(std::string id, type_node* return_type) {
    debug_print("Creating generic function signature with no parameters");
    function_signature_node* node = new function_signature_node();
    node->id = id;
    node->return_type = return_type;
    return node;
}

function_signature_node* create_generic_function_signature_simple(std::string id, generic_param_list_node* params) {
    debug_print("Creating simple generic function signature");
    function_signature_node* node = new function_signature_node();
    node->id = id;
    node->generic_params = params;
    return node;
}

sub_signature_node* create_generic_sub_signature(std::string id, generic_param_list_node* params, function_parameters_node* parameters) {
    debug_print("Creating generic sub signature");
    sub_signature_node* node = new sub_signature_node();
    node->id = id;
    node->generic_params = params;
    node->parameters = parameters;
    return node;
}

sub_signature_node* create_generic_sub_signature_no_params(std::string id, generic_param_list_node* params) {
    debug_print("Creating generic sub signature with no parameters");
    sub_signature_node* node = new sub_signature_node();
    node->id = id;
    node->generic_params = params;
    return node;
}

sub_signature_node* create_generic_sub_signature_simple(std::string id, generic_param_list_node* params) {
    debug_print("Creating simple generic sub signature");
    sub_signature_node* node = new sub_signature_node();
    node->id = id;
    node->generic_params = params;
    return node;
}

constructor_signature_node* create_constructor_signature(function_parameters_node* parameters) {
    debug_print("Creating constructor signature");
    constructor_signature_node* node = new constructor_signature_node();
    node->parameters = parameters;
    return node;
}

constructor_signature_node* create_constructor_signature_no_params() {
    debug_print("Creating constructor signature with no parameters");
    constructor_signature_node* node = new constructor_signature_node();
    return node;
}///

constructor_signature_node* create_simple_constructor_signature() {
    debug_print("Creating simple constructor signature");
    constructor_signature_node* node = new constructor_signature_node();
    return node;
}

constructor_declaration_node* create_constructor_declaration(opt_procedure_modifiers_node* modifiers, constructor_signature_node* signature, block_node* block) {
    debug_print("Creating constructor declaration");
    constructor_declaration_node* node = new constructor_declaration_node();
    node->modifiers = modifiers;
    node->signature = signature;
    node->block = block;
    return node;
}

function_declaration_node* create_function_declaration(opt_procedure_modifiers_node* modifiers, function_signature_node* signature, block_node* block) {
    debug_print("Creating function declaration");
    function_declaration_node* node = new function_declaration_node();
    node->modifiers = modifiers;
    node->signature = signature;
    node->block = block;
    return node;
}

function_declaration_node* create_simple_function_declaration(opt_procedure_modifiers_node* modifiers, function_signature_node* signature) {
    debug_print("Creating simple function declaration");
    function_declaration_node* node = new function_declaration_node();
    node->modifiers = modifiers;
    node->signature = signature;
    return node;
}

sub_declaration_node* create_sub_declaration(opt_procedure_modifiers_node* modifiers, sub_signature_node* signature, block_node* block) {
    debug_print("Creating sub declaration");
    sub_declaration_node* node = new sub_declaration_node();
    node->modifiers = modifiers;
    node->signature = signature;
    node->block = block;
    return node;
}

sub_declaration_node* create_simple_sub_declaration(opt_procedure_modifiers_node* modifiers, sub_signature_node* signature) {
    debug_print("Creating simple sub declaration");
    sub_declaration_node* node = new sub_declaration_node();
    node->modifiers = modifiers;
    node->signature = signature;
    return node;
}

generic_param_list_node* create_generic_param_list(std::string id, id_list_node* id_list) {
    debug_print("Creating generic parameter list");
    generic_param_list_node* node = new generic_param_list_node();
    node->id = id;
    node->id_list = id_list;
    return node;
}

const_declaration_node* create_const_declaration(var_declarator_node* declarator) {
    debug_print("Creating const declaration");
    const_declaration_node* node = new const_declaration_node();
    node->declarator = declarator;
    return node;
}

field_declaration_node* create_field_declaration(field_modifiers_node* modifiers, var_declarator_node* declarator) {
    debug_print("Creating field declaration");
    field_declaration_node* node = new field_declaration_node();
    node->modifiers = modifiers;
    node->declarator = declarator;
    return node;
}
