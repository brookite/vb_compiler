#include "utils.hpp"
#include "nodes.hpp"

void debug_print(const char* format, ...) {
    if (DEBUG) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}

template <class T>
list<T>::list() : id(++node::IdCounter) {}

template <class T>
list<T>::list(std::initializer_list<T> init_list) : id(++node::IdCounter), data(init_list) {}

template <class T>
void list<T>::add(const T& element) {
    data.push_back(element);
}

template <class T>
T list<T>::first() const {
    return get(0);
}

template <class T>
T list<T>::last() const {
    return get(size() - 1);
}

template <class T>
void list<T>::add(size_t index, const T& element) {
    if (index > data.size()) {
        throw std::out_of_range("Index out of range");
    }
    data.insert(data.begin() + index, element);
}


template <class T>
T list<T>::get(size_t index) const {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <class T>
void list<T>::set(size_t index, const T& element) {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = element;
}

template <class T>
void list<T>::remove(size_t index) {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    data.erase(data.begin() + index);
}

template <class T>
void list<T>::clear() {
    data.clear();
}

template <class T>
size_t list<T>::size() const {
    return data.size();
}

template <class T>
bool list<T>::isEmpty() const {
    return data.empty();
}

template <class T>
typename std::vector<T>::iterator list<T>::begin() {
    return data.begin();
}

template <class T>
typename std::vector<T>::iterator list<T>::end() {
    return data.end();
}

template <class T>
typename std::vector<T>::const_iterator list<T>::begin() const {
    return data.begin();
}

template <class T>
typename std::vector<T>::const_iterator list<T>::end() const {
    return data.end();
}

template <class T>
T& list<T>::operator[](size_t index) {
    if (index >= data.size()) throw std::out_of_range("Index out of range");
    return data[index];
}

template <class T>
const T& list<T>::operator[](size_t index) const {
    if (index >= data.size()) throw std::out_of_range("Index out of range");
    return data[index];
}

template <class T>
list<T>::list(const list<T>& other) : id(other.id), data(other.data) {}

template <class T>
list<T>& list<T>::operator=(const list<T>& other) {
    if (this == &other) {
        return *this; 
    }

    id = other.id;
    data = other.data; 

    return *this;
}

template <class T>
int list<T>::indexOf(const T& item) const {
    auto it = std::find(data.begin(), data.end(), item);
    return (it != data.end()) ? std::distance(data.begin(), it) : -1;
}

template <class T>
bool list<T>::contains(const T& item) const {
    return std::find(data.begin(), data.end(), item) != data.end();
}