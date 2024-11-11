#pragma once
#include <vector>

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
struct list {
public:
    const size_t id;
private:
    std::vector<T> data;
};