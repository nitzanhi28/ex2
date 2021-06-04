#pragma once
//#include "globals.h"
#include "node.h"
#include "exceptions.h"

namespace mtm {
    template<class T>
    class SortedList {
        Node<T>* head;
        Node<T>* iterator;
    public:

        //constructor
        SortedList() : head(NULL), iterator(head) {};

        //destructor
        ~SortedList() {
            Node<T>* cur = this->head;
            Node<T>* next = NULL;
            while (cur) {
                next = cur->getNext();
                delete cur;
                cur = next;
            }
        };

        //copy constructor
        SortedList(const SortedList& c_list) {
            if (c_list.head == NULL) {
                this->head = NULL;
                return;
            }
            Node<T>* temp = new Node<T>(c_list.head->getData());
            this->head = temp;

            Node<T>* curr_in_new = this->head;
            Node<T>* next_in_orig = c_list.head->getNext();

            while (next_in_orig) {
                Node<T>* new_node = new Node<T>(next_in_orig->getData());
                curr_in_new->setNext(new_node);
                new_node->setLast(curr_in_new);

                curr_in_new = curr_in_new->getNext();
                next_in_orig = next_in_orig->getNext();
            }
        }

        /**
        * insert: insert new node to the sorted list.
        *
        * @param data - current node data
        */
        void insert(T data) {
            Node<T>* new_node = new Node<T>(data);
            if (this->head == NULL)
            {
                this->head = new_node;
                return;
            }

            iterator = this->head;

            if (*new_node < *iterator)
            {
                new_node->setNext(iterator);
                this->head = new_node;
                iterator->setLast(new_node);
                return;
            }
            while (iterator->getNext() != NULL)
            {
                if (*new_node < *iterator)
                {
                    new_node->setNext(iterator);
                    new_node->setLast(iterator->getLast());
                    iterator->getLast()->setNext(new_node);
                    iterator->setLast(new_node);
                    return;
                }
                iterator = iterator->getNext();
            }
            if (*new_node<*iterator){
                iterator->getLast()->setNext(new_node);
                new_node->setLast(iterator->getLast());
                iterator->setLast(new_node);
                new_node->setNext(iterator);
                return;
            }
            iterator->setNext(new_node);
            new_node->setLast(iterator);
        }

        /**
        * removeNode: remove node from the sorted list
        *
        * @param data current node data
        */
        void removeNode(T data) {
            //    TODO: implement this (with delete)
            Node<T> _data(data);
            Node<T>* cur = this->head;
            while (cur) {
                if (*cur == _data) {
                    if (cur == head) {
                        head = cur->getNext();
                        head->setLast(NULL);
                        delete cur;
                        return;
                    }
                    if (cur->getNext() == NULL) {
                        cur->getLast()->setNext(NULL);
                        delete cur;
                        return;
                    }
                    cur->getLast()->setNext(cur->getNext());
                    cur->getNext()->setLast(cur->getLast());
                    delete cur;
                    return;
                }
                cur = cur->getNext();
            }
        }


        /**
        * doesDataExist: Check current list include specific data.
        *
        * @param data - specific data.
        * @return
        *   false - if list doesnt contain the specific data, true otherwise.
        */
        bool doesDataExist(T data) {
            Node<T>* node = this->head;
            while (node)
            {
                if (node->getData() == data)
                    return true;
                node = node->getNext();
            }
            return false;
        }


        //Operator overloading
        template<class T>
        friend std::ostream& operator<<(std::ostream& out, SortedList<T> const& my_list);


        //Iterator class
        class SortedListIterator {
            Node<T>* it;
        public:
            SortedListIterator(Node<T>* _it) : it(_it) {}
            SortedListIterator& operator++() {
                this->it = this->it->getNext();
                return *this;
            }
            T operator*() {
                return this->it->getData();
            }
            bool operator== (const SortedListIterator& _it) {
                return this->it == _it.it;
            }
            bool operator!= (const SortedListIterator& _it) {
                return this->it != _it.it;
            }
        };

        /**
        * begin: set the sorted list iterator to first node
        *
        * @return
        *   poinetr first node
        */
        SortedListIterator begin() const {
            return SortedListIterator(head);
        }

        /**
        * end: set the sorted list iterator to NULL
        *
        * @return
        *   poinetr to the end of the sorted list
        */
        SortedListIterator end() const{
            return SortedListIterator(NULL);
        }
    };

    //Operator overloading
    template <class Q>
    std::ostream& operator<<(std::ostream& out, const SortedList<Q>& my_list)
    {
        Node<Q>* node = my_list.head;
        while (node != NULL)
        {
            out << node->getData() << std::endl;
            node = node->getNext();
        }
        return out;
    }


}
