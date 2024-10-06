%option nounistd
%option noyywrap
%option never-interactive
%option case-insensitive
%option yylineno

%{
    #include <string>
    #define YY_DECL int yylex()

    bool DEBUG = false;

    bool endsWith(const std::string & str, const std::string & suffix);
    void removeUnderline(std::string * str);
    void removeUnderline(char * str);

    struct Date {
        int day = 0;
        int month = 0;
        int year = -1;
    };

    enum TimeFormat {
        AM, PM, HOURS_24
    };

    struct Time {
        int hour = 0;
        int minute = 0;
        int second = 0;
        TimeFormat format = HOURS_24;
    };

    struct DateTime {
        Date* date = nullptr;
        Time* time = nullptr;
    };

    void printDateTimeLiteral(DateTime& datetime);
%}


LETTER[A-Za-z]
DIGIT[0-9]
HEX_DIGIT[0-9A-Fa-f]
OCT_DIGIT[0-7]
EXPONENT[eE][+-]?[0-9](\_*[0-9])*
UNDERSCORE_NUMBER [0-9](\_*[0-9])*

%x STRING
%x COMMENT
%x DATETIME
%x DATE
%x TIME

%%

%{
    std::string strLiteral;
    std::string comment;
    char charValue;
    long long intValue;
    double doubleValue;
    DateTime datetime;

    int tempIntLiteral;
    int dateOrTimePositionIndex;

%}

AddHandler {printf("Found keyword : %s\n", yytext);}
AndAlso {printf("Found keyword : %s\n", yytext);}
Byte {printf("Found keyword : %s\n", yytext);}
Catch {printf("Found keyword : %s\n", yytext);}
CDate {printf("Found keyword : %s\n", yytext);}
CInt {printf("Found keyword : %s\n", yytext);}
Const {printf("Found keyword : %s\n", yytext);}
CSng {printf("Found keyword : %s\n", yytext);}
CULng {printf("Found keyword : %s\n", yytext);}
Declare {printf("Found keyword : %s\n", yytext);}
DirectCast {printf("Found keyword : %s\n", yytext);}
Else {printf("Found keyword : %s\n", yytext);}
Enum {printf("Found keyword : %s\n", yytext);}
Exit {printf("Found keyword : %s\n", yytext);}
Friend {printf("Found keyword : %s\n", yytext);}
GetXmlNamespace {printf("Found keyword : %s\n", yytext);}
Handles {printf("Found keyword : %s\n", yytext);}
In {printf("Found keyword : %s\n", yytext);}
Is {printf("Found keyword : %s\n", yytext);}
Like {printf("Found keyword : %s\n", yytext);}
Mod {printf("Found keyword : %s\n", yytext);}
MyBase {printf("Found keyword : %s\n", yytext);}
New {printf("Found keyword : %s\n", yytext);}
NotInheritable {printf("Found keyword : %s\n", yytext);}
On {printf("Found keyword : %s\n", yytext);}
Or {printf("Found keyword : %s\n", yytext);}
Overrides {printf("Found keyword : %s\n", yytext);}
Property {printf("Found keyword : %s\n", yytext);}
ReadOnly {printf("Found keyword : %s\n", yytext);}
Resume {printf("Found keyword : %s\n", yytext);}
Set {printf("Found keyword : %s\n", yytext);}
Single {printf("Found keyword : %s\n", yytext);}
String {printf("Found keyword : %s\n", yytext);}
Then {printf("Found keyword : %s\n", yytext);}
Try {printf("Found keyword : %s\n", yytext);}
ULong {printf("Found keyword : %s\n", yytext);}
Wend {printf("Found keyword : %s\n", yytext);}    
With {printf("Found keyword : %s\n", yytext);}
AddressOf {printf("Found keyword : %s\n", yytext);}
As {printf("Found keyword : %s\n", yytext);}
ByVal {printf("Found keyword : %s\n", yytext);}
CBool {printf("Found keyword : %s\n", yytext);}
CDbl {printf("Found keyword : %s\n", yytext);}
Class {printf("Found keyword : %s\n", yytext);}
Continue {printf("Found keyword : %s\n", yytext);}
CStr {printf("Found keyword : %s\n", yytext);}
CUShort {printf("Found keyword : %s\n", yytext);}
Default {printf("Found keyword : %s\n", yytext);}
Do {printf("Found keyword : %s\n", yytext);}
ElseIf {printf("Found keyword : %s\n", yytext);}
Erase {printf("Found keyword : %s\n", yytext);}
Function {printf("Found keyword : %s\n", yytext);}
Global {printf("Found keyword : %s\n", yytext);}
If {printf("Found keyword : %s\n", yytext);}
Inherits {printf("Found keyword : %s\n", yytext);}
IsNot {printf("Found keyword : %s\n", yytext);}
Long {printf("Found keyword : %s\n", yytext);}
Module {printf("Found keyword : %s\n", yytext);}
MyClass {printf("Found keyword : %s\n", yytext);}
Next {printf("Found keyword : %s\n", yytext);}
NotOverridable {printf("Found keyword : %s\n", yytext);}
Operator {printf("Found keyword : %s\n", yytext);}
OrElse {printf("Found keyword : %s\n", yytext);}
ParamArray {printf("Found keyword : %s\n", yytext);}
Protected {printf("Found keyword : %s\n", yytext);}
ReDim {printf("Found keyword : %s\n", yytext);}
Return {printf("Found keyword : %s\n", yytext);}
Shadows {printf("Found keyword : %s\n", yytext);}
Static {printf("Found keyword : %s\n", yytext);}
Structure {printf("Found keyword : %s\n", yytext);}
Throw {printf("Found keyword : %s\n", yytext);}
TryCast {printf("Found keyword : %s\n", yytext);}
UShort {printf("Found keyword : %s\n", yytext);}
When {printf("Found keyword : %s\n", yytext);}
WithEvents {printf("Found keyword : %s\n", yytext);}
Alias {printf("Found keyword : %s\n", yytext);}
Boolean {printf("Found keyword : %s\n", yytext);}
Call {printf("Found keyword : %s\n", yytext);}
CByte {printf("Found keyword : %s\n", yytext);}
CDec {printf("Found keyword : %s\n", yytext);}
CLng {printf("Found keyword : %s\n", yytext);}
CSByte {printf("Found keyword : %s\n", yytext);}
CType {printf("Found keyword : %s\n", yytext);}
Date {printf("Found keyword : %s\n", yytext);}
Delegate {printf("Found keyword : %s\n", yytext);}
Double {printf("Found keyword : %s\n", yytext);}
End {printf("Found keyword : %s\n", yytext);}
Error {printf("Found keyword : %s\n", yytext);}
Get {printf("Found keyword : %s\n", yytext);}
Finally {printf("Found keyword : %s\n", yytext);}
GoSub {printf("Found keyword : %s\n", yytext);} 
Implements {printf("Found keyword : %s\n", yytext);}
Integer {printf("Found keyword : %s\n", yytext);}
Let {printf("Found keyword : %s\n", yytext);}   
Loop {printf("Found keyword : %s\n", yytext);}
MustInherit {printf("Found keyword : %s\n", yytext);}
Namespace {printf("Found keyword : %s\n", yytext);}
Not {printf("Found keyword : %s\n", yytext);}
Object {printf("Found keyword : %s\n", yytext);}
Option {printf("Found keyword : %s\n", yytext);}
Overloads {printf("Found keyword : %s\n", yytext);}
Partial {printf("Found keyword : %s\n", yytext);}
Public {printf("Found keyword : %s\n", yytext);}
SByte {printf("Found keyword : %s\n", yytext);}
Shared {printf("Found keyword : %s\n", yytext);}
Step {printf("Found keyword : %s\n", yytext);}
Sub {printf("Found keyword : %s\n", yytext);}
To {printf("Found keyword : %s\n", yytext);}
TypeOf {printf("Found keyword : %s\n", yytext);}
Using {printf("Found keyword : %s\n", yytext);}
While {printf("Found keyword : %s\n", yytext);}
WriteOnly {printf("Found keyword : %s\n", yytext);}
And {printf("Found keyword : %s\n", yytext);}
ByRef {printf("Found keyword : %s\n", yytext);}
Case {printf("Found keyword : %s\n", yytext);}
CChar {printf("Found keyword : %s\n", yytext);}
Char {printf("Found keyword : %s\n", yytext);}
CObj {printf("Found keyword : %s\n", yytext);}
CShort {printf("Found keyword : %s\n", yytext);}
CUInt {printf("Found keyword : %s\n", yytext);}
Decimal {printf("Found keyword : %s\n", yytext);}
Dim {printf("Found keyword : %s\n", yytext);}
Each {printf("Found keyword : %s\n", yytext);}
EndIf {printf("Found keyword : %s\n", yytext);} 
Event {printf("Found keyword : %s\n", yytext);}
For {printf("Found keyword : %s\n", yytext);}
GetType {printf("Found keyword : %s\n", yytext);}
GoTo {printf("Found keyword : %s\n", yytext);}
Imports {printf("Found keyword : %s\n", yytext);}
Interface {printf("Found keyword : %s\n", yytext);}
Lib {printf("Found keyword : %s\n", yytext);}
Me {printf("Found keyword : %s\n", yytext);}
MustOverride {printf("Found keyword : %s\n", yytext);}
Narrowing {printf("Found keyword : %s\n", yytext);}
Of {printf("Found keyword : %s\n", yytext);}
Optional {printf("Found keyword : %s\n", yytext);}
Overridable {printf("Found keyword : %s\n", yytext);}
Private {printf("Found keyword : %s\n", yytext);}
RaiseEvent {printf("Found keyword : %s\n", yytext);}
RemoveHandler {printf("Found keyword : %s\n", yytext);}
Select {printf("Found keyword : %s\n", yytext);}
Short {printf("Found keyword : %s\n", yytext);}
Stop {printf("Found keyword : %s\n", yytext);}
SyncLock {printf("Found keyword : %s\n", yytext);}
UInteger {printf("Found keyword : %s\n", yytext);}
Variant {printf("Found keyword : %s\n", yytext);} 
Widening {printf("Found keyword : %s\n", yytext);}
Xor {printf("Found keyword : %s\n", yytext);}

Nothing {printf("Found nothing literal\n");}
True {printf("Found boolean literal : %s\n", yytext);}
False {printf("Found boolean literal : %s\n", yytext);}


\^ {printf("Found a XOR operator: %s\n", yytext);}
\* {printf("Found a MUL operator: %s\n", yytext);}
\\ {printf("Found a FLOOR_DIV operator: %s\n", yytext);}
\/ {printf("Found a DIV operator: %s\n", yytext);}
\+ {printf("Found a PLUS operator: %s\n", yytext);}
\- {printf("Found a MINUS operator: %s\n", yytext);}
\= {printf("Found an ASSIGNMENT operator: %s\n", yytext);}
\^= {printf("Found a XOR_ASSIGNMENT operator: %s\n", yytext);}
\*= {printf("Found a MUL_ASSIGNMENT operator: %s\n", yytext);}
\+= {printf("Found a ADD_ASSIGNMENT operator: %s\n", yytext);}
\-= {printf("Found a SUB_ASSIGNMENT operator: %s\n", yytext);}
\<= {printf("Found a LESS_EQUAL to operator: %s\n", yytext);}
\< {printf("Found a LESS operator: %s\n", yytext);}
\> {printf("Found a GREATER operator: %s\n", yytext);}
\>= {printf("Found a GREATER_EQUAL to operator: %s\n", yytext);}
\<\> {printf("Found a NOT_EQUAL to operator: %s\n", yytext);}
\& {printf("Found a STR_CONCAT operator: %s\n", yytext);}
\&= {printf("Found a STR_CONCAT_ASSIGNMENT operator: %s\n", yytext);}
\>\> {printf("Found a RSHIFT operator: %s\n", yytext);}
\<\< {printf("Found a LSHIFT operator: %s\n", yytext);}
\<\<= {printf("Found a LSHIFT_ASSIGNMENT operator: %s\n", yytext);}
\>\>= {printf("Found a RSHIFT_ASSIGNMENT operator: %s\n", yytext);}
\\= {printf("Found an FLOOR_DIV_ASSIGNMENT operator: %s\n", yytext);}
\/= {printf("Found a DIV_ASSIGNMENT operator: %s\n", yytext);}

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
    } else {
        printf("Error: character literal can have only one character, not string, line: %d\n", yylineno);
        if (!DEBUG) yyterminate();
    }
}
<STRING>\" {printf("Found a string literal: %s\n", strLiteral.c_str()); BEGIN(INITIAL);}


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
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?{EXPONENT}|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?) {
    std::string lexeme(yytext);
    removeUnderline(&lexeme);
    doubleValue = atof(lexeme.c_str());
    printf("Found floating point literal: %f\n", doubleValue);
}

({UNDERSCORE_NUMBER}(\.{UNDERSCORE_NUMBER})?{EXPONENT}|({UNDERSCORE_NUMBER})?\.{UNDERSCORE_NUMBER}({EXPONENT})?)([Ff]|[Dd]|[Rr]) {
    char floatLiteral[10000];
    strncpy_s(floatLiteral, yytext, strlen(yytext) - 1);
    removeUnderline(floatLiteral);
    doubleValue = atof(floatLiteral);
    printf("Found floating point literal: %f\n", doubleValue);
}

({UNDERSCORE_NUMBER}(\_+)?(\.{UNDERSCORE_NUMBER}(\_+)?)?{EXPONENT}|({UNDERSCORE_NUMBER}(\_+)?)?\.{UNDERSCORE_NUMBER}(\_+)?({EXPONENT}(\_+)?)?)([Ff]|[Dd]|[Rr])? {
    printf("Invalid float literal: %s at line %d\n", yytext, yylineno);
    if (!DEBUG) yyterminate();
}

# {BEGIN(DATETIME); datetime = DateTime(); printf("Found opening datetime literal lexeme\n");}
<DATETIME>[\r\t ]+ {printf("Found a whitespace inside datetime literal\n");}
<DATETIME>{DIGIT}+ {
    tempIntLiteral = atoi(yytext);
    dateOrTimePositionIndex = 0;
}
<DATETIME>AM {
    datetime.time = new Time();
    datetime.time->hour = tempIntLiteral;
    datetime.time->format = AM;
    tempIntLiteral = -1;
}
<DATETIME>PM {
    datetime.time = new Time();
    datetime.time->hour = tempIntLiteral;
    datetime.time->format = PM;
    tempIntLiteral = -1;
}
<DATETIME>[/\-] {
    if (datetime.time != nullptr) {
        printf("Error: Time must not be declared before date, line: %d\n", yylineno);
        if (!DEBUG) yyterminate();
    }
    datetime.date = new Date();
    datetime.date->month = tempIntLiteral;
    dateOrTimePositionIndex++;
    BEGIN(DATE);
}
<DATETIME,DATE>{DIGIT}+ {
    tempIntLiteral = atoi(yytext);
}
<DATETIME,DATE>[/\-] {
    switch (dateOrTimePositionIndex) {
        case 1:
            datetime.date->day = tempIntLiteral;
            break;
        default:
            printf("Error: date has more digit literal than required: %d\n", yylineno);
            if (!DEBUG) yyterminate();
    }
    dateOrTimePositionIndex++;
}
<DATETIME,DATE>[\r\t ]+ {
    if (dateOrTimePositionIndex < 2) {
        printf("Error: Missing date components\n");
        if (!DEBUG) yyterminate();
    }
    datetime.date->year = tempIntLiteral;
    BEGIN(INITIAL);
    BEGIN(DATETIME);
    tempIntLiteral = -1;
}
<DATETIME>: {
    BEGIN(TIME);
    datetime.time = new Time();
    datetime.time->hour = tempIntLiteral;
    dateOrTimePositionIndex++;
}

<DATETIME,TIME>{DIGIT}+ {
    tempIntLiteral = atoi(yytext);
}
<DATETIME,TIME>: {
    switch (dateOrTimePositionIndex) {
        case 1:
            datetime.time->minute = tempIntLiteral;
            break;
        default:
            printf("Error: time has more digit literal than required: %d\n", yylineno);
            if (!DEBUG) yyterminate();
    };
    dateOrTimePositionIndex++;
}
<DATETIME,TIME>AM {
    datetime.time->format = AM;
}
<DATETIME,TIME>PM {
    datetime.time->format = PM;
}
<DATETIME,TIME>[/\-]+ {
    printf("Error: date literal characters in time literal: %d\n", yylineno);
    if (!DEBUG) yyterminate();
}

<DATETIME># {
    if (datetime.date == nullptr && datetime.time == nullptr) {
        printf("Error: Unrecognized date literal at line %d\n", yylineno);
        if (!DEBUG) yyterminate();
    }
    if (tempIntLiteral != -1) {
        printf("Error: Unrecognized int literal: %d at line %d\n", tempIntLiteral, yylineno);
    }
    printf("Found a datetime literal:\n");
    printDateTimeLiteral(datetime);
    printf("Found closing datetime literal lexeme\n");
    BEGIN(INITIAL);
}

<DATETIME,DATE># {
    if (dateOrTimePositionIndex < 2) {
        printf("Error: Missing date components: %d\n", yylineno);
        if (!DEBUG) yyterminate();
    }
    datetime.date->year = tempIntLiteral;
    printf("Found a date literal:\n");
    printDateTimeLiteral(datetime);
    printf("Found closing datetime literal lexeme\n");
    BEGIN(INITIAL);
}

<DATETIME,TIME># {
    if (dateOrTimePositionIndex < 1) {
        printf("Error: Missing time components: %d\n", yylineno);
    } else if (dateOrTimePositionIndex == 1) {
        datetime.time->minute = tempIntLiteral;
    } else if (dateOrTimePositionIndex == 2) {
        datetime.time->second = tempIntLiteral;
    }
    printf("Found a datetime literal:\n");
    printDateTimeLiteral(datetime);
    printf("Found closing datetime literal lexeme\n");
    BEGIN(INITIAL);
}

<DATETIME>[^/:\-0-9#\r\t\n ]+ {
    printf("Error: invalid characters in datetime literal at line %d: %s\n", yylineno, yytext);
    if (!DEBUG) yyterminate();
}

<DATETIME,TIME>[^/:\-0-9#\r\t\n ]+ {
    printf("Error: invalid characters in datetime literal at line %d: %s\n", yylineno, yytext);
    if (!DEBUG) yyterminate();
}

<DATETIME,DATE>[^/:\-0-9#\r\t\n ]+ {
    printf("Error: invalid characters in datetime literal at line %d: %s\n", yylineno, yytext);
    if (!DEBUG) yyterminate();
}

<DATETIME>\n {printf("Error: line break in datetime literal at line %d\n", yylineno);}
<DATETIME><<EOF>> {printf("Error: unexpected file end in datetime literal at line %d\n", yylineno); yyterminate(); }

<DATETIME,TIME>\n {printf("Error: line break in datetime literal at line %d\n", yylineno); if (!DEBUG) yyterminate(); }
<DATETIME,DATE>\n { printf("Error: line break in datetime literal at line %d\n", yylineno); }


\( { printf("Found a separator left parenthesis: %s\n", yytext); }
\) {printf("Found a separator right parenthesis: %s\n", yytext);}
\{ {printf("Found a separator left curly brace: %s\n", yytext); }
\} { printf("Found a separator right curly brace: %s\n", yytext); }
\? {printf("Found a separator question mark: %s\n", yytext); }
\. {printf("Found a separator point: %s\n", yytext); }
\! {printf("Found a separator exclamation mark: %s\n", yytext); }
\, { printf("Found a separator comma: %s\n", yytext); }
\: {printf("Found a separator colon: %s\n", yytext); }

\[?({LETTER}|_[0-9A-Za-z_])[0-9A-Za-z_]*[%&@!#$]?\]? {printf("Found a identifier: %s\n", yytext);}

[\r\t ]+ {printf("Found a whitespace\n");}
[\r\t ]_[\r\t ]+\n+ {printf("Found a line continuation: %s\n", yytext);}
\n+  {printf("Found end of line %d\n\n", yylineno - 1);}
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

void printDateTimeLiteral(DateTime& datetime) {
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

int main(int argc, char** argv) {
    if (argc > 1) {
        if (strcmp(argv[1], "--debug") == 0) {
            runTests();
            return 0;
        }
        fopen_s(&yyin, argv[1], "r");
        yylex();
    }
    else {
        printf("File not found");
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