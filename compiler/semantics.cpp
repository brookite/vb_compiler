#include "semantics.hpp"
#include <climits>
#include "codegen/rtl.hpp"

void _walk_exprs(expr_node* expr, list<expr_node*>* result) {
	if (expr->condition != nullptr) {
		result->add(expr->condition);
		_walk_exprs(expr->condition, result);
	}
	if (expr->then_expr != nullptr) {
		result->add(expr->then_expr);
		_walk_exprs(expr->then_expr, result);
	}
	if (expr->else_expr != nullptr) {
		result->add(expr->else_expr);
		_walk_exprs(expr->else_expr, result);
	}
	if (expr->left != nullptr) {
		result->add(expr->left);
		_walk_exprs(expr->left, result);
	}
	if (expr->right != nullptr) {
		result->add(expr->right);
		_walk_exprs(expr->right, result);
	}
	for (expr_node* innerExpr : *expr->collection) {
		result->addNotNull(innerExpr);
		_walk_exprs(innerExpr, result);
	}
	for (expr_node* innerExpr : *expr->arg_list) {
		result->addNotNull(innerExpr);
		_walk_exprs(innerExpr, result);
	}
}

list<expr_node*> walkExprs(list<expr_node*> exprs) {
	list<expr_node*> newExprs;
	newExprs.addAll(exprs);
	for (expr_node* expr : exprs) {
		_walk_exprs(expr, &newExprs);
	}
	return newExprs;
}

// ������������� �������, ������ expr �� ����������� � ������ ��������� ������ �� �����������
list<expr_node*> collectExprs(stmt_node* stmt) {
	list<expr_node*> result;
	if (stmt == nullptr) {
		return result;
	}
	if (stmt->target_expr != nullptr) {
		result.add(stmt->target_expr);
	}
	if (stmt->expr_list != nullptr && !stmt->expr_list->isEmpty()) {
		result.addAll(*stmt->expr_list);
	}
	if (stmt->condition != nullptr) {
		result.add(stmt->condition);
	}
	if (stmt->lvalue != nullptr) {
		result.add(stmt->lvalue);
	}
	if (stmt->rvalue != nullptr) {
		result.add(stmt->rvalue);
	}
	for (redim_clause_node* redim : *stmt->redim) {
		result.addAllNotNull(*redim->arg);
	}

	if (stmt->var_decl != nullptr && stmt->var_decl->value != nullptr) {
		result.add(stmt->var_decl->value);
	}
	if (stmt->step_node != nullptr) {
		result.add(stmt->step_node);
	}
	if (stmt->to_expr != nullptr) {
		result.add(stmt->to_expr);
	}
	if (stmt->container_expr != nullptr) {
		result.add(stmt->container_expr);
	}

	return result;
}

void findRedimIds(stmt_node* stmt, list<std::string>* result);

void findRedimIds(list<stmt_node*>* nodes, list<std::string>* result) {
	if (nodes == nullptr) return;
	for (stmt_node* stmt : *nodes) {
		findRedimIds(stmt, result);
	}
}

void findRedimIds(stmt_node* stmt, list<std::string>* result) {
	if (stmt->redim != nullptr && !stmt->redim->isEmpty()) {
		for (redim_clause_node* rnode : *stmt->redim) {
			result->add(rnode->Id);
		}
	}
	findRedimIds(stmt->block, result);
	findRedimIds(stmt->else_block, result);
	findRedimIds(stmt->condition_nodes, result);
}

void findIdentifiers(expr_node* expr, list<std::string>* result) {
	if (expr == nullptr) {
		return;
	}
	if (expr->type == expr_type::Id) {
		result->add(expr->String);
	}
	else {
		if (expr->condition != nullptr) {
			findIdentifiers(expr->condition, result);
		}
		if (expr->then_expr != nullptr) {
			findIdentifiers(expr->then_expr, result);
		}
		if (expr->else_expr != nullptr) {
			findIdentifiers(expr->else_expr, result);
		}
		if (expr->left != nullptr) {
			findIdentifiers(expr->left, result);
		}
		if (expr->right != nullptr) {
			findIdentifiers(expr->right, result);
		}
		for (expr_node* innerExpr : *expr->collection) {
			findIdentifiers(innerExpr, result);
		}
		for (expr_node* innerExpr : *expr->arg_list) {
			findIdentifiers(innerExpr, result);
		}
	}
}

// ����� ��� ���������� ���������������, ��� ����� ������ ���������� ����������
list<std::string> findIdentifiers(stmt_node* stmt) {
	list<std::string> result;
	list<expr_node*> exprs = collectExprs(stmt);
	findRedimIds(stmt, &result);
	for (expr_node* expr : exprs) {
		findIdentifiers(expr, &result);
	}
	return result;
}


void findMemberAccess(expr_node* expr, list<expr_node*>* result) {
	if (expr == nullptr) {
		return;
	}
	if (expr->type == expr_type::MemberAccess ||
		expr->type == expr_type::MyBaseMemberAccess ||
		expr->type == expr_type::MyClassMemberAccess ||
		expr->type == expr_type::MethodCall
		) {
		result->add(expr);
		findMemberAccess(expr->left, result);
	}
	else {
		if (expr->condition != nullptr) {
			findMemberAccess(expr->condition, result);
		}
		if (expr->then_expr != nullptr) {
			findMemberAccess(expr->then_expr, result);
		}
		if (expr->else_expr != nullptr) {
			findMemberAccess(expr->else_expr, result);
		}
		if (expr->left != nullptr) {
			findMemberAccess(expr->left, result);
		}
		if (expr->right != nullptr) {
			findMemberAccess(expr->right, result);
		}
		for (expr_node* innerExpr : *expr->collection) {
			findMemberAccess(innerExpr, result);
		}
		for (expr_node* innerExpr : *expr->arg_list) {
			findMemberAccess(innerExpr, result);
		}
	}
}


list<expr_node*> findMemberAccess(stmt_node* stmt) {
	list<expr_node*> result;
	list<expr_node*> exprs = collectExprs(stmt);
	for (expr_node* expr : exprs) {
		findMemberAccess(expr, &result);
	}
	return result;
}

void findTypeMentions(expr_node* expr, list<type_node*>* result) {
	if (expr == nullptr) {
		return;
	}
	if (expr->datatype != nullptr) {
		result->add(expr->datatype);
	}
	if (expr->condition != nullptr) {
		findTypeMentions(expr->condition, result);
	}
	if (expr->then_expr != nullptr) {
		findTypeMentions(expr->then_expr, result);
	}
	if (expr->else_expr != nullptr) {
		findTypeMentions(expr->else_expr, result);
	}
	if (expr->left != nullptr) {
		findTypeMentions(expr->left, result);
	}
	if (expr->right != nullptr) {
		findTypeMentions(expr->right, result);
	}

	for (expr_node* innerExpr : *expr->collection) {
		findTypeMentions(innerExpr, result);
	}
	for (expr_node* innerExpr : *expr->arg_list) {
		findTypeMentions(innerExpr, result);
	}
}

list<type_node*> findTypeMentions(stmt_node* stmt) {
	list<type_node*> result;
	if (stmt->var_decl != nullptr && stmt->var_decl->type != nullptr) {
		result.add(stmt->var_decl->type);
	}
	if (stmt->id_type != nullptr) {
		result.add(stmt->id_type);
	}

	for (stmt_node* innerStmt : *stmt->condition_nodes) {
		result.addAllNotNull(findTypeMentions(innerStmt));
	}
	if (stmt->else_block != nullptr) {
		for (stmt_node* innerStmt : *stmt->else_block) {
			result.addAllNotNull(findTypeMentions(innerStmt));
		}
	}
	if (stmt->block != nullptr) {
		for (stmt_node* innerStmt : *stmt->block) {
			result.addAllNotNull(findTypeMentions(innerStmt));
		}
	}
	findTypeMentions(stmt->target_expr, &result);
	findTypeMentions(stmt->condition, &result);
	findTypeMentions(stmt->lvalue, &result);
	findTypeMentions(stmt->rvalue, &result);
	findTypeMentions(stmt->step_node, &result);
	findTypeMentions(stmt->to_expr, &result);
	findTypeMentions(stmt->container_expr, &result);

	return result;
}


semantic_analyzer::semantic_analyzer()
{
	ctx.setAnalyzer(this);
	initRTL();
	ctx.addRTL(rtl_class_record::String);
	ctx.addRTL(rtl_class_record::Integer);
	ctx.addRTL(rtl_class_record::Long);
	ctx.addRTL(rtl_class_record::ULong);
	ctx.addRTL(rtl_class_record::UInteger);
	ctx.addRTL(rtl_class_record::Short);
	ctx.addRTL(rtl_class_record::UShort);
	ctx.addRTL(rtl_class_record::Byte);
	ctx.addRTL(rtl_class_record::SByte);
	ctx.addRTL(rtl_class_record::Console);
	ctx.addRTL(rtl_class_record::Object);
	ctx.addRTL(rtl_class_record::DateTime);
	ctx.addRTL(rtl_class_record::Char);
	ctx.addRTL(rtl_class_record::Single);
	ctx.addRTL(rtl_class_record::Double);
	ctx.addRTL(rtl_class_record::Boolean);
	ctx.addRTL(rtl_class_record::Math);
}

void semantic_analyzer::analyzeProgram(program_node* node)
{
	// ���� �������������� ���������� � ������� � �������
	target = node;
	for (struct_node* cls : *node->nodes) {
		struct_record* clsRecord = ctx.addClass(cls);
		if (clsRecord->isGeneric()) {
			continue;
		}

	}

	for (struct_node* cls : *node->nodes) {
		struct_record* clsRecord = ctx.classes[cls->name];
		if (clsRecord->isGeneric()) {
			continue;
		}
		if (clsRecord->parent == nullptr && clsRecord->node->parent_class != nullptr) {
			type* t = inferType(clsRecord->node->parent_class, this->ctx, nullptr);
			struct_type* stype = dynamic_cast<struct_type*>(t);
			if (stype == nullptr) {
				type_error("Inheritance from unknown or unsupported type '%s'", t->readableName().c_str());
				return;
			}
			clsRecord->parent = stype->record;
		}
		if (clsRecord->node->parent_class == nullptr) {
			clsRecord->parent = rtl_class_record::Object;
		}
		for (field_node* field : *cls->fields) {
			clsRecord->addField(field, ctx);
		}
		// ������� ������� ���������� � ���� �������
		for (procedure_node* proc : *cls->methods) {
			clsRecord->addMethod(proc, ctx);
		}
	}

	// ��������� ������ ����� ��������� ���� ������� � �������, ����� ����� ���� ��������� �� ��� ������������� ������
	for (const auto& pair : this->ctx.classes) {
		if (dynamic_cast<rtl_class_record*>(pair.second) != nullptr || pair.second == nullptr || pair.second->isGeneric()) {
			continue;
		}
		struct_record* clsRecord = pair.second;
		processStruct(clsRecord);
	}
	flushErrorBuffer();
}

void semantic_analyzer::processMethod(struct_record* structRecord, method_record* method)
{
	for (parameter_record* param : method->args) {
		method->locals[param->name] = param;
	}
	for (stmt_node* stmt : *(method->node->block)) {
		processStmt(structRecord, method, stmt);
	}
}

void semantic_analyzer::processStmtList(struct_record* structRecord, method_record* method, block* block) {
	for (stmt_node* node : *block) {
		processStmt(structRecord, method, node);
	}
}

// ���������� ����� ����������� ��������� ���������� � �����
void semantic_analyzer::processStmt(struct_record* structRecord, method_record * method, stmt_node* stmt)
{
	if (stmt->type == stmt_type::Call) {
		if (stmt->target_expr->type != expr_type::CallOrIndex && stmt->target_expr->type != expr_type::Call) {
			value_error("Call statement must have only callable expressions");
			return;
		}
	}

	list<expr_node*> exprs = collectExprs(stmt);

	// constant refs for literals
	list<expr_node*> allExprs = walkExprs(exprs);
	for (expr_node* expr : allExprs) {
		processExpr(structRecord, method, expr);
	}

	list<std::string> idents = findIdentifiers(stmt);
	list<expr_node*> memAccessNodes = findMemberAccess(stmt);
	list<type_node*> mentionedTypes = findTypeMentions(stmt);

	// check undefined identifier, type
	for (std::string unknownId : idents) {
		expr_node* id = new expr_node(expr_type::Id);
		id->String = unknownId;
		if (ctx.resolveId(id, structRecord, method).first == nullptr) {
			name_error("Unknown identifier '%s'", unknownId.c_str());
			return;
		}
	}
	
	for (expr_node* memAccess : memAccessNodes) {
		std::pair<record *, access_target> record = ctx.resolveMemberAccess(memAccess, structRecord, method);
		if (record.first == nullptr) {
			continue;
		}
		
		if (record.second == STATIC_METHOD || record.second == METHOD) {
			structRecord->addConstantBy((method_record*) record.first);
		}
		else if (record.second == STATIC_FIELD || record.second == FIELD) {
			structRecord->addConstantBy((field_record*) record.first);
		}
	}

	// unknown type find
	for (type_node* type : mentionedTypes) {
		struct type* tVal = inferType(type, ctx, structRecord->typeMap);
		if (tVal == nullptr) {
			name_error("Type '%s' is not declared", type->getName().c_str());
		}
		else {
			structRecord->addConstantBy(tVal);
		}
	}
	
	// check type for var decl
	if (stmt->type == stmt_type::VarDecl) {

		localvar_record* varRecord = new localvar_record();
		varRecord->name = stmt->var_decl->varName;
		bool cond = strcmp("t", varRecord->name.c_str()) == 0;
		varRecord->type = inferType(stmt->var_decl->type, ctx, structRecord->typeMap);
		varRecord->owner = method;
		varRecord->valueNode = stmt->var_decl;
		method->locals[varRecord->name] = varRecord;

		type* declaredType = inferType(stmt->var_decl->type, this->ctx, structRecord->typeMap);
		if (stmt->var_decl->value == nullptr) {
			if (declaredType->isValueType()) {
				stmt->var_decl->value = new expr_node(expr_type::Int);
				stmt->var_decl->value->Int = 0;
			}
			else {
				stmt->var_decl->value = new expr_node(expr_type::Nothing);
			}
		}
		type* inferredType = inferType(stmt->var_decl->value, structRecord, method, this->ctx);
		if (stmt->var_decl->value != nullptr && !declaredType->isAssignableFrom(inferredType, this->ctx)) {
			type_error("Variable value in declaration '%s' has incompatible types: %s and %s (in value) ", stmt->var_decl->varName.c_str(), declaredType->readableName().c_str(),
				inferredType->readableName().c_str()
			);
			return;
		}
	}

	if (stmt->type == stmt_type::Call) {
		inferType(stmt->target_expr, structRecord, method, ctx);
		if (stmt->target_expr->type == expr_type::Index) {
			type_error("Index cannot be in call statement");
		}
	}

	// check type in for
	if (stmt->type == stmt_type::For) {
		if (stmt->id_type != nullptr && stmt->target_expr != nullptr) {
			type* exprInferredType = inferType(stmt->target_expr, structRecord, method, this->ctx);
			type* declaredType = inferType(stmt->id_type, this->ctx, structRecord->typeMap);
			type* toInferredType = inferType(stmt->to_expr, structRecord, method, this->ctx);
			if (!declaredType->isAssignableFrom(exprInferredType, this->ctx)) {
				type_error("Incompatible types in for-variable %s: %s (declared in field) and %s", stmt->Id.c_str(),
					declaredType->readableName().c_str(), exprInferredType->readableName().c_str());
				return;
			}
			if (!declaredType->isAssignableFrom(toInferredType, this->ctx)) {
				type_error("Incompatible types in for to-expression %s: %s (declared in field) and %s", stmt->Id.c_str(),
					declaredType->readableName().c_str(), toInferredType->readableName().c_str());
				return;
			}
		}
	}
	
	// lvalue, rvalue checks
	if (stmt->lvalue != nullptr && stmt->rvalue != nullptr) {
		if (
			stmt->lvalue->type != expr_type::MemberAccess &&
			stmt->lvalue->type != expr_type::Id &&
			stmt->lvalue->type != expr_type::Index) {
			value_error("This expression cannot be lvalue");
			return;
		}

		type* lvalueType = inferType(stmt->lvalue, structRecord, method, this->ctx);
		type* rvalueType = inferType(stmt->rvalue, structRecord, method, this->ctx);
		if (!lvalueType->isAssignableFrom(rvalueType, this->ctx)) {
			type_error("Incompatible types in assignment statement: %s and %s (left-value type)",
				rvalueType->readableName().c_str(), lvalueType->readableName().c_str());
			return;
		}
		
		if (stmt->lvalue->type == expr_type::Index) {
			stmt->type = stmt_type::ArrayAssign;
		}
		else if (stmt->lvalue->type == expr_type::MemberAccess 
			|| stmt->lvalue->type == expr_type::MyClassMemberAccess
			|| stmt->lvalue->type == expr_type::MyBaseMemberAccess
		) {
			stmt->type = stmt_type::FieldAssign;
		}
	}

	if (stmt->type == stmt_type::Return) {
		type* inferredRetType;
		if (stmt->target_expr != nullptr) {
			inferredRetType = inferType(stmt->target_expr, structRecord, method, this->ctx);
		}
		else {
			inferredRetType = new void_type();
		}
		if (!method->returnType->isAssignableFrom(inferredRetType, this->ctx)) {
			type_error("Incompatible types in return type of %s: %s (declared in signature) and %s", method->node->name.c_str(),
				method->returnType->readableName().c_str(), inferredRetType->readableName().c_str());
			return;
		}
	}

	if (stmt->block != nullptr) {
		if (stmt->type == stmt_type::For || stmt->type == stmt_type::ForEach) {
			method->locals[stmt->Id] = new localvar_record(stmt->Id, inferType(stmt->id_type, ctx, structRecord->typeMap), method);
		}
		list<std::string> locals;
		for (stmt_node* innerStmt : *stmt->block) {
			processStmt(structRecord, method, innerStmt);
			if (innerStmt->type == stmt_type::VarDecl) {
				locals.add(innerStmt->var_decl->varName);
			}
		}
		// ������� ���������� ��� ������ �� �����
		for (std::string local : locals) {
			method->locals.erase(local);
		}
		if (stmt->type == stmt_type::For || stmt->type == stmt_type::ForEach) {
			method->locals.erase(stmt->Id);
		}
	}
	if (stmt->else_block != nullptr) {
		list<std::string> locals;
		for (stmt_node* innerStmt : *stmt->else_block) {
			processStmt(structRecord, method, innerStmt);
			if (innerStmt->type == stmt_type::VarDecl) {
				locals.add(innerStmt->var_decl->varName);
			}
		}
		// ������� ���������� ��� ������ �� �����
		for (std::string local : locals) {
			method->locals.erase(local);
		}
	}
	if (stmt->condition_nodes != nullptr) {
		list<std::string> locals;
		for (stmt_node* innerStmt : *stmt->condition_nodes) {
			processStmt(structRecord, method, innerStmt);
			if (innerStmt->type == stmt_type::VarDecl) {
				locals.add(innerStmt->var_decl->varName);
			}
		}
		// ������� ���������� ��� ������ �� �����
		for (std::string local : locals) {
			method->locals.erase(local);
		}
	}
}

void semantic_analyzer::processExpr(struct_record* structRecord, method_record * method, expr_node* expr)
{
	// method may be nullptr, means - expr in field declaration

	// avoid recursive subexprs changes here
	
	if (expr->type == expr_type::Int && intSizeOf(expr->Int) >= 2) {
		structRecord->addLiteralConstant(expr->Int);
	}
	else if (expr->type == expr_type::String) {
		structRecord->addLiteralConstant(expr->String);
	}
	else if (expr->type == expr_type::Float) {
		if (expr->Float <= FLT_MAX && expr->Float >= FLT_MIN) {
			structRecord->addLiteralConstant((float) expr->Float);
		}
		else {
			structRecord->addLiteralConstant(expr->Float);
		}
	}

	// myclass
	if (expr->type == expr_type::MyClassMemberAccess) {
		expr->left = new expr_node(expr_type::Id);
		expr->left->String = structRecord->name;
		expr->type = expr_type::MemberAccess;
	}

	// detect index and call expr
	// separate call into method call and function call
	ctx.processCallOrIndex(expr, structRecord, method);
}

void semantic_analyzer::processStruct(struct_record* clsRecord)
{
	for (auto & pair: clsRecord->fields) {
		field_record* rec = pair.second;
		field_node* field = rec->node;
		type* declaredType = inferType(field->decl->type, this->ctx, clsRecord->typeMap);
		if (field->decl->value == nullptr) {
			if (declaredType->isValueType()) {
				field->decl->value = new expr_node(expr_type::Int);
				field->decl->value->Int = 0;
			}
			else {
				field->decl->value = new expr_node(expr_type::Nothing);
			}
		}
		processExpr(new static_struct_record_wrapper(clsRecord), nullptr, field->decl->value);
		type* exprInferredType = inferType(field->decl->value, clsRecord, nullptr, this->ctx);
		if (!declaredType->isAssignableFrom(exprInferredType, this->ctx)) {
			type_error("Incompatible types in field %s: %s (declared in field) and %s", field->decl->varName.c_str(),
				declaredType->readableName().c_str(), exprInferredType->readableName().c_str());
			return;
		}
	}
	for (const auto& pair : clsRecord->methods) {
		method_record* method = pair.second;
		processMethod(clsRecord, method);
	}
}