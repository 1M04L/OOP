#pragma once
#include <cassert>
#include <iostream>
#include <utility>
#include <algorithm>

template <typename ItemType>
class Array {
public:
    typedef ItemType* iterator;
    typedef ItemType value_type;
    typedef ItemType& reference;
    typedef ItemType* pointer;
    typedef int difference_type;

public:
    Array(int size = 10);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    int size() const;

    iterator begin();
    iterator end();
    const iterator begin() const;
    const iterator end() const;

    bool insert(const int index, const ItemType& value);
    void swap(Array& other) noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    ItemType& operator[](int index);
    const ItemType& operator[](int index) const;

    int find(const ItemType& value) const;
    void print() const;
    void sort();
    bool removeAt(int index);
    bool removeByValue(const ItemType& value);

private:
    ItemType* m_array = nullptr;
    int m_size = 0;
};