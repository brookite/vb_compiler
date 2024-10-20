%{
#include <string>
%}

%start program

%token ID
%token ENDL
%token GLOBAL_KW
%token NAMESPACE_KW
%token END_KW
%token MODULE_KW
%token CLASS_KW
%token STRUCTURE_KW
%token ENUM_KW
%token SUB_KW
%token FUNCTION_KW
%token PROPERTY_KW
%token AS_KW
%token INHERITS_KW
%token MUSTINHERIT_KW
%token NOTINHERITABLE_KW
%token PUBLIC_KW
%token PROTECTED_KW
%token FRIEND_KW
%token PRIVATE_KW
%token OVERLOADS_KW
%token OVERRIDABLE_KW
%token NOTOVERRIDABLE_KW
%token MUSTOVERRIDE_KW
%token OVERRIDES_KW
%token DEFAULT_KW
%token READONLY_KW
%token WRITEONLY_KW
%token DIM_KW
%token CONST_KW
%token STATIC_KW
%token NEW_KW
%token BYVAL_KW
%token BYREF_KW
%token PARAMARRAY_KW
%token WITH_KW
%token FROM_KW
%token KEY_KW
%token GET_KW
%token CALL_KW
%token SET_KW
%token IF_KW
%token THEN_KW
%token ELSE_KW
%token ELSEIF_KW
%token SELECT_KW
%token CASE_KW
%token TO_KW
%token GOTO_KW
%token EXIT_KW
%token CONTINUE_KW
%token STOP_KW
%token RETURN_KW
%token DO_KW
%token WHILE_KW
%token FOR_KW
%token FOREACH_KW
%token INT
%token STRING
%token BOOL
%token DATETIME
%token NOTHING
%token CHAR
%token FLOAT
%token ME_KW
%token MYCLASS_KW
%token MYBASE_KW
%token DIRECTCAST_KW
%token TRYCAST_KW
%token CTYPE_KW
%token CBOOL_KW
%token OF_KW
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
%token SINGLE
%token DOUBLE_KW
%token OBJECT_KW
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
%token CSINGLE
%token CDOUBLE
%token COBJECT_KW
%token UNTIL_KW
%token IN_KW
%token LOOP_KW
%token STEP_KW
%token NEXT_KW

%left XOR
%left OR OR_ELSE
%left AND AND_ALSO
%right NOT
%left EQ NEQ LEQ GEQ '<' '>' IS ISNOT LIKE
%left LSHIFT RSHIFT
%left '&'
%left '+' '-'
%left MOD
%left '\\'
%left '/' '*'
%right UMINUS UPLUS
%left '^'
%nonassoc '.' '(' ')' '{' '}'

%%

open_paren: '('
          | '(' ENDL
          ;
          
close_paren: ')'
          | ENDL ')'
          ;

open_curly: '{'
          | '{' ENDL
          ;
          
close_curly: '}'
          | ENDL '}'
          ;
          
comma: ','
     | ',' ENDL
     ;

dot: '.'
   | '.' ENDL
   ;

program: namespace_members
       ;

namespace_name: GLOBAL_KW
              | GLOBAL_KW '.' dotted_namespace_name
              | dotted_namespace_name
              ;

dotted_namespace_name: ID
                     | dotted_namespace_name dot ID
                     ;

namespace_declaration: NAMESPACE_KW namespace_name ENDL              
                       namespace_members
                       END_KW NAMESPACE_KW ENDL
                      ;

namespace_members: /* empty */
                 | namespace_member namespace_members
                 ;

namespace_member: namespace_declaration
                | type_declaration
                | module_declaration
                ;

module_declaration: access_modifier MODULE_KW ID ENDL module_members END_KW MODULE_KW ENDL
                  | MODULE_KW ID ENDL module_members END_KW MODULE_KW ENDL

module_members: /* empty */
              | module_member module_members
              ;

module_member: type_declaration
             | field_declaration
             | method_declaration
             ;

type_declaration: class_declaration
                | structure_declaration
                | enum_declaration;

type_name: array_type_name
         | nonarray_type_name
         ;

nonarray_type_name: simple_type_name
         | nullable_type_name
         ;
         
array_type_name: nonarray_type_name array_type_modifiers
               ;

array_type_modifiers: array_type_modifier
                      array_type_modifier array_type_modifiers
                    ;

array_type_modifier: open_paren close_paren
                   | open_paren array_rank close_paren
                   ;

array_rank: comma
          | comma array_rank
          ;
         
nullable_type_name: simple_type_name '?'
                  ;
                
         
simple_type_name: primitive_type_name
                | qualified_type_name
                ;
                
primitive_type_name: BYTE_KW
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
                    | SINGLE
                    | DOUBLE_KW
                    | OBJECT_KW
                    ;

identifier_or_kw: ID
                | GLOBAL_KW
                | NAMESPACE_KW
                | END_KW
                | MODULE_KW
                | CLASS_KW
                | STRUCTURE_KW
                | ENUM_KW
                | SUB_KW
                | FUNCTION_KW
                | PROPERTY_KW
                | AS_KW
                | INHERITS_KW
                | MUSTINHERIT_KW
                | NOTINHERITABLE_KW
                | PUBLIC_KW
                | PROTECTED_KW
                | FRIEND_KW
                | PRIVATE_KW
                | OVERLOADS_KW
                | OVERRIDABLE_KW
                | NOTOVERRIDABLE_KW
                | MUSTOVERRIDE_KW
                | OVERRIDES_KW
                | DEFAULT_KW
                | READONLY_KW
                | WRITEONLY_KW
                | DIM_KW
                | CONST_KW
                | STATIC_KW
                | NEW_KW
                | BYVAL_KW
                | BYREF_KW
                | PARAMARRAY_KW
                | WITH_KW
                | FROM_KW
                | KEY_KW
                | GET_KW
                | SET_KW
                | IF_KW
                | THEN_KW
                | ELSE_KW
                | ELSEIF_KW
                | SELECT_KW
                | CASE_KW
                | TO_KW
                | GOTO_KW
                | EXIT_KW
                | CONTINUE_KW
                | STOP_KW
                | RETURN_KW
                | DO_KW
                | WHILE_KW
                | FOR_KW
                | FOREACH_KW
                | CBOOL_KW
                | OF_KW
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
                | SINGLE
                | DOUBLE_KW
                | OBJECT_KW
                ;       

identifier_with_modifiers: ID identifier_modifiers
                         | ID
                         ;

identifier_modifiers: '?' array_modifier;
                    | '?'
                    | array_modifier
                    ;
                    
array_modifier: array_type_modifiers
              | array_sized_modifiers
              ;

array_sized_modifiers: open_paren expr_list close_paren
                     | open_paren expr_list close_paren array_type_modifiers
                     ;

qualified_type_name: ID 
                   | ID generic_type_arguments
                   | ID qualified_type_name_members
                   | ID generic_type_arguments qualified_type_name_members
                   | GLOBAL_KW qualified_type_name_members
                   ;

qualified_type_name_members: identifier_or_kw dot qualified_type_name_members
                           | identifier_or_kw
                           | identifier_or_kw generic_type_arguments
                           | identifier_or_kw generic_type_arguments dot qualified_type_name_members
                           ;
                
generic_type_arguments: open_paren OF_KW type_arguments close_paren
                      ;

type_arguments: ID
               | ID comma type_arguments
               ;

generic_type_parameters: open_paren OF_KW type_parameters close_paren
                       ;

              
type_parameters: ID
               | ID comma type_parameters
               ;

access_modifier: PUBLIC_KW
               | PROTECTED_KW
               | FRIEND_KW
               | PRIVATE_KW
               | PROTECTED_KW FRIEND_KW
               ;

class_modifier: access_modifier
              | MUSTINHERIT_KW
              | NOTINHERITABLE_KW
              ;

class_modifiers: /* empty */
               | class_modifier class_modifiers
               ;

class_base: INHERITS_KW nonarray_type_name ENDL
          ;

class_declaration: class_modifiers CLASS_KW ID ENDL
                   structure_body
                   END_KW CLASS_KW ENDL
                 | class_modifiers CLASS_KW ID ENDL
                   class_base
                   structure_body
                   END_KW CLASS_KW ENDL 
                 | class_modifiers CLASS_KW ID generic_type_parameters ENDL
                   structure_body
                   END_KW CLASS_KW ENDL 
                 | class_modifiers CLASS_KW ID generic_type_parameters ENDL
                   class_base
                   structure_body
                   END_KW CLASS_KW ENDL 
                 ;     

structure_body: method_declaration
          | field_declaration
          | constructor_declaration
          | property_declaration
          | type_declaration
          ;
          
structure_modifier: access_modifier
                  ;

structure_modifiers: structure_modifier
                   | structure_modifier structure_modifiers
                   ;

structure_declaration: structure_modifiers STRUCTURE_KW ID ENDL
                       structure_body
                       END_KW STRUCTURE_KW ENDL
                     | structure_modifiers STRUCTURE_KW ID generic_type_parameters ENDL
                       structure_body
                       END_KW STRUCTURE_KW ENDL 
                     ;

enum_declaration: access_modifier ENUM_KW ID ENDL enum_member_decl_list END_KW ENUM_KW ENDL
                | ENUM_KW ID ENDL enum_member_decl_list END_KW ENUM_KW ENDL
                | access_modifier ENUM_KW ID AS_KW nonarray_type_name ENDL enum_member_decl_list END_KW ENUM_KW ENDL
                | ENUM_KW ID ENDL enum_member_decl_list AS_KW nonarray_type_name END_KW ENUM_KW ENDL
                ;

enum_member_decl_list: /* empty */
                     | enum_member_decl enum_member_decl_list
                     ;

enum_member_decl: ID '=' expr ENDL
                | ID ENDL
                ;
                     
method_declaration: sub_declaration
                  | function_declaration
                  | abstract_sub_declaration
                  | abstract_function_declaration
                  ;

procedure_modifier: access_modifier
                  | OVERLOADS_KW
                  | OVERRIDABLE_KW
                  | NOTOVERRIDABLE_KW
                  ; 
 
procedure_modifiers: /* empty */
                   | procedure_modifier procedure_modifiers
                   ;

                  
sub_signature: SUB_KW ID 
               | SUB_KW ID type_parameters
               | SUB_KW ID open_paren procedure_parameters close_paren
               ;

function_signature: FUNCTION_KW ID
               | FUNCTION_KW ID type_parameters
               | FUNCTION_KW ID open_paren procedure_parameters close_paren
               | FUNCTION_KW ID AS_KW type_name
               | FUNCTION_KW ID type_parameters AS_KW type_name
               | FUNCTION_KW ID open_paren procedure_parameters close_paren AS_KW type_name
               ;

property_signature: PROPERTY_KW ID open_paren procedure_parameters close_paren
                  | PROPERTY_KW ID
                  | PROPERTY_KW ID AS_KW type_name
                  | PROPERTY_KW ID open_paren procedure_parameters close_paren AS_KW type_name
                  ;

procedure_param_modifier: BYVAL_KW
                        | BYREF_KW
                        | PARAMARRAY_KW
                        ;

procedure_parameters: /* empty */
                    | procedure_parametersE
                    ;

procedure_parametersE: procedure_parameter
                    | procedure_parameter comma procedure_parametersE
                    ;

procedure_param_modifiers: /* empty */
                         | procedure_param_modifier procedure_param_modifiers
                         ;

procedure_parameter: procedure_param_modifiers ID
                   | procedure_param_modifiers ID AS_KW type_name
                   ;

sub_declaration: procedure_modifiers sub_signature ENDL
                 block
                 END_KW SUB_KW ENDL
               ;
               
function_declaration: procedure_modifiers function_signature ENDL
                      block
                      END_KW SUB_KW ENDL
                    ;

abstract_procedure_modifiers: MUSTOVERRIDE_KW procedure_modifiers
                            | procedure_modifiers MUSTOVERRIDE_KW
                            ;

abstract_sub_declaration: abstract_procedure_modifiers sub_signature ENDL
                        ;

abstract_function_declaration: abstract_procedure_modifiers function_signature ENDL
                             ;

field_modifier: DIM_KW
              | CONST_KW
              ;

field_declaration: access_modifier field_modifier var_declarator ENDL
                 | field_modifier var_declarator ENDL
                 ;

var_declarator: identifier_with_modifiers '=' expr
                | identifier_with_modifiers
                | identifier_with_modifiers AS_KW type_name '=' expr
                | identifier_with_modifiers AS_KW type_name
                ;

constructor_declaration: access_modifier SUB_KW NEW_KW open_paren procedure_parameters close_paren ENDL
                         block
                         END_KW SUB_KW ENDL
                       ;

auto_property_modifier: access_modifier
                  | OVERLOADS_KW
                  | OVERRIDABLE_KW
                  | NOTOVERRIDABLE_KW
                  | OVERRIDES_KW
                  ;

property_modifier: auto_property_modifier
                  | DEFAULT_KW
                  | READONLY_KW
                  | WRITEONLY_KW
                  ; 
 
property_modifiers: /* empty */
                   | property_modifier property_modifiers
                   ;

abstract_property_modifiers: MUSTOVERRIDE_KW property_modifiers
                           | property_modifiers MUSTOVERRIDE_KW
                           ;

auto_property_modifiers: /* empty */
                   | auto_property_modifier auto_property_modifiers
                   ;

property_declaration: regular_property_declaration
                    | auto_property_declaration
                    | abstract_property_declaration
                    ;

regular_property_declaration: property_modifiers property_signature ENDL
                              property_accessor_declarations
                              END_KW PROPERTY_KW ENDL
                            ;

abstract_property_declaration: abstract_property_modifiers property_signature ENDL
                             ;


auto_property_declaration: auto_property_modifiers property_signature '=' expr ENDL
                         | auto_property_modifiers property_signature ENDL
                         | auto_property_modifiers property_signature AS_KW type_name '=' expr ENDL
                         | auto_property_modifiers property_signature AS_KW type_name ENDL
                         | auto_property_modifiers property_signature AS_KW object_creation_expr '=' expr ENDL
                         | auto_property_modifiers property_signature AS_KW object_creation_expr ENDL
                        ;

property_accessor_declarations: /* empty */
                              | property_accessor_declaration property_accessor_declarations
                              ;

property_accessor_declaration: property_get_declaration
                             | property_set_declaration
                             ;

property_get_declaration: access_modifier GET_KW ENDL block END_KW GET_KW ENDL
                        | GET_KW ENDL block END_KW GET_KW ENDL
                        ;

property_set_declaration: access_modifier SET_KW ENDL block END_KW SET_KW ENDL
                        | SET_KW ENDL block END_KW SET_KW ENDL
                        | access_modifier SET_KW open_paren procedure_parameters close_paren 
                          ENDL block END_KW SET_KW ENDL
                        | SET_KW open_paren procedure_parameters close_paren ENDL block END_KW SET_KW ENDL
                        ;

nonempty_expr_list: expr
                   | expr comma nonempty_expr_list
                   ;

expr_list: /* empty */
          | nonempty_expr_list
          ;

block: /* empty */
     | non_empty_block
     ;

non_empty_block: stmt 
               | stmt non_empty_block
               ;


expr: literal
    | '(' expr ')'
    | ME_KW
    | operator_expr
    | new_expr
    | cast_expr
    | index_expr
    | conditional_expr
    | call_expr
    | member_access_expr
    ;

literal: INT
       | STRING
       | BOOL
       | DATETIME
       | NOTHING
       | CHAR
       | FLOAT
       ;

operator_expr: expr '+' expr
             | expr '-' expr
             | expr '*' expr
             | expr '/' expr
             | expr '\\' expr
             | expr '^' expr
             | expr '&' expr
             | expr '=' expr %prec EQ
             | expr '>' expr
             | expr '<' expr
             | expr '!' expr
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
             ;

conditional_expr: IF_KW open_paren expr comma expr comma expr close_paren
                | IF_KW open_paren expr comma expr close_paren
                ;

call_expr: expr open_paren expr_list close_paren
         ;

index_expr: expr open_paren nonempty_expr_list close_paren
          ;

member_access_expr: member_access_base dot identifier_or_kw
                  | member_access_base dot identifier_or_kw open_paren OF_KW type_arguments close_paren
                  ;

member_access_base: expr
                  | nonarray_type_name
                  | GLOBAL_KW
                  | MYCLASS_KW
                  | MYBASE_KW
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
           | CSINGLE
           | CDOUBLE
           | COBJECT_KW
           ;

cast_expr: DIRECTCAST_KW open_paren expr comma type_name close_paren
         | TRYCAST_KW open_paren expr comma type_name close_paren
         | CTYPE_KW open_paren expr comma type_name close_paren
         | cast_target open_paren expr close_paren
         ;

new_expr: object_creation_expr
        | array_creation_expr
        | collection_initializer
        ;

array_creation_expr: NEW_KW nonarray_type_name array_modifier collection_initializer
                   ;

object_creation_expr: NEW_KW nonarray_type_name
                    | NEW_KW nonarray_type_name object_creation_expr_initializer
                    | NEW_KW nonarray_type_name open_paren procedure_parameters close_paren
                    | NEW_KW nonarray_type_name open_paren procedure_parameters close_paren object_creation_expr_initializer
                    ;

object_creation_expr_initializer: object_member_initializer
                                | object_collection_initializer
                                ;

object_member_initializer: WITH_KW open_curly field_initializer_list close_curly
                         ;

object_collection_initializer: FROM_KW collection_initializer


collection_initializer: open_curly nonempty_expr_list close_curly
                      ;

field_initializer_list: field_initializer
                      | field_initializer field_initializer_list
                      ;

field_initializer: expr
                 | '.' identifier_or_kw '=' expr
                 | KEY_KW expr
                 | KEY_KW '.' identifier_or_kw '=' expr
                 ;

stmt: assign_stmt
    | branch_stmt
    | cond_stmt
    | loop_stmt
    | label_stmt
    | call_stmt
    | var_decl_stmt
    ;

assign_stmt: expr '=' expr ENDL
           | expr '+' '=' expr ENDL
           | expr '-' '=' expr ENDL
           | expr '*' '=' expr ENDL
           | expr '/' '=' expr ENDL
           | expr '\\' '=' expr ENDL
           | expr '^' '=' expr ENDL
           | expr '&' '=' expr ENDL
           | expr '<' '<' '=' expr ENDL
           | expr '>' '>' '=' expr ENDL
           ;

label_name: ID
          | INT
          ;

label_stmt: label_name ':'
          ;

branch_stmt: GOTO_KW label_name ENDL
           | exit_stmt
           | continue_stmt
           | STOP_KW ENDL
           | END_KW ENDL;
           | return_stmt
           ;

exit_stmt: EXIT_KW DO_KW ENDL
         | EXIT_KW FOR_KW ENDL
         | EXIT_KW WHILE_KW ENDL
         | EXIT_KW SELECT_KW ENDL
         ;

continue_stmt: CONTINUE_KW DO_KW ENDL
             | CONTINUE_KW FOR_KW ENDL
             | CONTINUE_KW WHILE_KW ENDL
             ;

return_stmt: RETURN_KW ENDL
           | RETURN_KW expr ENDL
           ;

var_decl_stmt: var_modifier var_declarator ENDL;

var_modifier: STATIC_KW
            | DIM_KW
            | CONST_KW
            ;

call_stmt: call_expr ENDL
         | CALL_KW call_expr ENDL
         ;

cond_stmt: if_stmt
         | select_stmt
         ;

if_stmt: block_if_stmt
       | line_if_stmt
       ;

block_if_stmt: IF_KW expr THEN_KW ENDL block else_if_stmts else_stmt END_KW IF_KW ENDL
             | IF_KW expr THEN_KW ENDL block else_if_stmts END_KW IF_KW ENDL
             ;

else_if_stmts: /* empty */
               ELSEIF_KW expr THEN_KW ENDL block else_if_stmts
             ; 

else_stmt: ELSE_KW ENDL block
         ;

line_if_stmt: IF_KW expr THEN_KW stmt_separated_list ENDL
            | IF_KW expr THEN_KW stmt_separated_list ELSE_KW stmt_separated_list ENDL

stmt_separated_list: stmt
                   | stmt ':' stmt_separated_list
                   ;

select_stmt: SELECT_KW expr ENDL case_stmts case_else_stmt END_KW SELECT_KW ENDL
           | SELECT_KW expr ENDL case_stmts END_KW SELECT_KW ENDL 
           | SELECT_KW CASE_KW expr ENDL case_stmts case_else_stmt END_KW SELECT_KW ENDL
           | SELECT_KW CASE_KW expr ENDL case_stmts  END_KW SELECT_KW ENDL 
           ;

case_stmts: /* empty */
          | CASE_KW case_clause ENDL block case_stmts
          ;

case_clause: expr
           | expr TO_KW expr
           ;

case_else_stmt: CASE_KW ELSE_KW ENDL block
              ;

loop_stmt: while_stmt
         | for_stmt
         | foreach_stmt
         | do_stmt
         ;

while_stmt: WHILE_KW expr ENDL block END_KW WHILE_KW ENDL
          ;

for_stmt: FOR_KW for_loop_variable '=' expr TO_KW expr ENDL block END_KW NEXT_KW ENDL
        | FOR_KW for_loop_variable '=' expr TO_KW expr STEP_KW expr ENDL block END_KW NEXT_KW ENDL
        ;

for_loop_variable: ID
                 | ID AS_KW type_name
                 ;

foreach_stmt: FOREACH_KW for_loop_variable IN_KW ENDL expr ENDL block NEXT_KW ENDL
            | FOREACH_KW for_loop_variable IN_KW expr ENDL block NEXT_KW ENDL
            ;

do_stmt: do_while_stmt
       | do_until_stmt
       | do_true_stmt
       ;

do_true_stmt: DO_KW ENDL block ENDL
             ;

do_while_stmt: DO_KW ENDL block WHILE_KW expr LOOP_KW ENDL
             | DO_KW LOOP_KW WHILE_KW expr ENDL block ENDL
             ;

do_until_stmt: DO_KW ENDL block UNTIL_KW expr LOOP_KW ENDL
             | DO_KW LOOP_KW UNTIL_KW expr ENDL block ENDL
             ;

%%
/*
TODO List:
+ Типы и пространства имён (Шашков)
+ Объявления переменных и констант внутри функции (Шашков)
+ Классы и структуры, конструкторы, шаблоны (Шашков)
+ Функции, методы (Шашков)
+ Массивы (Шашков)
+ Выражения (Шашков)
+ Развилки (Шашков)
+ Перечисления (Шашков)

+ Выписывание всех токенов (Микулина)
+ Цикл for, until, while (Микулина)
*/