%option nounistd
%option noyywrap
%option never-interactive
%option case-insensitive

%{
    #include <string>
    #define YY_DECL int yylex()
%}


LETTER[A-Za-z]
DIGIT[0-9]
HEX_DIGIT[0-9A-Fa-f]
EXPONENT[eE][+-]?[0-9]+

%x STRING
%x COMMENT
%x DATETIME

%{
    std::string strLiteral;
    std::string datetime;
    std::string comment;
%}

%%

\'|REM {BEGIN(COMMENT); comment.clear(); }
<COMMENT>[^\n]* {comment += yytext;}
<COMMENT>\n {printf("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}
<COMMENT><<EOF>> {printf("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}

\" {BEGIN(STRING); strLiteral.clear();}
<STRING>[^\n\\"]* {strLiteral += yytext;}
<STRING>\\n {strLiteral += "\n";}
<STRING>\\r {strLiteral += "\r";}
<STRING>\\t {strLiteral += "\t";}
<STRING>\\b {strLiteral += "\b";}
<STRING>\"\" {strLiteral += "\"";}
<STRING><<EOF>>	{printf("Error: String literal wasn't closed\n"); yyterminate();}
<STRING>\n	{printf("Error: String literal wasn't closed\n"); yyterminate();}
<STRING>\" {printf("Found a string literal: %s\n", strLiteral.c_str()); BEGIN(INITIAL);}

\"([^\n"]|\"\")\"[Cc] {printf("Found character literal: %s\n", yytext);}
[+-]?({DIGIT}+\.?{DIGIT}*|{DIGIT}*\.?{DIGIT}+)({EXPONENT})?[frdFRD]? {printf("Found floating point literal: %s\n", yytext);}


# {BEGIN(DATETIME); datetime.clear();}
<DATETIME>[^#\n]+ {datetime += yytext;}
<DATETIME># {printf("Found a datetime literal: %s\n", datetime.c_str()); BEGIN(INITIAL);}

\[?({LETTER}|_[0-9A-Za-z_])[0-9A-Za-z_]*[%&@!#$]?\]? {printf("Found a identifier: %s\n", yytext);}


[\r\t ]+ {printf("Found a whitespace\n");}
[\r\t ]_[\r\t ]+\n+ {printf("Found a line continuation\n");}
\n+  {printf("Found end of line\n");}
<<EOF>> {printf("File ended"); yyterminate();}

%%

/*
TODO List:
+ Комментарии (Шашков)
+ Строки и символьные константы (Шашков)
+ Вещественные числа (Шашков)
+ Дата и время (Шашков)

+ Идентификаторы (Микулина)
Целые числа с обозначением типа и системы счисления (Микулина)
Логические значения (Микулина)
Зарезервированные слова, модификаторы (Микулина)
Скобки и управляющие символы (Микулина)

+ Продолжение строк (???) (Шашков)
*/

