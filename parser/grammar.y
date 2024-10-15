%{
#include <string>
%}

%start program
 
%%

open_paren: '('
          | '(' LINE_TERMINATOR
          ;
          
close_paren: ')'
          | LINE_TERMINATOR '('
          ;
          
comma: ','
     | ',' LINE_TERMINATOR
     ;

member_access: '.'
             | '.' LINE_TERMINATOR
             ;

program: namespace_declaration
       ;

namespace_declaration: NAMESPACE_KW IDENTIFIER LINE_TERMINATOR              
                       namespace_members
                       END_KW NAMESPACE_KW LINE_TERMINATOR
                      ;

namespace_members: /* empty */
                 | namespace_member
                 ;

namespace_member: namespace_declaration
                | type_declaration
                ;

type_declaration: class_declaration
                | structure_declaration
                | enum_declaration;

class_declaration

enum_declaration

structure_declaration

type_name: simple_type_name
         | nullable_type_name
         ;
                
         
simple_type_name: primitive_type_name
                | 
                
generic_type_arguments: open_paren OF_KW type_arguments close_paren
                      ;

type_arguments: /* empty */
              | type_argumentsE
              ;
              
type_argumentsE: type_name
               | type_argumentsE type_name
               ;


%%
/*
TODO List:
- Типы и пространства имён (Шашков)
- Объявления переменных и констант внутри функции (Шашков)
- Классы и структуры, конструкторы, шаблоны (Шашков)
- Функции, методы (Шашков)
- Цикл for, until (Шашков)
- Массивы (Шашков)
- Оставшиеся сложные выражения (Шашков)


- Выписывание всех токенов, операторов (и их приоритетов, ассоциативности) (Микулина)
- Бинарные и унарные операции (выражения) (Микулина)
- Условия (Микулина)
- Цикл while (Микулина)
- Перечисления (Микулина)
- Статические методы и поля (Микулина)
*/