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

%%

%{
    std::string strLiteral;
    std::string datetime;
    std::string comment;
    char charValue;
    double doubleValue;
%}

\'|REM {BEGIN(COMMENT); comment.clear(); }
<COMMENT>[^\n]+ {comment += yytext;}
<COMMENT>\n {printf("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}
<COMMENT><<EOF>> {printf("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}

\" {BEGIN(STRING); strLiteral.clear();}
<STRING>[^\n\\"]+ {strLiteral += yytext;}
<STRING>\\\\ {strLiteral += "\\";}
<STRING>\\n {strLiteral += "\n";}
<STRING>\\r {strLiteral += "\r";}
<STRING>\\t {strLiteral += "\t";}
<STRING>\\b {strLiteral += "\b";}
<STRING>\"\" {strLiteral += "\"";}
<STRING>\\x{HEX_DIGIT}{2} {strLiteral += (char) strtol(yytext + 2, NULL, 16);}
<STRING><<EOF>>	{printf("Error: String literal wasn't closed\n"); yyterminate();}
<STRING>\n	{printf("Error: String literal wasn't closed\n"); yyterminate();}
<STRING>\"[Cc] {
    if (strLiteral.length() == 1) {
        charValue = strLiteral.at(0);
        printf("Found a char literal: %s\n", strLiteral.c_str());
        BEGIN(INITIAL);
    } else {
        printf("Error: character literal can have only one character, not string");
        yyterminate();
    }
}
<STRING>\" {printf("Found a string literal: %s\n", strLiteral.c_str()); BEGIN(INITIAL);}


[+-]?({DIGIT}+\.?{DIGIT}*|{DIGIT}*\.?{DIGIT}+)({EXPONENT})? {
    doubleValue = atof(yytext);
    printf("Found floating point literal: %f\n", doubleValue);
}

[+-]?({DIGIT}+\.?{DIGIT}*|{DIGIT}*\.?{DIGIT}+)({EXPONENT})?[Ff] {
    char floatLiteral[10000];
    strncpy_s(floatLiteral, yytext, strlen(yytext) - 1);
    doubleValue = atof(floatLiteral);
    printf("Found floating point literal: %f\n", doubleValue);
}

[+-]?({DIGIT}+\.?{DIGIT}*|{DIGIT}*\.?{DIGIT}+)({EXPONENT})?[Dd] {
    char floatLiteral[10000];
    strncpy_s(floatLiteral, yytext, strlen(yytext) - 1);
    doubleValue = atof(floatLiteral);
    printf("Found floating point literal: %f\n", doubleValue);
}

[+-]?({DIGIT}+\.?{DIGIT}*|{DIGIT}*\.?{DIGIT}+)({EXPONENT})?[Rr] {
    char floatLiteral[10000];
    strncpy_s(floatLiteral, yytext, strlen(yytext) - 1);
    doubleValue = atof(floatLiteral);
    printf("Found floating point literal: %f\n", doubleValue);
}

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
+ Идентификаторы (Шашков)
+ Продолжение строк (Шашков)
Целые числа с обозначением типа и системы счисления (Шашков)

Логические значения (Микулина)
Зарезервированные слова, модификаторы (Микулина)
Скобки и управляющие символы (Микулина)
*/

