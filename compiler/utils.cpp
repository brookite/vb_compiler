#include "utils.hpp"

static size_t IdCounter = 0;

size_t getNewId() {
    return ++IdCounter;
}

size_t lastId() {
    return IdCounter;
}

static void debug_print(bool debugCondition, const char* component, const char* format, va_list args) {
    if (debugCondition) {
        if (strlen(component) > 0) printf("[%s]:", component);
        vprintf(format, args);
        if (!endsWith(format, "\n")) printf("\n");
    }
}

void debug_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(DEBUG, "", format, args);
    va_end(args);
}

void lexer_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(DEBUG || LEXER_DEBUG, "lexer", format, args);
    va_end(args);
}

void parser_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(DEBUG || PARSER_DEBUG, "parser", format, args);
    va_end(args);
}

void semantic_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(DEBUG, "semantic", format, args);
    va_end(args);
}

void codegen_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(DEBUG, "codegen", format, args);
    va_end(args);
}

static void compiler_error(const char* errorType, const char* msg, va_list args) {
    printf(errorType);
    vprintf(errorType, args);
    if (!endsWith(msg, "\n")) printf("\n");
}

void internal_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    compiler_error("InternalError", msg, args);
    va_end(args);
}

void syntax_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    compiler_error("SyntaxError", msg, args);
    va_end(args);
}

void type_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    compiler_error("TypeError", msg, args);
    va_end(args);
}

bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::vector<std::string> find_files(const std::string& directory, const std::string& ext) {
    std::vector<std::string> vb_files;

    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().extension() == ext) {
                vb_files.push_back(entry.path().string());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing the directory: " << e.what() << '\n';
    }

    return vb_files;
}