#pragma once
#include <string>
#include "utils.hpp"

extern class DotWriter;

struct stmt_node;
typedef list<stmt_node*> block; // сокращение, чтобы не писать длинно

struct node {
	node() : id(++IdCounter) {};
	virtual void dot(DotWriter * writer) = 0;
	virtual std::string getName() = 0;
	const size_t id; // Ќомер узла - должен быть уникальным у каждого нового узла, нужно дл€ вывода в dot
	static size_t IdCounter; // хранит каждый новый номер узла, его нужно увеличивать после присвоени€ номера узлу
};

enum expr_type {
	String, Id, Int, Float, Nothing, Me, Char, Datetime,
	AddOp, SubOp, MulOp, DivOp, FloorDivOp, ExpOp, StrConcatOp, 
	LtOp, GtOp, GteOp, LteOp, EqOp, NeqOp,
	AndOp, AndAlsoOp, OrOp, OrElseOp, LeqOp, GeqOp, XorOp, ModOp, 
	LshiftOp, RshiftOp, IsOp, IsNotOp, LikeOp
	UnaryMinusOp, UnaryPlusOp, NotOp

	MemberAccess, MyClassMemberAccess, MyBaseMemberAccess, CallOrIndex
};

enum stmt_type {
	Call, If, Else, ElseIf, For, ForEach, Select, Case, CaseElse, While, DoWhile, DoUntil, Label, VarDecl, Assign,
	ContinueDo, ContinueWhile, ContinueFor, ExitDo, ExitWhile, ExitFor, ExitSelect,
	Stop, End, GoTo, Redim, Erase, Return
};

enum datatype_type {
	Byte, Object, Integer, Boolean, SByte, UShort, Short,
	UInteger, Long, ULong, Date, Char, String, Decimal,
	Single, Double,
	UserType
};

struct type_node : node {
	datatype_type value;

	// ƒл€ пользовательского типа
	std::string Id;
	list<type_node*>* generics;

	// ≈сли тип - это массив
	bool isArray = false;
	list<int>* dimensions; // в нашей реализации длина массива - 1

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "type"; }
};

struct expr_node : public node {
	expr_type type;

	expr_node(expr_type type_) : type(type_) {}

	long long int Int;
	std::string String;
	double Float;
	char Char;
	DateTime DateTime;

	//For binary ops and member access
	expr_node* left; // дл€ MyClassMemberAccess, MyBaseMemberAccess не заполн€етс€
	expr_node* right; 

	//For unary ops and type cast expr
	expr_node* argument;

	// Member access: use left field as base (before '.') and right as member (after '.')
	// Function call and index: use left as expr and arg_list as arguments

	// For function call and collection initializer
	list<expr_node*>* arg_list;

	// If expr
	expr_node* condition;
	expr_node* then_expr;
	expr_node* else_expr;

	//New expr
	type_node* datatype;
	list<expr_node*>* collection;

	// Cast expr: always use datatype field and argument field for expr

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "expr"; }
};

struct goto_label : node {
	union {
		long long number;
		std::string string;
	} value;

	bool isString;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "goto_label"; }
};

struct typed_value : node {
	type_node* type;
	std::string varName;
	expr_node* value;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "var"; }
};

struct stmt_node : node {
	stmt_node(stmt_type type_) : type(type_) {}

	stmt_type type;
	expr_node* target_expr;
	list<expr_node*>* expr_list; //for redim

	// Condition for If and loops
	expr_node* condition;

	//If stmt
	list<stmt_node*>* condition_nodes; //else-if, cases
	stmt_node* else_node = NULL;

	// Var declaration
	typed_value* var_decl;
	enum {
		STATIC, DIM, CONST
	} var_type;

	//For stmt
	//Use var declaration above for for loop variable
	expr_node* step_node;
	expr_node* to_expr;
	expr_node* container_expr; // for-each

	// Use condition for loops while and do-until, do-while

	// Block for If, For, While, etc.
	block * block;

	// For select use condition_nodes as cases, in case stmt use condition and block

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "stmt"; }
};

struct procedure_node: node {
	type_node* returnType = NULL; // if NULL - means Sub in Syntax
	list<expr_node*>* generics;

	std::string name;
	list<typed_value*> arguments;

	block* block;

	bool isStatic = false; // works and required only for methods

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return returnType == NULL ? "sub" : "func"; }
};

struct constructor_node : node {
	list<typed_value*> arguments;
	block* block;
	
	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "constructor"; }
};

struct field_node : node {
	enum {
		STATIC, CONST, READONLY, DIM
	} type;
	typed_value* decl;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return "field"; }
};

struct struct_node : node {
	bool isClass = false; // if is false - means Struct in syntax
	list<expr_node*>* generics;
	std::string name;

	list<field_node*>* fields;
	list<procedure_node*> methods;
	list<constructor_node>* constructors;

	virtual void dot(DotWriter* writer);
	virtual std::string getName() { return isClass ? "class" : "struct"; }
};

struct program_node : node {
	list<struct_node*> nodes;
};

// ¬ каждом классе нужно реализовать метод dot из общего предка - класса node. Ёти реализации пишутс€ в nodes.cpp файле