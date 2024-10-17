#include "Array.h"

template <typename ItemType>
Array<ItemType>::Array(int size) : m_size(size) {
    m_array = new ItemType[m_size];
}

template <typename ItemType>
Array<ItemType>::Array(const ItemType* arr, int size) : m_size(size) {
    m_array = new ItemType[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = arr[i];
    }
}

template <typename ItemType>
Array<ItemType>::Array(const Array& other) : m_size(other.m_size) {
    m_array = new ItemType[m_size];
    std::copy(other.m_array, other.m_array + m_size, m_array);
}

template <typename ItemType>
Array<ItemType>::Array(Array&& other) noexcept : m_array(other.m_array), m_size(other.m_size) {
    other.m_array = nullptr;
    other.m_size = 0;
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

    resize(m_size + 1);
    
    for (int i = m_size - 1; i > index; --i) {
        m_array[i] = m_array[i - 1];
    }
    
    m_array[index] = value;
    
    return true;
}

template <typename ItemType>
bool Array<ItemType>::removeAt(int index) {
    if (index < 0 || index >= m_size) return false;

    for (int i = index; i < m_size - 1; ++i) {
        m_array[i] = m_array[i + 1];
    }

    resize(m_size - 1);
    
    return true;
}

template <typename ItemType>
bool Array<ItemType>::removeByValue(const ItemType& value) {
    int index = find(value);
    if (index == -1) return false;

    return removeAt(index);
}

template <typename ItemType>
int Array<ItemType>::find(const ItemType& value) const {
    for (int i = 0; i < m_size; ++i) {
        if (m_array[i] == value) return i;
    }
    return -1;
}

template <typename ItemType>
void Array<ItemType>::swap(Array& other) noexcept {
    std::swap(m_array, other.m_array);
    std::swap(m_size, other.m_size);
}

template <typename ItemType>
void Array<ItemType>::sort() {
    std::sort(m_array, m_array + m_size);
}

template <typename ItemType>
void Array<ItemType>::print() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
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

        m_array = other.m_array;
        m_size = other.m_size;

        other.m_array = nullptr;
        other.m_size = 0;
    }
    
    return *this;
}

template <typename ItemType>
ItemType& Array<ItemType>::operator[](int index) {
    if (index < 0 || index >= m_size) throw std::out_of_range("Index out of range");
    
    return m_array[index];
}

template <typename ItemType>
const ItemType& Array<ItemType>::operator[](int index) const {
    if (index < 0 || index >= m_size) throw std::out_of_range("Index out of range");
    
    return m_array[index];
}

template <typename ItemType>
void Array<ItemType>::resize(int newSize) {
    ItemType* newArray = new ItemType[newSize];
    
    for (int i = 0; i < std::min(m_size, newSize); ++i) {
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    
    m_array = newArray;
    m_size = newSize;
}
