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

    void removeUnderline(std::string * str);
    void removeUnderline(char * str);

    void printDateTimeLiteral(DateTime& datetime);

    bool LEXER_DEBUG = false;

    // Система флагов, которая позволяет определять когда '=' это присваивание, а когда проверка равенства
    bool new_stmt = true; // выставляется каждый раз, когда встречается новый statement
    bool blocking_kw = false; // иногда у If, While и т.п. скобок у expr может не быть, и первое '=' учтется как присваивание, хотя это не так
    bool in_brace = false; // определяет находится ли лексер внутри скобок, если да, то всегда = - это сравнение
    bool in_compound = false; // гарантирует, чтобы первый statement внутри составных операторов (If, For, ...) мог быть присваиванием 
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

AndAlso { lexer_print("Found keyword : %s\n", yytext); return AND_ALSO; }
Byte { lexer_print("Found keyword : %s\n", yytext); return BYTE_KW; }
CDate { lexer_print("Found keyword : %s\n", yytext); return CDATE_KW; }
CInt { lexer_print("Found keyword : %s\n", yytext); return CINTEGER_KW; }
Const { lexer_print("Found keyword : %s\n", yytext); return CONST_KW; }
CSng { lexer_print("Found keyword : %s\n", yytext); return CSINGLE_KW; }
CULng { lexer_print("Found keyword : %s\n", yytext); return CULONG_KW; }
Else { lexer_print("Found keyword : %s\n", yytext); in_compound = true; return ELSE_KW; }
Exit { lexer_print("Found keyword : %s\n", yytext); return EXIT_KW; }
In { lexer_print("Found keyword : %s\n", yytext); in_compound = true; return IN_KW; }
Is { lexer_print("Found keyword : %s\n", yytext); return IS; }
Like { lexer_print("Found keyword : %s\n", yytext); return LIKE; }
Mod { lexer_print("Found keyword : %s\n", yytext); return MOD; }
MyBase { lexer_print("Found keyword : %s\n", yytext); return MYBASE_KW; }
New { lexer_print("Found keyword : %s\n", yytext); return NEW_KW; }
Or { lexer_print("Found keyword : %s\n", yytext); return OR;  }
ReadOnly { lexer_print("Found keyword : %s\n", yytext); return READONLY_KW; }
Single { lexer_print("Found keyword : %s\n", yytext); return SINGLE_KW; }
String { lexer_print("Found keyword : %s\n", yytext); return STRING_KW; }
Then { lexer_print("Found keyword : %s\n", yytext); new_stmt = true; return THEN_KW; }
ULong { lexer_print("Found keyword : %s\n", yytext); return ULONG_KW; }
As { lexer_print("Found keyword : %s\n", yytext); return AS_KW; }
ByVal { lexer_print("Found keyword : %s\n", yytext); return BYVAL_KW; }
CBool { lexer_print("Found keyword : %s\n", yytext); return CBOOL_KW; }
CDbl { lexer_print("Found keyword : %s\n", yytext); return CDOUBLE_KW; }
Class { lexer_print("Found keyword : %s\n", yytext); return CLASS_KW; }
Continue { lexer_print("Found keyword : %s\n", yytext); return CONTINUE_KW; }
CStr { lexer_print("Found keyword : %s\n", yytext); return CSTRING_KW; }
CUShort { lexer_print("Found keyword : %s\n", yytext); return CUSHORT_KW; }
Do { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; in_compound = true; return DO_KW; }
ElseIf { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; in_compound = true; return ELSEIF_KW; }
Erase { lexer_print("Found keyword : %s\n", yytext); return ERASE_KW; }
Function { lexer_print("Found keyword : %s\n", yytext); return FUNCTION_KW; }
If { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; in_compound = true; return IF_KW; }
Inherits { lexer_print("Found keyword : %s\n", yytext); return INHERITS_KW;  }
IsNot { lexer_print("Found keyword : %s\n", yytext); return ISNOT; }
Long { lexer_print("Found keyword : %s\n", yytext); return LONG_KW; }
MyClass { lexer_print("Found keyword : %s\n", yytext); return MYCLASS_KW;  }
Next { lexer_print("Found keyword : %s\n", yytext); return NEXT_KW; }
OrElse { lexer_print("Found keyword : %s\n", yytext); return OR_ELSE; }
ParamArray { lexer_print("Found keyword : %s\n", yytext); return PARAMARRAY_KW; }
Protected { lexer_print("Found keyword : %s\n", yytext); return PROTECTED_KW; }
ReDim { lexer_print("Found keyword : %s\n", yytext); return REDIM_KW; }
Return { lexer_print("Found keyword : %s\n", yytext); return RETURN_KW; }
Static { lexer_print("Found keyword : %s\n", yytext); return STATIC_KW; }
Structure { lexer_print("Found keyword : %s\n", yytext); return STRUCT_KW; }
UShort { lexer_print("Found keyword : %s\n", yytext); return USHORT_KW;  }
Boolean { lexer_print("Found keyword : %s\n", yytext); return BOOLEAN_KW; }
Call { lexer_print("Found keyword : %s\n", yytext); return CALL_KW; }
CByte { lexer_print("Found keyword : %s\n", yytext); return CBYTE_KW; }
CLng { lexer_print("Found keyword : %s\n", yytext); return CLONG_KW; }
CSByte { lexer_print("Found keyword : %s\n", yytext); return CSBYTE_KW;  }
CType { lexer_print("Found keyword : %s\n", yytext); return CTYPE_KW; }
Date { lexer_print("Found keyword : %s\n", yytext); return DATE_KW; }
Double { lexer_print("Found keyword : %s\n", yytext); return DOUBLE_KW; }
End { lexer_print("Found keyword : %s\n", yytext); return END_KW; }
End[ ]+Function { lexer_print("Found keyword : %s\n", yytext); return END_FUNCTION; }
End[ ]+Select { lexer_print("Found keyword : %s\n", yytext); return END_SELECT; }
End[ ]+If { lexer_print("Found keyword : %s\n", yytext); return END_IF; }
End[ ]+Sub { lexer_print("Found keyword : %s\n", yytext); return END_SUB; }
End[ ]+While { lexer_print("Found keyword : %s\n", yytext); return END_WHILE; }
Integer { lexer_print("Found keyword : %s\n", yytext); return INTEGER_KW; }
Loop { lexer_print("Found keyword : %s\n", yytext); return LOOP_KW; }
Not { lexer_print("Found keyword : %s\n", yytext); return NOT; }
Object { lexer_print("Found keyword : %s\n", yytext); return OBJECT_KW; }
Public { lexer_print("Found keyword : %s\n", yytext); return PUBLIC_KW; }
SByte { lexer_print("Found keyword : %s\n", yytext); return SBYTE_KW; }
Shared { lexer_print("Found keyword : %s\n", yytext); return SHARED_KW; }
Step { lexer_print("Found keyword : %s\n", yytext); return STEP_KW; }
Sub { lexer_print("Found keyword : %s\n", yytext); return SUB_KW; }
To { lexer_print("Found keyword : %s\n", yytext); in_compound = true; return TO_KW; }
While { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; in_compound = true; return WHILE_KW; }
And { lexer_print("Found keyword : %s\n", yytext); return AND; }
ByRef { lexer_print("Found keyword : %s\n", yytext); return BYREF_KW; }
Case { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; in_compound = true; return CASE_KW; }
CChar { lexer_print("Found keyword : %s\n", yytext); return CCHAR_KW; }
Char { lexer_print("Found keyword : %s\n", yytext); return CHAR_KW; }
CObj { lexer_print("Found keyword : %s\n", yytext); return COBJECT_KW; }
CShort { lexer_print("Found keyword : %s\n", yytext); return CSHORT_KW; }
CUInt { lexer_print("Found keyword : %s\n", yytext); return CUINTEGER_KW; }
Decimal { lexer_print("Found keyword : %s\n", yytext); return DECIMAL_KW; }
Dim { lexer_print("Found keyword : %s\n", yytext); return DIM_KW; }
Each { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; return EACH_KW; }
For { lexer_print("Found keyword : %s\n", yytext); in_compound = true; return FOR_KW; }
GoTo { lexer_print("Found keyword : %s\n", yytext); return GOTO_KW; }
Me { lexer_print("Found keyword : %s\n", yytext); return ME_KW; }
Of { lexer_print("Found keyword : %s\n", yytext); return OF_KW; }
Optional { lexer_print("Found keyword : %s\n", yytext); return OPTIONAL_KW; }
Private { lexer_print("Found keyword : %s\n", yytext); return PRIVATE_KW; }
Select { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; return SELECT_KW; }
Short { lexer_print("Found keyword : %s\n", yytext); return SHORT_KW; }
Stop { lexer_print("Found keyword : %s\n", yytext); return STOP_KW; }
UInteger { lexer_print("Found keyword : %s\n", yytext); return UINTEGER_KW; }
Xor { lexer_print("Found keyword : %s\n", yytext); return XOR; }
Until { lexer_print("Found keyword : %s\n", yytext); blocking_kw = true; return UNTIL_KW; }

Nothing { lexer_print("Found nothing literal\n"); return NOTHING; }
True { lexer_print("Found boolean literal : %s\n", yytext); yylval.Bool = true; return BOOL; }
False { lexer_print("Found boolean literal : %s\n", yytext); yylval.Bool = false; return BOOL; }

\^ {lexer_print("Found a XOR operator: %s\n", yytext); return '^'; }
\* {lexer_print("Found a MUL operator: %s\n", yytext); return '*'; }
\\ {lexer_print("Found a FLOOR_DIV operator: %s\n", yytext); return '\\'; }
\/ {lexer_print("Found a DIV operator: %s\n", yytext); return '/'; }
\+ {lexer_print("Found a PLUS operator: %s\n", yytext); return '+'; }
\- {lexer_print("Found a MINUS operator: %s\n", yytext); return '-'; }
\= {
    if (new_stmt && !in_brace && !blocking_kw) {
        lexer_print("Found an assignment operator: %s\n", yytext); 
        new_stmt = false;
        return '='; 
    }
    if (blocking_kw) {
        blocking_kw = false;
        new_stmt = false;
    }
    lexer_print("Found an equality operator: %s\n", yytext); 
    return EQ;
}
\^= {lexer_print("Found a XOR_ASSIGNMENT operator: %s\n", yytext); return EXP_ASSIGN; }
\*= {lexer_print("Found a MUL_ASSIGNMENT operator: %s\n", yytext); return MUL_ASSIGN; }
\+= {lexer_print("Found a ADD_ASSIGNMENT operator: %s\n", yytext); return ADD_ASSIGN; }
\-= {lexer_print("Found a SUB_ASSIGNMENT operator: %s\n", yytext); return SUB_ASSIGN; }
\<= {lexer_print("Found a LESS_EQUAL to operator: %s\n", yytext); return LEQ; }
\< {lexer_print("Found a LESS operator: %s\n", yytext); return '<'; }
\> {lexer_print("Found a GREATER operator: %s\n", yytext); return '>'; }
\>= {lexer_print("Found a GREATER_EQUAL to operator: %s\n", yytext); return GEQ; }
\<\> {lexer_print("Found a NOT_EQUAL to operator: %s\n", yytext); return NEQ; }
\& {lexer_print("Found a STR_CONCAT operator: %s\n", yytext); return '&'; }
\&= {lexer_print("Found a STR_CONCAT_ASSIGNMENT operator: %s\n", yytext); return STRCAT_ASSIGN; }
\>\>  {lexer_print("Found a RSHIFT operator: %s\n", yytext); return RSHIFT; }
\<\< {lexer_print("Found a LSHIFT operator: %s\n", yytext); return LSHIFT; }
\<\<= {lexer_print("Found a LSHIFT_ASSIGNMENT operator: %s\n", yytext); return LSHIFT_ASSIGN; }
\>\>= {lexer_print("Found a RSHIFT_ASSIGNMENT operator: %s\n", yytext); return RSHIFT_ASSIGN; }
\\= { lexer_print("Found an FLOOR_DIV_ASSIGNMENT operator: %s\n", yytext); return FLOORDIV_ASSIGN; }
\/= {lexer_print("Found a DIV_ASSIGNMENT operator: %s\n", yytext); return DIV_ASSIGN; }

\'|REM {BEGIN(COMMENT); comment.clear(); }
<COMMENT>[^\n]+ {comment += yytext;}
<COMMENT>\n {lexer_print("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}
<COMMENT><<EOF>> {lexer_print("Found a comment: %s\n", comment.c_str()); BEGIN(INITIAL);}

\" {BEGIN(STRING); strLiteral.clear();}
<STRING>[^\n"]+ {strLiteral += yytext;}
<STRING>\"\" {strLiteral += "\"";}
<STRING><<EOF>>	{lexer_print("Error: String literal wasn't closed\n"); yyterminate();}
<STRING>\n	{
    lexer_print("Error: String literal wasn't closed at line %d\n", yylineno - 1); 
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
        lexer_print("Found a char literal: %s\n", strLiteral.c_str());
        BEGIN(INITIAL);
        yylval.Char = charValue;
        return CHAR;
    } else {
        lexer_print("Error: character literal can have only one character, not string, line: %d\n", yylineno);
        if (!DEBUG) yyterminate();
    }
}
<STRING>\" {lexer_print("Found a string literal: %s\n", strLiteral.c_str()); yylval.Str = new std::string(strLiteral); BEGIN(INITIAL); lexer_print("%d", STR); return STR; }


{UNDERSCORE_NUMBER}\_+(S|US|I|UI|L|UL)? {
    lexer_print("Error: invalid underscore character in number literal\n");
    if (!DEBUG) yyterminate();
}

&H{HEX_DIGIT}(\_*{HEX_DIGIT})*\_+(S|US|I|UI|L|UL)? {
    lexer_print("Error: invalid underscore character in number literal\n");
    if (!DEBUG) yyterminate();
}

&O{OCT_DIGIT}(\_*{OCT_DIGIT})*\_+(S|US|I|UI|L|UL)? {
    lexer_print("Error: invalid underscore character in number literal\n");
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
    intValue = atoi(intLiteral); lexer_print("Found a integer value: %d\n", intValue);
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
    lexer_print("Found a hex integer value: %d\n", intValue);
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
    lexer_print("Found a oct integer value: %d\n", intValue);
    yylval.Int = intValue;
    return INT;
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?{EXPONENT}|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?) {
    std::string lexeme(yytext);
    removeUnderline(&lexeme);
    doubleValue = atof(lexeme.c_str());
    lexer_print("Found floating point literal: %f\n", doubleValue);
    yylval.Float = doubleValue;
    return FLOAT;
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?({EXPONENT})?|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?)([Ff]|[Dd]|[Rr]) {
    char floatLiteral[10000];
    strncpy_s(floatLiteral, yytext, strlen(yytext) - 1);
    removeUnderline(floatLiteral);
    doubleValue = atof(floatLiteral);
    lexer_print("Found floating point literal: %f\n", doubleValue);
    yylval.Float = doubleValue;
    return FLOAT;
}

{UNDERSCORE_NUMBER}(\_*(\.{UNDERSCORE_NUMBER}\_*)?({EXPONENT})?|({UNDERSCORE_NUMBER}\_*)?\.{UNDERSCORE_NUMBER}\_*({EXPONENT}\_*)?)([Ff]|[Dd]|[Rr])? {
    lexer_print("Invalid float literal: %s at line %d\n", yytext, yylineno);
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
    lexer_print("Found a datetime literal: \n");
    printDateTimeLiteral(*datetime);
    yylval.DateTime = datetime;
    return DATETIME;
}

\#[^\n]*\# {
    lexer_print("Invalid datetime literal: %s\n", yytext);
    if (!DEBUG) yyterminate();
}

\#[^\n\#]* {
    lexer_print("Datetime literal wasn't closed: %s\n", yytext);
    if (!DEBUG) yyterminate();
}

\( { lexer_print("Found a separator left parenthesis: %s\n", yytext); in_brace = true; return '(';}
\) {lexer_print("Found a separator right parenthesis: %s\n", yytext); in_brace = false; return ')';}
\{ {lexer_print("Found a separator left curly brace: %s\n", yytext); in_brace = true; return '{';}
\} { lexer_print("Found a separator right curly brace: %s\n", yytext); in_brace = false; return '}';}
\? {lexer_print("Found a separator question mark: %s\n", yytext); return '?';}
\. {lexer_print("Found a separator point: %s\n", yytext); return '.';}
\! {lexer_print("Found a separator exclamation mark: %s\n", yytext); return '!'; }
\, { lexer_print("Found a separator comma: %s\n", yytext); return ','; }
\: {lexer_print("Found a separator colon: %s\n", yytext); return ':'; }

\[?({LETTER}|_[0-9A-Za-z_])[0-9A-Za-z_]*[%&@!#$]?\]? {
    lexer_print("Found a identifier: %s\n", yytext);
    yylval.Id = new std::string(yytext);
    return ID;
}

[\r\t ]+ {}
[\r\t ]_[\r\t ]+\n+ {lexer_print("Found a line continuation: %s\n", yytext);}
\n+ {
    lexer_print("Found end of line %d\n\n", yylineno - 1);
    if (in_compound) {
        in_compound = false;
        new_stmt = true;
        lexer_print("Set new statement in compound statement");
    }
    blocking_kw = false;
    return ENDL; 
}
<<EOF>> {lexer_print("File ended\n"); yyterminate();}

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


void printDateTimeLiteral(DateTime & datetime) {
    if (datetime.date != nullptr) {
        lexer_print("Month: %d\n", datetime.date->month);
        lexer_print("Day: %d\n", datetime.date->day);
        lexer_print("Year: %d\n", datetime.date->year);
    }
    if (datetime.time != nullptr) {
        lexer_print("Hour: %d\n", datetime.time->hour);
        lexer_print("Minute: %d\n", datetime.time->minute);
        lexer_print("Second: %d\n", datetime.time->second);
        lexer_print("Time format: ");
        if (datetime.time->format == AM) {
            lexer_print("AM\n");
        }
        else if (datetime.time->format == PM) {
            lexer_print("PM\n");
        }
        else {
            lexer_print("24-hour format\n");
        }
    }
}

void runLexerTests() {
    LEXER_DEBUG = true;
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
        lexer_print("Processing file: %s\n", files[i]);
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