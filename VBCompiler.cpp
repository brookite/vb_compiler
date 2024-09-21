#include <iostream>
#include "lexer/lexer.flex.cpp"

int main(int argc, char** argv) {
    if (argc > 1) {
        fopen_s(&yyin, argv[1], "r");
        yylex();
    }
    else {
        printf("File not found");
    }
}