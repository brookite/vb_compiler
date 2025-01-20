#include <string>
#include "parser/grammar.tab.h"
#include "compiler/nodes.hpp"
#include "compiler/semantics.hpp"
#include "compiler/codegen/rtl.hpp"

extern FILE * yyin;
extern int yylineno;
extern bool new_stmt;
extern bool DEBUG;
extern bool hasSyntaxErrors;
extern void runParserTests();

bool COMPILE_DEBUG = false;

extern program_node* program;

void runCompile(const char* path, const char * outDir) {
    fs::path file_path = path;
    if (!fs::exists(file_path)) {
        internal_error("File doesn't exists %s", fs::absolute(file_path).string().c_str());
    }
    if (!fs::exists(outDir)) {
        fs::create_directories(outDir);
    }
    fopen_s(&yyin, path, "r");
    yyparse();
    if (hasSyntaxErrors) {
        return;
    }
    semantic_analyzer analyzer;
    bool err = analyzer.analyzeProgram(program);
    if (!err) {
        std::map<std::string, bytearray_t>* code = analyzer.compile();
        std::string filename = file_path.stem().string();
        std::string outputDir = std::string(outDir);
        outputDir += std::string("/out/") + filename;
        std::string codeDir = outputDir + "/brookit/vb/code/";
        if (!fs::exists(codeDir)) {
            fs::create_directories(codeDir);
        }

        std::string rtlPath = "RTL/brookit/vb/lang";
        if (!fs::exists(rtlPath)) {
            rtlPath = "VbRTL/target/classes/brookit/vb/lang";
            if (!fs::exists(rtlPath)) {
                internal_error("No RTL added with executable file. Put RTL/ folder with RTL nearby this executable file");
            }
        }
        fs::copy(rtlPath, outputDir + "/brookit/vb/lang", fs::copy_options::overwrite_existing);

        for (auto& pair : *code) {
            FILE* file = fopen((codeDir + pair.first + ".class").c_str(), "wb");
            fwrite(pair.second.bytes, sizeof(byte_t), pair.second.length, file);
            fclose(file);
        }

        char command[1024];
        sprintf(command, "jar cfe \"%s.vb.jar\" brookit.vb.code.%s -C \"%s\" .", outputDir.c_str(), 
            analyzer.entryPoint->owner->name.c_str(), outputDir.c_str());
        system(command);
    }
    if (DEBUG) {
        std::string constantFile = std::string(outDir) + "/" + file_path.stem().string() + ".constant.txt";
        std::string text = path;
        text += ":\n\n";
        for (auto& pair : analyzer.ctx.classes) {
            if (dynamic_cast<rtl_class_record*>(pair.second) != nullptr) continue;
            text += printableConstant(pair.second->name, pair.second->constant);
            text += "\n\n";
        }
        FILE* out = fopen(constantFile.c_str(), "w");
        fwrite(text.c_str(), sizeof(char), text.length(), out);
        fclose(out);
    }
    if (yyin != 0) fclose(yyin);
}


static void runTests() {
    DEBUG = true;
    fs::create_directories("tests");
    std::vector<std::string> test_files = find_files("tests", ".vb");
    for (std::string testpath : test_files) {
        yylineno = 1;
        new_stmt = true;
        printf("Processing %s\n\n", testpath.c_str());
        runCompile(testpath.c_str(), "tests/const");
        program = nullptr;
        printf("\n\n\n");
    }
}

int main(int argc, char** argv) {
    if (argc > 1) {
        std::string cwd = fs::current_path().string();
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
        if (argc > 2 && strcmp(argv[2], "--debug") == 0) {
            DEBUG = true;
        }
        runCompile(argv[1], cwd.c_str());
    }
    else {
        internal_error("File not found");
    }
}
