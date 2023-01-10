//
// Created by nimrod on 10-Jan-23.
//

#ifndef CPPCOURSE_LINKEDLIST_H
#define CPPCOURSE_LINKEDLIST_H

#include <ostream>

template<typename T>
class Node {
private:
    Node *next;
    T *value;
public:
    explicit Node(T *value) : value(value), next(nullptr) {

    }

    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        this->next = next;
    }

    T *getValue() const {
        return value;
    }

    void setValue(T *value) {
        this->value = value;
    }
};

template<typename T>
class LinkedList {

private:
    Node<T> *head;
    unsigned int count;

public:
    LinkedList() : count(0), head(nullptr) {}

    void insert(T *element);

    void insert(T *element, unsigned int index);

    bool remove(T *element);

    void clear();

    int size() const { return count; }

    T *operator[](int index);

    const T *operator[](int index) const;

    template<class U>
    friend std::ostream &operator<<(std::ostream &stream, LinkedList<U> &linkedList);
};

template<typename T>
void LinkedList<T>::insert(T *element) {
    if (head == nullptr) {
        head = new Node<T>(element);
        count++;
        return;
    }
    Node<T> *node = head;
    while (node->getNext() != nullptr) {
        node = node->getNext();
    }
    node->setNext(new Node<T>(element));
    count++;
}

template<typename T>
void LinkedList<T>::insert(T *element, unsigned int index) {
    Node<T> *node = head;
    for (int i = 0; i < index; ++i) {
        node = node->getNext();

    }
    Node<T> *newNode = new Node<T>(element);
    newNode->setNext(node->getNext());
    node->setNext(newNode);
    count++;
}

template<typename T>
bool LinkedList<T>::remove(T *element) {
    Node<T> *node = head;
    while (node != nullptr) {
        if (node->getValue() == element) {
            if (node->getNext() != nullptr) {
                node->setNext(node->getNext()->getNext());
            }
            count--;
            return true;
        }
        node = node->getNext();
    }
    return false;
}

template<typename T>
void LinkedList<T>::clear() {
    Node<T> *node = head;
    while (node != nullptr) {
        Node<T> *temp = node->getNext();
        delete node;
        node = temp;
    }
}

template<typename T>
T *LinkedList<T>::operator[](int index) {
    Node<T> *node = head;
    for (int i = 0; i < index; ++i) {
        node = node->getNext();

    }
    return node->getValue();
}

template<typename T>
const T *LinkedList<T>::operator[](int index) const {
    Node<T> *node = head;
    for (int i = 0; i < index; ++i) {
        node = node->getNext();
    }
    return node->getValue();
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, LinkedList<T> &list) {
    for (int i = 0; i < list.size(); ++i) {
        stream << *list[i] << " ";
    }
    stream << std::endl;
    return stream;
}

#endif //CPPCOURSE_LINKEDLIST_H
