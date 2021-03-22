//
// Created by alex on 3/19/21.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include "Node.h"

template<typename T>
class List {
    struct Node {
    private:
        T m_value = {};
        Node *m_next = nullptr;
        Node *m_prev = nullptr;

        Node() { std::cout << "New"; }

        ~Node() { std::cout << "Del"; }
    };

    struct iterator {
    private:
        Node *ptr;
    public:
        iterator operator++() {
            ptr = ptr->m_next;
            return *this;
        }

        iterator operator+(int) {
            ptr = ptr->m_next;
            return iterator(ptr->m_prev);
        }
        T &operator*() {
            return ptr->m_value;
        }
    };

    int m_size = 0;
    Node *m_head = nullptr;
    Node *m_last = nullptr;

    void resize(int);
};

template<typename T>
void List<T>::resize(int newSize) {
    if (m_size == newSize) {
        return;
    }
    if (newSize > m_size) {

    }
}


#endif //LIST_LIST_H
