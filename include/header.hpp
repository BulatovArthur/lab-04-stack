#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <initializer_list>
#include <stdarg.h>
#include <iostream>

template <class T>
class stack {
    struct Node {
        T value;
        Node *next;
    };
    Node *head;
public:
    stack();
  
    template <class... Args>
    void push_emplace(Args&&... value);
    
    void push(T&& value);
    void push(const T& value);
    const T& head() const;
    T pop();
    ~stack();
};

template <class T>
stack<T>::stack() {
    head = nullptr;
}

template <class T>
void stack<T>::push(T&& value) {
    Node *node = new Node;
    node->value = value;
    node->next = head;
    head = node;
}

template <typename T>
void stack<T>::push(const T& value) {
    Node *node = new Node;
    node->value = value;
    node->next = head;
    head = node;
}

template <class T>
template <class... Args>
void stack<T>::push_emplace(Args&&... value) {
    for (auto ch : std::initializer_list<T>{value...}) {
        Node *node = new Node;
        node->value = ch;
        node->next = head;
        head = node;
    }
}

template <class T>
const T& stack<T>::head() const {
    return head->value;
}

template <class T>
T stack<T>::pop() {
    T value = head->value;
    Node *helper = head;
    head = head->next;
    delete helper;
    return value;
}

template <class T>
stack<T>::~stack() {
    while (head) {
        Node *helper = head;
        head = head->next;
        delete helper;
    }
}

#endif // INCLUDE_HEADER_HPP_
