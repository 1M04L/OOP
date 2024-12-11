//list.h:
#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm> 


template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List();
    List(const T arr[], int size);
    List(const List<T>& other);
    ~List();
    List<T>& operator=(const List<T>& other);

    int getSize() const;
    void swap(List<T>& other);
    void print() const;
    Node* find(const T& value) const;
    void append(const T& value);
    void prepend(const T& value);
    void removeFirst();
    void removeLast();
    T& operator[](int index);
    bool operator==(const List<T>& other) const;
    bool operator!=(const List<T>& other) const;
    void clear();
    
};




//list.cpp:
#include "list.h"
#include<iostream>

template <typename T>
void List<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::List(const T arr[], int size) : head(nullptr), tail(nullptr), size(0) {
    for (int i = 0; i < size; ++i) {
        append(arr[i]);
    }
}


template <typename T>
List<T>::List(const List<T>& other) : head(nullptr), tail(nullptr), size(0) {
    *this = other;
}

template <typename T>
List<T>::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        clear(); 
        Node* current = other.head;
        while (current != nullptr) {
            append(current->data);
            current = current->next;
        }
    }
    return *this;
}


template <typename T>
int List<T>::getSize() const {
    return size;
}

template <typename T>
void List<T>::swap(List<T>& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
}

template <typename T>
void List<T>::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
typename List<T>::Node* List<T>::find(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


template <typename T>
void List<T>::append(const T& value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void List<T>::prepend(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void List<T>::removeFirst() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void List<T>::removeLast() {
    if (tail == nullptr) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    size--;
}


template <typename T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}


template <typename T>
bool List<T>::operator==(const List<T>& other) const {
    if (size != other.size) return false;
    Node* current1 = head;
    Node* current2 = other.head;
    while (current1 != nullptr) {
        if (current1->data != current2->data) return false;
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T>& other) const {
    return !(*this == other);
}


