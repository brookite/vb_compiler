#include "utils.hpp"

static size_t IdCounter = 0;

size_t getNewId() {
    return ++IdCounter;
}

size_t lastId() {
    return IdCounter;
}

void debug_print(const char* format, ...) {
    if (DEBUG) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}

void internal_error(const char* msg) {
    printf("Internal Error:");
    puts(msg);
}
