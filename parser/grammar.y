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

%}

%start program

%token INT
%token STRING
%token FLOAT
%token BOOL
%token DATETIME
%token CHAR
%token NOTHING
%token ID
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


%union {
    long long int Int;
    std::string * Str;
    bool Bool;
    double Float;
    DateTime * DateTime;
    std::string * Id;
    char Char;

    expr_node * Expr;
    // ������ ���� ������ ���� � ������� ��� ��� � �� ������ %type
}

%%

program: program_member
       | program program_member
       ;

program_member: struct_declaration
              | class_declaration
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

kw: ME_KW
  | IF_KW
  | MYBASE_KW
  | MYCLASS_KW
  | NEW_KW
  | REDIM_KW
  | THEN_KW
  | END_KW
  | ELSE_KW
  | ELSEIF_KW
  | SELECT_KW
  | CASE_KW
  | TO_KW
  | FOR_KW
  | EACH_KW
  | WHILE_KW
  | NEXT_KW
  | IN_KW
  | UNTIL_KW
  | LOOP_KW
  | DO_KW
  | STEP_KW
  | AS_KW
  | CALL_KW
  | GOTO_KW
  | CONTINUE_KW
  | EXIT_KW
  | STOP_KW
  | RETURN_KW
  | BYTE_KW
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
  | DIM_KW
  | CONST_KW
  | STATIC_KW
  | OF_KW
  | FUNCTION_KW
  | SUB_KW
  | BYREF_KW
  | BYVAL_KW
  | PARAMARRAY_KW
  | OPTIONAL_KW
  | PUBLIC_KW
  | PRIVATE_KW
  | PROTECTED_KW
  | SHARED_KW
  | CLASS_KW
  | STRUCT_KW
  | INHERITS_KW
  | READONLY_KW
  | ERASE_KW
  | CBOOL_KW
  | CBYTE_KW
  | CSBYTE_KW
  | CUSHORT_KW
  | CSHORT_KW
  | CINTEGER_KW
  | CUINTEGER_KW
  | CLONG_KW
  | CULONG_KW
  | CDATE_KW
  | CCHAR_KW
  | CSTRING_KW
  | CDECIMAL_KW
  | CSINGLE_KW
  | CDOUBLE_KW
  | COBJECT_KW
  | CTYPE_KW
  ;

type_name: simple_type_name
         | array_type_name
         ;

expr: INT
    | STRING
    | ID 
    | FLOAT
    | BOOL
    | DATETIME
    | CHAR
    | NOTHING
    | ME_KW
    | '(' opt_endl expr opt_endl ')'
    | expr '+' opt_endl expr
    | expr '-' opt_endl expr
    | expr '*' opt_endl expr
    | expr '/' opt_endl expr
    | expr '\\' opt_endl expr
    | expr '^' opt_endl expr
    | expr '&' opt_endl expr
    | expr '>' opt_endl expr
    | expr '<' opt_endl expr
    | expr '=' ENDL expr %prec '='
    | expr '=' expr 
    | expr NEQ opt_endl expr
    | expr LEQ opt_endl expr
    | expr GEQ opt_endl expr
    | expr AND opt_endl expr
    | expr AND_ALSO opt_endl expr
    | expr OR_ELSE opt_endl expr
    | expr OR opt_endl expr
    | expr XOR opt_endl expr
    | expr MOD opt_endl expr
    | expr LSHIFT opt_endl expr
    | expr RSHIFT opt_endl expr
    | '+' expr %prec UPLUS
    | '-' expr %prec UMINUS
    | NOT expr
    | expr IS opt_endl expr
    | expr ISNOT opt_endl expr
    | expr LIKE opt_endl expr
    | expr '(' opt_endl expr_list opt_endl ')'
	| expr '(' opt_endl ')'
    | cast_target '(' opt_endl expr opt_endl ')'
    | CTYPE_KW '(' opt_endl expr ',' opt_endl type_name opt_endl ')'
    | IF_KW '(' opt_endl expr ',' opt_endl expr ',' opt_endl expr opt_endl ')'
    | IF_KW '(' opt_endl expr ',' opt_endl expr opt_endl ')'
    | expr '.' member_access_member
    | MYBASE_KW '.' member_access_member
    | MYCLASS_KW '.' member_access_member
	| NEW_KW simple_type_name %prec BARE_NEW
    | NEW_KW simple_type_name '(' opt_endl ')'
    | NEW_KW simple_type_name '(' opt_endl expr_list opt_endl ')'
    | NEW_KW simple_type_name '(' opt_endl ')' collection_initializer
    | NEW_KW simple_type_name '(' opt_endl expr_list opt_endl ')' collection_initializer
    | collection_initializer
    ;

cast_target: CBOOL_KW
           | CBYTE_KW
           | CSBYTE_KW
           | CUSHORT_KW
           | CSHORT_KW
           | CINTEGER_KW
           | CUINTEGER_KW
           | CLONG_KW
           | CULONG_KW
           | CDATE_KW
           | CCHAR_KW
           | CSTRING_KW
           | CDECIMAL_KW
           | CSINGLE_KW
           | CDOUBLE_KW
           | COBJECT_KW
           ;

collection_initializer: '{' opt_endl expr_list opt_endl '}'
                      | '{' opt_endl '}'
                      ;

member_access_member: ID
                    | kw
                    ;

expr_list: expr
         | expr_list ',' opt_endl expr 
         ;

stmt: CALL_KW expr endl_list
    | REDIM_KW redim_clause_list endl_list
    | ERASE_KW expr_list endl_list
    | if_stmt 
    | select_stmt
    | label_stmt
    | for_stmt
    | foreach_stmt
    | DO_KW endl_list opt_block LOOP_KW endl_list
    | do_while_stmt
    | do_until_stmt
    | while_stmt
    | var_declaration
    | expr '=' expr endl_list
    | expr ADD_ASSIGN expr endl_list
    | expr SUB_ASSIGN expr endl_list
    | expr MUL_ASSIGN expr endl_list
    | expr DIV_ASSIGN expr endl_list
    | expr FLOORDIV_ASSIGN expr endl_list
    | expr EXP_ASSIGN expr endl_list
    | expr STRCAT_ASSIGN expr endl_list
    | expr LSHIFT_ASSIGN expr endl_list
    | expr RSHIFT_ASSIGN expr endl_list
    | RETURN_KW endl_list
    | RETURN_KW expr endl_list
    | CONTINUE_KW DO_KW endl_list
    | CONTINUE_KW FOR_KW endl_list
    | CONTINUE_KW WHILE_KW endl_list
    | EXIT_KW DO_KW endl_list
    | EXIT_KW FOR_KW endl_list
    | EXIT_KW WHILE_KW endl_list
    | EXIT_KW SELECT_KW endl_list
    | STOP_KW endl_list
    | END_KW endl_list
    | GOTO_KW label_name endl_list
    ;

label_name: ID
          | INT
          ;

label_stmt: label_name ':'
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