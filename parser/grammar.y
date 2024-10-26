%{
#include <string>
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

%%

program: stmt;

endl_list: ENDL
         | endl_list ENDL
         ;

opt_endl_list: /* empty */
             | endl_list
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
    | '(' expr ')'
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '\\' expr
    | expr '^' expr
    | expr '&' expr
    | expr '=' expr
    | expr '>' expr
    | expr '<' expr
    | expr NEQ expr
    | expr LEQ expr
    | expr GEQ expr
    | expr AND expr
    | expr AND_ALSO expr
    | expr OR_ELSE expr
    | expr OR expr
    | expr XOR expr
    | expr MOD expr
    | expr LSHIFT expr
    | expr RSHIFT expr
    | '+' expr %prec UPLUS
    | '-' expr %prec UMINUS
    | NOT expr
    | expr IS expr
    | expr ISNOT expr
    | expr LIKE expr
    | expr '(' opt_endl expr_list opt_endl ')'
    | expr '(' opt_endl ')'
    //| IF_KW '(' opt_endl expr ',' opt_endl expr ',' opt_endl expr opt_endl ')'
    //| IF_KW '(' opt_endl expr ',' opt_endl expr opt_endl ')'
    | expr '.' member_access_member
    | MYBASE_KW '.' member_access_member
    | MYCLASS_KW '.' member_access_member
    //| NEW_KW simple_type_name paren_expr_list // проблемное место
    | NEW_KW array_type_name collection_initializer
    | collection_initializer
    ;

/* костыли paren_expr_list, paren_expr */
paren_expr_list: '(' ENDL ')'
    | '(' ')'
    | '(' expr_list ')'
    | '(' ENDL expr_list ')'
    | '(' expr_list ENDL ')'
    | '(' ENDL expr_list ENDL ')'
    ;

paren_expr: '(' expr ')'
          | '(' ENDL expr ')'
          | '(' expr ENDL ')'
          | '(' ENDL expr ENDL ')'
          ;

collection_initializer: '{' opt_endl expr_list opt_endl '}'
                      | '{' opt_endl '}'
                      ;


member_access_member: ID
                    | kw
                    ;

expr_list: expr
         | expr ',' opt_endl expr_list
         ;


opt_expr_list: /* empty */
          | expr_list
          ;

stmt: expr endl_list
    | REDIM_KW redim_clause_list
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
    //| expr '=' expr endl_list
    | expr '+' '=' expr endl_list
    | expr '-' '=' expr endl_list
    | expr '*' '=' expr endl_list
    | expr '/' '=' expr endl_list
    | expr '\\' '=' expr endl_list
    | expr '^' '=' expr endl_list
    | expr '&' '=' expr endl_list
    | expr '<' '<' '=' expr endl_list
    | expr '>' '>' '=' expr endl_list
    | CALL_KW expr '(' opt_endl expr_list opt_endl ')' endl_list
    | CALL_KW expr '(' opt_endl ')' endl_list
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
    //| END_KW endl_list
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

if_stmt: IF_KW expr THEN_KW endl_list opt_block else_if_stmts ELSE_KW endl_list opt_block END_KW IF_KW endl_list
       | IF_KW expr THEN_KW endl_list opt_block else_if_stmts END_KW IF_KW endl_list
       ;

else_if_stmts: /* empty */
             | else_if_stmts ELSEIF_KW expr THEN_KW endl_list opt_block
             ; 

select_stmt: SELECT_KW expr endl_list case_stmts END_KW SELECT_KW endl_list
           | SELECT_KW CASE_KW expr endl_list case_stmts END_KW SELECT_KW endl_list 
           ;

case_condition_branch: CASE_KW expr endl_list opt_block
                     | CASE_KW expr TO_KW expr endl_list opt_block
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

while_stmt: WHILE_KW expr endl_list opt_block END_KW WHILE_KW endl_list
          ;

for_stmt: FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr endl_list opt_block END_KW NEXT_KW endl_list
        | FOR_KW for_loop_variable '=' opt_endl expr TO_KW expr STEP_KW expr endl_list opt_block END_KW NEXT_KW endl_list
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

array_modifier: paren_expr
              | '(' ENDL ')'
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
                | primitive_type
                | ID '(' opt_endl OF_KW type_list opt_endl ')' // SR-конфликт
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

type_list: type_name
         | type_list ',' opt_endl type_name
         ;

id_list: ID
       | id_list ',' opt_endl ID
       ;