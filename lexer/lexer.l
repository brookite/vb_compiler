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

AndAlso { debug_print("Found keyword : %s\n", yytext); return AND_ALSO; }
Byte { debug_print("Found keyword : %s\n", yytext); return BYTE_KW; }
CDate { debug_print("Found keyword : %s\n", yytext); return CDATE_KW; }
CInt { debug_print("Found keyword : %s\n", yytext); return CINTEGER_KW; }
Const { debug_print("Found keyword : %s\n", yytext); return CONST_KW; }
CSng { debug_print("Found keyword : %s\n", yytext); return CSINGLE_KW; }
CULng { debug_print("Found keyword : %s\n", yytext); return CULONG_KW; }
Else { debug_print("Found keyword : %s\n", yytext); return ELSE_KW; }
Exit { debug_print("Found keyword : %s\n", yytext); return EXIT_KW; }
In { debug_print("Found keyword : %s\n", yytext); return IN_KW; }
Is { debug_print("Found keyword : %s\n", yytext); return IS; }
Like { debug_print("Found keyword : %s\n", yytext); return LIKE; }
Mod { debug_print("Found keyword : %s\n", yytext); return MOD; }
MyBase { debug_print("Found keyword : %s\n", yytext); return MYBASE_KW; }
New { debug_print("Found keyword : %s\n", yytext); return NEW_KW; }
Or { debug_print("Found keyword : %s\n", yytext); return OR;  }
ReadOnly { debug_print("Found keyword : %s\n", yytext); return READONLY_KW; }
Single { debug_print("Found keyword : %s\n", yytext); return SINGLE_KW; }
String { debug_print("Found keyword : %s\n", yytext); return STRING_KW; }
Then { debug_print("Found keyword : %s\n", yytext); return THEN_KW; }
ULong { debug_print("Found keyword : %s\n", yytext); return ULONG_KW; }
As { debug_print("Found keyword : %s\n", yytext); return AS_KW; }
ByVal { debug_print("Found keyword : %s\n", yytext); return BYVAL_KW; }
CBool { debug_print("Found keyword : %s\n", yytext); return CBOOL_KW; }
CDbl { debug_print("Found keyword : %s\n", yytext); return CDOUBLE_KW; }
Class { debug_print("Found keyword : %s\n", yytext); return CLASS_KW; }
Continue { debug_print("Found keyword : %s\n", yytext); return CONTINUE_KW; }
CStr { debug_print("Found keyword : %s\n", yytext); return CSTRING_KW; }
CUShort { debug_print("Found keyword : %s\n", yytext); return CUSHORT_KW; }
Do { debug_print("Found keyword : %s\n", yytext); return DO_KW; }
ElseIf { debug_print("Found keyword : %s\n", yytext); return ELSEIF_KW; }
Erase { debug_print("Found keyword : %s\n", yytext); return ERASE_KW; }
Function { debug_print("Found keyword : %s\n", yytext); return FUNCTION_KW; }
If { debug_print("Found keyword : %s\n", yytext); return IF_KW; }
Inherits { debug_print("Found keyword : %s\n", yytext); return INHERITS_KW;  }
IsNot { debug_print("Found keyword : %s\n", yytext); return ISNOT; }
Long { debug_print("Found keyword : %s\n", yytext); return LONG_KW; }
MyClass { debug_print("Found keyword : %s\n", yytext); return MYCLASS_KW;  }
Next { debug_print("Found keyword : %s\n", yytext); return NEXT_KW; }
OrElse { debug_print("Found keyword : %s\n", yytext); return OR_ELSE; }
ParamArray { debug_print("Found keyword : %s\n", yytext); return PARAMARRAY_KW; }
Protected { debug_print("Found keyword : %s\n", yytext); return PROTECTED_KW; }
ReDim { debug_print("Found keyword : %s\n", yytext); return REDIM_KW; }
Return { debug_print("Found keyword : %s\n", yytext); return RETURN_KW; }
Static { debug_print("Found keyword : %s\n", yytext); return STATIC_KW; }
Structure { debug_print("Found keyword : %s\n", yytext); return STRUCT_KW; }
UShort { debug_print("Found keyword : %s\n", yytext); return USHORT_KW;  }
Boolean { debug_print("Found keyword : %s\n", yytext); return BOOLEAN_KW; }
Call { debug_print("Found keyword : %s\n", yytext); return CALL_KW; }
CByte { debug_print("Found keyword : %s\n", yytext); return CBYTE_KW; }
CLng { debug_print("Found keyword : %s\n", yytext); return CLONG_KW; }
CSByte { debug_print("Found keyword : %s\n", yytext); return CSBYTE_KW;  }
CType { debug_print("Found keyword : %s\n", yytext); return CTYPE_KW; }
Date { debug_print("Found keyword : %s\n", yytext); return DATE_KW; }
Double { debug_print("Found keyword : %s\n", yytext); return DOUBLE_KW; }
End { debug_print("Found keyword : %s\n", yytext); return END_KW; }
End[ ]+Function { debug_print("Found keyword : %s\n", yytext); return END_FUNCTION; }
End[ ]+Select { debug_print("Found keyword : %s\n", yytext); return END_SELECT; }
End[ ]+If { debug_print("Found keyword : %s\n", yytext); return END_IF; }
End[ ]+Sub { debug_print("Found keyword : %s\n", yytext); return END_SUB; }
End[ ]+While { debug_print("Found keyword : %s\n", yytext); return END_WHILE; }
Integer { debug_print("Found keyword : %s\n", yytext); return INTEGER_KW; }
Loop { debug_print("Found keyword : %s\n", yytext); return LOOP_KW; }
Not { debug_print("Found keyword : %s\n", yytext); return NOT; }
Object { debug_print("Found keyword : %s\n", yytext); return OBJECT_KW; }
Public { debug_print("Found keyword : %s\n", yytext); return PUBLIC_KW; }
SByte { debug_print("Found keyword : %s\n", yytext); return SBYTE_KW; }
Shared { debug_print("Found keyword : %s\n", yytext); return SHARED_KW; }
Step { debug_print("Found keyword : %s\n", yytext); return STEP_KW; }
Sub { debug_print("Found keyword : %s\n", yytext); return SUB_KW; }
To { debug_print("Found keyword : %s\n", yytext); return TO_KW; }
While { debug_print("Found keyword : %s\n", yytext); return WHILE_KW; }
And { debug_print("Found keyword : %s\n", yytext); return AND; }
ByRef { debug_print("Found keyword : %s\n", yytext); return BYREF_KW; }
Case { debug_print("Found keyword : %s\n", yytext); return CASE_KW; }
CChar { debug_print("Found keyword : %s\n", yytext); return CCHAR_KW; }
Char { debug_print("Found keyword : %s\n", yytext); return CHAR_KW; }
CObj { debug_print("Found keyword : %s\n", yytext); return COBJECT_KW; }
CShort { debug_print("Found keyword : %s\n", yytext); return CSHORT_KW; }
CUInt { debug_print("Found keyword : %s\n", yytext); return CUINTEGER_KW; }
Decimal { debug_print("Found keyword : %s\n", yytext); return DECIMAL_KW; }
Dim { debug_print("Found keyword : %s\n", yytext); return DIM_KW; }
Each { debug_print("Found keyword : %s\n", yytext); return EACH_KW; }
For { debug_print("Found keyword : %s\n", yytext); return FOR_KW; }
GoTo { debug_print("Found keyword : %s\n", yytext); return GOTO_KW; }
Me { debug_print("Found keyword : %s\n", yytext); return ME_KW; }
Of { debug_print("Found keyword : %s\n", yytext); return OF_KW; }
Optional { debug_print("Found keyword : %s\n", yytext); return OPTIONAL_KW; }
Private { debug_print("Found keyword : %s\n", yytext); return PRIVATE_KW; }
Select { debug_print("Found keyword : %s\n", yytext); return SELECT_KW; }
Short { debug_print("Found keyword : %s\n", yytext); return SHORT_KW; }
Stop { debug_print("Found keyword : %s\n", yytext); return STOP_KW; }
UInteger { debug_print("Found keyword : %s\n", yytext); return UINTEGER_KW; }
Xor { debug_print("Found keyword : %s\n", yytext); return XOR; }
Until { debug_print("Found keyword : %s\n", yytext); return UNTIL_KW; }

Nothing { debug_print("Found nothing literal\n"); return NOTHING; }
True { debug_print("Found boolean literal : %s\n", yytext); yylval.Bool = true; return BOOL; }
False { debug_print("Found boolean literal : %s\n", yytext); yylval.Bool = false; return BOOL; }

\^ {debug_print("Found a XOR operator: %s\n", yytext); return '^'; }
\* {debug_print("Found a MUL operator: %s\n", yytext); return '*'; }
\\ {debug_print("Found a FLOOR_DIV operator: %s\n", yytext); return '\\'; }
\/ {debug_print("Found a DIV operator: %s\n", yytext); return '/'; }
\+ {debug_print("Found a PLUS operator: %s\n", yytext); return '+'; }
\- {debug_print("Found a MINUS operator: %s\n", yytext); return '-'; }
\= { debug_print("Found an ASSIGNMENT operator: %s\n", yytext); return '='; }
\^= {debug_print("Found a XOR_ASSIGNMENT operator: %s\n", yytext); return EXP_ASSIGN; }
\*= {debug_print("Found a MUL_ASSIGNMENT operator: %s\n", yytext); return MUL_ASSIGN; }
\+= {debug_print("Found a ADD_ASSIGNMENT operator: %s\n", yytext); return ADD_ASSIGN; }
\-= {debug_print("Found a SUB_ASSIGNMENT operator: %s\n", yytext); return SUB_ASSIGN; }
\<= {debug_print("Found a LESS_EQUAL to operator: %s\n", yytext); return LEQ; }
\< {debug_print("Found a LESS operator: %s\n", yytext); return '<'; }
\> {debug_print("Found a GREATER operator: %s\n", yytext); return '>'; }
\>= {debug_print("Found a GREATER_EQUAL to operator: %s\n", yytext); return GEQ; }
\<\> {debug_print("Found a NOT_EQUAL to operator: %s\n", yytext); return NEQ; }
\& {debug_print("Found a STR_CONCAT operator: %s\n", yytext); return '&'; }
\&= {debug_print("Found a STR_CONCAT_ASSIGNMENT operator: %s\n", yytext); return STRCAT_ASSIGN; }
\>\>  {debug_print("Found a RSHIFT operator: %s\n", yytext); return RSHIFT; }
\<\< {debug_print("Found a LSHIFT operator: %s\n", yytext); return LSHIFT; }
\<\<= {debug_print("Found a LSHIFT_ASSIGNMENT operator: %s\n", yytext); return LSHIFT_ASSIGN; }
\>\>= {debug_print("Found a RSHIFT_ASSIGNMENT operator: %s\n", yytext); return RSHIFT_ASSIGN; }
\\= { debug_print("Found an FLOOR_DIV_ASSIGNMENT operator: %s\n", yytext); return FLOORDIV_ASSIGN; }
\/= {debug_print("Found a DIV_ASSIGNMENT operator: %s\n", yytext); return DIV_ASSIGN; }

\'|REM {BEGIN(COMMENT); comment.clear(); }
<COMMENT>[^\n]+ {comment += yytext;}
<COMMENT>\n {debug_print("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}
<COMMENT><<EOF>> {debug_print("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}

\" {BEGIN(STRING); strLiteral.clear();}
<STRING>[^\n"]+ {strLiteral += yytext;}
<STRING>\"\" {strLiteral += "\"";}
<STRING><<EOF>>	{debug_print("Error: String literal wasn't closed\n"); yyterminate();}
<STRING>\n	{
    debug_print("Error: String literal wasn't closed at line %d\n", yylineno - 1); 
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
        debug_print("Found a char literal: %s\n", strLiteral.c_str());
        BEGIN(INITIAL);
        yylval.Char = charValue;
        return CHAR;
    } else {
        debug_print("Error: character literal can have only one character, not string, line: %d\n", yylineno);
        if (!DEBUG) yyterminate();
    }
}
<STRING>\" {debug_print("Found a string literal: %s\n", strLiteral.c_str()); yylval.Str = new std::string(strLiteral); BEGIN(INITIAL); return STRING; }


{UNDERSCORE_NUMBER}\_+(S|US|I|UI|L|UL)? {
    debug_print("Error: invalid underscore character in number literal\n");
    if (!DEBUG) yyterminate();
}

&H{HEX_DIGIT}(\_*{HEX_DIGIT})*\_+(S|US|I|UI|L|UL)? {
    debug_print("Error: invalid underscore character in number literal\n");
    if (!DEBUG) yyterminate();
}

&O{OCT_DIGIT}(\_*{OCT_DIGIT})*\_+(S|US|I|UI|L|UL)? {
    debug_print("Error: invalid underscore character in number literal\n");
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
    intValue = atoi(intLiteral); debug_print("Found a integer value: %d\n", intValue);
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
    debug_print("Found a hex integer value: %d\n", intValue);
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
    debug_print("Found a oct integer value: %d\n", intValue);
    yylval.Int = intValue;
    return INT;
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?{EXPONENT}|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?) {
    std::string lexeme(yytext);
    removeUnderline(&lexeme);
    doubleValue = atof(lexeme.c_str());
    debug_print("Found floating point literal: %f\n", doubleValue);
    yylval.Float = doubleValue;
    return FLOAT;
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?({EXPONENT})?|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?)([Ff]|[Dd]|[Rr]) {
    char floatLiteral[10000];
    strncpy_s(floatLiteral, yytext, strlen(yytext) - 1);
    removeUnderline(floatLiteral);
    doubleValue = atof(floatLiteral);
    debug_print("Found floating point literal: %f\n", doubleValue);
    yylval.Float = doubleValue;
    return FLOAT;
}

{UNDERSCORE_NUMBER}(\_*(\.{UNDERSCORE_NUMBER}\_*)?({EXPONENT})?|({UNDERSCORE_NUMBER}\_*)?\.{UNDERSCORE_NUMBER}\_*({EXPONENT}\_*)?)([Ff]|[Dd]|[Rr])? {
    debug_print("Invalid float literal: %s at line %d\n", yytext, yylineno);
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
    debug_print("Found a datetime literal: \n");
    printDateTimeLiteral(*datetime);
    yylval.DateTime = datetime;
    return DATETIME;
}

\#[^\n]*\# {
    debug_print("Invalid datetime literal: %s\n", yytext);
    if (!DEBUG) yyterminate();
}

\#[^\n\#]* {
    debug_print("Datetime literal wasn't closed: %s\n", yytext);
    if (!DEBUG) yyterminate();
}

\( { debug_print("Found a separator left parenthesis: %s\n", yytext); return '(';}
\) {debug_print("Found a separator right parenthesis: %s\n", yytext); return ')';}
\{ {debug_print("Found a separator left curly brace: %s\n", yytext); return '{';}
\} { debug_print("Found a separator right curly brace: %s\n", yytext); return '}';}
\? {debug_print("Found a separator question mark: %s\n", yytext); return '?';}
\. {debug_print("Found a separator point: %s\n", yytext); return '.';}
\! {debug_print("Found a separator exclamation mark: %s\n", yytext); return '!'; }
\, { debug_print("Found a separator comma: %s\n", yytext); return ','; }
\: {debug_print("Found a separator colon: %s\n", yytext); return ':'; }

\[?({LETTER}|_[0-9A-Za-z_])[0-9A-Za-z_]*[%&@!#$]?\]? {
    debug_print("Found a identifier: %s\n", yytext);
    yylval.Id = new std::string(yytext);
    return ID;
}

[\r\t ]+ {}
[\r\t ]_[\r\t ]+\n+ {debug_print("Found a line continuation: %s\n", yytext);}
\n+ {debug_print("Found end of line %d\n\n", yylineno - 1); return ENDL; }
<<EOF>> {debug_print("File ended\n"); yyterminate();}

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
        debug_print("Month: %d\n", datetime.date->month);
        debug_print("Day: %d\n", datetime.date->day);
        debug_print("Year: %d\n", datetime.date->year);
    }
    if (datetime.time != nullptr) {
        debug_print("Hour: %d\n", datetime.time->hour);
        debug_print("Minute: %d\n", datetime.time->minute);
        debug_print("Second: %d\n", datetime.time->second);
        debug_print("Time format: ");
        if (datetime.time->format == AM) {
            debug_print("AM\n");
        }
        else if (datetime.time->format == PM) {
            debug_print("PM\n");
        }
        else {
            debug_print("24-hour format\n");
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
        debug_print("Processing file: %s\n", files[i]);
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