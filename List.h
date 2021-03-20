//
// Created by alex on 3/19/21.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include "Node.h"
template <typename T>
class List{
    int m_size=0;
    Node<T> * m_head = nullptr;
    Node<T> * pNode(int number);
public:
    const int& size() const;

    List(int size);

    List(const List & other);

    List<T> & operator= (const List<T> other);

    T & operator[](int number);

    void resize(int newSize);

    void print();

};
template<typename T>
const int& List<T>::size() const{
    return m_size;
}

template<typename T>
List<T>::List(const List<T>& other){
    m_size = other.m_size;
    *this = List<T>(other.m_size);
    auto otherIter = other.m_head;
    auto thisIter = m_head;
    for(int i =0; i < m_size;i++){
        thisIter->m_value=otherIter->m_value;
        thisIter = thisIter->next;
        otherIter = otherIter->next;
    }
}

template <typename T>
Node<T>* List<T>::pNode(int number){
    if (number > m_size){
        return nullptr;
    }
    auto currentNode=m_head;
    for(int i=0;i<number && i < m_size; i++){
        currentNode= currentNode->m_next;
    }
    return currentNode;
}

template<typename T>
List<T>& List<T>::operator= (const List<T> other){
    *this = List<T>(other);
    return *this;
}

template<typename T>
List<T>::List(int size){
    m_size = size;
    if(size == 0){
        return;
    }
    m_head = new Node<T>;
    auto currentNode = m_head;
    for(int i = 0;i < size-1;i++){
        currentNode->m_next=new Node<T>;
        currentNode = currentNode->m_next;
    }
}

template <typename T>
void List<T>::print(){
    std::cout<<"My nodes: ";
    if(m_size == 0){
        std::cout<<std::endl;
        return;
    }
    for(auto iterator = m_head;
        iterator!= nullptr;
        iterator = iterator->m_next){
        std::cout<<iterator->m_value;
    }

    std::cout<<std::endl;
}

template<typename T>
void List<T>::resize(int newSize){
    if(newSize == m_size){
        return;
    }
    if(newSize < m_size){
        auto toDelete = pNode(newSize);
        Node<T> * nextToDelete;
        for(int i = 0; i < m_size - newSize; i++){
            nextToDelete=toDelete->m_next;
            delete toDelete;
            toDelete=nextToDelete;
        }
        m_size=newSize;
        pNode(m_size - 1)->m_next= nullptr;
        return;
    }
    if(newSize > m_size){
        auto* last = pNode(m_size - 1);
        auto newNodes = new Node<T>;
        last->m_next=newNodes;
        auto currentNewNode = newNodes;
        for(int i=0;i< newSize - m_size - 1; i++){
            currentNewNode->m_next= new Node<T>;
            currentNewNode=currentNewNode->m_next;
        }
        m_size=newSize;
        return;
    }
}
template<typename T>
T & List<T>::operator[](int number){
    return *pNode(number);
}
#endif //LIST_LIST_H
