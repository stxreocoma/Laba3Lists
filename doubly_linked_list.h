#pragma once


#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <chrono>
#include <iostream>

template <class T> class Element {
public:
    T data;
    Element<T>* next;
    Element<T>* prev;
    explicit Element(T data) : data(data), next(nullptr), prev(nullptr) {}
    ~Element() {
        delete next;
        delete prev;
    }
};

template <class T> class TwoList {
public:
    Element<T>* first;
    Element<T>* last;
    int count;
    TwoList() : first(nullptr), last(nullptr), count(0) {}
    ~TwoList();
    void push_front(T data);
    void push_back(T data);
    void insert(int, T);
    void pop_back();
    void pop_front();
    void remove(T);
    int size();
    Element<T>* front();
    Element<T>* back();
    bool empty();
    Element<T>* operator[](int);
    void print();
    void rmDot(int);
};

template<class T>
TwoList<T>::~TwoList() {
    delete first;
    delete last;
}

template<class T>
void TwoList<T>::push_front(T data) {
    auto* new_elem = new Element<T>(data);

    if (empty()) {
        first = new_elem;
        last = new_elem;
    }
    else {
        new_elem->next = first;
        first->prev = new_elem;
        first = new_elem;
    }
}

template<class T>
void TwoList<T>::push_back(T data) {
    auto* new_elem = new Element<T>(data);
    if (empty()) {
        first = new_elem;
        last = new_elem;
    }
    else {
        new_elem->prev = last;
        last->next = new_elem;
        last = new_elem;
    }
}

template<class T>
void TwoList<T>::insert(const int index, T data) {
    if (empty) {
        auto* new_elem = new Element<T>(data);
        first = new_elem;
        last = new_elem;
    }

    else if (count <= index) {
        return push_back(data);
    }
    else {
        auto* new_elem = new Element<T>(data);
        auto* elem = first;
        for (int i = 1; i < index; i++) {
            elem = elem->next;
        }
        new_elem->next = elem->next;
        new_elem->next->prev = new_elem;
        elem->next = new_elem;
        new_elem->prev = elem;
    }
}

template<class T>
void TwoList<T>::pop_back() {
    if (empty) {
        return;
    }
    else {
        auto* elem = last;
        last = last->prev;
        last->next = nullptr;
    }
}

template<class T>
void TwoList<T>::pop_front() {
    if (empty) {
        return;
    }
    else {
        auto* elem = first;
        first = first->next;
    }
}

template<class T>
void TwoList<T>::remove(T data) {
    if (empty) {
        return;
    }
    else {
        auto* elem = first;

        while (elem->next != nullptr) {

        }

        if (first->data == data) {
            pop_front();
        }
        else if (last->data == data) {
            pop_back();
        }
    }
}

template<class T>
int TwoList<T>::size() {
    return count;
}

template<class T>
Element<T>* TwoList<T>::front() {
    return first;
}

template<class T>
Element<T>* TwoList<T>::back() {
    return last;
}

template<class T>
bool TwoList<T>::empty() {
    return first == nullptr;
}

template<class T>
Element<T>* TwoList<T>::operator[](int) {
    auto* elem = first;

    for (int i = 1; i <= count; i++) {
        elem = elem->next;
    }
    return elem;
}

template<class T>
void TwoList<T>::print() {
    std::cout << "[ ";
    auto* elem = first;
    while (elem != nullptr) {
        std::cout << elem->data << " ";
        elem = elem->next;
    }
    std::cout << "]" << std::endl;
}

template<class T>
void TwoList<T>::rmDot(const int index) {
    auto* elem = first;
    for (int i = 0; i < index; i++) {
        elem = elem->next;
    }
    auto* prev_elem = elem->prev;
    prev_elem->next = elem->next;
}




#endif //DOUBLY_LINKED_LIST_H
