//
// Created by alex on 3/19/21.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

template<typename T>
struct Node {
    T m_value = {};
    Node *m_next = nullptr;
    Node *m_prev = nullptr;
    Node(){std::cout<<"New";}
    ~Node(){std::cout<<"Del";}

};

#endif //LIST_NODE_H
