#pragma once
#include <iostream>
#include <utility>
#include <algorithm>
#include <stdexcept>

template <typename ItemType>
class Array {
public:
    typedef ItemType* iterator;
    typedef ItemType value_type;
    typedef ItemType& reference;
    typedef ItemType* pointer;
    typedef int difference_type;

    Array(int size = 10);
    Array(const ItemType* arr, int size);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    int size() const;

    iterator begin();
    iterator end();
    const iterator begin() const;
    const iterator end() const;

    bool insert(const int index, const ItemType& value);
    bool removeAt(int index);
    bool removeByValue(const ItemType& value);
    void swap(Array& other) noexcept;

    int find(const ItemType& value) const;

    void print() const;
    void sort();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    ItemType& operator[](int index);
    const ItemType& operator[](int index) const;

private:
    void resize(int newSize);

private:
    ItemType* m_array = nullptr;
    int m_size = 0;
};