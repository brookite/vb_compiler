#include "utils.hpp"
#include <winsock2.h>  
#pragma comment(lib, "ws2_32.lib") 


static size_t IdCounter = 0;
list<std::string> * errorBuffer = new list<std::string>();

size_t getNewId() {
    return ++IdCounter;
}

size_t lastId() {
    return IdCounter;
}

static void debug_print(bool debugCondition, const char* component, const char* format, va_list args) {
    if (debugCondition) {
        if (strlen(component) > 0) printf("[%s]: ", component);
        vprintf(format, args);
        if (!endsWith(format, "\n")) printf("\n");
    }
}

void debug_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(DEBUG || LEXER_DEBUG || PARSER_DEBUG, "", format, args);
    va_end(args);
}


void lexer_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(LEXER_DEBUG, "lexer", format, args);
    va_end(args);
}

void parser_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(PARSER_DEBUG, "parser", format, args);
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

static void cumulative_compiler_error(const char* errorType, int statusCode, const char* msg, va_list args) {
    char text[10000];
    char* textPtr = text;
    textPtr += sprintf(textPtr, "\033[31m");
    textPtr += sprintf(textPtr, errorType);
    textPtr += sprintf(textPtr, ": ");
    textPtr += vsprintf(textPtr, msg, args);
    textPtr += sprintf(textPtr, "\033[0m");
    std::string str = std::string(text);
    if (!errorBuffer->contains(str)) {
        errorBuffer->add(str);
    }
}


static void compiler_error(const char* errorType, int statusCode, const char* msg, va_list args) {
    printf("\033[31m");
    printf(errorType);
    printf(": ");
    vprintf(msg, args);
    printf("\033[0m");
    if (!endsWith(msg, "\n")) printf("\n");
    if (!DEBUG && !LEXER_DEBUG && !PARSER_DEBUG) exit(statusCode);
}

void flushErrorBuffer() {
    for (std::string error : *errorBuffer) {
        printf(error.c_str());
        if (!endsWith(error, "\n")) printf("\n");
    }
    errorBuffer->clear();
    if (!DEBUG) {
        exit(10);
    }
}

void lexer_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    compiler_error("SyntaxError", 1, msg, args);
    va_end(args);
}

void internal_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    compiler_error("InternalError", 1, msg, args);
    va_end(args);
    flushErrorBuffer();
    exit(1);
}

void syntax_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    compiler_error("SyntaxError", 2, msg, args);
    va_end(args);
}

void type_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    cumulative_compiler_error("TypeError", 3, msg, args);
    va_end(args);
}

void name_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    cumulative_compiler_error("NameError", 4, msg, args);
    va_end(args);
}

void value_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    cumulative_compiler_error("NameError", 4, msg, args);
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


byte_writer::byte_writer(byte_t* initial, size_t len)
    : buffer(new byte_t[len]), capacity(len), position(0) {
    std::memcpy(buffer, initial, len);
}


byte_writer::byte_writer() : buffer(new byte_t[64]), capacity(64), position(0) {}


void byte_writer::ensureCapacity(size_t additional) {
    if (position + additional > capacity) {
        size_t newCapacity = capacity * 2 + additional;
        byte_t* newBuffer = new byte_t[newCapacity];
        std::memcpy(newBuffer, buffer, position);
        delete[] buffer;
        buffer = newBuffer;
        capacity = newCapacity;
    }
}

void byte_writer::addUTF8(std::string str) {
    size_t len = str.size();
    ensureCapacity(len);
    std::memcpy(buffer + position, str.data(), len);
    position += len;
}

void byte_writer::addByte(byte_t num) {
    ensureCapacity(1);
    buffer[position++] = num;
}

void byte_writer::addInt16(int16_t num, bool big_endian) {
    if (big_endian) {
        num = htons(num);
    }
    ensureCapacity(2);
    std::memcpy(buffer + position, &num, sizeof(num));
    position += 2;
}

void byte_writer::addInt32(int32_t num, bool big_endian) {
    if (big_endian) {
        num = htonl(num);
    }
    ensureCapacity(4);
    std::memcpy(buffer + position, &num, sizeof(num));
    position += 4;
}

void byte_writer::addInt64(int64_t num, bool big_endian) {
    if (big_endian) {
        uint32_t high = static_cast<uint32_t>((num >> 32) & 0xFFFFFFFF); 
        uint32_t low = static_cast<uint32_t>(num & 0xFFFFFFFF); 

        high = htonl(high);
        low = htonl(low);
        num = (static_cast<int64_t>(high) << 32) | low;
    }
    ensureCapacity(8);
    std::memcpy(buffer + position, &num, sizeof(num));
    position += 8;
}

void byte_writer::addBytes(byte_t* start, size_t count) {
    ensureCapacity(count);
    std::memcpy(buffer + position, start, count);
    position += count;
}

void byte_writer::addBytes(char* bytes, size_t count) {
    ensureCapacity(count);
    std::memcpy(buffer + position, bytes, count);
    position += count;
}

void byte_writer::addFloat(float value) {
    ensureCapacity(sizeof(float));
    std::memcpy(buffer + position, &value, sizeof(value));
    position += sizeof(float);
}

void byte_writer::addDouble(double value) {
    ensureCapacity(sizeof(double));
    std::memcpy(buffer + position, &value, sizeof(value));
    position += sizeof(double);
}

bytearray_t * byte_writer::getByteArray() {
    byte_t* result = new byte_t[position];
    std::memcpy(result, buffer, position);
    bytearray_t* arr = new bytearray_t();
    arr->bytes = result;
    arr->length = position;
    return arr;
}

byte_writer::~byte_writer() {
    delete[] buffer;
}

void bytearray_t::reverseByteOrder()
{
    size_t left = 0;
    size_t right = length - 1;

    while (left < right) {
        std::swap(bytes[left], bytes[right]); 
        left++;
        right--;
    }
}
