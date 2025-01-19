#include "context.hpp"
#include "../semantics.hpp"
#include "rtl.hpp"

std::pair<record*, access_target> semantic_context::resolveId(expr_node* value, struct_record* context, method_record * methodContext) {
	if (value == nullptr) {
		return std::pair(nullptr, FIELD);
	}
	record* rec = nullptr;
	access_target acc;
	if (value->type == expr_type::Id) {
		std::string member = value->String;
		if (methodContext != nullptr && methodContext->allLocals.count(value->localvarNum)) {
			rec = methodContext->allLocals[value->localvarNum];
			acc = LOCAL_VAR;
		} else if (methodContext != nullptr && methodContext->locals.count(member)) {
			rec = methodContext->locals[member];
			acc = LOCAL_VAR;
		} else if (context->resolveMethod(member) != nullptr && context->resolveField(member) != nullptr) {
			name_error("Member '%s' in type %s declared twice", member.c_str(), context->type->readableName().c_str());
			return std::pair<record*, access_target>(nullptr, FIELD);
		} else if (context->resolveMethod(member) != nullptr) {
			rec = context->resolveMethod(member);
			if (!context->resolveMethod(member)->isStatic && methodContext->isStatic) {
				type_error("'%s' is instance method. Instance method isn't allowed in static context", member.c_str());
			}
			acc = ((method_record*)rec)->isStatic ? STATIC_METHOD : METHOD;
		}
		else if (context->resolveField(member) != nullptr) {
			rec = context->resolveField(member);
			if (!context->resolveField(member)->isStatic && methodContext->isStatic) {
				type_error("'%s' is instance field. Instance field isn't allowed in static context", member.c_str());
			}
			acc = context->resolveField(member)->isStatic ? STATIC_FIELD : FIELD;
		}
		else if (classes.count(member)) {
			rec = classes[member];
			acc = STATIC_STRUCT;
		}
	}
	else if (value->type == expr_type::Me) {
		rec = context;
		acc = STRUCT;
	}
	else if (value->type == expr_type::MyBase) {
		rec = context->parent;
		acc = STRUCT;
	}
	else {
		type* exprType = inferType(value, context, methodContext, *this);
		if (dynamic_cast<struct_type*>(exprType) != nullptr) {
			return std::pair(dynamic_cast<struct_type*>(exprType)->record, STRUCT);
		}
		else {
			internal_error("Expression type inferring was failed");
		}
	}
	if (rec == nullptr) {
		name_error("Member '%s' not found in context of struct '%s'", value->String.c_str(), context->name.c_str());
	}
	return std::pair(rec, acc);
}

std::pair<record*, access_target> semantic_context::resolveMember(record * record, std::string member, struct_record* context,
	expr_type memAccessType, bool isStatic, type** ownerType) {
	std::string accessType = isStatic ? "static" : "instance or static";
	if (record == nullptr) {
		return std::pair(nullptr, FIELD);
	}
	
	if (dynamic_cast<field_record*>(record) != nullptr) {
		field_record* rec = dynamic_cast<field_record*>(record);
		struct_type* typeRec = dynamic_cast<struct_type*>(rec->type);
		if (typeRec != nullptr) {
			struct_record* record = typeRec->record;
			if (ownerType != nullptr) *ownerType = record->type;
			if (record->resolveField(member) != nullptr && record->resolveMethod(member) != nullptr) {
				name_error("Member '%s' in type %s declared twice", member.c_str(), record->type->readableName().c_str());
			} else if (record->resolveField(member) != nullptr) {
				return std::pair(record->resolveField(member), isStatic ? STATIC_FIELD : FIELD);
			} else if (record->resolveMethod(member) != nullptr) {
				return std::pair(record->resolveMethod(member), isStatic ? STATIC_METHOD : METHOD);
			} else {
				name_error("Type '%s' doesn't contain '%s' %s member", rec->type->readableName().c_str(), member.c_str(), accessType.c_str());
			}
		}
		else {
			name_error("Type '%s' doesn't contain '%s' %s member", rec->type->readableName().c_str(), member.c_str(), accessType.c_str());
		}
	} else if (dynamic_cast<struct_record*>(record) != nullptr) {
		struct_record* rec = dynamic_cast<struct_record*>(record);
		if (ownerType != nullptr) *ownerType = rec->type;
		if (isStatic) {
			rec = new static_struct_record_wrapper(rec);
		}
		if (rec->isGeneric() && isStatic) {
			type_error("Generic class doesn't support static access");
		}
		else {
			if (rec->resolveField(member) != nullptr && rec->resolveMethod(member) != nullptr) {
				name_error("Member %s '%s' in type %s declared twice", accessType.c_str(), member.c_str(), rec->type->readableName().c_str());
			} else if (rec->resolveField(member) != nullptr) {
				return std::pair(rec->resolveField(member), isStatic ? STATIC_FIELD : FIELD);
			} else if (rec->resolveMethod(member) != nullptr) {
				return std::pair(rec->resolveMethod(member), isStatic ? STATIC_METHOD : METHOD);
			} else {
				name_error("Type '%s' doesn't contain '%s' %s member", rec->type->readableName().c_str(), member.c_str(), accessType.c_str());
			}
		}
	}
	else if (dynamic_cast<localvar_record*>(record) != nullptr) {
		localvar_record* rec = dynamic_cast<localvar_record*>(record);
		struct_type* typeRec = dynamic_cast<struct_type*>(rec->type);
		if (typeRec != nullptr) {
			struct_record* record = typeRec->record;
			if (record->resolveField(member) != nullptr && record->resolveMethod(member) != nullptr) {
				name_error("Member %s '%s' in type %s declared twice", accessType.c_str(), member.c_str(), record->type->readableName().c_str());
			}
			else if (record->resolveField(member) != nullptr) {
				return std::pair(record->resolveField(member), isStatic ? STATIC_FIELD : FIELD);
			}
			else if (record->resolveMethod(member) != nullptr) {
				return std::pair(record->resolveMethod(member), isStatic ? STATIC_METHOD : METHOD);
			}
			else {
				name_error("Type '%s' doesn't contain '%s' %s member (local variable %s)", rec->type->readableName().c_str(),
					member.c_str(), accessType.c_str(), rec->name.c_str());
			}
		}
		else {
			name_error("Type '%s' doesn't contain '%s' %s member (local variable %s)", rec->type->readableName().c_str(), 
				member.c_str(), accessType.c_str(), rec->name.c_str());
		}
	} else if (dynamic_cast<method_record*>(record) != nullptr) {
		method_record* rec = dynamic_cast<method_record*>(record);
		struct_type* typeRec = dynamic_cast<struct_type*>(rec->returnType);
		if (ownerType != nullptr) *ownerType = typeRec;
		if (memAccessType != expr_type::MethodCall && !isCodegen) {
			name_error("Method '%s' is not structure object", rec->name.c_str());
		}
		if (typeRec != nullptr) {
			struct_record* record = typeRec->record;
			if (record->resolveField(member) != nullptr && record->resolveMethod(member) != nullptr) {
				name_error("Member %s '%s' in type %s declared twice", accessType.c_str(), member.c_str(), record->type->readableName().c_str());
			} else if (record->resolveField(member) != nullptr) {
				return std::pair(record->resolveField(member), isStatic ? STATIC_FIELD : FIELD);
			}
			else if (record->resolveMethod(member) != nullptr) {
				return std::pair(record->resolveMethod(member), isStatic ? STATIC_METHOD : METHOD);
			}
			else {
				name_error("Type '%s' doesn't contain '%s' %s member", rec->returnType->readableName().c_str(), member.c_str(), accessType.c_str());
			}
		}
		else {
			name_error("Type '%s' doesn't contain '%s' %s member", rec->returnType->readableName().c_str(), member.c_str(), accessType.c_str());
		}
	}
	else {
		internal_error("Only methods, fields and struct are supported for member access");
	}
	return std::pair(nullptr, FIELD);
}

list<expr_node*> plainMemberAccess(expr_node* memAccess) {
	if (memAccess->type != expr_type::MemberAccess
		&& memAccess->type != expr_type::MyBaseMemberAccess
		&& memAccess->type != expr_type::MethodCall
		) {
		internal_error("Only member access is accepted");
	}
	list<expr_node*> nodes;
	nodes.add(memAccess);
	expr_node* left = memAccess->left;
	while (left != nullptr &&
		(left->type == expr_type::MemberAccess
			|| left->type == expr_type::MyBaseMemberAccess
			|| left->type == expr_type::MethodCall
			)
		) {
		nodes.add(left);
		left = left->left;
	}
	nodes.reverse();
	return nodes;
}

void semantic_context::processCallOrIndex(expr_node* expr, struct_record * structRecord, method_record * method) {
	if (expr->type == expr_type::CallOrIndex) {
		if (expr->left->type == expr_type::CallOrIndex ) {
			expr->type = expr_type::Index;
			processCallOrIndex(expr->left, structRecord, method);
			inferType(expr, structRecord, method, *this);
			expr->argument = expr->arg_list->first();
			return;
		}
		else if (expr->left->type == expr_type::Call) {
			expr->type = expr_type::Index;
			expr->argument = expr->arg_list->first();
			inferType(expr, structRecord, method, *this);
			return;
		}

		std::pair<record*, access_target> record = resolveMemberAccess(expr->left, structRecord, method);
		if (record.first == nullptr) {
			return;
		}

		if (record.second == METHOD || record.second == STATIC_METHOD) {
			expr->type = expr_type::Call;
			expr_node* call_index = expr;
			call_index->String = call_index->left->String;
			if (call_index->left->type == expr_type::MemberAccess) {
				call_index->left = call_index->left->left;
				call_index->type = expr_type::MethodCall;
			}
			else if (call_index->left->type == expr_type::MyBaseMemberAccess) {
				if (method->isStatic) {
					value_error("MyBase allowed only in instance context, not static");
					return;
				}
				call_index->left = new expr_node(expr_type::MyBase);
				call_index->type = expr_type::MethodCall;
			}
			else if (call_index->left->type == expr_type::MyClassMemberAccess) {
				call_index->left = new expr_node(expr_type::Id);
				call_index->left->String = structRecord->name;
				call_index->type = expr_type::MethodCall;
			}
		}
		else {
			expr->type = expr_type::Index;
			expr->argument = expr->arg_list->first();
			inferType(expr, structRecord, method, *this);
		}

	}
}

std::pair<record*, access_target> semantic_context::resolveMemberAccess(expr_node* memAccess, struct_record* context, method_record * method, type ** ownerType)
{
	if (memAccess->type == expr_type::Id || memAccess->type == expr_type::Me || memAccess->type == expr_type::MyBase) {
		return resolveId(memAccess, context, method);
	} 
	if (memAccess->type != expr_type::MethodCall
		&& memAccess->type != expr_type::MyBaseMemberAccess
		&& memAccess->type != expr_type::MemberAccess) {
		internal_error("Invalid member access given");
	}
	list<expr_node*> plain = plainMemberAccess(memAccess);
	expr_node* left = plain.first()->left;
	std::string member = plain.first()->String;
	std::pair<record*, access_target> buf;

	record* rec = nullptr;
	bool isStatic = false;
	access_target acc = FIELD;
	buf = resolveId(left, context, method);
	rec = buf.first;
	acc = buf.second;
	buf = resolveMember(rec, member, context, plain.first()->type, acc == STATIC_STRUCT, ownerType);
	rec = buf.first;
	acc = buf.second;

	for (int i = 1; i < plain.size(); i++) {
		buf = resolveMember(rec, plain.get(i)->String, context, plain.get(i)->type, ownerType);
		rec = buf.first;
		acc = buf.second;
		if (rec == nullptr) {
			return std::pair(nullptr, FIELD);
		}
	}

	return std::pair<record*, access_target>(rec, acc);
}

type* semantic_context::specializeType(type_node* node)
{
	struct_record* cls = classes.count(node->Id) ? classes[node->Id] : nullptr;
	if (cls == nullptr) {
		name_error("No type with name '%s'", node->Id.c_str());
		return new unknown_type();
	}
	if (!cls->isGeneric()) {
		internal_error("'%s' doesn't support generics", cls->name.c_str());
	}
	if (!specializedTypes.count(node->hash())) {
		struct_node* structNode = cls->node->clone();
		struct_record* newRecord = new struct_record();
		newRecord->node = structNode;
		newRecord->name = cls->name + "$";
		newRecord->node->record = newRecord;
		newRecord->type = new struct_type(newRecord);

		std::map<std::string, type*>* cmpMap = new std::map<std::string, type*>();
		for (size_t i = 0; i < structNode->generics->size(); i++) {
			type* type = inferType(node->generics->get(i), *this, nullptr);
			(*cmpMap)[structNode->generics->get(i)] = type;
		}
		for (auto& pair : *cmpMap) {
			newRecord->name += pair.second->readableName() + "_";
		}
		newRecord->name += "$";
		structNode->generics = new list<std::string>();
		newRecord->node->name = newRecord->name;
		if (cls->parent == nullptr && cls->node->parent_class != nullptr) {
			type* t = inferType(cls->node->parent_class, *this, nullptr);
			struct_type* stype = dynamic_cast<struct_type*>(t);
			if (stype == nullptr || *t == *cls->type) {
				type_error("Inheritance from unknown or unsupported type '%s'", t->readableName().c_str());
				return new unknown_type();
			}
			newRecord->parent = stype->record;
		}
		if (cls->node->parent_class == nullptr) {
			newRecord->parent = rtl_class_record::Object;
		}
		newRecord->typeMap = cmpMap;
		specializedTypes[node->hash()] = (struct_type*)newRecord->type;
		for (field_node* field : *structNode->fields) {
			newRecord->addField(field, *this);
		}
		for (procedure_node* method : *structNode->methods) {
			newRecord->addMethod(method, *this);
		}
		analyzer->processStruct(newRecord);
	}
	return specializedTypes[node->hash()];
}

struct_record* semantic_context::addClass(struct_node* cls)
{
	struct_record* record = new struct_record();
	record->name = cls->name;
	record->type = new struct_type(record);
	record->node = cls;
	record->node->record = record;
	record->parent = nullptr; // assigned after all add
	this->classes[cls->name] = record;
	return record;
}

rtl_class_record* semantic_context::addRTL(rtl_class_record* record)
{
	std::string name = record->name;
	if (record->allowLowercase) {
		toLower(&name);
	}
	classes[name] = record;
	return record;
}
