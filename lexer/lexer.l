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

AddHandler {printf(" Found keyword : %s\n", yytext);}
AndAlso {printf(" Found keyword : %s\n", yytext);}
Byte {printf(" Found keyword : %s\n", yytext);}
Catch {printf(" Found keyword : %s\n", yytext);}
CDate {printf(" Found keyword : %s\n", yytext);}
CInt {printf(" Found keyword : %s\n", yytext);}
Const {printf(" Found keyword : %s\n", yytext);}
CSng {printf(" Found keyword : %s\n", yytext);}
CULng {printf(" Found keyword : %s\n", yytext);}
Declare {printf(" Found keyword : %s\n", yytext);}
DirectCast {printf(" Found keyword : %s\n", yytext);}
Else {printf(" Found keyword : %s\n", yytext);}
Enum {printf(" Found keyword : %s\n", yytext);}
Exit {printf(" Found keyword : %s\n", yytext);}
Friend {printf(" Found keyword : %s\n", yytext);}
GetXmlNamespace {printf(" Found keyword : %s\n", yytext);}
Handles {printf(" Found keyword : %s\n", yytext);}
In {printf(" Found keyword : %s\n", yytext);}
Is {printf(" Found keyword : %s\n", yytext);}
Like {printf(" Found keyword : %s\n", yytext);}
Mod {printf(" Found keyword : %s\n", yytext);}
MyBase {printf(" Found keyword : %s\n", yytext);}
New {printf(" Found keyword : %s\n", yytext);}
NotInheritable {printf(" Found keyword : %s\n", yytext);}
On {printf(" Found keyword : %s\n", yytext);}
Or {printf(" Found keyword : %s\n", yytext);}
Overrides {printf(" Found keyword : %s\n", yytext);}
Property {printf(" Found keyword : %s\n", yytext);}
ReadOnly {printf(" Found keyword : %s\n", yytext);}
Resume {printf(" Found keyword : %s\n", yytext);}
Set {printf(" Found keyword : %s\n", yytext);}
Single {printf(" Found keyword : %s\n", yytext);}
String {printf(" Found keyword : %s\n", yytext);}
Then {printf(" Found keyword : %s\n", yytext);}
Try {printf(" Found keyword : %s\n", yytext);}
ULong {printf(" Found keyword : %s\n", yytext);}
Wend {printf(" Found keyword : %s\n", yytext);}    
With {printf(" Found keyword : %s\n", yytext);}
AddressOf {printf(" Found keyword : %s\n", yytext);}
As {printf(" Found keyword : %s\n", yytext);}
ByVal {printf(" Found keyword : %s\n", yytext);}
CBool {printf(" Found keyword : %s\n", yytext);}
CDbl {printf(" Found keyword : %s\n", yytext);}
Class {printf(" Found keyword : %s\n", yytext);}
Continue {printf(" Found keyword : %s\n", yytext);}
CStr {printf(" Found keyword : %s\n", yytext);}
CUShort {printf(" Found keyword : %s\n", yytext);}
Default {printf(" Found keyword : %s\n", yytext);}
Do {printf(" Found keyword : %s\n", yytext);}
ElseIf {printf(" Found keyword : %s\n", yytext);}
Erase {printf(" Found keyword : %s\n", yytext);}
False {printf(" Found keyword : %s\n", yytext);}
Function {printf(" Found keyword : %s\n", yytext);}
Global {printf(" Found keyword : %s\n", yytext);}
If {printf(" Found keyword : %s\n", yytext);}
Inherits {printf(" Found keyword : %s\n", yytext);}
IsNot {printf(" Found keyword : %s\n", yytext);}
Long {printf(" Found keyword : %s\n", yytext);}
Module {printf(" Found keyword : %s\n", yytext);}
MyClass {printf(" Found keyword : %s\n", yytext);}
Next {printf(" Found keyword : %s\n", yytext);}
NotOverridable {printf(" Found keyword : %s\n", yytext);}
Operator {printf(" Found keyword : %s\n", yytext);}
OrElse {printf(" Found keyword : %s\n", yytext);}
ParamArray {printf(" Found keyword : %s\n", yytext);}
Protected {printf(" Found keyword : %s\n", yytext);}
ReDim {printf(" Found keyword : %s\n", yytext);}
Return {printf(" Found keyword : %s\n", yytext);}
Shadows {printf(" Found keyword : %s\n", yytext);}
Static {printf(" Found keyword : %s\n", yytext);}
Structure {printf(" Found keyword : %s\n", yytext);}
Throw {printf(" Found keyword : %s\n", yytext);}
TryCast {printf(" Found keyword : %s\n", yytext);}
UShort {printf(" Found keyword : %s\n", yytext);}
When {printf(" Found keyword : %s\n", yytext);}
WithEvents {printf(" Found keyword : %s\n", yytext);}
Alias {printf(" Found keyword : %s\n", yytext);}
Boolean {printf(" Found keyword : %s\n", yytext);}
Call {printf(" Found keyword : %s\n", yytext);}
CByte {printf(" Found keyword : %s\n", yytext);}
CDec {printf(" Found keyword : %s\n", yytext);}
CLng {printf(" Found keyword : %s\n", yytext);}
CSByte{printf(" Found keyword : %s\n", yytext);}
CType {printf(" Found keyword : %s\n", yytext);}
Date {printf(" Found keyword : %s\n", yytext);}
Delegate {printf(" Found keyword : %s\n", yytext);}
Double {printf(" Found keyword : %s\n", yytext);}
End {printf(" Found keyword : %s\n", yytext);}
Error {printf(" Found keyword : %s\n", yytext);}
Get {printf(" Found keyword : %s\n", yytext);}
Finally {printf(" Found keyword : %s\n", yytext);}
GoSub {printf(" Found keyword : %s\n", yytext);} 
Implements {printf(" Found keyword : %s\n", yytext);}
Integer {printf(" Found keyword : %s\n", yytext);}
Let {printf(" Found keyword : %s\n", yytext);}   
Loop {printf(" Found keyword : %s\n", yytext);}
MustInherit {printf(" Found keyword : %s\n", yytext);}
Namespace {printf(" Found keyword : %s\n", yytext);}
Not {printf(" Found keyword : %s\n", yytext);}
Object {printf(" Found keyword : %s\n", yytext);}
Option {printf(" Found keyword : %s\n", yytext);}
Overloads {printf(" Found keyword : %s\n", yytext);}
Partial {printf(" Found keyword : %s\n", yytext);}
Public {printf(" Found keyword : %s\n", yytext);}
REM {printf(" Found keyword : %s\n", yytext);}
SByte {printf(" Found keyword : %s\n", yytext);}
Shared{printf(" Found keyword : %s\n", yytext);}
Step {printf(" Found keyword : %s\n", yytext);}
Sub {printf(" Found keyword : %s\n", yytext);}
To {printf(" Found keyword : %s\n", yytext);}
TypeOf {printf(" Found keyword : %s\n", yytext);}
Using {printf(" Found keyword : %s\n", yytext);}
While {printf(" Found keyword : %s\n", yytext);}
WriteOnly {printf(" Found keyword : %s\n", yytext);}
And {printf(" Found keyword : %s\n", yytext);}
ByRef {printf(" Found keyword : %s\n", yytext);}
Case {printf(" Found keyword : %s\n", yytext);}
CChar {printf(" Found keyword : %s\n", yytext);}
Char {printf(" Found keyword : %s\n", yytext);}
CObj {printf(" Found keyword : %s\n", yytext);}
CShort {printf(" Found keyword : %s\n", yytext);}
CUInt {printf(" Found keyword : %s\n", yytext);}
Decimal {printf(" Found keyword : %s\n", yytext);}
Dim {printf(" Found keyword : %s\n", yytext);}
Each {printf(" Found keyword : %s\n", yytext);}
EndIf {printf(" Found keyword : %s\n", yytext);} 
Event {printf(" Found keyword : %s\n", yytext);}
For {printf(" Found keyword : %s\n", yytext);}
GetType {printf(" Found keyword : %s\n", yytext);}
GoTo {printf(" Found keyword : %s\n", yytext);}
Imports {printf(" Found keyword : %s\n", yytext);}
Interface {printf(" Found keyword : %s\n", yytext);}
Lib {printf(" Found keyword : %s\n", yytext);}
Me {printf(" Found keyword : %s\n", yytext);}
MustOverride {printf(" Found keyword : %s\n", yytext);}
Narrowing {printf(" Found keyword : %s\n", yytext);}
Nothing {printf(" Found keyword : %s\n", yytext);}
Of {printf(" Found keyword : %s\n", yytext);}
Optional {printf(" Found keyword : %s\n", yytext);}
Overridable {printf(" Found keyword : %s\n", yytext);}
Private {printf(" Found keyword : %s\n", yytext);}
RaiseEvent{printf(" Found keyword : %s\n", yytext);}
RemoveHandler {printf(" Found keyword : %s\n", yytext);}
Select {printf(" Found keyword : %s\n", yytext);}
Short {printf(" Found keyword : %s\n", yytext);}
Stop {printf(" Found keyword : %s\n", yytext);}
SyncLock {printf(" Found keyword : %s\n", yytext);}
True {printf(" Found keyword : %s\n", yytext);}
UInteger {printf(" Found keyword : %s\n", yytext);}
Variant {printf(" Found keyword : %s\n", yytext);} 
Widening {printf(" Found keyword : %s\n", yytext);}
Xor {printf(" Found keyword : %s\n", yytext);}

Nothing {printf(" Found nothing literal \n");}

/*Separators*/
\( {printf("Found a plus operator lexeme: %s", yytext);}
\) {printf("Found a plus operator lexeme: %s", yytext);}
\{ {printf("Found a plus operator lexeme: %s", yytext);}
\} {printf("Found a plus operator lexeme: %s", yytext);}
\? {printf("Found a plus operator lexeme: %s", yytext);}
\. {printf("Found a plus operator lexeme: %s", yytext);}
\! {printf("Found a plus operator lexeme: %s", yytext);}
/# {printf("Found a plus operator lexeme: %s", yytext);}
/, {printf("Found a plus operator lexeme: %s", yytext);}
/: {printf("Found a plus operator lexeme: %s", yytext);}

/*operator characters*/

\^ {printf("Found a operator characters: %s", yytext);}
\* {printf("Found a operator characters: %s", yytext);}
\\ {printf("Found a operator characters: %s", yytext);}
// {printf("Found a operator characters: %s", yytext);}
\+ {printf("Found a operator characters: %s", yytext);}
\- {printf("Found a operator characters: %s", yytext);}
\= {printf("Found a operator characters: %s", yytext);}
\^= {printf("Found a operator characters: %s", yytext);}
\*= {printf("Found a operator characters: %s", yytext);}
\+= {printf("Found a operator characters: %s", yytext);}
\-= {printf("Found a operator characters: %s", yytext);}
\<= {printf("Found a operator characters: %s", yytext);}
\< {printf("Found a operator characters: %s", yytext);}
\> {printf("Found a operator characters: %s", yytext);}
\>= {printf("Found a operator characters: %s", yytext);}
\<> {printf("Found a operator characters: %s", yytext);}
\& {printf("Found a operator characters: %s", yytext);}
\&= {printf("Found a operator characters: %s", yytext);}
\>> {printf("Found a operator characters: %s", yytext);}
\<< {printf("Found a operator characters: %s", yytext);}
\<<= {printf("Found a operator characters: %s", yytext);}
\>>= {printf("Found a operator characters: %s", yytext);}
\\= {printf("Found a operator characters: %s", yytext);}
//= {printf("Found a operator characters: %s", yytext);}


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

