//
// Created by alex on 3/19/21.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H
template <typename T>
struct Node{
    T m_value = {};
    Node* m_next = nullptr;
    Node(){
        std::cout<<"Node created!"<<std::endl;
    }
    ~Node(){
        std::cout << "Node with value " << m_value << " deleted!" << std::endl;
    }
};
#endif //LIST_NODE_H
