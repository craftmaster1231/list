//
// Created by alex on 3/19/21.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H


template<typename T>
class List {
    struct Node {
        T m_value = {};
        Node *m_next = nullptr;
        Node *m_prev = nullptr;

        Node() {
            std::cout << "New ";
            std::cout.flush();
        }

        ~Node() {
            std::cout << "Del ";
            std::cout.flush();
        }
    };



    int m_size = 0;
    Node *m_head = nullptr;
    Node *m_last = nullptr;
public:
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

    List(int);

//    List(const List<T> &);

    iterator first(){
        return m_head;
    }

    iterator last(){
        return m_last;
    }

    void resize(int);


};

template<typename T>
List<T>::List(int size) {
    resize(size);
}

//template<typename T>
//List<T>::List(const List<T> & other) {
//    resize(other.m_size);
//}

template<typename T>
void List<T>::resize(int newSize) {
    if (m_size == newSize) {
        return;
    }
    if (newSize > m_size) {
        Node *newNodes = new Node;
        if(m_head == 0) {
            m_head = newNodes;
        } else {
            m_last->m_next = newNodes;
            newNodes->m_prev = m_last;
        }
        Node *iter = newNodes;
        for(int i=0; i< newSize - m_size -1;i++){
            iter->m_next = new Node;
            iter->m_next->m_prev =iter;
            iter = iter->m_next;
        }
        m_last = iter; // =)
        m_size = newSize;
        return;
    }
    if (newSize < m_size) {
        Node *iter = m_last;
        for(int i = 0; i< m_size - newSize; i++) {
            Node *nextToDel = iter->m_prev;
            delete iter;
            iter = nextToDel;
        }
        m_last = iter;
        m_last->m_next = nullptr; // =)
        m_size = newSize;
        return;
    }
}


#endif //LIST_LIST_H
