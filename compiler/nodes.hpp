#pragma once
#include <string>
#include "utils.hpp"

extern class DotWriter;

extern struct field_record;
extern struct method_record;
extern struct struct_record;
extern struct constant_record;

struct stmt_node;
typedef list<stmt_node*> block;

struct node : public cloneable {
	node() : id(getNewId()) {};
	virtual void dot(DotWriter * writer) = 0;
	virtual std::string getName() = 0;
	const size_t id; 
	virtual node* clone() = 0;
};


enum class expr_type {
	String, Id, Int, Bool, Float, Nothing, Me, Char, Datetime,
	AddOp, SubOp, MulOp, DivOp, FloorDivOp, ExpOp, StrConcatOp, 
	LtOp, GtOp, GteOp, LteOp, EqOp, NeqOp,
	AndOp, AndAlsoOp, OrOp, OrElseOp, LeqOp, GeqOp, XorOp, ModOp, 
	LshiftOp, RshiftOp, IsOp, IsNotOp,
	UnaryMinusOp, UnaryPlusOp, NotOp,
	MemberAccess, MyClassMemberAccess,
	MyBaseMemberAccess, CallOrIndex, Cast,
	If, New, Collection, ArrayNew,
	Index, Call, MethodCall, // for semantic analysis
	MyBase // used only after semantic analysis
};

enum class stmt_type {
	Call, If, ElseIf, For, ForEach, Select, Case, CaseRange,
	CaseElse, While, DoWhile, DoUntil, Label, VarDecl, Assignment,
	ContinueDo, ContinueWhile, ContinueFor, ExitDo, ExitWhile, ExitFor, ExitSelect, //TODO: нужно?
	Redim, Erase, Return,
	FieldAssign, ArrayAssign // for semantic analysis
};

enum class assignment_type {
	AddAssign, SubAssign, MulAssign, DivAssign,
	FloorDivAssign, ExpAssign, StrConcatAssign,
	LshiftAssign, RshiftAssign, Assign
};

enum class datatype_type {
	Byte, Object, Integer, Boolean, SByte, UShort, Short,
	UInteger, Long, ULong, Date, Char, String, Decimal,
	Single, Double,
	UserType
};

enum class var_type {
	DIM, CONST
};

struct type_node : node {
	datatype_type value;

	std::string Id;
	list<type_node*>* generics = new list<type_node*>();

	bool isArray = false;
	list<int>* dimensions = new list<int>();

	type_node(datatype_type type) {
		value = type;
		generics = new list<type_node*>();
		dimensions = new list<int>();
	}

	virtual void dot(DotWriter* writer);
	virtual std::string getName();
	virtual type_node* clone() {
		type_node* res = new type_node(value);
		res->Id = Id;
		res->generics = new list<type_node*>();
		for (type_node* expr : *generics) {
			res->generics->add(expr != nullptr ? expr->clone() : nullptr);
		}
		res->isArray = isArray;
		res->dimensions = new list<int>();
		for (int dim : *dimensions) {
			res->dimensions->add(dim);
		}
		return res;
	}
	bool operator== (const type_node& t) const {
		return value == t.value && Id == t.Id &&
			*generics == *t.generics && 
			isArray == t.isArray && 
			*dimensions == *t.dimensions;
	}

	bool operator<(const type_node& other) const {
		return value < other.value;
	}
};

static type_node* intTypeNode = new type_node(datatype_type::Integer);

struct expr_node : public node {
	expr_type type;

	expr_node(expr_type type) : type(type) {}

	long long int Int;
	type_node * numericType = intTypeNode;
	std::string String; // member id in member access, in method call means method name
	double Float;
	char Char;
	bool Bool;
	DateTime * DateTime = nullptr;

	//For binary ops and member access
	expr_node* left = nullptr; // for MyClassMemberAccess, MyBaseMemberAccess is empty, in call means id
	expr_node* right = nullptr;

	//For unary ops and type cast expr
	expr_node* argument = nullptr;

	// Member access: use left field as base (before '.') and right as member (after '.')
	// Function call and index: use left as expr and arg_list as arguments

	// For function call and new arguments and index
	list<expr_node*>* arg_list = new list<expr_node*>();

	// If expr
	expr_node* condition = nullptr;
	expr_node* then_expr = nullptr;
	expr_node* else_expr = nullptr;

	//New expr
	type_node* datatype = nullptr;
	list<expr_node*>* collection = new list<expr_node*>(); // for collection initializer

	constant_record* constant = nullptr;

	// Cast expr: always use datatype field and argument field for expr

	virtual void dot(DotWriter* writer);
	virtual std::string getName();
	virtual expr_node* clone() {
		expr_node* res = new expr_node(type);
		res->Int = Int;
		res->numericType = numericType->clone();
		res->String = String;
		res->Float = Float;
		res->Char = Char;
		res->Bool = Bool;
		res->constant = constant;
		res->DateTime = DateTime != nullptr ? DateTime->clone() : nullptr;
		res->left = left != nullptr ? left->clone() : nullptr;
		res->right = right != nullptr ? right->clone() : nullptr;
		res->argument = argument != nullptr ? argument->clone() : nullptr;
		res->arg_list = new list<expr_node*>();
		for (expr_node* expr : *arg_list) {
			res->arg_list->add(expr != nullptr ? expr->clone() : nullptr);
		}
		res->condition = condition != nullptr ? condition->clone() : nullptr;
		res->then_expr = then_expr != nullptr ? then_expr->clone() : nullptr;
		res->else_expr = else_expr != nullptr ? else_expr->clone() : nullptr;
		res->datatype = datatype != nullptr ? datatype->clone() : nullptr;
		return res;
	}
};

struct typed_value : node {
	type_node* type = nullptr;
	std::string varName;
	expr_node* value = nullptr;

	bool isArray = false; // marker in case var()
	expr_node* array_size = nullptr;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "var"; }
	virtual typed_value* clone() {
		typed_value* clone = new typed_value();
		clone->varName = varName;
		clone->type = type != nullptr ? type->clone() : nullptr;
		clone->value = value != nullptr ? value->clone() : nullptr;
		clone->array_size = array_size != nullptr ? array_size->clone() : nullptr;
		clone->isArray = isArray;
		return clone;
	}
};

struct redim_clause_node : node {
	std::string Id;
	list<expr_node*>* arg = new list<expr_node*>();

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "redim_clause"; }
	virtual redim_clause_node* clone() {
		redim_clause_node* redim = new redim_clause_node();
		redim->Id = Id;
		redim->arg = new list<expr_node*>();
		for (expr_node* expr : *arg) {
			redim->arg->add(expr != nullptr ? expr->clone() : nullptr);
		}
		return redim;
	}
};

struct stmt_node : node {

	stmt_type type;
	expr_node* target_expr = nullptr; // for case expr, call, return
	list<expr_node*>* expr_list = nullptr; //for erase

	list<redim_clause_node*>* redim = new list<redim_clause_node*>();

	stmt_node(stmt_type type) : type(type) {}


	// Condition for If and loops
	expr_node* condition = nullptr;

	//If stmt
	list<stmt_node*>* condition_nodes = new list<stmt_node*>(); //else-if, cases
	block * else_block = nullptr;

	// Var declaration
	typed_value* var_decl = nullptr;
	var_type var_type;

	// Assignment
	expr_node* lvalue = nullptr;
	expr_node* rvalue = nullptr;
	assignment_type assign_type;

	//For stmt
	type_node* id_type = nullptr;
	std::string Id;
	expr_node* step_node = nullptr;
	expr_node* to_expr = nullptr;
	expr_node* container_expr = nullptr; // for-each

	// Use condition for loops while and do-until, do-while

	// Block for If, For, While, etc.
	block * block = nullptr;

	// For select use condition_nodes as cases, in case stmt use condition and block

	virtual stmt_node* clone() {
		stmt_node* stmt = new stmt_node(type);
		stmt->target_expr = target_expr != nullptr ? target_expr->clone() : nullptr;
		stmt->expr_list = expr_list != nullptr ? new list<expr_node *>() : nullptr;
		if (stmt->expr_list != nullptr) {
			for (expr_node* expr : *expr_list) {
				stmt->expr_list->add(expr != nullptr ? expr->clone() : nullptr);
			}
		}
		stmt->redim = new list<redim_clause_node*>();
		for (redim_clause_node* expr : *redim) {
			stmt->redim->add(expr != nullptr ? expr->clone() : nullptr);
		}
		stmt->condition = condition != nullptr ? condition->clone() : nullptr;
		stmt->condition_nodes = new list<stmt_node*>();
		for (stmt_node* expr : *condition_nodes) {
			stmt->condition_nodes->add(expr != nullptr ? expr->clone() : nullptr);
		}
		stmt->var_decl = var_decl == nullptr ? nullptr : var_decl->clone();
		stmt->var_type = var_type;
		stmt->lvalue = lvalue != nullptr ? lvalue->clone() : nullptr;
		stmt->rvalue = rvalue != nullptr ? rvalue->clone() : nullptr;
		stmt->assign_type = assign_type;
		stmt->id_type = id_type != nullptr ? id_type->clone() : nullptr;
		stmt->Id = Id;
		stmt->step_node = step_node != nullptr ? step_node->clone() : nullptr;
		stmt->to_expr = to_expr != nullptr ? to_expr->clone() : nullptr;
		stmt->container_expr = container_expr != nullptr ? container_expr->clone() : nullptr;
		stmt->block = block != nullptr ? new list<stmt_node*>() : nullptr;
		if (stmt->block != nullptr) {
			for (stmt_node* expr : *block) {
				stmt->block->add(expr != nullptr ? expr->clone() : nullptr);
			}
		}
		return stmt;
	}

	virtual void dot(DotWriter* writer);
	virtual std::string getName();
};


struct procedure_node: node {
	type_node* returnType = nullptr; // if nullptr - means Sub in Syntax
	list<std::string>* generics = new list<std::string>();
	method_record* record = nullptr;

	std::string name;
	list<typed_value*>* arguments = new list<typed_value*>();

	block* block = nullptr;

	bool isStatic = false;
	bool isProcedure = false;

	virtual void dot(DotWriter* writer);

	virtual std::string getName() { 
		std::string ret = returnType == nullptr ? "sub" : "func"; 
		if (isStatic) ret = "static_" + ret;
		return ret;
	}
	virtual procedure_node* clone() {
		procedure_node* clone = new procedure_node();
		clone->returnType = returnType != nullptr ? returnType->clone() : nullptr;
		clone->generics = new list<std::string>();
		clone->generics->addAll(*generics);
		clone->record = record;
		clone->isProcedure = isProcedure;
		clone->name = name;
		clone->arguments = new list<typed_value*>();
		for (typed_value* expr : *arguments) {
			clone->arguments->add(expr != nullptr ? expr->clone() : nullptr);
		}
		clone->block = block != nullptr ? new list<stmt_node*>() : nullptr;
		if (clone->block != nullptr) {
			for (stmt_node* expr : *block) {
				clone->block->add(expr != nullptr ? expr->clone() : nullptr);
			}
		}
		clone->isStatic = isStatic;
		return clone;
	}
};

struct field_node : node {
	typed_value* decl = nullptr;
	field_record* record = nullptr;
	var_type type = var_type::DIM;

	bool isStatic = false;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "field"; }
	virtual field_node* clone() {
		field_node* node = new field_node();
		node->decl = decl != nullptr ? decl->clone() : nullptr;
		node->record = nullptr;
		node->isStatic = isStatic;
		node->type = type;
		node->record = record;

		return node;
	}
};

struct struct_node : node {
	struct_record* record = nullptr;
	list<std::string>* generics = new list<std::string>();
	std::string name;

	list<field_node*>* fields = new list<field_node*>();
	list<procedure_node*>* methods = new list<procedure_node*>();
	type_node* parent_class = nullptr;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "class"; }
	virtual struct_node* clone() {
		struct_node* copy = new struct_node();
		copy->name = name;
		copy->record = record;
		copy->generics = new list<std::string>();
		copy->generics->addAll(*generics);
		copy->fields = new list<field_node*>();
		for (field_node* expr : *fields) {
			copy->fields->add(expr != nullptr ? expr->clone() : nullptr);
		}
		copy->methods = new list<procedure_node*>();
		for (procedure_node* expr : *methods) {
			copy->methods->add(expr != nullptr ? expr->clone() : nullptr);
		}
		copy->parent_class = parent_class != nullptr ? parent_class->clone() : nullptr;
		return copy;
	}
};

struct program_node : node {
	list<struct_node*>* nodes = new list<struct_node*>();
	bool analyzed = false;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "program"; }
	virtual program_node* clone() {
		program_node* copy = new program_node();
		copy->nodes = new list<struct_node *>();
		for (struct_node* expr : *nodes) {
			copy->nodes->add(expr != nullptr ? expr->clone() : nullptr);
		}
		copy->analyzed = analyzed;
		return copy;
	}
};
