%define parse.trace
%define parse.error detailed
%locations

%code requires{ #include "../compiler/nodes.hpp" }

%{
#include <string>
#include "grammar_handler.cpp"
#include "../compiler/utils.hpp"

extern int yylineno;
extern FILE* yyin;

int yyparse();
int yylex();

void yyerror(char const* s) {
    fprintf(stderr, "Error: %s on line %d\n", s, yylineno);
    exit(1);
}

bool DEBUG = true;
program_node * program = NULL;

%}

%start program

%token<Int> INT
%token<Str> STRING
%token<Float> FLOAT
%token<Bool> BOOL
%token<Datetime> DATETIME
%token<Char> CHAR
%token<Id> ID
%token NOTHING

%token ENDL

%token ME_KW
%token MYBASE_KW
%token MYCLASS_KW
%token IF_KW
%token NEW_KW
%token BYTE_KW
%token SBYTE_KW
%token USHORT_KW 
%token SHORT_KW
%token UINTEGER_KW
%token INTEGER_KW
%token ULONG_KW
%token LONG_KW
%token BOOLEAN_KW
%token DATE_KW
%token CHAR_KW
%token STRING_KW
%token DECIMAL_KW
%token SINGLE_KW
%token DOUBLE_KW
%token OBJECT_KW
%token REDIM_KW
%token THEN_KW
%token END_KW
%token ELSE_KW
%token ELSEIF_KW
%token SELECT_KW
%token CASE_KW
%token TO_KW
%token FOR_KW
%token EACH_KW
%token WHILE_KW
%token NEXT_KW
%token IN_KW
%token UNTIL_KW
%token LOOP_KW
%token DO_KW
%token STEP_KW
%token AS_KW
%token CALL_KW
%token GOTO_KW
%token CONTINUE_KW
%token EXIT_KW
%token STOP_KW
%token RETURN_KW
%token STATIC_KW
%token DIM_KW
%token CONST_KW
%token OF_KW
%token FUNCTION_KW
%token SUB_KW
%token BYREF_KW
%token BYVAL_KW
%token PARAMARRAY_KW
%token OPTIONAL_KW
%token PRIVATE_KW
%token PROTECTED_KW
%token PUBLIC_KW
%token SHARED_KW
%token CLASS_KW
%token STRUCT_KW
%token INHERITS_KW
%token READONLY_KW
%token ERASE_KW
%token CBOOL_KW
%token CBYTE_KW
%token CSBYTE_KW
%token CUSHORT_KW
%token CSHORT_KW
%token CINTEGER_KW
%token CUINTEGER_KW
%token CLONG_KW
%token CULONG_KW
%token CDATE_KW
%token CCHAR_KW
%token CSTRING_KW
%token CDECIMAL_KW
%token CSINGLE_KW
%token CDOUBLE_KW
%token COBJECT_KW
%token CTYPE_KW
%token END_FUNCTION
%token END_SELECT
%token END_IF
%token END_SUB
%token END_WHILE

%token ADD_ASSIGN
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token FLOORDIV_ASSIGN
%token EXP_ASSIGN
%token STRCAT_ASSIGN
%token LSHIFT_ASSIGN
%token RSHIFT_ASSIGN

%precedence BARE_NEW
%precedence ID
%left XOR
%left OR OR_ELSE
%left AND AND_ALSO
%right NOT
%left '=' NEQ LEQ GEQ '<' '>' IS ISNOT LIKE
%left LSHIFT RSHIFT
%left '&'
%left '+' '-'
%left MOD
%left '\\'
%left '/' '*'
%right UMINUS UPLUS
%left '^'
%left '.'
%nonassoc '(' ')' '{' '}'

%type<Expr> expr
%type<Stmt> stmt
%type<ExprList> expr_list;

%type<Struct> program_member;
%type<Struct> struct_declaration;
%type<Struct> class_declaration;

%type<Type> type_name;
%type<Type> simple_type_name;
%type<Type> array_type_name;
%type<Type> cast_target;

%union {
    long long int Int;
    std::string * Str;
    bool Bool;
    double Float;
    DateTime * DateTime;
    std::string * Id;
    char Char;

    expr_node * Expr;
    stmt_node * Stmt;
    list<expr_node *> * ExprList;
    struct_node * Struct;
    type_node * Type;

    // добавь сюда другие типы и пропиши для них и их правил %type
}



%%

program: program_member                     {debug_print("program_member -> program"); program = create_program(); program->nodes.add($1);}
       | program program_member             {debug_print("program program_member -> program"); program = $1; program->nodes.add($2);}
       ;

program_member: struct_declaration              {debug_print("struct_declaration -> program_member"); $$ = $1;}
              | class_declaration               {debug_print("class_declaration -> program_member"); $$ = $1;}
              ;

endl_list: ENDL
         | endl_list ENDL
         ;

stmt_endl: ENDL
         | ':'
         ;

opt_endl: ENDL
        | /* empty */
        ;

kw: ME_KW                               {$$ = create_id("Me");}
  | IF_KW                               {$$ = create_id("If");}
  | MYBASE_KW                           {$$ = create_id("MyBase");}
  | MYCLASS_KW                          {$$ = create_id("MyClass");}
  | NEW_KW                              {$$ = create_id("New");}
  | REDIM_KW                            {$$ = create_id("ReDim");}
  | THEN_KW                             {$$ = create_id("Then");}
  | END_KW                              {$$ = create_id("End");}
  | ELSE_KW                             {$$ = create_id("Else");}
  | ELSEIF_KW                           {$$ = create_id("ElseIf");}
  | SELECT_KW                           {$$ = create_id("Select");}
  | CASE_KW                             {$$ = create_id("Case");}
  | TO_KW                               {$$ = create_id("To");}
  | FOR_KW                              {$$ = create_id("For");}
  | EACH_KW                             {$$ = create_id("Each");}
  | WHILE_KW                            {$$ = create_id("While");}
  | NEXT_KW                             {$$ = create_id("Next");}
  | IN_KW                               {$$ = create_id("In");}
  | UNTIL_KW                            {$$ = create_id("Until");}
  | LOOP_KW                             {$$ = create_id("Loop");}
  | DO_KW                               {$$ = create_id("Do");}
  | STEP_KW                             {$$ = create_id("Step");}
  | AS_KW                               {$$ = create_id("As");}
  | CALL_KW                             {$$ = create_id("Call");}
  | GOTO_KW                             {$$ = create_id("GoTo");}
  | CONTINUE_KW                         {$$ = create_id("Continue");}
  | EXIT_KW                             {$$ = create_id("Exit");}
  | STOP_KW                             {$$ = create_id("Stop");}
  | RETURN_KW                           {$$ = create_id("Return");}
  | BYTE_KW                             {$$ = create_id("Byte");}
  | SBYTE_KW                            {$$ = create_id("SByte");}
  | USHORT_KW                           {$$ = create_id("UShort");}
  | SHORT_KW                            {$$ = create_id("Short");}
  | UINTEGER_KW                         {$$ = create_id("UInteger");}
  | INTEGER_KW                          {$$ = create_id("Integer");}
  | ULONG_KW                            {$$ = create_id("ULong");}
  | LONG_KW                             {$$ = create_id("Long");}
  | BOOLEAN_KW                          {$$ = create_id("Boolean");}
  | DATE_KW                             {$$ = create_id("Date");}
  | CHAR_KW                             {$$ = create_id("Char");}
  | STRING_KW                           {$$ = create_id("String");}
  | DECIMAL_KW                          {$$ = create_id("Decimal");}
  | SINGLE_KW                           {$$ = create_id("Single");}
  | DOUBLE_KW                           {$$ = create_id("Double");}
  | OBJECT_KW                           {$$ = create_id("Object");}
  | DIM_KW                              {$$ = create_id("Dim");}
  | CONST_KW                            {$$ = create_id("Const");}
  | STATIC_KW                           {$$ = create_id("Static");}
  | OF_KW                               {$$ = create_id("Of");}
  | FUNCTION_KW                         {$$ = create_id("Function");}
  | SUB_KW                              {$$ = create_id("Sub");}
  | BYREF_KW                            {$$ = create_id("ByRef");}
  | BYVAL_KW                            {$$ = create_id("ByVal");}
  | PARAMARRAY_KW                       {$$ = create_id("ParamArray");}
  | OPTIONAL_KW                         {$$ = create_id("Optional");}
  | PUBLIC_KW                           {$$ = create_id("Public");}
  | PRIVATE_KW                          {$$ = create_id("Private");}
  | PROTECTED_KW                        {$$ = create_id("Protected");}
  | SHARED_KW                           {$$ = create_id("Shared");}
  | CLASS_KW                            {$$ = create_id("Class");}
  | STRUCT_KW                           {$$ = create_id("Struct");}
  | INHERITS_KW                         {$$ = create_id("Inherits");}
  | READONLY_KW                         {$$ = create_id("Readonly");}
  | ERASE_KW                            {$$ = create_id("Erase");}
  | CBOOL_KW                            {$$ = create_id("CBool");}
  | CBYTE_KW                            {$$ = create_id("CByte");}
  | CSBYTE_KW                           {$$ = create_id("CSByte");}
  | CUSHORT_KW                          {$$ = create_id("CUShort");}
  | CSHORT_KW                           {$$ = create_id("CShort");}
  | CINTEGER_KW                         {$$ = create_id("CInteger");}
  | CUINTEGER_KW                        {$$ = create_id("CUInteger");}
  | CLONG_KW                            {$$ = create_id("CLong");}
  | CULONG_KW                           {$$ = create_id("CULong");}
  | CDATE_KW                            {$$ = create_id("CDate");}
  | CCHAR_KW                            {$$ = create_id("CChar");}
  | CSTRING_KW                          {$$ = create_id("CString");}
  | CDECIMAL_KW                         {$$ = create_id("CDecimal");}
  | CSINGLE_KW                          {$$ = create_id("CSingle");}
  | CDOUBLE_KW                          {$$ = create_id("CDouble");}
  | COBJECT_KW                          {$$ = create_id("CObject");}
  | CTYPE_KW                            {$$ = create_id("CType");}
  ;

type_name: simple_type_name         {$$ = $1;}
         | array_type_name          {$$ = $1;}
         ;

expr: INT                                        {debug_print("INT -> expr"); $$ = create_int($1);}
    | STRING                                     {debug_print("STRING -> expr"); $$ = create_string($1);}
    | ID                                         {debug_print("ID -> expr"); $$ = create_id($1);}
    | FLOAT                                      {debug_print("FLOAT -> expr"); $$ = create_float($1);}
    | BOOL                                       {debug_print("BOOL -> expr"); $$ = create_bool($1);}
    | DATETIME                                   {debug_print("DATETIME -> expr"); $$ = create_datetime($1);}
    | CHAR                                       {debug_print("CHAR -> expr"); $$ = create_char($1);}
    | NOTHING                                    {debug_print("NOTHING -> expr"); $$ = create_nothing($1);}
    | ME_KW                                      {debug_print("ME_KW -> expr"); $$ = create_me($1);}
    | '(' opt_endl expr opt_endl ')'             {$$ = $3;}
    | expr '+' opt_endl expr                     {debug_print("expr + opt_endl expr -> expr"); $$ = create_binary($1, $4, AddOp);}
    | expr '-' opt_endl expr                     {debug_print("expr - opt_endl expr -> expr"); $$ = create_binary($1, $4, SubOp);}
    | expr '*' opt_endl expr                     {debug_print("expr * opt_endl expr -> expr"); $$ = create_binary($1, $4, MulOp);}
    | expr '/' opt_endl expr                     {debug_print("expr / opt_endl expr -> expr"); $$ = create_binary($1, $4, DivOp);} 
    | expr '\\' opt_endl expr                     {debug_print("expr \\ opt_endl expr -> expr"); $$ = create_binary($1, $4, FloorDivOp);} 
    | expr '^' opt_endl expr                      {debug_print("expr ^ opt_endl expr -> expr"); $$ = create_binary($1, $4, ExpOp);} 
    | expr '&' opt_endl expr                      {debug_print("expr & opt_endl expr -> expr"); $$ = create_binary($1, $4, StrConcatOp);}  
    | expr '>' opt_endl expr                      {debug_print("expr > opt_endl expr -> expr"); $$ = create_binary($1, $4, GtOp);}  
    | expr '<' opt_endl expr                      {debug_print("expr < opt_endl expr -> expr"); $$ = create_binary($1, $4, LtOp);}  
    | expr '=' ENDL expr %prec '='                {debug_print("expr = ENDL expr -> expr"); $$ = create_binary($1, $4, EqOp);}         
    | expr '=' expr                               {debug_print("expr = expr -> expr"); $$ = create_binary($1, $4, EqOp);}   
    | expr NEQ opt_endl expr                      {debug_print("expr NEQ expr -> expr"); $$ = create_binary($1, $4, NeqOp);} 
    | expr LEQ opt_endl expr                      {debug_print("expr LEQ expr -> expr"); $$ = create_binary($1, $4, LeqOp);} 
    | expr GEQ opt_endl expr                      {debug_print("expr GEQ expr -> expr"); $$ = create_binary($1, $4, GeqOp);} 
    | expr AND opt_endl expr                      {debug_print("expr AND expr -> expr"); $$ = create_binary($1, $4, AndOp);} 
    | expr AND_ALSO opt_endl expr                 {debug_print("expr AND_ALSO expr -> expr"); $$ = create_binary($1, $4, AndAlsoOp);} 
    | expr OR_ELSE opt_endl expr                  {debug_print("expr OR_ELSE expr -> expr"); $$ = create_binary($1, $4, OrElseOp);} 
    | expr OR opt_endl expr                       {debug_print("expr OR expr -> expr"); $$ = create_binary($1, $4, OrOp);} 
    | expr XOR opt_endl expr                      {debug_print("expr XOR expr -> expr"); $$ = create_binary($1, $4, XorOp);} 
    | expr MOD opt_endl expr                      {debug_print("expr MOD expr -> expr"); $$ = create_binary($1, $4, ModOp);} 
    | expr LSHIFT opt_endl expr                   {debug_print("expr LSHIFT expr -> expr"); $$ = create_binary($1, $4, LshiftOp);} 
    | expr RSHIFT opt_endl expr                   {debug_print("expr RSHIFT expr -> expr"); $$ = create_binary($1, $4, RshiftOp);} 
    | '+' expr %prec UPLUS                        {debug_print("expr = + expr"); $$ = create_unary($1, $4, UnaryPlusOp);} 
    | '-' expr %prec UMINUS                       {debug_print("expr = - expr"); $$ = create_unary($1, $4, UnaryMinusOp);} 
    | NOT expr                                    {debug_print("expr = Not expr"); $$ = create_unary($1, $4, NotOp);} 
    | expr IS opt_endl expr                       {debug_print("expr Is opt_endl expr -> expr"); $$ = create_binary($1, $4, IsOp);} 
    | expr ISNOT opt_endl expr                    {debug_print("expr IsNot opt_endl expr -> expr"); $$ = create_binary($1, $4, IsNotOp);} 
    | expr LIKE opt_endl expr                     {debug_print("expr Like opt_endl expr -> expr"); $$ = create_binary($1, $4, LikeOp);} 
    | expr '(' opt_endl expr_list opt_endl ')'    {debug_print("expr(expr_list) -> expr"); $$ = create_call_expr($1, $4);} 
	| expr '(' opt_endl ')'                       {debug_print("expr() -> expr"); $$ = create_call($1);} 
    | cast_target '(' opt_endl expr opt_endl ')'  {debug_print("cast_target (expr) -> expr"); $$ = create_cast($1, $4);} 
    | CTYPE_KW '(' opt_endl expr ',' opt_endl type_name opt_endl ')'                {debug_print("cast_target (expr) -> expr"); $$ = create_cast($7, $4);} 
    | IF_KW '(' opt_endl expr ',' opt_endl expr ',' opt_endl expr opt_endl ')'      {debug_print("if(expr, expr, expr) -> expr"); $$ = create_if_expr($4, $6, $10);}
    | IF_KW '(' opt_endl expr ',' opt_endl expr opt_endl ')'                        {debug_print("if(expr, expr) -> expr"); $$ = create_if_expr($4, $6);}
    | expr '.' member_access_member               {debug_print("expr . member_access_member -> expr"); $$ = create_member_access($1, $3);}
    | MYBASE_KW '.' member_access_member          {debug_print("my_base . member_access_member -> expr"); $$ = create_mybase_access($3);}
    | MYCLASS_KW '.' member_access_member         {debug_print("my_base . member_access_member -> expr"); $$ = create_myclass_access($3);}
	| NEW_KW simple_type_name %prec BARE_NEW      {debug_print("NEW simple_type_name -> expr"); $$ = create_new_expr($2);}
    | NEW_KW simple_type_name '(' opt_endl ')'    {debug_print("NEW simple_type_name -> expr"); $$ = create_new_expr($2);}
    | NEW_KW simple_type_name '(' opt_endl expr_list opt_endl ')'       {debug_print("NEW simple_type_name (expr_list)-> expr"); $$ = create_new_expr($2, $4);}
    | NEW_KW simple_type_name '(' opt_endl ')' collection_initializer   {debug_print("NEW simple_type_name () collection_initializer -> expr"); $$ = create_arraynew_expr($2, $6);}
    | NEW_KW simple_type_name '(' opt_endl expr_list opt_endl ')' collection_initializer    {debug_print("NEW simple_type_name (expr_list) collection_initializer -> expr"); $$ = create_arraynew_expr($2, $5, $8);}
    | collection_initializer {debug_print("collection_initializer -> expr"); $$ = create_array_literal($1);}
    ;

cast_target: CBOOL_KW                   {$$ = create_primitive_type(Boolean);}
           | CBYTE_KW                   {$$ = create_primitive_type(Byte);}
           | CSBYTE_KW                  {$$ = create_primitive_type(SByte);}
           | CUSHORT_KW                 {$$ = create_primitive_type(UShort);}
           | CSHORT_KW                  {$$ = create_primitive_type(Short);}
           | CINTEGER_KW                {$$ = create_primitive_type(Integer);}
           | CUINTEGER_KW               {$$ = create_primitive_type(UInteger);}
           | CLONG_KW                   {$$ = create_primitive_type(Long);}
           | CULONG_KW                  {$$ = create_primitive_type(ULong);}
           | CDATE_KW                   {$$ = create_primitive_type(Date);}
           | CCHAR_KW                   {$$ = create_primitive_type(Char);}
           | CSTRING_KW                 {$$ = create_primitive_type(String);}
           | CDECIMAL_KW                {$$ = create_primitive_type(Decimal);}
           | CSINGLE_KW                 {$$ = create_primitive_type(Single);}
           | CDOUBLE_KW                 {$$ = create_primitive_type(Double);}
           | COBJECT_KW                 {$$ = create_ref_type(Object, "Object");}
           ;

collection_initializer: '{' opt_endl expr_list opt_endl '}'         {debug_print("{ opt_endl expr_list opt_endl } -> collection_initializer"); $$ = $3;}
                      | '{' opt_endl '}'                            {debug_print("{ opt_endl } -> collection_initializer"); $$ = create_expr_list();}
                      ;

member_access_member: ID                {debug_print("ID -> member_access_member"); $$ = create_id($1);}
                    | kw                {debug_print("kw -> member_access_member"); $$ = $1;}
                    ;

expr_list: expr                             {debug_print("expr -> expr_list"); $$ = create_expr_list();}
         | expr_list ',' opt_endl expr      {debug_print("expr_list ',' opt_endl expr -> expr_list"); $1.add($4); $$ = $1;}
         ;

stmt: CALL_KW expr endl_list                        {debug_print("CALL_KW expr endl_list -> stmt"); $$ = create_call_stmt($2);}
    | REDIM_KW redim_clause_list endl_list          {debug_print("REDIM_KW redim_clause_list endl_list -> stmt"); $$ = create_redim($2);}
    | ERASE_KW expr_list endl_list                  {debug_print("ERASE_KW expr_list endl_list -> stmt"); $$ = create_erase($2);}
    | if_stmt                                       {$$ = $1;}
    | select_stmt                                   {$$ = $1;}
    | label_stmt                                    {$$ = $1;}
    | for_stmt                                      {$$ = $1;}
    | foreach_stmt                                  {$$ = $1;}
    | DO_KW endl_list opt_block LOOP_KW endl_list   {debug_print("DO_KW endl_list opt_block LOOP_KW endl_list"); $$ = create_do_infinite_loop($3);}
    | do_while_stmt                                 {$$ = $1;}
    | do_until_stmt                                 {$$ = $1;}
    | while_stmt                                    {$$ = $1;}
    | var_declaration                               {$$ = $1;}
    | expr '=' expr endl_list                       {debug_print("expr '=' expr endl_list -> stmt"); $$ = create_assign($1, $3, Assign);}
    | expr ADD_ASSIGN expr endl_list                {debug_print("expr ADD_ASSIGN expr endl_list -> stmt"); $$ = create_assign($1, $3, AddAssign);}
    | expr SUB_ASSIGN expr endl_list                {debug_print("expr SUB_ASSIGN expr endl_list -> stmt"); $$ = create_assign($1, $3, SubAssign);}
    | expr MUL_ASSIGN expr endl_list                {debug_print("expr MUL_ASSIGN expr endl_list -> stmt"); $$ = create_assign($1, $3, MulAssign);}
    | expr DIV_ASSIGN expr endl_list                {debug_print("expr DIV_ASSIGN expr endl_list -> stmt"); $$ = create_assign($1, $3, DivAssign);}
    | expr FLOORDIV_ASSIGN expr endl_list           {debug_print("expr FLOORDIV_ASSIGN expr endl_list -> stmt"); $$ = create_assign($1, $3, FloorDivAssign);}
    | expr EXP_ASSIGN expr endl_list                {debug_print("expr EXP_ASSIGN expr endl_list -> stmt"); $$ = create_assign($1, $3, ExpAssign);}
    | expr STRCAT_ASSIGN expr endl_list             {debug_print("expr STRCAT_ASSIGN expr endl_list -> stmt");$$ = create_assign($1, $3, StrConcatAssign);}
    | expr LSHIFT_ASSIGN expr endl_list             {debug_print("expr LSHIFT_ASSIGN expr endl_list -> stmt");$$ = create_assign($1, $3, LshiftAssign);}
    | expr RSHIFT_ASSIGN expr endl_list             {debug_print("expr RSHIFT_ASSIGN expr endl_list -> stmt"); $$ = create_assign($1, $3, RshiftAssign);}
    | RETURN_KW endl_list                           {debug_print("RETURN_KW endl_list -> stmt"); $$ = create_return();}
    | RETURN_KW expr endl_list                      {debug_print("RETURN_KW expr endl_list -> stmt"); $$ = create_return($2);}
    | CONTINUE_KW DO_KW endl_list                   {debug_print("CONTINUE_KW DO_KW endl_list -> stmt"); $$ = create_continue(ContinueDo);}
    | CONTINUE_KW FOR_KW endl_list                  {debug_print("CONTINUE_KW FOR_KW endl_list -> stmt"); $$ = create_continue(ContinueFor);}
    | CONTINUE_KW WHILE_KW endl_list                {debug_print("CONTINUE_KW WHILE_KW endl_list -> stmt"); $$ = create_continue(ContinueWhile);}
    | EXIT_KW DO_KW endl_list                       {debug_print("EXIT_KW DO_KW endl_list -> stmt"); $$ = create_exit(ExitDo);}
    | EXIT_KW FOR_KW endl_list                      {debug_print("EXIT_KW FOR_KW endl_list -> stmt"); $$ = create_exit(ExitFor);}
    | EXIT_KW WHILE_KW endl_list                    {$$ = create_exit(ExitWhile);}
    | EXIT_KW SELECT_KW endl_list                   {$$ = create_exit(ExitSelect);}
    | STOP_KW endl_list                             {$$ = create_stop();}
    | END_KW endl_list                              {$$ = create_end();}
    | GOTO_KW label_name endl_list
    ;

label_name: ID                      {debug_print("ID -> label_name"); $$ = create_goto_label($1);}
          | INT                     {debug_print("INT -> label_name"); $$ = create_goto_label($1);}
          ;

label_stmt: label_name ':'          {debug_print("label_name : -> label_stmt"); $$ = $1;}
          ;

redim_clause: ID '(' opt_endl expr_list opt_endl ')'
            ;

redim_clause_list: redim_clause
                 | redim_clause_list ',' opt_endl redim_clause
                 ;

if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list block END_IF endl_list
	   | IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list block END_IF endl_list
	   | IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list END_IF endl_list
	   | IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list END_IF endl_list
       | IF_KW expr THEN_KW endl_list block else_if_stmts END_IF endl_list
	   | IF_KW expr THEN_KW endl_list else_if_stmts END_IF endl_list
       ;

else_if_stmts: /* empty */
             | else_if_stmts ELSEIF_KW expr THEN_KW endl_list block
			 | else_if_stmts ELSEIF_KW expr THEN_KW endl_list
             ; 

select_stmt: SELECT_KW expr endl_list case_stmts END_SELECT endl_list
           | SELECT_KW CASE_KW expr endl_list case_stmts END_SELECT endl_list 
           ;

case_condition_branch: CASE_KW expr endl_list block
					 | CASE_KW expr endl_list
                     | CASE_KW expr TO_KW expr endl_list block
					 | CASE_KW expr TO_KW expr endl_list
                     ;

case_condition_branches: case_condition_branch
                       | case_condition_branches case_condition_branch
                       ;

case_else_stmt: CASE_KW ELSE_KW endl_list opt_block
              ;

case_stmts: case_condition_branches
          | case_else_stmt
          | case_condition_branches case_else_stmt
          ;

while_stmt: WHILE_KW expr endl_list block END_WHILE endl_list
          | WHILE_KW expr endl_list END_WHILE endl_list
          ;

for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list block NEXT_KW endl_list
        | FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list NEXT_KW endl_list
        | FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list block NEXT_KW endl_list
		| FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list NEXT_KW endl_list
        ;

for_loop_variable: ID
                 | ID AS_KW type_name
                 ;

foreach_stmt: FOR_KW EACH_KW for_loop_variable opt_endl IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list
            | FOR_KW EACH_KW for_loop_variable opt_endl IN_KW expr endl_list opt_block NEXT_KW endl_list
            ;

do_while_stmt: DO_KW endl_list opt_block LOOP_KW WHILE_KW expr endl_list
             | DO_KW WHILE_KW expr endl_list opt_block LOOP_KW endl_list
             ;

do_until_stmt: DO_KW endl_list opt_block LOOP_KW UNTIL_KW expr endl_list
             | DO_KW UNTIL_KW expr endl_list opt_block LOOP_KW endl_list
             ;

opt_block: /* empty */
         | block
         ;

block: stmt
     | block stmt
     ;

variable_name: ID
             | ID array_modifier
             ;

array_modifier: '(' ENDL ')'
              | '(' ')'
              ;

var_declarator: variable_name
              | variable_name AS_KW type_name
              | variable_name '=' expr
              | variable_name AS_KW type_name '=' expr
              ;

var_declaration: STATIC_KW var_declarator endl_list
               | DIM_KW var_declarator endl_list
               | CONST_KW var_declarator endl_list
               ;

array_type_name: simple_type_name array_modifier
               ;

simple_type_name: ID
                | ID '(' opt_endl OF_KW type_list opt_endl ')'
                | primitive_type
                ;
               
primitive_type: BYTE_KW
              | SBYTE_KW
              | USHORT_KW 
              | SHORT_KW
              | UINTEGER_KW
              | INTEGER_KW
              | ULONG_KW
              | LONG_KW
              | BOOLEAN_KW
              | DATE_KW
              | CHAR_KW
              | STRING_KW
              | DECIMAL_KW
              | SINGLE_KW
              | DOUBLE_KW
              | OBJECT_KW
              ;

type_list: simple_type_name
         | type_list ',' opt_endl simple_type_name
         ;

id_list: ID
       | id_list ',' opt_endl ID
       ;

function_signature: FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' AS_KW type_name
                  | FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')'
                  | FUNCTION_KW ID '(' opt_endl ')' AS_KW type_name
                  | FUNCTION_KW ID '(' opt_endl ')'
                  | FUNCTION_KW ID AS_KW type_name
                  | FUNCTION_KW ID
                  | FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' AS_KW type_name
                  | FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')'
                  | FUNCTION_KW ID generic_param_list '(' opt_endl ')' AS_KW type_name
                  | FUNCTION_KW ID generic_param_list '(' opt_endl ')'
                  | FUNCTION_KW ID generic_param_list AS_KW type_name
                  | FUNCTION_KW ID generic_param_list
                  ;

sub_signature: SUB_KW ID '(' opt_endl function_parameters opt_endl ')'
             | SUB_KW ID '(' opt_endl ')'
             | SUB_KW ID
             | SUB_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')'
             | SUB_KW ID generic_param_list '(' opt_endl ')'
             | SUB_KW ID generic_param_list
             ;

constructor_signature: SUB_KW NEW_KW '(' opt_endl function_parameters opt_endl ')'
                     | SUB_KW NEW_KW '(' opt_endl ')'
                     | SUB_KW NEW_KW
                     ;

constructor_declaration: opt_procedure_modifiers constructor_signature endl_list block END_SUB endl_list
			           | opt_procedure_modifiers constructor_signature endl_list END_SUB endl_list
                       ;

function_declaration: opt_procedure_modifiers function_signature endl_list block END_FUNCTION endl_list |
				      opt_procedure_modifiers function_signature endl_list END_FUNCTION endl_list
                    ;


sub_declaration: opt_procedure_modifiers sub_signature endl_list block END_SUB endl_list
			   | opt_procedure_modifiers sub_signature endl_list END_SUB endl_list
               ;

opt_procedure_modifiers: SHARED_KW
                   | /* empty */
                   ;

function_parameters: function_parameter
                   | function_parameters ',' function_parameter
                   ;

function_parameter: variable_name AS_KW type_name '=' expr
                  ;


class_declaration: CLASS_KW ID stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW
                 | CLASS_KW ID endl_list opt_structure_body END_KW CLASS_KW
                 | CLASS_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW
                 | CLASS_KW ID generic_param_list endl_list opt_structure_body END_KW CLASS_KW
                 ;

struct_declaration: STRUCT_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW STRUCT_KW
                  | STRUCT_KW ID generic_param_list endl_list opt_structure_body END_KW STRUCT_KW
                  ;

                
generic_param_list: ID '(' opt_endl OF_KW id_list opt_endl ')';


opt_structure_body: /* empty */
                  | structure_body
                  ;

structure_body: structure_member
              | structure_body structure_member
              ;

structure_member: function_declaration
                | sub_declaration
                | field_declaration
                | const_declaration
                | constructor_declaration
                ;

const_declaration: CONST_KW var_declarator endl_list
                 ;

field_declaration: field_modifiers var_declarator endl_list
                 ;


field_modifiers: field_var_modifier
                   | field_modifiers field_var_modifier
                   ;

field_var_modifier: DIM_KW
                  | READONLY_KW
                  | SHARED_KW
                  ;

%%

int main(int argc, char** argv) {
    if (argc > 1) {
        fopen_s(&yyin, argv[1], "r");
        yyparse();
    }
    else {
        printf("File not found");
    }
}