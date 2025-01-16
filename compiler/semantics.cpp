#include "semantics.hpp"
#include <climits>
#include "codegen/rtl.hpp"

void _walk_exprs(expr_node* expr, list<expr_node*>* result) {
	if (expr->condition != nullptr) {
		result->add(expr->condition);
		_walk_exprs(expr->condition, result);
	}
	if (expr->argument != nullptr) {
		result->add(expr->argument);
		_walk_exprs(expr->argument, result);
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

// Нерекурсивная функция, внутрь expr не заглядывает и другие выражения оттуда не вытаскивает
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
		result.add(redim->Id);
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

void findRedimIds(stmt_node* stmt, list<expr_node*>* result);

void findRedimIds(list<stmt_node*>* nodes, list<expr_node*>* result) {
	if (nodes == nullptr) return;
	for (stmt_node* stmt : *nodes) {
		findRedimIds(stmt, result);
	}
}

void findRedimIds(stmt_node* stmt, list<expr_node*>* result) {
	if (stmt->redim != nullptr && !stmt->redim->isEmpty()) {
		for (redim_clause_node* rnode : *stmt->redim) {
			result->add(rnode->Id);
		}
	}
	findRedimIds(stmt->block, result);
	findRedimIds(stmt->else_block, result);
	findRedimIds(stmt->condition_nodes, result);
}

void findIdentifiers(expr_node* expr, list<expr_node*>* result) {
	if (expr == nullptr) {
		return;
	}
	if (expr->type == expr_type::Id) {
		result->add(expr);
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
		if (expr->argument != nullptr) {
			findIdentifiers(expr->argument, result);
		}
		for (expr_node* innerExpr : *expr->collection) {
			findIdentifiers(innerExpr, result);
		}
		for (expr_node* innerExpr : *expr->arg_list) {
			findIdentifiers(innerExpr, result);
		}
	}
}

// Найти все упоминания идентификаторов, без учета самого объявления переменной
list<expr_node*> findIdentifiers(stmt_node* stmt) {
	list<expr_node*> result;
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
		if (expr->argument != nullptr) {
			findMemberAccess(expr->argument, result);
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
	if (expr->argument != nullptr) {
		findTypeMentions(expr->argument, result);
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

bool semantic_analyzer::analyzeProgram(program_node* node)
{
	list<method_record*> * mainMethods = new list<method_record*>();

	// Сбор первоначальной информации о классах и методах
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
			if (stype == nullptr || *t == *cls->record->type) {
				type_error("Inheritance from unknown or unsupported type '%s'", t->readableName().c_str());
				return true;
			}
			clsRecord->parent = stype->record;
		}
		if (clsRecord->node->parent_class == nullptr) {
			clsRecord->parent = rtl_class_record::Object;
		}
		for (field_node* field : *cls->fields) {
			clsRecord->addField(field, ctx);
		}
		// Сначала соберем информацию о всех методах
		for (procedure_node* proc : *cls->methods) {
			method_record * rec = clsRecord->addMethod(proc, ctx);
			if ((rec->name == "main" || rec->name == "Main") && rec->isStatic && rec->args.isEmpty()
				&& dynamic_cast<void_type*>(rec->returnType) != nullptr) {
				mainMethods->add(rec);
			}
		}
	}

	if (mainMethods->size() == 0) {
		name_error("Entry point is missing in this program. Shared Main method is needed");
	}
	else if (mainMethods->size() > 1) {
		name_error("Too many entry points. Program must have only one Shared Main method in one of classes of program");
	}
	else {
		entryPoint = mainMethods->get(0);
	}

	// Повторный проход после собранных имен методов и классов, чтобы можно было ссылаться на еще необъявленные классы
	for (const auto& pair : this->ctx.classes) {
		if (dynamic_cast<rtl_class_record*>(pair.second) != nullptr || pair.second == nullptr || pair.second->isGeneric()) {
			continue;
		}
		struct_record* clsRecord = pair.second;
		processStruct(clsRecord);
	}
	bool err = hasCompilerErrors();
	flushErrorBuffer();
	return err;
}

std::map<std::string, bytearray_t>* semantic_analyzer::compile()
{
	this->ctx.isCodegen = true;
	this->entryPoint->name = "main";
	this->entryPoint->args.add(new parameter_record("args", new jvm_type("String[]", "[Ljava/lang/String;"), this->entryPoint));
	this->entryPoint->localvarCounter++;
	std::map<std::string, bytearray_t>* result = new std::map<std::string, bytearray_t>();
	for (auto& pair : this->ctx.classes) {
		if (dynamic_cast<rtl_class_record*>(pair.second) == nullptr && !pair.second->isGeneric()) {
			bytearray_t bytes = pair.second->toBytes(&ctx);
			(*result)[pair.first] = bytes;
			if (hasCompilerErrors()) {
				flushErrorBuffer();
			}
		}
	}
	for (auto& pair : this->ctx.specializedTypes) {
		bytearray_t bytes = pair.second->record->toBytes(&ctx);
		(*result)[pair.second->record->name] = bytes;
		if (hasCompilerErrors()) {
			flushErrorBuffer();
		}
	}
	return result;
}

void semantic_analyzer::processMethod(struct_record* structRecord, method_record* method)
{
	size_t returnCount = 0;
	for (parameter_record* param : method->args) {
		method->locals[param->name] = param;
		param->number = method->localvarCounter;
		method->localvarCounter++;
	}
	for (stmt_node* stmt : *(method->node->block)) {
		processStmt(structRecord, method, stmt, &returnCount);
	}
	if (method->returnType == nullptr) internal_error("Return type isn't specified");

	if (dynamic_cast<void_type*>(method->returnType) == nullptr && returnCount == 0) {
		type_error("Function '%s' must return object of type '%s'", method->name.c_str(), method->returnType->readableName().c_str());
	}
}

void semantic_analyzer::processStmtList(struct_record* structRecord, method_record* method, block* block, size_t* returnCount) {
	for (stmt_node* node : *block) {
		processStmt(structRecord, method, node, returnCount);
	}
}

// Возвращает новые добавленные локальные переменные в метод
void semantic_analyzer::processStmt(struct_record* structRecord, method_record * method, stmt_node* stmt, size_t* returnCount)
{
	if (stmt->type == stmt_type::Call) {
		if (stmt->target_expr->type != expr_type::CallOrIndex && stmt->target_expr->type != expr_type::Call) {
			value_error("Call statement must have only callable expressions");
			return;
		}
	}

	if (stmt->type == stmt_type::Select) {
		internal_error("Select cases are not supported in this version. Please remove it from code");
	}

	list<expr_node*> exprs = collectExprs(stmt);

	// constant refs for literals
	list<expr_node*> allExprs = walkExprs(exprs);
	for (expr_node* expr : allExprs) {
		processExpr(structRecord, method, expr);
	}

	list<expr_node*> idents = findIdentifiers(stmt);
	list<expr_node*> memAccessNodes = findMemberAccess(stmt);
	list<type_node*> mentionedTypes = findTypeMentions(stmt);

	// check undefined identifier, type
	for (expr_node * unknownId : idents) {
		std::pair<record*, access_target> pair = ctx.resolveId(unknownId, structRecord, method);
		if (pair.first == nullptr) {
			name_error("Unknown identifier '%s'", unknownId->String.c_str());
			return;
		}
		if (pair.second == STRUCT || pair.second == STATIC_STRUCT) {
			structRecord->addConstantBy((struct_record*)pair.first);
		}
		if (dynamic_cast<localvar_record*>(pair.first) != nullptr) {
			unknownId->localvarNum = ((localvar_record*)pair.first)->number;
		}
	}
	
	for (expr_node* memAccess : memAccessNodes) {
		type* ownerType = nullptr;
		std::pair<record *, access_target> record = ctx.resolveMemberAccess(memAccess, structRecord, method, &ownerType);
		if (record.first == nullptr) {
			continue;
		}
		
		if (record.second == STATIC_METHOD || record.second == METHOD) {
			structRecord->addConstantBy((method_record*) record.first, ownerType == nullptr ? nullptr : ((struct_type*)ownerType)->record);
		}
		else if (record.second == STATIC_FIELD || record.second == FIELD) {
			structRecord->addConstantBy((field_record*) record.first, ownerType == nullptr ? nullptr : ((struct_type*)ownerType)->record);
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
		if (method->locals.count(stmt->var_decl->varName) || structRecord->fields.count(stmt->var_decl->varName)) {
			name_error("Variable '%s' already declared (re-declaraton)", stmt->var_decl->varName.c_str());
		}
		localvar_record* varRecord = new localvar_record();
		varRecord->name = stmt->var_decl->varName;
		varRecord->isConst = stmt->var_type == var_type::CONST;
		bool cond = strcmp("t", varRecord->name.c_str()) == 0;
		varRecord->type = inferType(stmt->var_decl->type, ctx, structRecord->typeMap);
		varRecord->owner = method;
		varRecord->valueNode = stmt->var_decl;
		varRecord->number = method->localvarCounter;
		method->localvarCounter++;
		stmt->localvarNum = varRecord->number;
		method->locals[varRecord->name] = varRecord;
		method->allLocals[varRecord->number] = varRecord;

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

	if (stmt->type == stmt_type::ForEach) {
		type* containerInferredType = inferType(stmt->container_expr, structRecord, method, this->ctx);
		type* declaredType = inferType(stmt->id_type, this->ctx, structRecord->typeMap);
		if (dynamic_cast<jvm_array_type*>(containerInferredType) == nullptr) {
			type_error("ForEach can be only applied to arrays");
		}
		if (*(dynamic_cast<jvm_array_type*>(containerInferredType)->valueType) != *declaredType) {
			type_error("Incompatible types in for-header %s (declared) and %s (arrayType)", declaredType->readableName().c_str(),
				containerInferredType->readableName().c_str());
		}
	}

	if (stmt->type == stmt_type::Redim) {
		for (redim_clause_node* redimCl : *stmt->redim) {
			type* varType = inferType(redimCl->Id, structRecord, method, this->ctx);
			if (dynamic_cast<jvm_array_type*>(varType) == nullptr) {
				type_error("Redim is supported only for arrays");
			}
			for (int i = 0; i < redimCl->arg->size(); i++) {
				expr_node* arg = redimCl->arg->get(i);
				type* argType = inferType(arg, structRecord, method, this->ctx);
				if (dynamic_cast<sized_rtl_type*>(argType) == nullptr) {
					type_error("Argument %d of Redim is not number", i);
				}
			}
		}
	}

	if (stmt->type == stmt_type::Erase) {
		for (expr_node* id : *stmt->expr_list) {
			type* varType = inferType(id, structRecord, method, this->ctx);
			if (dynamic_cast<jvm_array_type*>(varType) == nullptr) {
				type_error("Erase is supported only for arrays");
			}
		}
	}

	if (stmt->type == stmt_type::If || stmt->type == stmt_type::ElseIf || stmt->type == stmt_type::While ||
		stmt->type == stmt_type::DoUntil || stmt->type == stmt_type::DoWhile) {
		type* condType = inferType(stmt->condition, structRecord, method, this->ctx);
		if (dynamic_cast<bool_rtl_type*>(condType) == nullptr) {
			type_error("This type of loop or if must have boolean condition");
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


		if (stmt->lvalue->type != expr_type::Index) {
			std::pair<record*, access_target> res = ctx.resolveMemberAccess(stmt->lvalue, structRecord, method);
			if (res.second == LOCAL_VAR) {
				localvar_record* rec = (localvar_record*)res.first;
				if (rec->isConst) {
					value_error("Const variables cannot be redefined");
				}
			}
			else if ((res.second == FIELD || res.second == STATIC_FIELD) && res.first != nullptr) {
				field_record* field = (field_record*)res.first;
				if (field->isConst) {
					value_error("Const fields cannot be redefined");
				}
			}
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
			|| dynamic_cast<field_record *>(ctx.resolveMemberAccess(stmt->lvalue, structRecord, method).first) != nullptr
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
		if (dynamic_cast<void_type*>(method->returnType) != nullptr && stmt->target_expr != nullptr) {
				type_error("'%s' function doesn't return any type", structRecord->name.c_str());
		}
		(*returnCount)++;
	}

	if (stmt->block != nullptr) {
		if (stmt->type == stmt_type::For || stmt->type == stmt_type::ForEach) {
			method->locals[stmt->Id] = new localvar_record(stmt->Id, inferType(stmt->id_type, ctx, structRecord->typeMap), method);
			method->locals[stmt->Id]->number = method->localvarCounter;
			method->localvarCounter++;
			method->allLocals[method->locals[stmt->Id]->number] = method->locals[stmt->Id];
			stmt->localvarNum = method->locals[stmt->Id]->number;
			if (stmt->type == stmt_type::ForEach) {
				++method->localvarCounter;
			}
		}
		list<std::string> locals;
		for (stmt_node* innerStmt : *stmt->block) {
			processStmt(structRecord, method, innerStmt, returnCount);
			if (innerStmt->type == stmt_type::VarDecl) {
				locals.add(innerStmt->var_decl->varName);
			}
		}
		// Удалить переменную при выходе из блока
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
			processStmt(structRecord, method, innerStmt, returnCount);
			if (innerStmt->type == stmt_type::VarDecl) {
				locals.add(innerStmt->var_decl->varName);
			}
		}
		// Удалить переменную при выходе из блока
		for (std::string local : locals) {
			method->locals.erase(local);
		}
	}
	if (stmt->condition_nodes != nullptr) {
		list<std::string> locals;
		for (stmt_node* innerStmt : *stmt->condition_nodes) {
			processStmt(structRecord, method, innerStmt, returnCount);
			if (innerStmt->type == stmt_type::VarDecl) {
				locals.add(innerStmt->var_decl->varName);
			}
		}
		// Удалить переменную при выходе из блока
		for (std::string local : locals) {
			method->locals.erase(local);
		}
	}
}

void semantic_analyzer::processExpr(struct_record* structRecord, method_record * method, expr_node* expr)
{
	// method may be nullptr, means - expr in field declaration

	// avoid recursive subexprs changes here
	
	constant_record * constant = nullptr;
	if (expr->type == expr_type::Int && intSizeOf(expr->Int) > 2) {
		constant = structRecord->addLiteralConstant(expr->Int);
	}
	else if (expr->type == expr_type::String) {
		constant = structRecord->addLiteralConstant(expr->String);
	}
	else if (expr->type == expr_type::Float) {
		if (expr->Float > FLT_MAX && expr->Float < FLT_MIN) {
			constant = structRecord->addLiteralConstant(expr->Float);
		}
		else {
			constant = structRecord->addLiteralConstant((float) expr->Float);
		}
	}

	if (constant != nullptr) {
		expr->constant = constant;
	}

	// myclass
	if (expr->type == expr_type::MyClassMemberAccess) {
		expr->left = new expr_node(expr_type::Id);
		expr->left->String = structRecord->name;
		expr->type = expr_type::MemberAccess;
	}

	if (method != nullptr && (expr->type == expr_type::ArrayNew || expr->type == expr_type::Collection)) {
		expr->localvarNum = method->localvarCounter;
		method->localvarCounter += 2;
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
	clsRecord->makeInit(ctx);
	for (const auto& pair : clsRecord->methods) {
		method_record* method = pair.second;
		processMethod(clsRecord, method);
		if (method->allLocals.size() >= UINT16_MAX - 1) {
			codegen_error("Too many local variables in one method");
		}
	}
}