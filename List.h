//
// Created by alex on 3/19/21.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include "Node.h"

template<typename T>
class List {
    int m_size = 0;
    Node<T> *m_head = nullptr;

    Node<T> *pNode(int number);

public:
    struct iterator {
        void operator* (){
            return *ptr->value;
        }
        void operator++(){
            ptr = ptr->m_next;
            return *ptr->m_value;
        }
        void operator++(int){
            ptr = ptr->m_next;
            return *ptr->m_prev->m_value;
        }

    private:
        Node<T> *ptr;
    };
    int size() const;

    List(int size);

    ~List();

    List(const List &other);

    List (const List<T> &&other);

    List<T> &operator=(const List<T> &other);

    List<T> &operator=(const List<T> &&other);

    T &operator[](int number);

    const T &operator[](int number) const;

    void resize(int newSize);

    void print();

};

template<typename T>
int List<T>::size() const {
    return m_size;
}

template<typename T>
List<T>::List(const List<T> &other) { //Edit after doing iterator
    resize(other.m_size);
}

template<typename T>
Node<T> *List<T>::pNode(int number) {
    if (number > m_size) {
        return nullptr;
    }
    auto currentNode = m_head;
    for (int i = 0; i < number && i < m_size; i++) {
        currentNode = currentNode->m_next;
    }
    return currentNode;
}

template<typename T>
List<T>::List(const List<T> &&other) {
    m_size = other.m_size;
    m_head = other.m_head;
    other.m_head = nullptr;
}


template<typename T>
List<T> &List<T>::operator=(const List<T> &other) {
    resize(other.m_size);
    auto iterator = m_head;
    auto otherIterator = other.m_head;
    for (int i = 0; i < m_size; i++) {
        iterator->m_value = otherIterator->m_value;
        iterator = iterator->m_next;
        otherIterator = otherIterator->m_next;
    }
    return *this;
}

template<typename T>
List<T> &List<T>::operator=(const List<T> &&other) {
    m_size = other.m_size;
    m_head = other.m_head;
    other.m_head = nullptr;
    return *this;
}

template<typename T>
List<T>::List(int size) {
   resize(size);
}

template<typename T>
List<T>::~List(){
    resize(0);
}

template<typename T>
void List<T>::print() {
    std::cout << "My nodes: ";
    if (m_size == 0) {
        std::cout << std::endl;
        return;
    }
    for (auto iterator = m_head;
         iterator != nullptr;
         iterator = iterator->m_next) {
        std::cout << iterator->m_value;
    }

    std::cout << std::endl;
}


template<typename T>
void List<T>::resize(int newSize) {
    if (newSize == m_size) {
        return;
    }
    if (newSize < m_size) {
        auto toDelete = pNode(newSize);
        Node<T> *nextToDelete;
        for (int i = 0; i < m_size - newSize; i++) {
            nextToDelete = toDelete->m_next;
            delete toDelete;
            toDelete = nextToDelete;
        }
        m_size = newSize;
        pNode(m_size - 1)->m_next = nullptr;
        return;
    }
    if (newSize > m_size) {

        auto newNodes = new Node<T>;
        if (m_size == 0){
            m_head = newNodes;
        } else {
            pNode(m_size - 1)->m_next = newNodes;
        }
        auto currentNewNode = newNodes;
        for (int i = 0; i < newSize - m_size - 1; i++) {
            currentNewNode->m_next = new Node<T>;
            currentNewNode = currentNewNode->m_next;
        }
        m_size = newSize;
        return;
    }
}

template<typename T>
T &List<T>::operator[](int number) {
    return pNode(number)->m_value;
}

template<typename T>
const T &List<T>::operator[](int number) const {
    return pNode(number)->m_value;
}


#endif //LIST_LIST_H
