#pragma once
#include "sortedList.h"

template<class T>
class Node {
    T data;
    Node<T>* next;
    Node<T>* last;

public:
    //creator
    Node() : data(NULL), next(NULL), last(NULL) {};

    explicit Node(const T data) : data(data), next(NULL), last(NULL) {}

    //copy
    Node(const Node& node) : data(node.data), next(NULL), last(NULL) {}

    //destroy
    ~Node() {}


    Node<T>* getNext() {
        return this->next;
    }
    Node<T>* getLast() {
        return this->last;
    }
    T getData() {
        return this->data;
    }
    bool operator== (const Node& node) const {
        return data == node.data;
    }
    bool operator!= (const Node& node) const {
        return data != node.data;
    }
    bool operator> (const Node& node) const {
        return this->data > node.data;
    }
    bool operator< (const Node& node) const {
        return this->data < node.data;
    }
    bool operator>= (const Node& node) const {
        return this->data >= node.data;
    }
    bool operator<= (const Node& node) const {
        return this->data <= node.data;
    }
    template<class Q>
    friend ostream& operator<<(ostream& out, const Node<Q>& node);

    void setNext(Node<T>* next);

    void setLast(Node<T>* last);
};

template<class T>
void Node<T>::setNext(Node<T>* next) {
    Node::next = next;
}

template<class T>
void Node<T>::setLast(Node<T>* last) {
    Node::last = last;
}

