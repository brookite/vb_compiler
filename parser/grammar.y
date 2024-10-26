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
  ;

type_name: scalar_type_name
         | array_type_name
         ;

array_type_name: scalar_type_name '(' opt_endl_list ')'
               ;

scalar_type_name: ID
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
    | expr '(' opt_endl_list expr_list opt_endl_list ')'
    | expr '(' opt_endl_list ')'
    // | IF_KW '(' opt_endl_list expr ',' opt_endl_list expr ',' opt_endl_list expr opt_endl_list ')'
    // | IF_KW '(' opt_endl_list expr ',' opt_endl_list expr opt_endl_list ')'
    | expr '.' member_access_member
    | MYBASE_KW '.' member_access_member
    | MYCLASS_KW '.' member_access_member
    | NEW_KW scalar_type_name '(' opt_endl_list ')'
    | NEW_KW scalar_type_name '(' opt_endl_list expr_list opt_endl_list ')'
    | NEW_KW array_type_name collection_initializer
    | collection_initializer
    ;


collection_initializer: '{' opt_endl_list expr_list opt_endl_list '}'
                      | '{' opt_endl_list '}'
                      ;


member_access_member: ID
                    | kw
                    ;

expr_list: expr
         | expr ',' opt_endl_list expr_list
         ;


opt_expr_list: /* empty */
          | expr_list
          ;

stmt: expr endl_list
    | REDIM_KW redim_clause_list
    | if_stmt
    | select_stmt
    | for_stmt
    | foreach_stmt
    | DO_KW endl_list opt_block LOOP_KW endl_list
    | do_while_stmt
    | do_until_stmt
    | while_stmt
    ;

redim_clause: ID '(' opt_endl_list expr_list opt_endl_list ')'
            ;

redim_clause_list: redim_clause
                 | redim_clause_list ',' opt_endl_list redim_clause
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

for_stmt: FOR_KW for_loop_variable '=' opt_endl_list expr TO_KW expr endl_list opt_block END_KW NEXT_KW endl_list
        | FOR_KW for_loop_variable '=' opt_endl_list expr TO_KW expr STEP_KW expr endl_list opt_block END_KW NEXT_KW endl_list
        ;

for_loop_variable: ID
                 | ID AS_KW type_name
                 ;

foreach_stmt: FOR_KW EACH_KW for_loop_variable opt_endl_list IN_KW endl_list expr endl_list opt_block NEXT_KW endl_list
            | FOR_KW EACH_KW for_loop_variable opt_endl_list IN_KW expr endl_list opt_block NEXT_KW endl_list
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

