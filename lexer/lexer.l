%option nounistd
%option noyywrap
%option never-interactive
%option case-insensitive
%option yylineno

%{
    #include <string>
    #include <iostream>
    #include <regex>
    #include "../compiler/utils.hpp"
    #include "../parser/grammar.tab.h"
    #define YY_DECL int yylex()

    bool DEBUG = false;

    bool endsWith(const std::string & str, const std::string & suffix);
    void removeUnderline(std::string * str);
    void removeUnderline(char * str);

    void printDateTimeLiteral(DateTime& datetime);
%}


LETTER[A-Za-z]
DIGIT[0-9]
HEX_DIGIT[0-9A-Fa-f]
OCT_DIGIT[0-7]
EXPONENT[eE][+-]?[0-9](\_*[0-9])*
UNDERSCORE_NUMBER [0-9](\_*[0-9])*
WHITESPACE [\n\r\t ]
DATE(({DIGIT}{1,2})[\-\/]({DIGIT}{1,2})[\-\/]({DIGIT}{4}))
TIME({DIGIT}{1,2}:{DIGIT}{2}(:({DIGIT}{2}))?({WHITESPACE}*(AM|PM))?)
HOUR({DIGIT}{1,2}{WHITESPACE}*(AM|PM))


%x STRING
%x COMMENT

%%

%{
    std::string strLiteral;
    std::string comment;
    char charValue;
    long long intValue;
    double doubleValue;
    DateTime * datetime;

    int tempIntLiteral;
    int dateOrTimePositionIndex;
    bool boolLiteral;

%}

AndAlso { printf("Found keyword : %s\n", yytext); return AND_ALSO; }
Byte { printf("Found keyword : %s\n", yytext); return BYTE_KW; }
CDate { printf("Found keyword : %s\n", yytext); return CDATE_KW; }
CInt { printf("Found keyword : %s\n", yytext); return CINTEGER_KW; }
Const { printf("Found keyword : %s\n", yytext); return CONST_KW; }
CSng { printf("Found keyword : %s\n", yytext); return CSINGLE_KW; }
CULng { printf("Found keyword : %s\n", yytext); return CULONG_KW; }
Else { printf("Found keyword : %s\n", yytext); return ELSE_KW; }
Exit { printf("Found keyword : %s\n", yytext); return EXIT_KW; }
In { printf("Found keyword : %s\n", yytext); return IN_KW; }
Is { printf("Found keyword : %s\n", yytext); return IS; }
Like { printf("Found keyword : %s\n", yytext); return LIKE; }
Mod { printf("Found keyword : %s\n", yytext); return MOD; }
MyBase { printf("Found keyword : %s\n", yytext); return MYBASE_KW; }
New { printf("Found keyword : %s\n", yytext); return NEW_KW; }
Or { printf("Found keyword : %s\n", yytext); return OR;  }
ReadOnly { printf("Found keyword : %s\n", yytext); return READONLY_KW; }
Single { printf("Found keyword : %s\n", yytext); return SINGLE_KW; }
String { printf("Found keyword : %s\n", yytext); return STRING_KW; }
Then { printf("Found keyword : %s\n", yytext); return THEN_KW; }
ULong { printf("Found keyword : %s\n", yytext); return ULONG_KW; }
As { printf("Found keyword : %s\n", yytext); return AS_KW; }
ByVal { printf("Found keyword : %s\n", yytext); return BYVAL_KW; }
CBool { printf("Found keyword : %s\n", yytext); return CBOOL_KW; }
CDbl { printf("Found keyword : %s\n", yytext); return CDOUBLE_KW; }
Class { printf("Found keyword : %s\n", yytext); return CLASS_KW; }
Continue { printf("Found keyword : %s\n", yytext); return CONTINUE_KW; }
CStr { printf("Found keyword : %s\n", yytext); return CSTRING_KW; }
CUShort { printf("Found keyword : %s\n", yytext); return CUSHORT_KW; }
Do { printf("Found keyword : %s\n", yytext); return DO_KW; }
ElseIf { printf("Found keyword : %s\n", yytext); return ELSEIF_KW; }
Erase { printf("Found keyword : %s\n", yytext); return ERASE_KW; }
Function { printf("Found keyword : %s\n", yytext); return FUNCTION_KW; }
If { printf("Found keyword : %s\n", yytext); return IF_KW; }
Inherits { printf("Found keyword : %s\n", yytext); return INHERITS_KW;  }
IsNot { printf("Found keyword : %s\n", yytext); return ISNOT; }
Long { printf("Found keyword : %s\n", yytext); return LONG_KW; }
MyClass { printf("Found keyword : %s\n", yytext); return MYCLASS_KW;  }
Next { printf("Found keyword : %s\n", yytext); return NEXT_KW; }
OrElse { printf("Found keyword : %s\n", yytext); return OR_ELSE; }
ParamArray { printf("Found keyword : %s\n", yytext); return PARAMARRAY_KW; }
Protected { printf("Found keyword : %s\n", yytext); return PROTECTED_KW; }
ReDim { printf("Found keyword : %s\n", yytext); return REDIM_KW; }
Return { printf("Found keyword : %s\n", yytext); return RETURN_KW; }
Static { printf("Found keyword : %s\n", yytext); return STATIC_KW; }
Structure { printf("Found keyword : %s\n", yytext); return STRUCT_KW; }
UShort { printf("Found keyword : %s\n", yytext); return USHORT_KW;  }
Boolean { printf("Found keyword : %s\n", yytext); return BOOLEAN_KW; }
Call { printf("Found keyword : %s\n", yytext); return CALL_KW; }
CByte { printf("Found keyword : %s\n", yytext); return CBYTE_KW; }
CLng { printf("Found keyword : %s\n", yytext); return CLONG_KW; }
CSByte { printf("Found keyword : %s\n", yytext); return CSBYTE_KW;  }
CType { printf("Found keyword : %s\n", yytext); return CTYPE_KW; }
Date { printf("Found keyword : %s\n", yytext); return DATE_KW; }
Double { printf("Found keyword : %s\n", yytext); return DOUBLE_KW; }
End { printf("Found keyword : %s\n", yytext); return END_KW; }
End[ ]+Function { printf("Found keyword : %s\n", yytext); return END_FUNCTION; }
End[ ]+Select { printf("Found keyword : %s\n", yytext); return END_SELECT; }
End[ ]+If { printf("Found keyword : %s\n", yytext); return END_IF; }
End[ ]+Sub { printf("Found keyword : %s\n", yytext); return END_SUB; }
End[ ]+While { printf("Found keyword : %s\n", yytext); return END_WHILE; }
Integer { printf("Found keyword : %s\n", yytext); return INTEGER_KW; }
Loop { printf("Found keyword : %s\n", yytext); return LOOP_KW; }
Not { printf("Found keyword : %s\n", yytext); return NOT; }
Object { printf("Found keyword : %s\n", yytext); return OBJECT_KW; }
Public { printf("Found keyword : %s\n", yytext); return PUBLIC_KW; }
SByte { printf("Found keyword : %s\n", yytext); return SBYTE_KW; }
Shared { printf("Found keyword : %s\n", yytext); return SHARED_KW; }
Step { printf("Found keyword : %s\n", yytext); return STEP_KW; }
Sub { printf("Found keyword : %s\n", yytext); return SUB_KW; }
To { printf("Found keyword : %s\n", yytext); return TO_KW; }
While { printf("Found keyword : %s\n", yytext); return WHILE_KW; }
And { printf("Found keyword : %s\n", yytext); return AND; }
ByRef { printf("Found keyword : %s\n", yytext); return BYREF_KW; }
Case { printf("Found keyword : %s\n", yytext); return CASE_KW; }
CChar { printf("Found keyword : %s\n", yytext); return CCHAR_KW; }
Char { printf("Found keyword : %s\n", yytext); return CHAR_KW; }
CObj { printf("Found keyword : %s\n", yytext); return COBJECT_KW; }
CShort { printf("Found keyword : %s\n", yytext); return CSHORT_KW; }
CUInt { printf("Found keyword : %s\n", yytext); return CUINTEGER_KW; }
Decimal { printf("Found keyword : %s\n", yytext); return DECIMAL_KW; }
Dim { printf("Found keyword : %s\n", yytext); return DIM_KW; }
Each { printf("Found keyword : %s\n", yytext); return EACH_KW; }
For { printf("Found keyword : %s\n", yytext); return FOR_KW; }
GoTo { printf("Found keyword : %s\n", yytext); return GOTO_KW; }
Me { printf("Found keyword : %s\n", yytext); return ME_KW; }
Of { printf("Found keyword : %s\n", yytext); return OF_KW; }
Optional { printf("Found keyword : %s\n", yytext); return OPTIONAL_KW; }
Private { printf("Found keyword : %s\n", yytext); return PRIVATE_KW; }
Select { printf("Found keyword : %s\n", yytext); return SELECT_KW; }
Short { printf("Found keyword : %s\n", yytext); return SHORT_KW; }
Stop { printf("Found keyword : %s\n", yytext); return STOP_KW; }
UInteger { printf("Found keyword : %s\n", yytext); return UINTEGER_KW; }
Xor { printf("Found keyword : %s\n", yytext); return XOR; }
Until { printf("Found keyword : %s\n", yytext); return UNTIL_KW; }

Nothing { printf("Found nothing literal\n"); return NOTHING; }
True { printf("Found boolean literal : %s\n", yytext); yylval.Bool = true; return BOOL; }
False { printf("Found boolean literal : %s\n", yytext); yylval.Bool = false; return BOOL; }

\^ {printf("Found a XOR operator: %s\n", yytext); return '^'; }
\* {printf("Found a MUL operator: %s\n", yytext); return '*'; }
\\ {printf("Found a FLOOR_DIV operator: %s\n", yytext); return '\\'; }
\/ {printf("Found a DIV operator: %s\n", yytext); return '/'; }
\+ {printf("Found a PLUS operator: %s\n", yytext); return '+'; }
\- {printf("Found a MINUS operator: %s\n", yytext); return '-'; }
\= { printf("Found an ASSIGNMENT operator: %s\n", yytext); return '='; }
\^= {printf("Found a XOR_ASSIGNMENT operator: %s\n", yytext); return EXP_ASSIGN; }
\*= {printf("Found a MUL_ASSIGNMENT operator: %s\n", yytext); return MUL_ASSIGN; }
\+= {printf("Found a ADD_ASSIGNMENT operator: %s\n", yytext); return ADD_ASSIGN; }
\-= {printf("Found a SUB_ASSIGNMENT operator: %s\n", yytext); return SUB_ASSIGN; }
\<= {printf("Found a LESS_EQUAL to operator: %s\n", yytext); return LEQ; }
\< {printf("Found a LESS operator: %s\n", yytext); return '<'; }
\> {printf("Found a GREATER operator: %s\n", yytext); return '>'; }
\>= {printf("Found a GREATER_EQUAL to operator: %s\n", yytext); return GEQ; }
\<\> {printf("Found a NOT_EQUAL to operator: %s\n", yytext); return NEQ; }
\& {printf("Found a STR_CONCAT operator: %s\n", yytext); return '&'; }
\&= {printf("Found a STR_CONCAT_ASSIGNMENT operator: %s\n", yytext); return STRCAT_ASSIGN; }
\>\>  {printf("Found a RSHIFT operator: %s\n", yytext); return RSHIFT; }
\<\< {printf("Found a LSHIFT operator: %s\n", yytext); return LSHIFT; }
\<\<= {printf("Found a LSHIFT_ASSIGNMENT operator: %s\n", yytext); return LSHIFT_ASSIGN; }
\>\>= {printf("Found a RSHIFT_ASSIGNMENT operator: %s\n", yytext); return RSHIFT_ASSIGN; }
\\= { printf("Found an FLOOR_DIV_ASSIGNMENT operator: %s\n", yytext); return FLOORDIV_ASSIGN; }
\/= {printf("Found a DIV_ASSIGNMENT operator: %s\n", yytext); return DIV_ASSIGN; }

\'|REM {BEGIN(COMMENT); comment.clear(); }
<COMMENT>[^\n]+ {comment += yytext;}
<COMMENT>\n {printf("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}
<COMMENT><<EOF>> {printf("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}

\" {BEGIN(STRING); strLiteral.clear();}
<STRING>[^\n"]+ {strLiteral += yytext;}
<STRING>\"\" {strLiteral += "\"";}
<STRING><<EOF>>	{printf("Error: String literal wasn't closed\n"); yyterminate();}
<STRING>\n	{
    printf("Error: String literal wasn't closed at line %d\n", yylineno - 1); 
    if (!DEBUG) {
        yyterminate();
    }
    else {
        BEGIN(INITIAL);
    }
}
<STRING>\"[Cc] {
    if (strLiteral.length() == 1) {
        charValue = strLiteral.at(0);
        printf("Found a char literal: %s\n", strLiteral.c_str());
        BEGIN(INITIAL);
        yylval.Char = charValue;
        return CHAR;
    } else {
        printf("Error: character literal can have only one character, not string, line: %d\n", yylineno);
        if (!DEBUG) yyterminate();
    }
}
<STRING>\" {printf("Found a string literal: %s\n", strLiteral.c_str()); yylval.Str = new std::string(strLiteral); BEGIN(INITIAL); return STRING; }


{UNDERSCORE_NUMBER}\_+(S|US|I|UI|L|UL)? {
    printf("Error: invalid underscore character in number literal\n");
    if (!DEBUG) yyterminate();
}

&H{HEX_DIGIT}(\_*{HEX_DIGIT})*\_+(S|US|I|UI|L|UL)? {
    printf("Error: invalid underscore character in number literal\n");
    if (!DEBUG) yyterminate();
}

&O{OCT_DIGIT}(\_*{OCT_DIGIT})*\_+(S|US|I|UI|L|UL)? {
    printf("Error: invalid underscore character in number literal\n");
    if (!DEBUG) yyterminate();
}


{UNDERSCORE_NUMBER}(S|US|I|UI|L|UL)? {
    char intLiteral[10000];
    std::string lexeme(yytext);

    if (endsWith(lexeme, "US") || endsWith(lexeme, "UI") || endsWith(lexeme, "UL")) {
        strncpy_s(intLiteral, yytext, strlen(yytext) - 2);
    } else if (endsWith(lexeme, "S") || endsWith(lexeme, "I") || endsWith(lexeme, "L")) {
        strncpy_s(intLiteral, yytext, strlen(yytext - 1));
    } else {
        strcpy_s(intLiteral, yytext);
    }

    removeUnderline(intLiteral);
    intValue = atoi(intLiteral); printf("Found a integer value: %d\n", intValue);
    yylval.Int = intValue;
    return INT;
}

&H{HEX_DIGIT}(\_*{HEX_DIGIT})*(S|US|I|UI|L|UL)? {
    char intLiteral[10000];
    std::string lexeme(yytext);

    if (endsWith(lexeme, "US") || endsWith(lexeme, "UI") || endsWith(lexeme, "UL")) {
        strncpy_s(intLiteral, yytext, strlen(yytext) - 2);
    } else if (endsWith(lexeme, "S") || endsWith(lexeme, "I") || endsWith(lexeme, "L")) {
        strncpy_s(intLiteral, yytext, strlen(yytext - 1));
    } else {
        strcpy_s(intLiteral, yytext);
    }

    removeUnderline(intLiteral);
    intValue = strtol(intLiteral + 2, NULL, 16);
    printf("Found a hex integer value: %d\n", intValue);
    yylval.Int = intValue;
    return INT;
}

&O{OCT_DIGIT}(\_*{OCT_DIGIT})*(S|US|I|UI|L|UL)? {
    char intLiteral[10000];
    std::string lexeme(yytext);

    if (endsWith(lexeme, "US") || endsWith(lexeme, "UI") || endsWith(lexeme, "UL")) {
        strncpy_s(intLiteral, yytext, strlen(yytext) - 2);
    } else if (endsWith(lexeme, "S") || endsWith(lexeme, "I") || endsWith(lexeme, "L")) {
        strncpy_s(intLiteral, yytext, strlen(yytext - 1));
    } else {
        strcpy_s(intLiteral, yytext);
    }

    removeUnderline(intLiteral);
    intValue = strtol(intLiteral + 2, NULL, 8);
    printf("Found a oct integer value: %d\n", intValue);
    yylval.Int = intValue;
    return INT;
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?{EXPONENT}|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?) {
    std::string lexeme(yytext);
    removeUnderline(&lexeme);
    doubleValue = atof(lexeme.c_str());
    printf("Found floating point literal: %f\n", doubleValue);
    yylval.Float = doubleValue;
    return FLOAT;
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?({EXPONENT})?|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?)([Ff]|[Dd]|[Rr]) {
    char floatLiteral[10000];
    strncpy_s(floatLiteral, yytext, strlen(yytext) - 1);
    removeUnderline(floatLiteral);
    doubleValue = atof(floatLiteral);
    printf("Found floating point literal: %f\n", doubleValue);
    yylval.Float = doubleValue;
    return FLOAT;
}

{UNDERSCORE_NUMBER}(\_*(\.{UNDERSCORE_NUMBER}\_*)?({EXPONENT})?|({UNDERSCORE_NUMBER}\_*)?\.{UNDERSCORE_NUMBER}\_*({EXPONENT}\_*)?)([Ff]|[Dd]|[Rr])? {
    printf("Invalid float literal: %s at line %d\n", yytext, yylineno);
    if (!DEBUG) yyterminate();
}

\#{WHITESPACE}*({DATE}{WHITESPACE}+{TIME}|{DATE}|{TIME}|{HOUR}){WHITESPACE}*\# {
    std::regex date_regex(R"((\d{1,2})[\-\/](\d{1,2})[\-\/](\d{4}))");
    std::regex time_regex(R"((\d{1,2}):(\d{2})(:(\d{2}))?(\s*(AM|PM))?)");
    std::regex hour_regex(R"((\d{1,2})\s*(AM|PM))");

    std::smatch match;
    std::string text(yytext);

    Date * date = nullptr;
    Time * time = nullptr;

    if (std::regex_search(text, match, date_regex)) {
        date = new Date();
        date->day = std::stoi(match[2].str());
        date->month = std::stoi(match[1].str());
        date->year = std::stoi(match[3].str());
    }

    if (std::regex_search(text, match, hour_regex)) {
        time = new Time();
        time->hour = std::stoi(match[1].str());

        if (match[2].str() == "AM") {
            time->format = AM;
        }
        else if (match[2].str() == "PM") {
            time->format = PM;
        }
    }

    if (std::regex_search(text, match, time_regex)) {
        time = new Time();
        time->hour = std::stoi(match[1].str());
        time->minute = std::stoi(match[2].str());
        time->second = match[4].matched ? std::stoi(match[4].str()) : 0;

        if (match[6].matched) {
            if (match[6].str() == "AM") {
                time->format = AM;
            }
            else if (match[6].str() == "PM") {
                time->format = PM;
            }
        }
    }


    datetime = new DateTime();
    datetime->date = date;
    datetime->time = time;
    printf("Found a datetime literal: \n");
    printDateTimeLiteral(*datetime);
    yylval.DateTime = datetime;
    return DATETIME;
}

\#[^\n]*\# {
    printf("Invalid datetime literal: %s\n", yytext);
    if (!DEBUG) yyterminate();
}

\#[^\n\#]* {
    printf("Datetime literal wasn't closed: %s\n", yytext);
    if (!DEBUG) yyterminate();
}

\( { printf("Found a separator left parenthesis: %s\n", yytext); }
\) {printf("Found a separator right parenthesis: %s\n", yytext);}
\{ {printf("Found a separator left curly brace: %s\n", yytext); }
\} { printf("Found a separator right curly brace: %s\n", yytext); }
\? {printf("Found a separator question mark: %s\n", yytext); }
\. {printf("Found a separator point: %s\n", yytext); }
\! {printf("Found a separator exclamation mark: %s\n", yytext); }
\, { printf("Found a separator comma: %s\n", yytext); }
\: {printf("Found a separator colon: %s\n", yytext); }

\[?({LETTER}|_[0-9A-Za-z_])[0-9A-Za-z_]*[%&@!#$]?\]? {
    printf("Found a identifier: %s\n", yytext);
    yylval.Id = new std::string(yytext);
    return ID;
}

[\r\t ]+ {}
[\r\t ]_[\r\t ]+\n+ {printf("Found a line continuation: %s\n", yytext);}
\n+ {printf("Found end of line %d\n\n", yylineno - 1); return ENDL; }
<<EOF>> {printf("File ended\n"); yyterminate();}

%%

void removeUnderline(std::string* str) {
    if (str == nullptr) {
        return; 
    }
    str->erase(std::remove(str->begin(), str->end(), '_'), str->end());
}

void removeUnderline(char* str) {
    if (str == nullptr) {
        return; 
    }

    char* writePtr = str;
    char* readPtr = str;

    while (*readPtr != '\0') {
        if (*readPtr != '_') {
            *writePtr = *readPtr;
            writePtr++;
        }
        readPtr++;
    }

    *writePtr = '\0';
}


bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void printDateTimeLiteral(DateTime & datetime) {
    if (datetime.date != nullptr) {
        printf("Month: %d\n", datetime.date->month);
        printf("Day: %d\n", datetime.date->day);
        printf("Year: %d\n", datetime.date->year);
    }
    if (datetime.time != nullptr) {
        printf("Hour: %d\n", datetime.time->hour);
        printf("Minute: %d\n", datetime.time->minute);
        printf("Second: %d\n", datetime.time->second);
        printf("Time format: ");
        if (datetime.time->format == AM) {
            printf("AM\n");
        }
        else if (datetime.time->format == PM) {
            printf("PM\n");
        }
        else {
            printf("24-hour format\n");
        }
    }
}

void runTests() {
    DEBUG = true;
    const char* files[] = {
        "lexer/tests/lexer_comment_test.vb",
        "lexer/tests/lexer_literal_test.vb",
        "lexer/tests/lexer_string_test.vb",
        "lexer/tests/lexer_identifier_test.vb",
        "lexer/tests/lexer_datetime_test.vb",
        "lexer/tests/lexer_program1_test.vb",
        "lexer/tests/lexer_program2_test.vb",
        "lexer/tests/lexer_program3_test.vb",
    };
    int numFiles = sizeof(files) / sizeof(files[0]);
    for (int i = 0; i < numFiles; i++) {
        fopen_s(&yyin, files[i], "r");
        printf("Processing file: %s\n", files[i]);
        yylex();
        fclose(yyin);
        BEGIN(INITIAL);
        yylineno = 1;
    }
}


/*
TODO List:
+ Комментарии (Шашков)
+ Строки и символьные константы (Шашков)
+ Вещественные числа (Шашков)
+ Идентификаторы (Шашков)
+ Продолжение строк (Шашков)
+ Целые числа с обозначением типа и системы счисления (Шашков)
+ Ошибки (номер строки, ошибочные символы) (Шашков)
+ Мелкие улучшения (Шашков)

+ Часть тестов (Микулина)
+ Логические значения (Микулина)
+ Дата и время (Микулина)
+ Зарезервированные слова, модификаторы (Микулина)
+ Скобки и управляющие символы (Микулина)
*/