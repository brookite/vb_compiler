#pragma once
#include <vector>
#include <iostream>
#include <cstdarg>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

extern bool DEBUG;

void debug_print(const char* format, ...);
void internal_error(const char* msg);

size_t getNewId();
size_t lastId();

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

        id = other.id;
        data = other.data;

        return *this;
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

private:
    std::vector<T> data;
};
