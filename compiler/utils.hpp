#pragma once
#include <vector>
#include <iostream>
#include <cstdarg>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

extern bool DEBUG;

void debug_print(const char* format, ...);

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

    list();
    list(std::initializer_list<T> init_list);
    list(const list<T>& other);
    list<T>& operator=(const list<T>& other);

    void add(const T& element);
    void add(size_t index, const T& element);
    T get(size_t index) const;
    void set(size_t index, const T& element);
    void remove(size_t index);
    void clear();
    int indexOf(const T& item) const;
    bool contains(const T& item) const;

    size_t size() const;
    bool isEmpty() const;

    T first() const;
    T last() const;

    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    typename std::vector<T>::const_iterator begin() const;
    typename std::vector<T>::const_iterator end() const;

    T& operator[](size_t index);            
    const T& operator[](size_t index) const;

private:
    std::vector<T> data;
};