#pragma once

#ifndef ONCE_LINKED_LIST_H
#define ONCE_LINKED_LIST_H

#include <iostream>

template <class T> class Element {
public:
    T data;
    Element<T>* next;
    explicit Element(T data) : data(data), next(nullptr) {}
    ~Element() {
        //delete data;
        delete next;
    }
    void print();
};

template <class T> class OneList {
public:
    Element<T>* front;
    Element<T>* back;
    int size;

    OneList() : front(nullptr), back(nullptr), size(0) {}
    bool empty() {
        return back == nullptr;
    }
    void push_front(T data);
    void push_back(T data);
    void insert(int, T);
    void pop_back();
    void pop_front();
    void remove(T);
    void print();
    Element<T>* operator[](int);
};

template <class T> void OneList<T>::push_front(T data) {
    Element<T>* new_elem = new Element<T>(data);
    size++;

    if (empty()) {
        front = new_elem;
        back = new_elem;

        return;
    }

    new_elem->next = front;
    front = new_elem;
    front->data = data;

}

template <class T> void OneList<T>::push_back(T data) {
    Element<T>* new_elem = new Element<T>(data);

    size++;

    if (empty()) {
        front = new_elem;
        back = new_elem;
        return;
    }

    back->next = new_elem;
    back = new_elem;
}

template<class T>
void OneList<T>::insert(const int index, T data) {
    auto* new_elem = new Element<T>(data);
    size++;

    Element<T>* elem = front;
    for (int i = 0; i < index; i++) {
        elem = elem->next;
    }

    new_elem->next = elem;
    elem = new_elem;
}

template<class T>
void OneList<T>::pop_front() {
    if (this->empty()) {
        return;
    }
    size--;
    auto* elem = front;
    front = elem->next;
    delete elem;
}

template<class T>
void OneList<T>::pop_back() {
    if (this->empty()) {
        return;
    }
    size--;
    auto* elem = front;
    int index = 1;
    while (index != size - 1) {
        elem = elem->next;
        index++;
    }

    size--;
    back = elem;
    delete elem->next;
}

template<class T>
void OneList<T>::remove(T removeData) {
    if (this->empty()) {
        return;
    }

    auto* elem = front;
    if (elem->data == removeData) {
        auto* removeElem = elem;
        front = elem->next;
        delete removeElem;
    }
    for (int i = 0;elem != back; i++) {
        if (elem->next->data == removeData) {
            auto* removeElem = elem->next;
            elem->next = removeElem->next;
            delete removeElem;
        }
    }

    if (back->data == removeData) {
        back = elem;
        delete back->next;
        back->next = nullptr;
    }
}

template<class T>
void OneList<T>::print() {

    if (empty()) return;
    Element<T>* elem = front;
    while (elem != nullptr) {
        std::cout << elem->data << " ";
        elem = elem->next;
    }
    std::cout << std::endl;

}

template<class T>
Element<T>* OneList<T>::operator[](int index) {
    auto* elem = front;
    for (int i = 0; i < index; i++) {
        elem = elem->next;
    }

    return elem;
}






template <class T> void Element<T>::print() {
    std::cout << data << " ";
}
#endif //ONCE_LINKED_LIST_H
