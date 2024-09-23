%option nounistd
%option noyywrap
%option never-interactive
%option case-insensitive
%option yylineno

%{
    #include <string>
    #define YY_DECL int yylex()

    bool endsWith(const std::string& str, const std::string& suffix)
    {
        return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

%}


LETTER[A-Za-z]
DIGIT[0-9]
HEX_DIGIT[0-9A-Fa-f]
OCT_DIGIT[0-7]
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
    long long intValue;
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
<STRING>\n	{printf("Error: String literal wasn't closed at line %d\n", yylineno - 1); yyterminate();}
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

[+-]?{DIGIT}+(S|US|I|UI|L|UL)? {
    char intLiteral[10000];
    std::string lexeme(yytext);

    if (endsWith(lexeme, "US") || endsWith(lexeme, "UI") || endsWith(lexeme, "UL")) {
        strncpy_s(intLiteral, yytext, strlen(yytext) - 2);
    } else if (endsWith(lexeme, "S") || endsWith(lexeme, "I") || endsWith(lexeme, "L")) {
        strncpy_s(intLiteral, yytext, strlen(yytext - 1));
    } else {
        strcpy_s(intLiteral, yytext);
    }

    intValue = atoi(intLiteral); printf("Found a integer value: %d\n", intValue);
}

&H{HEX_DIGIT}+(S|US|I|UI|L|UL)? {
    char intLiteral[10000];
    std::string lexeme(yytext);

    if (endsWith(lexeme, "US") || endsWith(lexeme, "UI") || endsWith(lexeme, "UL")) {
        strncpy_s(intLiteral, yytext, strlen(yytext) - 2);
    } else if (endsWith(lexeme, "S") || endsWith(lexeme, "I") || endsWith(lexeme, "L")) {
        strncpy_s(intLiteral, yytext, strlen(yytext - 1));
    } else {
        strcpy_s(intLiteral, yytext);
    }

    intValue = strtol(intLiteral + 2, NULL, 16);
    printf("Found a hex integer value: %d\n", intValue);
}

&O{OCT_DIGIT}+(S|US|I|UI|L|UL)? {
    char intLiteral[10000];
    std::string lexeme(yytext);

    if (endsWith(lexeme, "US") || endsWith(lexeme, "UI") || endsWith(lexeme, "UL")) {
        strncpy_s(intLiteral, yytext, strlen(yytext) - 2);
    } else if (endsWith(lexeme, "S") || endsWith(lexeme, "I") || endsWith(lexeme, "L")) {
        strncpy_s(intLiteral, yytext, strlen(yytext - 1));
    } else {
        strcpy_s(intLiteral, yytext);
    }

    intValue = strtol(intLiteral + 2, NULL, 8);
    printf("Found a hex integer value: %d\n", intValue);
}

[+-]?({DIGIT}+(\.{DIGIT}+)?{EXPONENT}|{DIGIT}*\.{DIGIT}+({EXPONENT})?) {
    doubleValue = atof(yytext);
    printf("Found floating point literal: %f\n", doubleValue);
}

[+-]?({DIGIT}+(\.{DIGIT}+)?{EXPONENT}|{DIGIT}*\.{DIGIT}+({EXPONENT})?)([Ff]|[Dd]|[Rr]) {
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
\n+  {printf("Found end of line %d\n", yylineno - 1);}
<<EOF>> {printf("File ended"); yyterminate();}

%%

/*
TODO List:
+ Комментарии (Шашков)
+ Строки и символьные константы (Шашков)
+ Вещественные числа (Шашков)
+ Идентификаторы (Шашков)
+ Продолжение строк (Шашков)
+ Целые числа с обозначением типа и системы счисления (Шашков)

Логические значения (Микулина)
Дата и время (Микулина)
Зарезервированные слова, модификаторы (Микулина)
Скобки и управляющие символы (Микулина)
*/

