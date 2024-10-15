#pragma once
#include <assert.h>
#include <iostream>
#include <utility>

#undef DEBUG_OUTPUT

template <typename ItemType>
class Array
{
public:
    typedef ItemType* iterator;
    typedef ItemType value_type;
    typedef ItemType& reference;
    typedef ItemType* pointer;
    typedef int difference_type;
    
public:
    Array(int size = 10);
    Array(const Array& other);
    Array(Array&& other);
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
    Array operator+(const Array& other) const;
    Array& operator+=(const Array& other);

private:
    ItemType* m_array = nullptr;
    int m_size = 0;
};

