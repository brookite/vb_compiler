#include "utils.hpp"
#include <winsock2.h>  
#include <algorithm> 
#include <cctype>

#pragma comment(lib, "ws2_32.lib") 

#define INITIAL_CAPACITY 128

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
    debug_print(COMPILE_DEBUG, "semantic", format, args);
    va_end(args);
}

void codegen_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    debug_print(COMPILE_DEBUG, "codegen", format, args);
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

bool hasCompilerErrors()
{
    return !errorBuffer->isEmpty();
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
    cumulative_compiler_error("ValueError", 4, msg, args);
    va_end(args);
}

void codegen_error(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    compiler_error("CompileError", 5, msg, args);
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


byte_writer::byte_writer() : buffer(new byte_t[INITIAL_CAPACITY]), capacity(INITIAL_CAPACITY), position(0) {}


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
    buffer[position] = num;
    position++;
}

void byte_writer::addInt16(int16_t num, bool big_endian) {
    if (big_endian) {
        num = htons(num);
    }
    ensureCapacity(sizeof(num));
    std::memcpy(buffer + position, &num, sizeof(num));
    position += sizeof(num);
}

void byte_writer::addInt32(int32_t num, bool big_endian) {
    if (big_endian) {
        num = htonl(num);
    }
    ensureCapacity(sizeof(num));
    std::memcpy(buffer + position, &num, sizeof(num));
    position += sizeof(num);
}

void byte_writer::addInt64(int64_t num, bool big_endian) {
    if (big_endian) {
        num = htonll(num);
    }
    ensureCapacity(sizeof(int64_t));
    std::memcpy(buffer + position, &num, sizeof(int64_t));
    position += sizeof(int64_t);
}

void byte_writer::addBytes(byte_t* start, size_t count) {
    ensureCapacity(count);
    std::memcpy(buffer + position, start, count);
    position += count;
}

void byte_writer::addBytes(const char* bytes, size_t count) {
    ensureCapacity(count);
    std::memcpy(buffer + position, bytes, count);
    position += count;
}

void byte_writer::addBytes(bytearray_t& array)
{
    addBytes(array.bytes, array.length);
}

void byte_writer::addBytes(bytearray_t && array)
{
    addBytes(array.bytes, array.length);
}

void byte_writer::addFloat(float value, bool bigEndian) {
    ensureCapacity(sizeof(float));
    if (bigEndian) {
        return addInt32(htonf(value), false);
    }
    std::memcpy(buffer + position, &value, sizeof(float));
    position += sizeof(float);
}

void byte_writer::addDouble(double value, bool bigEndian) {
    ensureCapacity(sizeof(double));
    if (bigEndian) {
        return addInt64(htond(value), false);
    }
    std::memcpy(buffer + position, &value, sizeof(double));
    position += sizeof(double);
}

void byte_writer::setBytes(size_t from, size_t to, void* val)
{
    std::memcpy(buffer + from, val, to - from);
}

int16_t byte_writer::bigEndian(int16_t val)
{
    return htons(val);
}

int32_t byte_writer::bigEndian(int32_t val)
{
    return htonl(val);
}

int64_t byte_writer::bigEndian(int64_t val)
{
    return htonll(val);
}

size_t byte_writer::offset()
{
    return position;
}

bytearray_t byte_writer::getByteArray() {
    byte_t* result = new byte_t[position];
    std::memcpy(result, buffer, position);
    bytearray_t arr;
    arr.bytes = result;
    arr.length = position;
    return arr;
}

bytearray_t byte_writer::getByteArray(size_t from, size_t to) {
    byte_t* result = new byte_t[to - from];
    std::memcpy(result, buffer + from, to - from);
    bytearray_t arr;
    arr.bytes = result;
    arr.length = to - from;
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

void toLower(std::string* strPtr) {
    if (strPtr == nullptr) {
        return;
    }
    std::transform(strPtr->begin(), strPtr->end(), strPtr->begin(),
        [](unsigned char c) { return std::tolower(c); });
}

void capitalize(std::string * result) {
    if (result->empty()) {
        return; 
    }

    (*result)[0] = std::toupper((*result)[0]);

    for (size_t i = 1; i < result->size(); ++i) {
        (*result)[i] = std::tolower((*result)[i]);
    }

}
