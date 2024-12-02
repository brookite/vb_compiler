#pragma once
#include <string>
#include "utils.hpp"

extern class DotWriter;

struct stmt_node;
typedef list<stmt_node*> block;

struct node {
	node() : id(getNewId()) {};
	virtual void dot(DotWriter * writer) = 0;
	virtual std::string getName() = 0;
	const size_t id; 
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
	Index, Call // for semantic analysis
};

enum class stmt_type {
	Call, If, ElseIf, For, ForEach, Select, Case, CaseRange,
	CaseElse, While, DoWhile, DoUntil, Label, VarDecl, Assignment,
	ContinueDo, ContinueWhile, ContinueFor, ExitDo, ExitWhile, ExitFor, ExitSelect, //TODO: нужно?
	Redim, Erase, Return
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
		generics = new list<type_node*>();
		dimensions = new list<int>();
	}

	virtual void dot(DotWriter* writer);
	virtual std::string getName();
};

struct expr_node : public node {
	expr_type type;

	expr_node(expr_type type) : type(type) {}

	long long int Int;
	std::string String;
	double Float;
	char Char;
	bool Bool;
	DateTime * DateTime = NULL;

	//For binary ops and member access
	expr_node* left = NULL; // for MyClassMemberAccess, MyBaseMemberAccess is empty
	expr_node* right = NULL;

	//For unary ops and type cast expr
	expr_node* argument = NULL;

	// Member access: use left field as base (before '.') and right as member (after '.')
	// Function call and index: use left as expr and arg_list as arguments

	// For function call and new arguments
	list<expr_node*>* arg_list = new list<expr_node*>();

	// If expr
	expr_node* condition = NULL;
	expr_node* then_expr = NULL;
	expr_node* else_expr = NULL;

	//New expr
	type_node* datatype = NULL;
	list<expr_node*>* collection = new list<expr_node*>(); // for collection initializer

	// Cast expr: always use datatype field and argument field for expr

	virtual void dot(DotWriter* writer);
	virtual std::string getName();
};

struct typed_value : node {
	type_node* type = NULL;
	std::string varName;
	expr_node* value = NULL;

	bool isArray = false; // marker in case var()
	expr_node* array_size = NULL;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "var"; }
};

struct redim_clause_node : node {
	std::string Id;
	list<expr_node*>* arg = new list<expr_node*>();

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "redim_clause"; }
};

struct stmt_node : node {

	stmt_node(stmt_type type) : type(type) {}

	stmt_type type;
	expr_node* target_expr = NULL; // for case expr, call, return
	list<expr_node*>* expr_list = NULL; //for erase

	list<redim_clause_node*>* redim = new list<redim_clause_node*>();

	// Condition for If and loops
	expr_node* condition = NULL;

	//If stmt
	list<stmt_node*>* condition_nodes = new list<stmt_node*>(); //else-if, cases
	block * else_block = NULL;

	// Var declaration
	typed_value* var_decl = NULL;
	var_type var_type;

	// Assignment
	expr_node* lvalue = NULL;
	expr_node* rvalue = NULL;
	assignment_type assign_type;

	//For stmt
	type_node* id_type = NULL;
	std::string Id;
	expr_node* step_node = NULL;
	expr_node* to_expr = NULL;
	expr_node* container_expr = NULL; // for-each

	// Use condition for loops while and do-until, do-while

	// Block for If, For, While, etc.
	block * block = NULL;

	// For select use condition_nodes as cases, in case stmt use condition and block

	virtual void dot(DotWriter* writer);
	virtual std::string getName();
};


struct procedure_node: node {
	type_node* returnType = NULL; // if NULL - means Sub in Syntax
	list<std::string>* generics = new list<std::string>();

	std::string name;
	list<typed_value*>* arguments = new list<typed_value*>();

	block* block = NULL;

	bool isStatic = false;

	virtual void dot(DotWriter* writer);
	bool isProcedure() { return returnType == NULL; }

	virtual std::string getName() { 
		std::string ret = returnType == NULL ? "sub" : "func"; 
		if (isStatic) ret = "static_" + ret;
		return ret;
	}
};

struct field_node : node {
	typed_value* decl = NULL;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "field"; }
};

struct struct_node : node {
	list<std::string>* generics = new list<std::string>();
	std::string name;

	list<field_node*>* fields = new list<field_node*>();
	list<procedure_node*>* methods = new list<procedure_node*>();
	type_node* parent_class = NULL;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "class"; }
};

struct program_node : node {
	list<struct_node*>* nodes = new list<struct_node*>();

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "program"; }

};
