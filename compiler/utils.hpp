#pragma once
#include <vector>
#include <iostream>
#include <cstdarg>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>
#include <filesystem>

#pragma warning(disable:4996)

extern bool DEBUG;
extern bool PARSER_DEBUG;
extern bool LEXER_DEBUG;

void debug_print(const char* format, ...);

void lexer_print(const char* format, ...);
void parser_print(const char* format, ...);
void semantic_print(const char* format, ...);
void codegen_print(const char* format, ...);

void internal_error(const char* msg, ...);
void lexer_error(const char* msg, ...);
void syntax_error(const char* msg, ...);
void type_error(const char* msg, ...);
void name_error(const char* msg, ...);
void value_error(const char* msg, ...);
void codegen_error(const char* msg, ...);

void flushErrorBuffer();
bool hasCompilerErrors();


namespace fs = std::filesystem;

size_t getNewId();
bool endsWith(const std::string& str, const std::string& suffix);
size_t lastId();
std::vector<std::string> find_files(const std::string& directory, const std::string& extension);

struct cloneable {
    virtual ~cloneable() = default;
    virtual cloneable* clone() = 0;
};

struct Date : cloneable {
    int day = 0;
    int month = 0;
    int year = -1;

    virtual Date* clone() {
        Date* date = new Date();
        date->day = day;
        date->month = month;
        date->year = year;
        return date;
    }
};

enum TimeFormat {
    AM, PM, HOURS_24
};

struct Time : cloneable {
    int hour = 0;
    int minute = 0;
    int second = 0;
    TimeFormat format = HOURS_24;

    virtual Time* clone() {
        Time * t = new Time();
        t->hour = hour;
        t->minute = minute;
        t->second = second;
        t->format = format;
        return t;
    }
};

struct DateTime : public cloneable {
    Date* date = nullptr;
    Time* time = nullptr;

    DateTime* clone() {
        DateTime* clone = new DateTime();
        clone->date = date != nullptr ? date->clone() : nullptr;
        clone->time = time != nullptr ? time->clone() : nullptr;
        return clone;
    }

    std::string str() {
        char string[128];
        const char* format = "";
        if (time != nullptr) {
            if (time->format == AM) {
                format = "AM";
            }
            else {
                format = "PM";
            }
        }
        if (time == nullptr && date != nullptr) {
            sprintf(string, "%0d.%0d.%d", date->day, date->month, date->year);
        }
        else if (time != nullptr && date == nullptr) {
            sprintf(string, "%0d:%0d:%d %s",
                time->hour, time->minute, time->second,
                format
            );
        }
        else {
            sprintf(string, "%0d.%0d.%d %0d:%0d:%d %s", date->day, date->month, date->year,
                time->hour, time->minute, time->second,
                format
            );
        }
        
        return std::string(string);
    }
};


template <class T>
class list {
public:
    const size_t id;

    list() : id(getNewId()) {}
    list(std::initializer_list<T> init_list) : id(getNewId()), data(init_list) {}
    list(const list<T>& other) : id(other.id), data(other.data) {}

    list<T>& operator=(const list<T>& other) {
        if (this == &other) {
            return *this;
        }
        data = other.data;

        return *this;
    }

    list<T>& operator=(const std::initializer_list<T>& other) {
        data = std::vector<T>(other);
        return *this;
    }

    bool operator== (const list<T>& t) const {
        if (t.size() != this->size()) {
            return false;
        }
        for (size_t i = 0; i < size(); i++) {
            if (t[i] != (*this)[i]) {
                return false;
            }
        }
        return true;
    }

    void add(const T& element) {
        data.push_back(element);
    }

    void add(size_t index, const T& element) {
        if (index > data.size()) {
            throw std::out_of_range("Index out of range");
        }
        data.insert(data.begin() + index, element);
    }

    T get(size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void set(size_t index, const T& element) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = element;
    }

    void remove(size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        data.erase(data.begin() + index);
    }

    void clear() {
        data.clear();
    }

    void reverse() {
        std::reverse(data.begin(), data.end());
    }

    void sort() {
        std::sort(data.begin(), data.end());
    }

    void addAll(list<T> & other) {
        for (T val : other) {
            add(val);
        }
    }

    void addAll(list<T>&& other) {
        for (T val : std::move(other)) {
            add(val);
        }
    }
    
    void addNotNull(T val) {
        if (val != nullptr) {
            add(val);
        }
    }

    std::vector<T> * vector() {
        return &data;
    }

    void addAllNotNull(list<T>& other) {
        for (T val : other) {
            addNotNull(val);
        }
    }

    void addAllNotNull(list<T>&& other) {
        for (T val : std::move(other)) {
            addNotNull(val);
        }
    }

    int indexOf(const T& item) const {
        auto it = std::find(data.begin(), data.end(), item);
        return (it != data.end()) ? std::distance(data.begin(), it) : -1;
    }

    bool contains(const T& item) const {
        return std::find(data.begin(), data.end(), item) != data.end();
    }

    size_t size() const {
        return data.size();
    }

    bool isEmpty() const {
        return data.empty();
    }

    T first() const {
        return get(0);
    }

    T last() const {
        return get(size() - 1);
    }

    typename std::vector<T>::iterator begin() {
        return data.begin();
    }

    typename std::vector<T>::iterator end() {
        return data.end();
    }

    typename std::vector<T>::const_iterator begin() const {
        return data.begin();
    }

    typename std::vector<T>::const_iterator end() const {
        return data.end();
    }

    T& operator[](size_t index) {
        if (index >= data.size()) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= data.size()) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t countNotNull() {
        size_t counter = 0;
        for (T val : *this) {
            if (val != nullptr) {
                counter++;
            }
        }
        return counter;
    }

private:
    std::vector<T> data;
};

typedef uint8_t byte_t;

struct bytearray_t {
    size_t length;
    byte_t* bytes;

    bytearray_t() { length = 0; bytes = nullptr; }
    bytearray_t(size_t length, byte_t* content) : length(length), bytes(content) {}

    void reverseByteOrder();
};

struct byte_writer {
public:
    byte_writer(byte_t* initial, size_t len);
    byte_writer();

    void addUTF8(std::string str);
    void addByte(byte_t num);
    void addInt16(int16_t num, bool big_endian = true);
    void addInt32(int32_t num, bool big_endian = true);
    void addInt64(int64_t num, bool big_endian = true);
    void addBytes(byte_t* start, size_t count);
    void addBytes(const char* bytes, size_t count);
    void addBytes(bytearray_t & array);
    void addBytes(bytearray_t && array);
    void addFloat(float value, bool big_endian = true);
    void addDouble(double value, bool big_endian = true);
    void setBytes(size_t from, size_t to, void* val);
    int16_t bigEndian(int16_t);
    int32_t bigEndian(int32_t);
    int64_t bigEndian(int64_t);

    size_t offset();

    bytearray_t getByteArray();
    bytearray_t getByteArray(size_t from, size_t to);

    ~byte_writer();
private:
    byte_t* buffer;    
    size_t capacity;  
    size_t position;

    void ensureCapacity(size_t additional);
};
