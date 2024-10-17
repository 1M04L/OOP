#include "Array.h"

template <typename ItemType>
Array<ItemType>::Array(int size) : m_size(size), m_array(new ItemType[size]) {}

template <typename ItemType>
Array<ItemType>::Array(const Array& other) : m_size(other.m_size), m_array(new ItemType[other.m_size]) {
    std::copy(other.m_array, other.m_array + other.m_size, m_array);
}

template <typename ItemType>
Array<ItemType>::Array(Array&& other) noexcept : m_size(other.m_size), m_array(other.m_array) {
    other.m_size = 0;
    other.m_array = nullptr;
}

template <typename ItemType>
Array<ItemType>::~Array() {
    delete[] m_array;
}

template <typename ItemType>
int Array<ItemType>::size() const {
    return m_size;
}

template <typename ItemType>
typename Array<ItemType>::iterator Array<ItemType>::begin() {
    return m_array;
}

template <typename ItemType>
typename Array<ItemType>::iterator Array<ItemType>::end() {
    return m_array + m_size;
}

template <typename ItemType>
const typename Array<ItemType>::iterator Array<ItemType>::begin() const {
    return m_array;
}

template <typename ItemType>
const typename Array<ItemType>::iterator Array<ItemType>::end() const {
    return m_array + m_size;
}

template <typename ItemType>
bool Array<ItemType>::insert(const int index, const ItemType& value) {
    if (index < 0 || index > m_size) return false;

    ItemType* newArray = new ItemType[m_size + 1];
    std::copy(m_array, m_array + index, newArray);
    newArray[index] = value;
    std::copy(m_array + index, m_array + m_size, newArray + index + 1);

    delete[] m_array;
    m_array = newArray;
    ++m_size;

    return true;
}

template <typename ItemType>
void Array<ItemType>::swap(Array& other) noexcept {
    std::swap(m_size, other.m_size);
    std::swap(m_array, other.m_array);
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator=(const Array& other) {
    if (this != &other) {
        delete[] m_array;
        m_size = other.m_size;
        m_array = new ItemType[m_size];
        std::copy(other.m_array, other.m_array + m_size, m_array);
    }
    return *this;
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] m_array;
        m_size = other.m_size;
        m_array = other.m_array;

        other.m_size = 0;
        other.m_array = nullptr;
    }
    return *this;
}

template <typename ItemType>
ItemType& Array<ItemType>::operator[](int index) {
    assert(index >= 0 && index < m_size);
    return m_array[index];
}

template <typename ItemType>
const ItemType& Array<ItemType>::operator[](int index) const {
    assert(index >= 0 && index < m_size);
    return m_array[index];
}

template <typename ItemType>
int Array<ItemType>::find(const ItemType& value) const {
    for (int i = 0; i < m_size; ++i) {
        if (m_array[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename ItemType>
void Array<ItemType>::print() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename ItemType>
void Array<ItemType>::sort() {
    for (int i = 0; i < m_size - 1; ++i) {
        for (int j = 0; j < m_size - i - 1; ++j) {
            if (m_array[j] > m_array[j + 1]) {
                std::swap(m_array[j], m_array[j + 1]);
            }
        }
    }
}

template <typename ItemType>
bool Array<ItemType>::removeAt(int index) {
    if (index < 0 || index >= m_size) return false;

    ItemType* newArray = new ItemType[m_size - 1];
    
    std::copy(m_array, m_array + index, newArray);
    std::copy(m_array + index + 1, m_array + m_size, newArray + index);

    delete[] m_array;
    m_array = newArray;
    --m_size;

    return true;
}

template <typename ItemType>
bool Array<ItemType>::removeByValue(const ItemType& value) {
    int index = find(value);
    
    if (index != -1) {
        return removeAt(index);
    }
    
    return false;
}
