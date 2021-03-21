//
// Created by alex on 3/19/21.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

template<typename T>
struct Node {
    T m_value = {};
    Node *m_next = nullptr;

    Node() {
        ;
        std::cout << "Created!\t" << this << std::endl;
    }

    ~Node() {
        std::cout << "Deleted!\n" << this << std::endl;
    }
};

#endif //LIST_NODE_H
