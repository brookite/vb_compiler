#include <string>
#include "parser/grammar.tab.h"
#include "compiler/nodes.hpp"
#include "compiler/semantics.hpp"

extern FILE * yyin;
extern int yylineno;
extern bool new_stmt;
extern bool DEBUG;
extern void runParserTests();

extern program_node* program;

void runCompile(const char* path) {
    fopen_s(&yyin, path, "r");
    yyparse();
    semantic_analyzer analyzer;
    analyzer.analyzeProgram(program);
    if (yyin != 0) fclose(yyin);
    program = nullptr;
}


static void runTests() {
    DEBUG = true;
    fs::create_directories("tests");
    std::vector<std::string> test_files = find_files("tests", ".vb");
    for (std::string testpath : test_files) {
        yylineno = 1;
        new_stmt = true;
        printf("Processing %s\n\n", testpath.c_str());
        runCompile(testpath.c_str());
        printf("\n\n\n");
    }
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (strcmp(argv[1], "--test-parser") == 0) {
            PARSER_DEBUG = true;
            LEXER_DEBUG = true;
            runParserTests();
            return 0;
        }
        if (strcmp(argv[1], "--test") == 0) {
            runTests();
            return 0;
        }
        runCompile(argv[1]);
        if (argc > 2 && strcmp(argv[2], "--debug") == 0) {
            DEBUG = true;
        }
        
    }
    else {
        printf("File not found");
    }
}
