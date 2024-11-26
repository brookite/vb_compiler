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

    
}



%%

program: program_member                     {debug_print("program_member -> program"); program = create_program(); program->nodes.add($1);}
       | program program_member             {debug_print("program program_member -> program"); program = $1; program->nodes.add($2);}
       ;

program_member: struct_declaration              {debug_print("struct_declaration -> program_member"); $$ = $1;}
              | class_declaration               {debug_print("class_declaration -> program_member"); $$ = $1;}
              ;

endl_list: ENDL                                { debug_print("ENDL -> endl_list"); $$ = create_endl_node(); }
         | endl_list ENDL                      { debug_print("endl_list ENDL -> endl_list"); $$ = add_endl_to_list($1, $2); }
         ;

stmt_endl: ENDL                                { debug_print("ENDL -> stmt_endl"); $$ = create_stmt_endl_node(); }
         | ':'                                 { debug_print("':' -> stmt_endl"); $$ = create_stmt_endl_colon_node(); }
         ;

opt_endl: ENDL                                 { debug_print("ENDL -> opt_endl"); $$ = create_opt_endl_node(); }
        | /* empty */                          { debug_print("empty -> opt_endl"); $$ = create_empty_node(); }
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
    | expr '>' opt_endl expr                       {debug_print("expr > opt_endl expr -> expr"); $$ = create_binary($1, $4, GtOp);}  
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

redim_clause: ID '(' opt_endl expr_list opt_endl ')'                 { debug_print("ID '(' opt_endl expr_list opt_endl ')' -> redim_clause"); $$ = create_redim_clause($1, $3, $4, $5); }
            ;

redim_clause_list: redim_clause                                      { debug_print("redim_clause -> redim_clause_list"); $$ = create_redim_clause_list($1); }
                 | redim_clause_list ',' opt_endl redim_clause       { debug_print("redim_clause_list ',' opt_endl redim_clause -> redim_clause_list"); $$ = add_to_redim_clause_list($1, $4); }
                 ;

if_stmt: IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list block END_IF endl_list                      { debug_print("IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list block END_IF endl_list -> if_stmt"); $$ = create_if_stmt($2, $5, $6, $9); }
	   | IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list block END_IF endl_list                            { debug_print("IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list block END_IF endl_list -> if_stmt"); $$ = create_if_stmt($2, NULL, $5, $8); }
	   | IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list END_IF endl_list                            { debug_print("IF_KW expr THEN_KW endl_list block else_if_stmts ELSE_KW endl_list END_IF endl_list -> if_stmt"); $$ = create_if_stmt($2, $5, $6, NULL); }
	   | IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list END_IF endl_list                                  { debug_print("IF_KW expr THEN_KW endl_list else_if_stmts ELSE_KW endl_list END_IF endl_list -> if_stmt"); $$ = create_if_stmt($2, NULL, $5, NULL); }
       | IF_KW expr THEN_KW endl_list block else_if_stmts END_IF endl_list                                              { debug_print("IF_KW expr THEN_KW endl_list block else_if_stmts END_IF endl_list -> if_stmt"); $$ = create_if_stmt($2, $5, $6, NULL); }
	   | IF_KW expr THEN_KW endl_list else_if_stmts END_IF endl_list                                                    { debug_print("IF_KW expr THEN_KW endl_list else_if_stmts END_IF endl_list -> if_stmt"); $$ = create_if_stmt($2, NULL, $5, NULL); }
       ;

else_if_stmts: /* empty */                                                     { debug_print("empty -> else_if_stmts"); $$ = create_empty_else_if_stmts(); }
             | else_if_stmts ELSEIF_KW expr THEN_KW endl_list block            { debug_print("else_if_stmts ELSEIF_KW expr THEN_KW endl_list block -> else_if_stmts"); $$ = add_to_else_if_stmts($1, $3, $6); }
			 | else_if_stmts ELSEIF_KW expr THEN_KW endl_list                  { debug_print("else_if_stmts ELSEIF_KW expr THEN_KW endl_list -> else_if_stmts"); $$ = add_to_else_if_stmts($1, $3, NULL); }
             ; 

select_stmt: SELECT_KW expr endl_list case_stmts END_SELECT endl_list                    { debug_print("SELECT_KW expr endl_list case_stmts END_SELECT endl_list -> select_stmt"); $$ = create_select_stmt($2, $4); }
           | SELECT_KW CASE_KW expr endl_list case_stmts END_SELECT endl_list            { debug_print("SELECT_KW CASE_KW expr endl_list case_stmts END_SELECT endl_list -> select_stmt"); $$ = create_select_case_stmt($3, $5); }
           ;

case_condition_branch: CASE_KW expr endl_list block                                      { debug_print("CASE_KW expr endl_list block -> case_condition_branch"); $$ = create_case_condition_branch($2, $4); }
					 | CASE_KW expr endl_list                                            { debug_print("CASE_KW expr endl_list -> case_condition_branch"); $$ = create_case_condition_branch($2, NULL); }
                     | CASE_KW expr TO_KW expr endl_list block                           { debug_print("CASE_KW expr TO_KW expr endl_list block -> case_condition_branch"); $$ = create_case_range_branch($2, $4, $6); }
					 | CASE_KW expr TO_KW expr endl_list                                 { debug_print("CASE_KW expr TO_KW expr endl_list -> case_condition_branch"); $$ = create_case_range_branch($2, $4, NULL); }
                     ;

case_condition_branches: case_condition_branch                                   { debug_print("case_condition_branch -> case_condition_branches"); $$ = create_case_condition_branches($1); }
                       | case_condition_branches case_condition_branch           { debug_print("case_condition_branches case_condition_branch -> case_condition_branches"); $$ = add_case_condition_branch($1, $2); }
                       ;

case_else_stmt: CASE_KW ELSE_KW endl_list opt_block                              { debug_print("CASE_KW ELSE_KW endl_list opt_block -> case_else_stmt"); $$ = create_case_else_stmt($4); }
              ;

case_stmts: case_condition_branches                                              { debug_print("case_condition_branches -> case_stmts"); $$ = create_case_stmts($1); }
          | case_else_stmt                                                       { debug_print("case_else_stmt -> case_stmts"); $$ = create_case_stmts_else($1); }
          | case_condition_branches case_else_stmt                               { debug_print("case_condition_branches case_else_stmt -> case_stmts"); $$ = add_case_else_stmt($1, $2); }
          ;

while_stmt: WHILE_KW expr endl_list block END_WHILE endl_list                    { debug_print("WHILE_KW expr endl_list block END_WHILE endl_list -> while_stmt"); $$ = create_while_stmt($2, $4); }
          | WHILE_KW expr endl_list END_WHILE endl_list                          { debug_print("WHILE_KW expr endl_list END_WHILE endl_list -> while_stmt"); $$ = create_empty_while_stmt($2); }
          ;

for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list block NEXT_KW endl_list                               { debug_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list block NEXT_KW endl_list -> for_stmt"); $$ = create_for_stmt($2, $5, $7, $9); }
        | FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list NEXT_KW endl_list                                     { debug_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list NEXT_KW endl_list -> for_stmt"); $$ = create_simple_for_stmt($2, $5, $7); }
        | FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list block NEXT_KW endl_list                  { debug_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list block NEXT_KW endl_list -> for_stmt"); $$ = create_step_for_stmt($2, $5, $7, $9, $11); }
		| FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list NEXT_KW endl_list                        { debug_print("FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list NEXT_KW endl_list -> for_stmt"); $$ = create_simple_step_for_stmt($2, $5, $7, $9); }
        ;

for_loop_variable: ID                                 { debug_print("ID -> for_loop_variable"); $$ = create_variable_node($1); }
                 | ID AS_KW type_name                 { debug_print("ID AS_KW type_name -> for_loop_variable"); $$ = create_typed_variable_node($1, $3); }
                 ;

foreach_stmt: FOR_KW EACH_KW for_loop_variable opt_endl IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list            { debug_print("FOR_KW EACH_KW for_loop_variable opt_endl IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list -> foreach_stmt"); $$ = create_foreach_stmt($3, $7, $9); }
            | FOR_KW EACH_KW for_loop_variable opt_endl IN_KW expr endl_list opt_block NEXT_KW endl_list                      { debug_print("FOR_KW EACH_KW for_loop_variable opt_endl IN_KW expr endl_list opt_block NEXT_KW endl_list -> foreach_stmt"); $$ = create_simple_foreach_stmt($3, $6, $8); }
            ;

do_while_stmt: DO_KW endl_list opt_block LOOP_KW WHILE_KW expr endl_list                                                      { debug_print("DO_KW endl_list opt_block LOOP_KW WHILE_KW expr endl_list -> do_while_stmt"); $$ = create_do_while_stmt($3, $6); }
             | DO_KW WHILE_KW expr endl_list opt_block LOOP_KW endl_list                                                      { debug_print("DO_KW WHILE_KW expr endl_list opt_block LOOP_KW endl_list -> do_while_stmt"); $$ = create_while_do_stmt($3, $5); }
             ;

do_until_stmt: DO_KW endl_list opt_block LOOP_KW UNTIL_KW expr endl_list                                                      { debug_print("DO_KW endl_list opt_block LOOP_KW UNTIL_KW expr endl_list -> do_until_stmt"); $$ = create_do_until_stmt($3, $6); }
             | DO_KW UNTIL_KW expr endl_list opt_block LOOP_KW endl_list                                                      { debug_print("DO_KW UNTIL_KW expr endl_list opt_block LOOP_KW endl_list -> do_until_stmt"); $$ = create_until_do_stmt($3, $5); }
             ;

opt_block: /* empty */         { debug_print("empty -> opt_block"); $$ = create_empty_block(); }
         | block               { debug_print("block -> opt_block"); $$ = $1; }
         ;

block: stmt                    { debug_print("stmt -> block"); $$ = create_block($1); }
     | block stmt              { debug_print("block stmt -> block"); $$ = add_to_block($1, $2); }
     ;

variable_name: ID                             { debug_print("ID -> variable_name"); $$ = create_variable_name($1); }
             | ID array_modifier              { debug_print("ID array_modifier -> variable_name"); $$ = create_array_variable($1, $2); }
             ;

array_modifier: '(' ENDL ')'                  { debug_print("'(' ENDL ')' -> array_modifier"); $$ = create_array_modifier(); }
              | '(' ')'                       { debug_print("'(' ')' -> array_modifier"); $$ = create_empty_array_modifier(); }
              ;

var_declarator: variable_name                                        { debug_print("variable_name -> var_declarator"); $$ = create_var_declarator($1); }
              | variable_name AS_KW type_name                        { debug_print("variable_name AS_KW type_name -> var_declarator"); $$ = create_typed_var_declarator($1, $3); }
              | variable_name '=' expr                               { debug_print("variable_name '=' expr -> var_declarator"); $$ = create_initialized_var_declarator($1, $3); }
              | variable_name AS_KW type_name '=' expr               { debug_print("variable_name AS_KW type_name '=' expr -> var_declarator"); $$ = create_typed_initialized_var_declarator($1, $3, $5); }
              ;

var_declaration: STATIC_KW var_declarator endl_list                  { debug_print("STATIC_KW var_declarator endl_list -> var_declaration"); $$ = create_static_var_declaration($2); }
               | DIM_KW var_declarator endl_list                     { debug_print("DIM_KW var_declarator endl_list -> var_declaration"); $$ = create_dim_var_declaration($2); }
               | CONST_KW var_declarator endl_list                   { debug_print("CONST_KW var_declarator endl_list -> var_declaration"); $$ = create_const_var_declaration($2); }
               ;

array_type_name: simple_type_name array_modifier                     { debug_print("simple_type_name array_modifier -> array_type_name"); $$ = create_array_type($1, $2); }
               ;

simple_type_name: ID                                                  { debug_print("ID -> simple_type_name"); $$ = create_simple_type($1); }
                | ID '(' opt_endl OF_KW type_list opt_endl ')'        { debug_print("ID '(' opt_endl OF_KW type_list opt_endl ')' -> simple_type_name"); $$ = create_generic_type($1, $5); }
                | primitive_type                                      { debug_print("primitive_type -> simple_type_name"); $$ = $1; }
                ;
               
primitive_type: BYTE_KW      { debug_print("BYTE_KW -> primitive_type"); $$ = create_primitive_type(Byte); }
              | SBYTE_KW     { debug_print("SBYTE_KW -> primitive_type"); $$ = create_primitive_type(SByte); }
              | USHORT_KW    { debug_print("USHORT_KW -> primitive_type"); $$ = create_primitive_type(UShort); }
              | SHORT_KW     { debug_print("SHORT_KW -> primitive_type"); $$ = create_primitive_type(Short); }
              | UINTEGER_KW  { debug_print("UINTEGER_KW -> primitive_type"); $$ = create_primitive_type(UInteger); }
              | INTEGER_KW   { debug_print("INTEGER_KW -> primitive_type"); $$ = create_primitive_type(Integer); }
              | ULONG_KW     { debug_print("ULONG_KW -> primitive_type"); $$ = create_primitive_type(ULong); }
              | LONG_KW      { debug_print("LONG_KW -> primitive_type"); $$ = create_primitive_type(Long); }
              | BOOLEAN_KW   { debug_print("BOOLEAN_KW -> primitive_type"); $$ = create_primitive_type(Boolean); }
              | DATE_KW      { debug_print("DATE_KW -> primitive_type"); $$ = create_primitive_type(Date); }
              | CHAR_KW      { debug_print("CHAR_KW -> primitive_type"); $$ = create_primitive_type(Char); }
              | STRING_KW    { debug_print("STRING_KW -> primitive_type"); $$ = create_primitive_type(String); }
              | DECIMAL_KW   { debug_print("DECIMAL_KW -> primitive_type"); $$ = create_primitive_type(Decimal); }
              | SINGLE_KW    { debug_print("SINGLE_KW -> primitive_type"); $$ = create_primitive_type(Single); }
              | DOUBLE_KW    { debug_print("DOUBLE_KW -> primitive_type"); $$ = create_primitive_type(Double); }
              | OBJECT_KW    { debug_print("OBJECT_KW -> primitive_type"); $$ = create_primitive_type(Object); }
              ;

type_list: simple_type_name                                   { debug_print("simple_type_name -> type_list"); $$ = create_type_list($1); }
         | type_list ',' opt_endl simple_type_name            { debug_print("type_list ',' opt_endl simple_type_name -> type_list"); $$ = append_to_type_list($1, $4); }
         ;

id_list: ID                                                   { debug_print("ID -> id_list"); $$ = create_id_list($1); }
       | id_list ',' opt_endl ID                              { debug_print("id_list ',' opt_endl ID -> id_list"); $$ = append_to_id_list($1, $4); }
       ;

function_signature: FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' AS_KW type_name                                  { debug_print("FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' AS_KW type_name -> function_signature"); $$ = create_function_signature($2, $5, $9); }
                  | FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')'                                                  { debug_print("FUNCTION_KW ID '(' opt_endl function_parameters opt_endl ')' -> function_signature"); $$ = create_function_signature($2, $5); }
                  | FUNCTION_KW ID '(' opt_endl ')' AS_KW type_name                                                               { debug_print("FUNCTION_KW ID '(' opt_endl ')' AS_KW type_name -> function_signature"); $$ = create_function_signature_no_params($2, $6); }
                  | FUNCTION_KW ID '(' opt_endl ')'                                                                               { debug_print("FUNCTION_KW ID '(' opt_endl ')' -> function_signature"); $$ = create_function_signature_no_params($2); }
                  | FUNCTION_KW ID AS_KW type_name                                                                                { debug_print("FUNCTION_KW ID AS_KW type_name -> function_signature"); $$ = create_function_signature_simple($2, $4); }
                  | FUNCTION_KW ID                                                                                                { debug_print("FUNCTION_KW ID -> function_signature"); $$ = create_function_signature_simple($2); }
                  | FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' AS_KW type_name               { debug_print("FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' AS_KW type_name -> function_signature"); $$ = create_generic_function_signature($2, $3, $6, $10); }
                  | FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')'                               { debug_print("FUNCTION_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' -> function_signature"); $$ = create_generic_function_signature($2, $3, $6); }
                  | FUNCTION_KW ID generic_param_list '(' opt_endl ')' AS_KW type_name                                            { debug_print("FUNCTION_KW ID generic_param_list '(' opt_endl ')' AS_KW type_name -> function_signature"); $$ = create_generic_function_signature_no_params($2, $3, $8); }
                  | FUNCTION_KW ID generic_param_list '(' opt_endl ')'                                                            { debug_print("FUNCTION_KW ID generic_param_list '(' opt_endl ')' -> function_signature"); $$ = create_generic_function_signature_no_params($2, $3); }
                  | FUNCTION_KW ID generic_param_list AS_KW type_name                                                             { debug_print("FUNCTION_KW ID generic_param_list AS_KW type_name -> function_signature"); $$ = create_generic_function_signature_simple($2, $3, $5); }
                  | FUNCTION_KW ID generic_param_list                                                                             { debug_print("FUNCTION_KW ID generic_param_list -> function_signature"); $$ = create_generic_function_signature_simple($2, $3); }
                  ;

sub_signature: SUB_KW ID '(' opt_endl function_parameters opt_endl ')'                    { debug_print("SUB_KW ID '(' opt_endl function_parameters opt_endl ')' -> sub_signature"); $$ = create_sub_signature($2, $5); }
             | SUB_KW ID '(' opt_endl ')'                                                 { debug_print("SUB_KW ID '(' opt_endl ')' -> sub_signature"); $$ = create_sub_signature_no_params($2); }
             | SUB_KW ID                                                                  { debug_print("SUB_KW ID -> sub_signature"); $$ = create_sub_signature_simple($2); }
             | SUB_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' { debug_print("SUB_KW ID generic_param_list '(' opt_endl function_parameters opt_endl ')' -> sub_signature"); $$ = create_generic_sub_signature($2, $3, $6); }
             | SUB_KW ID generic_param_list '(' opt_endl ')'                              { debug_print("SUB_KW ID generic_param_list '(' opt_endl ')' -> sub_signature"); $$ = create_generic_sub_signature_no_params($2, $3); }
             | SUB_KW ID generic_param_list                                               { debug_print("SUB_KW ID generic_param_list -> sub_signature"); $$ = create_generic_sub_signature_simple($2, $3); }
             ;

constructor_signature: SUB_KW NEW_KW '(' opt_endl function_parameters opt_endl ')'           { debug_print("SUB_KW NEW_KW '(' opt_endl function_parameters opt_endl ')' -> constructor_signature"); $$ = create_constructor_signature($5); }
                     | SUB_KW NEW_KW '(' opt_endl ')'                                        { debug_print("SUB_KW NEW_KW '(' opt_endl ')' -> constructor_signature"); $$ = create_constructor_signature_no_params(); }
                     | SUB_KW NEW_KW                                                         { debug_print("SUB_KW NEW_KW -> constructor_signature"); $$ = create_simple_constructor_signature(); }
                     ;

constructor_declaration: opt_procedure_modifiers constructor_signature endl_list block END_SUB endl_list            { debug_print("opt_procedure_modifiers constructor_signature endl_list block END_SUB endl_list -> constructor_declaration"); $$ = create_constructor_declaration($1, $2, $4); }
			           | opt_procedure_modifiers constructor_signature endl_list END_SUB endl_list                  { debug_print("opt_procedure_modifiers constructor_signature endl_list END_SUB endl_list -> constructor_declaration"); $$ = create_simple_constructor_declaration($1, $2); }
                       ;

function_declaration: opt_procedure_modifiers function_signature endl_list block END_FUNCTION endl_list     { debug_print("opt_procedure_modifiers function_signature endl_list block END_FUNCTION endl_list -> function_declaration"); $$ = create_function_declaration($1, $2, $4); }
                    | opt_procedure_modifiers function_signature endl_list END_FUNCTION endl_list           { debug_print("opt_procedure_modifiers function_signature endl_list END_FUNCTION endl_list -> function_declaration"); $$ = create_simple_function_declaration($1, $2); }
                    ;


sub_declaration: opt_procedure_modifiers sub_signature endl_list block END_SUB endl_list          { debug_print("opt_procedure_modifiers sub_signature endl_list block END_SUB endl_list -> sub_declaration"); $$ = create_sub_declaration($1, $2, $4); }
			   | opt_procedure_modifiers sub_signature endl_list END_SUB endl_list                { debug_print("opt_procedure_modifiers sub_signature endl_list END_SUB endl_list -> sub_declaration"); $$ = create_simple_sub_declaration($1, $2); }
               ;

opt_procedure_modifiers: SHARED_KW                  { debug_print("SHARED_KW -> opt_procedure_modifiers"); $$ = create_shared_modifier(); }
                   | /* empty */                    { debug_print("empty -> opt_procedure_modifiers"); $$ = create_empty_modifier(); }
                   ;

function_parameters: function_parameter                               { debug_print("function_parameter -> function_parameters"); $$ = create_function_parameters($1); }
                   | function_parameters ',' function_parameter       { debug_print("function_parameters ',' function_parameter -> function_parameters"); $$ = append_to_function_parameters($1, $3); }
                   ;

function_parameter: variable_name AS_KW type_name '=' expr                     { debug_print("variable_name AS_KW type_name '=' expr -> function_parameter"); $$ = create_function_parameter($1, $3, $5); }
                  ;


class_declaration: CLASS_KW ID stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW                          { debug_print("CLASS_KW ID stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); $$ = create_class_declaration($2, $5, $7); }
                 | CLASS_KW ID endl_list opt_structure_body END_KW CLASS_KW                                                   { debug_print("CLASS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); $$ = create_class_declaration_no_inheritance($2, $4); }
                 | CLASS_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW       { debug_print("CLASS_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); $$ = create_generic_class_declaration($2, $3, $6, $8); }
                 | CLASS_KW ID generic_param_list endl_list opt_structure_body END_KW CLASS_KW                                { debug_print("CLASS_KW ID generic_param_list endl_list opt_structure_body END_KW CLASS_KW -> class_declaration"); $$ = create_generic_class_declaration_no_inheritance($2, $3, $5); }
                 ;

struct_declaration: STRUCT_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW STRUCT_KW              { debug_print("STRUCT_KW ID generic_param_list stmt_endl INHERITS_KW ID endl_list opt_structure_body END_KW STRUCT_KW -> struct_declaration"); $$ = create_struct_declaration($2, $3, $6, $8); }
                  | STRUCT_KW ID generic_param_list endl_list opt_structure_body END_KW STRUCT_KW                                       { debug_print("STRUCT_KW ID generic_param_list endl_list opt_structure_body END_KW STRUCT_KW -> struct_declaration"); $$ = create_struct_declaration_no_inheritance($2, $3, $5); }
                  ;

                
generic_param_list: ID '(' opt_endl OF_KW id_list opt_endl ')'                          { debug_print("ID '(' opt_endl OF_KW id_list opt_endl ')' -> generic_param_list"); $$ = create_generic_param_list($1, $5); };


opt_structure_body: /* empty */          { debug_print("empty -> opt_structure_body"); $$ = create_empty_structure_body(); }
                  | structure_body       { debug_print("structure_body -> opt_structure_body"); $$ = $1; }
                  ;

structure_body: structure_member                          { debug_print("structure_member -> structure_body"); $$ = create_structure_body($1); }
              | structure_body structure_member           { debug_print("structure_body structure_member -> structure_body"); $$ = append_to_structure_body($1, $2); }
              ;

structure_member: function_declaration                   { debug_print("function_declaration -> structure_member"); $$ = $1; }
                | sub_declaration                        { debug_print("sub_declaration -> structure_member"); $$ = $1; }
                | field_declaration                      { debug_print("field_declaration -> structure_member"); $$ = $1; }
                | const_declaration                      { debug_print("const_declaration -> structure_member"); $$ = $1; }
                | constructor_declaration                { debug_print("constructor_declaration -> structure_member"); $$ = $1; }
                ;

const_declaration: CONST_KW var_declarator endl_list       { debug_print("CONST_KW var_declarator endl_list -> const_declaration"); $$ = create_const_declaration($2); }
                 ;

field_declaration: field_modifiers var_declarator endl_list         { debug_print("field_modifiers var_declarator endl_list -> field_declaration"); $$ = create_field_declaration($1, $2); }
                 ;


field_modifiers: field_var_modifier                          { debug_print("field_var_modifier -> field_modifiers"); $$ = create_field_modifiers($1); }
                   | field_modifiers field_var_modifier      { debug_print("field_modifiers field_var_modifier -> field_modifiers"); $$ = append_field_modifier($1, $2); }
                   ;

field_var_modifier: DIM_KW            { debug_print("DIM_KW -> field_var_modifier"); $$ = create_dim_modifier(); }
                  | READONLY_KW       { debug_print("READONLY_KW -> field_var_modifier"); $$ = create_readonly_modifier(); }
                  | SHARED_KW         { debug_print("SHARED_KW -> field_var_modifier"); $$ = create_shared_modifier(); }
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