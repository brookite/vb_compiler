#include "nodes.hpp"
#include "dot.hpp"
#include "../compiler/codegen/bytecode.hpp"
#include "../compiler/semantics.hpp"
#include "../compiler/codegen/rtl.hpp"

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


void expr_node::dot(DotWriter* out) {
	size_t litId, rightId;

	switch (type) {
	case expr_type::String:
		litId = out->addStringNode(this->String);
		out->link(this->id, litId, "");
		break;
	case expr_type::Id:

		litId = out->addStringNode(this->String);
		out->link(this->id, litId, "");
		break;
	case expr_type::Int:

		litId = out->addStringNode(std::to_string(this->Int));
		out->link(this->id, litId, "");
		break;
	case expr_type::Bool:
		out->label(this->id, this->Bool ? "true" : "false");
		break;
	case expr_type::Float:

		litId = out->addStringNode(std::to_string(this->Float));
		out->link(this->id, litId, "");
		break;
	case expr_type::Nothing:
		out->label(this->id, "Nothing");
		break;
	case expr_type::Me:
		out->label(this->id, "Me");
		break;
	case expr_type::Char:
		out->label(this->id, std::string({ this->Char }));
		break;
	case expr_type::Datetime:

		litId = out->addStringNode(this->DateTime->str());
		out->link(this->id, litId, "");
		break;
	case expr_type::UnaryMinusOp:

		out->addNode(this->argument);
		out->linkNodes(this, this->argument, "argument");
		break;
	case expr_type::UnaryPlusOp:

		out->addNode(this->argument);
		out->linkNodes(this, this->argument, "argument");
		break;
	case expr_type::NotOp:

		out->addNode(this->argument);
		out->linkNodes(this, this->argument, "argument");
		break;
	case expr_type::MemberAccess:
		out->addNode(this->left);
		out->linkNodes(this, this->left, "left");
		rightId = out->addStringNode(this->String);
		out->link(this->id, rightId, "right");
		break;
	case expr_type::MyClassMemberAccess:
		rightId = out->addStringNode(this->String);
		out->link(this->id, rightId, "right");
		break;
	case expr_type::MyBaseMemberAccess:
		rightId = out->addStringNode(this->String);
		out->link(this->id, rightId, "right");
		break;
	case expr_type::CallOrIndex:

		out->addNode(this->left);
		out->linkNodes(this, this->left, "left");
		out->addList(this->arg_list);
		out->linkList(this, this->arg_list, "arg_list");
		break;
	case expr_type::Cast:

		out->addNode(this->datatype);
		out->linkNodes(this, this->datatype, "datatype");
		out->addNode(this->argument);
		out->linkNodes(this, this->argument, "argument");
		break;
	case expr_type::If:

		out->addNode(this->condition);
		out->linkNodes(this, this->condition, "cond");
		out->addNode(this->then_expr);
		out->linkNodes(this, this->then_expr, "then");
		out->addNode(this->else_expr);
		out->linkNodes(this, this->else_expr, "else");
		break;
	case expr_type::New:

		out->addNode(this->datatype);
		out->linkNodes(this, this->datatype, "datatype");
		out->addList(this->arg_list);
		out->linkList(this, this->arg_list, "arg_list");
		break;
	case expr_type::Collection:

		out->addList(this->arg_list);
		out->linkList(this, this->arg_list, "arg_list");
		break;
	case expr_type::ArrayNew:

		out->addNode(this->datatype);
		out->linkNodes(this, this->datatype, "datatype");
		out->addList(this->arg_list);
		out->linkList(this, this->arg_list, "arg_list");
		out->addList(this->collection);
		out->linkList(this, this->collection, "collection");
		break;
	case expr_type::Index:

		out->addNode(this->left);
		out->linkNodes(this, this->left, "left");
		out->addList(this->arg_list);
		out->linkList(this, this->arg_list, "arg_list");
		break;
	case expr_type::Call:

		out->addNode(this->left);
		out->linkNodes(this, this->left, "left");
		out->addList(this->arg_list);
		out->linkList(this, this->arg_list, "right");
		break;
	default:
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
			prefix = "strcat";
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
		return prefix + (prefix.length() == 0 ? "" : "_") + "assignment_stmt";
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

void expr_node::bytecode(Bytecode* code)
{
	if (type == expr_type::MyBase || type == expr_type::Me) {
		code->loadThis();
	}
	else if (type == expr_type::Nothing) {
		code->nullLoad();
	}
	else if (type == expr_type::Int) {
		rtl_class_record* rec = ((rtl_type*)inferType(this->numericType, *code->context, nullptr))->record;
		code->newObject(rec->type);
		if (Int > INT16_MAX || Int < INT16_MIN) {
			code->intLoad(Int);
		}
		else {
			code->constLoad(this->constant);
		}
		code->dup();
		code->invokevirtual(rec->getConstructorConstant({ "L" }, code->method->owner)->number);
	}
	else if (type == expr_type::Float) {
		//TODO: check
		rtl_class_record* rec = ((rtl_type*)inferType(this->numericType, *code->context, nullptr))->record;
		code->newObject(rec->type);
		code->dup();
		code->constLoad(constant);
		code->invokevirtual(rec->getConstructorConstant({ "D" }, code->method->owner)->number);
	}
	else if (type == expr_type::String) {
		//TODO: check
		code->newObject(rtl_class_record::String->type);
		code->dup();
		code->constLoad(constant);
		code->invokevirtual(rtl_class_record::String->getConstructorConstant({ "Ljava/lang/String;" }, code->method->owner)->number);
	}
	else if (type == expr_type::Bool) {
		code->newObject(rtl_class_record::Boolean->type);
		code->dup();
		code->boolLoad(Bool);
		code->invokespecial(rtl_class_record::Boolean->getConstructorConstant({ "Z" }, code->method->owner)->number);
	}
	else if (type == expr_type::Char) {
		code->newObject(rtl_class_record::Char->type);
		code->dup();
		code->intLoad(Char);
		code->invokespecial(rtl_class_record::Char->getConstructorConstant({ "C" }, code->method->owner)->number);
	}
	else if (type == expr_type::Datetime) {
		code->newObject(rtl_class_record::DateTime->type);
		code->dup();
		if (DateTime->date != nullptr) {
			code->intLoad(DateTime->date->year);
			code->intLoad(DateTime->date->month);
			code->intLoad(DateTime->date->day);
		}
		else {
			code->intLoad(1970);
			code->intLoad(1);
			code->intLoad(1);
		}
		if (DateTime->time != nullptr) {
			code->intLoad(DateTime->time->hour);
			code->intLoad(DateTime->time->minute);
			code->intLoad(DateTime->time->second);
		}
		else {
			code->intLoad(0);
			code->intLoad(0);
			code->intLoad(0);
		}
		code->invokespecial(rtl_class_record::DateTime->getConstructorConstant({ "I", "I", "I", "I", "I", "I" }, code->method->owner)->number);
	}
	else if (type == expr_type::Id) {
		std::pair<record*, access_target> record = code->context->resolveId(this, code->method->owner, code->method);
		if (record.second == LOCAL_VAR) {
			localvar_record* var = (localvar_record*)(record.first);
			code->aload(var->number);
		}
		else if (record.second == FIELD) {
			field_record* field = (field_record*)(record.first);
			code->loadThis();
			code->getfield(field->getConstantFor(code->method->owner)->number);
		}
	}
	else if (type == expr_type::Call) {
		std::pair<record*, access_target> record = code->context->resolveId(this, code->method->owner, code->method);
		method_record* method = (method_record*)record.first;
		if (!method->isStatic) {
			code->loadThis();
		}
		for (expr_node* expr : *arg_list) {
			expr->bytecode(code);
		}
		code->invokemethod(method, method->isStatic ? CallInfo::STATIC : CallInfo::VIRTUAL);
	}
	else if (type == expr_type::MethodCall) {
		struct type* ownerType = nullptr;
		std::pair<record*, access_target> record = code->context->resolveMemberAccess(this, code->method->owner, code->method, &ownerType);
		method_record* method = (method_record*)record.first;
		if (!method->isStatic) {
			left->bytecode(code);
		}
		for (expr_node* expr : *arg_list) {
			expr->bytecode(code);
		}
		CallInfo info = CallInfo::VIRTUAL;
		if (method->isStatic) {
			info = CallInfo::STATIC;
		}
		else if (left->type == expr_type::MyBase) {
			info = CallInfo::SPECIAL;
		}
		code->invokemethod(method, info, (struct_type*) ownerType);
	}
	else if (type == expr_type::MemberAccess || type == expr_type::MyBaseMemberAccess) {
		struct type* ownerType = nullptr;
		std::pair<record*, access_target> record = code->context->resolveMemberAccess(this, code->method->owner, code->method, &ownerType);

		if (dynamic_cast<field_record*>(record.first) == nullptr) {
			codegen_error("Member access can lead only to fields");
		}
		field_record* field = dynamic_cast<field_record*>(record.first);

		if (record.second == STATIC_FIELD) {
			code->getstatic(field->getConstantFor(code->method->owner, (struct_type*) ownerType)->number);
		}
		else {
			left->bytecode(code);
			code->getfield(field->getConstantFor(code->method->owner, (struct_type*)ownerType)->number);
		}
	}
	else if (type == expr_type::Cast) {
		struct struct_type* castType = (struct_type*)inferType(this->datatype, *code->context, nullptr);
		struct struct_type* exprType = (struct_type*)inferType(this->argument, code->method->owner, code->method, *code->context);
		if (castType == rtl_class_record::String->type) {
			method_record* method = rtl_class_record::String->resolveMethod("ToString");
			argument->bytecode(code);
			code->invokevirtual(method->getConstantFor(code->method->owner)->number);
		}
		else if (dynamic_cast<sized_rtl_type*>(castType) != nullptr) {
			code->newObject(castType);
			code->dup();
			argument->bytecode(code);
			code->invokevirtual(castType->record->getConstructorConstant({ rtl_class_record::Object->jvmDescriptor() }, code->method->owner)->number);
		}
		else {
			argument->bytecode(code);
			code->checkcast(castType->record->getConstantFor(code->method->owner)->number);
		}
	}
	else if (type == expr_type::New) {
		struct struct_type* targetType = (struct_type*)inferType(this->datatype, *code->context, nullptr);
		code->newObject(targetType);
		code->dup();
		code->invokespecial(targetType->record->getConstructorConstant({}, code->method->owner)->number);
	}
	else if (type == expr_type::ArrayNew || type == expr_type::Collection) {
		struct_type* targetType;
		if (type == expr_type::Collection) {
			targetType = (struct_type*)inferType(this, code->method->owner, code->method, *code->context);
		}
		else {
			targetType = (struct_type*)inferType(this->datatype, *code->context, nullptr);
		}
		expr_node* length = this->arg_list->isEmpty() ? nullptr : this->arg_list->first();
		size_t size = this->collection->size();
		if (length == nullptr) {
			if (size <= UINT16_MAX) {
				code->intLoad(size);
			}
			else {
				constant_record* constRec = code->method->owner->addConstant(new constant_long(size));
				code->constLoad(constRec);
			}
		}
		else {
			length->bytecode(code);
		}
		code->newArray(targetType);

		for (size_t i = 0; i < collection->size(); i++) {
			code->dup();
			code->intLoad(size);
			collection->get(i)->bytecode(code);
			code->aastore();
		}
		code->astore(localvarNum);
		code->intLoad(collection->size());
		code->istore(localvarNum + 1);
		code->iload(localvarNum + 1);
		code->aload(localvarNum);
		code->arrayLength();
		size_t pos1 = code->currentOffset();
		uint32_t f1 = code->futureJump(Instruction::if_icmpge);

		code->aload(localvarNum);
		code->iload(localvarNum + 1);
		if (dynamic_cast<sized_rtl_type*>(targetType) != nullptr) {
			code->newObject(targetType);
			code->dup();
			code->invokespecial(targetType->record->getConstructorConstant({}, code->method->owner)->number);
		}
		else {
			code->nullLoad();
		}
		code->aastore();
		int16_t offset = code->currentOffset() - pos1;
		code->jump(Instruction::_goto, -offset);
		code->resolveFuture(f1);
	}
	else if (type == expr_type::If) {
		condition->bytecode(code);
		struct type* condType = inferType(condition, code->method->owner, code->method, *code->context);
		if (dynamic_cast<sized_rtl_type*>(condition) != nullptr) {
			code->invokemethod(((sized_rtl_type*)condType)->record->resolveMethod("getBoolean"), CallInfo::VIRTUAL);
		}
		else {
			codegen_error("Condition accepts only boolean values");
		}
		uint32_t f1 = code->futureJump(Instruction::ifeq);
		then_expr->bytecode(code);
		uint32_t f2 = code->futureJump(Instruction::_goto);
		code->resolveFuture(f1);
		else_expr->bytecode(code);
		code->resolveFuture(f2);
	}
	else if (type == expr_type::Index) {
		left->bytecode(code);
		argument->bytecode(code);
		code->aaload();
	}
	else if (type == expr_type::AddOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("add"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::SubOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("sub"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::MulOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("mul"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::DivOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("div"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::FloorDivOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("floordiv"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::ExpOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("exp"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::StrConcatOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("concat"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::LtOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("lt"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::GtOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("gt"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::GteOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("gte"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::LteOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("lte"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::EqOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("equals"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::NeqOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("notEquals"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::AndOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("and"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::AndAlsoOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("andAlso"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::OrOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("or"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::OrElseOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("orElse"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::XorOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("xor"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::ModOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("mod"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::LshiftOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("lshift"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::RshiftOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("rshift"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::IsOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("is"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::IsNotOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		right->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("isNot"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::UnaryMinusOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("unaryMinus"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::UnaryPlusOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("unaryPlus"), CallInfo::VIRTUAL);
	}
	else if (type == expr_type::NotOp) {
		struct_type* leftType = (struct_type*)inferType(left, code->method->owner, code->method, *code->context);
		left->bytecode(code);
		code->invokemethod(leftType->record->resolveMethod("not"), CallInfo::VIRTUAL);
	}
}

void bytecodeBlock(block* block, Bytecode* code, stmt_node* parent) {
	for (stmt_node* node : *block) {
		node->bytecode(code);

		if (parent != nullptr && node->type == stmt_type::ContinueFor && parent == code->lastFor && parent->type == stmt_type::For) {
			struct_type* varType = (struct_type*)inferType(parent->id_type, *code->context, nullptr);
			code->aload(parent->localvarNum);
			parent->step_node->bytecode(code);
			code->invokemethod(varType->record->resolveMethod("add"), CallInfo::VIRTUAL);
		}

		if (parent != nullptr && node->type == stmt_type::ContinueFor && parent == code->lastFor && parent->type == stmt_type::ForEach) {
			code->iload(parent->localvarNum + 1);
			code->intLoad(1);
			code->writeSimple(Instruction::iadd);
			code->istore(parent->localvarNum + 1);
		}

		stmt_node *lastNode = nullptr;
		bool isExit = node->type == stmt_type::ExitDo || node->type == stmt_type::ExitFor || node->type == stmt_type::ExitWhile;
		if (node->type == stmt_type::ContinueDo || node->type == stmt_type::ExitDo) {
			if (code->lastDo == nullptr || parent == nullptr || (parent->type != stmt_type::DoUntil && parent->type != stmt_type::DoWhile)) {
				codegen_error("ContinueDo or ExitDo are not allowed here");
			}
			lastNode = code->lastDo;
		}
		if (node->type == stmt_type::ContinueFor || node->type == stmt_type::ExitFor) {
			if (code->lastFor == nullptr || parent == nullptr || (parent->type != stmt_type::For && parent->type != stmt_type::ForEach)) {
				codegen_error("ContinueFor or ExitFor are not allowed here");
			}
			lastNode = code->lastFor;
		}
		if (node->type == stmt_type::ContinueWhile || node->type == stmt_type::ExitWhile) {
			if (code->lastWhile == nullptr || parent == nullptr || parent->type != stmt_type::While) {
				codegen_error("ContinueFor or ExitFor are not allowed here");
			}
			lastNode = code->lastWhile;
		}
		if (lastNode != nullptr) {
			if (isExit) {
				lastNode->endFutureJump = code->futureJump(Instruction::_goto);
			}
			else {
				code->jump(Instruction::_goto, lastNode->beginOffset);
			}
		}
	}
}

void stmt_node::bytecode(Bytecode* code)
{
	if (type == stmt_type::Call) {
		target_expr->bytecode(code);
		code->pop();
	}
	else if (type == stmt_type::If) {
		condition->bytecode(code);
		struct type* condType = inferType(condition, code->method->owner, code->method, *code->context);
		if (dynamic_cast<sized_rtl_type*>(condition) != nullptr) {
			code->invokemethod(((sized_rtl_type*)condType)->record->resolveMethod("getBoolean"), CallInfo::VIRTUAL);
		}
		else {
			codegen_error("Condition accepts only boolean values");
		}
		list<uint32_t> * exitStack = new list<uint32_t>();

		uint32_t f1 = code->futureJump(Instruction::ifeq);
		bytecodeBlock(this->block, code, this);
		exitStack->add(code->futureJump(Instruction::_goto));
		code->resolveFuture(f1);
		for (stmt_node* stmt : *condition_nodes) {
			stmt->condition->bytecode(code);
			struct type* condType = inferType(stmt->condition, code->method->owner, code->method, *code->context);
			if (dynamic_cast<sized_rtl_type*>(stmt->condition) != nullptr) {
				code->invokemethod(((sized_rtl_type*)condType)->record->resolveMethod("getBoolean"), CallInfo::VIRTUAL);
			}
			else {
				codegen_error("Condition accepts only boolean values");
			}
			uint32_t f = code->futureJump(Instruction::ifeq);
			bytecodeBlock(stmt->block, code, this);
			exitStack->add(code->futureJump(Instruction::_goto));
			code->resolveFuture(f);
		}
		if (else_block != nullptr) {
			bytecodeBlock(this->block, code, this);
		}
		for (uint32_t futureId : *exitStack) {
			code->resolveFuture(futureId);
		}
	}
	else if (type == stmt_type::For) {
		code->lastFor = this;
		target_expr->bytecode(code);
		struct_type* varType = (struct_type*)inferType(id_type, *code->context, nullptr);
		code->astore(localvarNum);

		code->makeWaypoint(this);
		beginOffset = code->getWaypoint(this);
		code->aload(localvarNum);
		target_expr->bytecode(code);
		code->invokemethod(varType->record->resolveMethod("lt"), CallInfo::VIRTUAL);
		code->invokemethod(rtl_class_record::Boolean->resolveMethod("getBoolean"), CallInfo::VIRTUAL);
		uint32_t f = code->futureJump(Instruction::ifeq);

		bytecodeBlock(this->block, code, this);

		code->aload(localvarNum);
		step_node->bytecode(code);
		code->invokemethod(varType->record->resolveMethod("add"), CallInfo::VIRTUAL);
		int16_t offset = (code->currentOffset() - code->popWaypoint(this));
		code->jump(Instruction::_goto, -offset);
		code->resolveFuture(f);
		if (endFutureJump != -1) code->resolveFuture(endFutureJump);
		code->lastFor = nullptr;
	}
	else if (type == stmt_type::ForEach) {
		code->lastFor = this;
		code->intLoad(0);
		struct_type* varType = (struct_type*)inferType(id_type, *code->context, nullptr);
		code->istore(localvarNum + 1);

		code->makeWaypoint(this);
		beginOffset = code->getWaypoint(this);

		code->iload(localvarNum + 1);
		container_expr->bytecode(code);
		code->arrayLength();
		uint32_t f = code->futureJump(Instruction::if_icmpge);

		container_expr->bytecode(code);
		code->iload(localvarNum + 1);
		code->aaload();
		code->astore(localvarNum);

		bytecodeBlock(this->block, code, this);

		code->iload(localvarNum + 1);
		code->intLoad(1);
		code->writeSimple(Instruction::iadd);
		code->istore(localvarNum + 1);
		int16_t offset = (code->currentOffset() - code->popWaypoint(this));
		code->jump(Instruction::_goto, -offset);
		code->resolveFuture(f);
		if (endFutureJump != -1) code->resolveFuture(endFutureJump);
		code->lastFor = nullptr;
	}
	else if (type == stmt_type::While) {
		code->lastWhile = this;
		code->makeWaypoint(this);
		beginOffset = code->getWaypoint(this);
		condition->bytecode(code);
		code->invokemethod(rtl_class_record::Boolean->resolveMethod("getBoolean"), CallInfo::VIRTUAL);
		uint32_t f = code->futureJump(Instruction::ifeq);

		bytecodeBlock(this->block, code, this);

		step_node->bytecode(code);
		int16_t offset = (code->currentOffset() - code->popWaypoint(this));
		code->jump(Instruction::_goto, -offset);
		code->resolveFuture(f);
		if (endFutureJump != -1) code->resolveFuture(endFutureJump);
		code->lastWhile = nullptr;
	}
	else if (type == stmt_type::DoWhile) {
		code->lastDo = this;
		code->makeWaypoint(this);
		beginOffset = code->getWaypoint(this);

		bytecodeBlock(this->block, code, this);

		condition->bytecode(code);
		code->invokemethod(rtl_class_record::Boolean->resolveMethod("getBoolean"), CallInfo::VIRTUAL);
		int16_t offset = (code->currentOffset() - code->popWaypoint(this));
		code->jump(Instruction::ifne, -offset);
		if (endFutureJump != -1) code->resolveFuture(endFutureJump);
		code->lastDo = nullptr;
	}
	else if (type == stmt_type::DoUntil) {
		code->lastDo = this;
		code->makeWaypoint(this);
		beginOffset = code->getWaypoint(this);

		bytecodeBlock(this->block, code, this);

		condition->bytecode(code);
		code->invokemethod(rtl_class_record::Boolean->resolveMethod("getBoolean"), CallInfo::VIRTUAL);
		int16_t offset = (code->currentOffset() - code->popWaypoint(this));
		code->jump(Instruction::ifeq, -offset);
		if (endFutureJump != -1) code->resolveFuture(endFutureJump);
		code->lastDo = nullptr;
	}
	else if (type == stmt_type::VarDecl) {
		var_decl->value->bytecode(code);
		code->astore(localvarNum);
	}
	else if (type == stmt_type::ArrayAssign || type == stmt_type::FieldAssign || type == stmt_type::Assignment) {
		struct_type* lvalueType = (struct_type*)inferType(lvalue, code->method->owner, code->method, *code->context);
		
		if (type == stmt_type::ArrayAssign) {
			lvalue->left->bytecode(code);
			lvalue->argument->bytecode(code);
		}

		if (assign_type != assignment_type::Assign) {
			lvalue->bytecode(code);
		}
		rvalue->bytecode(code);
		if (assign_type == assignment_type::AddAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("add"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::SubAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("sub"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::MulAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("mul"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::DivAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("diì"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::FloorDivAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("floordiv"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::ExpAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("exp"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::StrConcatAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("concat"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::LshiftAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("lshift"), CallInfo::VIRTUAL);
		}
		else if (assign_type == assignment_type::RshiftAssign) {
			code->invokemethod(lvalueType->record->resolveMethod("rshift"), CallInfo::VIRTUAL);
		}

		std::pair<record*, access_target> target = code->context->resolveMemberAccess(lvalue, code->method->owner, code->method);
		if (type == stmt_type::ArrayAssign) {
			code->aastore();
		}
		else if (type == stmt_type::FieldAssign) {
			field_record* field = (field_record*) target.first;
			if (field->isStatic) {
				code->putstatic(field->getConstantFor(code->method->owner)->number);
			}
			else {
				code->putfield(field->getConstantFor(code->method->owner)->number);
			}
		}
		else {
			localvar_record* var = (localvar_record*)target.first;
			code->astore(var->number);
		}
	}
	else if (type == stmt_type::Return) {
		if (target_expr == nullptr) {
			code->returnVoid();
		}
		else {
			target_expr->bytecode(code);
			code->areturn();
		}
	}
	else if (type == stmt_type::Redim) {
		for (redim_clause_node* clause : *redim) {
			expr_node* idNode = new expr_node(expr_type::Id);
			idNode->String = clause->Id;
			idNode->bytecode(code);
			clause->arg->first()->bytecode(code);
			code->invokemethod(rtl_class_record::CompilerUtils->resolveStaticMethod("redim"), CallInfo::STATIC);
		}
	}
	else if (type == stmt_type::Erase) {
		for (expr_node* expr : *expr_list) {
			expr->bytecode(code);
			code->invokemethod(rtl_class_record::CompilerUtils->resolveStaticMethod("erase"), CallInfo::STATIC);
		}
	}
}

void stmt_node::dot(DotWriter* out) {
	size_t nameId, modId;
	const char* var;

	switch (type) {
	case stmt_type::Call:

		out->addNode(target_expr);
		out->linkNodes(this, target_expr);
		break;
	case stmt_type::If:

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

		out->addNode(condition);
		out->linkNodes(this, condition, "condition");
		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::For:

		nameId = out->addStringNode(Id);
		out->link(((node*)this)->id, nameId, "varname");
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

		nameId = getNewId();
		out->label(nameId, Id);
		out->link(((node*)this)->id, nameId, "varname");
		out->addNode(container_expr);
		out->linkNodes(this, container_expr, "container");
		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::Select:

		out->addNode(target_expr);
		out->linkNodes(this, target_expr, "target");
		out->addList(condition_nodes);
		out->linkList(this, condition_nodes, "branches");
		break;
	case stmt_type::Case:

		out->addNode(condition);
		out->linkNodes(this, condition, "cond");
		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::CaseRange:

		out->addNode(condition);
		out->linkNodes(this, condition, "from");
		out->addNode(to_expr);
		out->linkNodes(this, to_expr, "to");
		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::CaseElse:

		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::While:

		out->addNode(condition);
		out->linkNodes(this, condition, "cond");
		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::DoWhile:

		out->addNode(condition);
		out->linkNodes(this, condition, "cond");
		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::DoUntil:

		out->addNode(condition);
		out->linkNodes(this, condition, "cond");
		out->addList(block);
		out->linkList(this, block, "block");
		break;
	case stmt_type::VarDecl:

		out->addNode(var_decl);
		out->linkNodes(this, var_decl, "decl");
		var = var_type == var_type::DIM ? "dim" : "const";
		modId = out->addStringNode(var);
		out->link(((node*)this)->id, modId, "modifier");
		break;
	case stmt_type::Assignment:

		out->addNode(lvalue);
		out->linkNodes(this, lvalue, "lval");
		out->addNode(rvalue);
		out->linkNodes(this, rvalue, "rval");
		break;
	case stmt_type::ContinueDo:

		break;
	case stmt_type::ContinueWhile:

		break;
	case stmt_type::ContinueFor:

		break;
	case stmt_type::ExitDo:

		break;
	case stmt_type::ExitWhile:

		break;
	case stmt_type::ExitFor:

		break;
	case stmt_type::ExitSelect:

		break;
	case stmt_type::Redim:

		out->addList(redim);
		out->linkList(this, redim);
		break;
	case stmt_type::Erase:

		out->addList(expr_list);
		out->linkList(this, expr_list);
		break;
	case stmt_type::Return:

		out->addNode(target_expr);
		out->linkNodes(this, target_expr, "val");
		break;
	default:
		std::cerr << "Unknown stmt type\n";
		break;
	}
}

void procedure_node::dot(DotWriter* out) {

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

	out->addStringList(generics);
	out->linkList(this, generics, "generic");
	size_t nameId = out->addStringNode(name);
	out->link(this->id, nameId, "name");
	out->addNode(parent_class);
	out->linkNodes(this, parent_class, "parent");
	out->addList(fields);
	out->linkList(this, fields, "fields");
	out->addList(methods);
	out->linkList(this, methods, "methods");
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

	out->addList(generics);
	out->linkList(this, generics, "generics");
	out->addList(dimensions, true, !isArray);
	out->linkList(this, dimensions, "array_dimensions", !isArray);
}

void typed_value::dot(DotWriter* out) {

	size_t nameId = out->addStringNode(varName);
	out->link(this->id, nameId, "name");
	out->addNode(type);
	out->linkNodes(this, type, "type");
	out->addNode(value);
	out->linkNodes(this, value, "value");
	out->addNode(array_size);
	out->linkNodes(this, array_size, "array_size");
}

void redim_clause_node::dot(DotWriter* out) {

	size_t id = out->addStringNode(Id);
	out->link(this->id, id, "id");
	out->addList(arg);
	out->linkList(this, arg, "args");
}

void program_node::dot(DotWriter* out) {
	*out << "digraph {" << '\n';
	*out << "subgraph {" << '\n';
	out->addNodeLabel(this);
	int i = 0;
	for (node* node : *nodes) {
		out->addNode(node);
		out->linkNodes(this, node, std::to_string(i));
		i++;
	}
	*out << "}" << '\n';
	*out << "}" << '\n';
}

void field_node::dot(DotWriter* out) {
	out->addNode(decl);
	out->linkNodes(this, decl, "decl");
}