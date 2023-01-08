//
// Created by nimrod on 08-Jan-23.
//

#include <ostream>

#ifndef CPPCOURSE_QUEUE_H
#define CPPCOURSE_QUEUE_H

template<typename T>
class Node {
    T *value;
    Node<T> *next;
    Node<T> *previous;

public: //All allocation are handled outside the class wo we don't need big three
    explicit Node(T *node) : Node(node, nullptr, nullptr) {

    }

    Node(T *value, Node<T> *next, Node<T> *last) {
        this->value = value;
        this->next = next;
        this->previous = last;
    }

    bool isEquals(T &other) {
        return value != nullptr && *value == other;
    }

    Node<T> *getNext() {
        return next;
    }

    Node<T> *getPrevious() {
        return previous;
    }

    void setNext(Node<T> *node) {
        this->next = node;
    }

    void setPrevious(Node<T> *node) {
        this->previous = node;
    }

    T *getValue() {
        return value;
    }
};

template<typename T>
class Queue {
private:

    Node<T> *head;
    Node<T> *tail;
    Node<T> *cursor;

    int size;

    void addNewNodeBefore(T *value, Node<T> *first);

public: //There is no need for move ctor and oper as there is no logic in moving the SortedLinkedList in my code
    Queue(T &defaultMinValue, T &defaultMaxValue);

    Queue(Queue<T> &rhs);

    Queue &operator=(const Queue &rhs);

    ~Queue();

    void addByPriority(T *value);

    void add(T *value);

    void remove(T *virus);

    T *getFirst();

    T *getlast();

    bool getNext(T **next);

    bool getPrevious(T **previous);

    int getSize() const;

    template<class U>
    friend std::ostream &operator<<(std::ostream &stream, Queue<U> &queue);

};

#endif //CPPCOURSE_QUEUE_H

//
// Created by nimrod on 20/12/2022.
//

template<typename T>
Queue<T>::Queue(T &defaultMinValue, T &defaultMaxValue) {
    head = new Node<T>(new T(defaultMinValue));
    tail = new Node<T>(new T(defaultMaxValue));
    size = 0;
    cursor = head;
    head->setPrevious(tail);
    tail->setNext(head);

}

template<typename T>
Queue<T>::Queue(Queue<T> &rhs) {
    head = nullptr;
    tail = nullptr;
    cursor = nullptr;
    size = 0;
    *this = rhs;
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &rhs) {
    if (this == &rhs) {
        return (*this);
    }

    delete head;
    delete tail;
    delete cursor;

    head = new Node<T>(new T(rhs.head->getValue()));
    tail = new Node<T>(new T(rhs.tail->getValue()));
    size = 0;
    cursor = head;
    head->setPrevious(tail);
    tail->setNext(head);
    if (rhs.size == 0) {
        return *this;
    }

    Node<T> *vNode = rhs.tail->getNext();
    while (vNode->getNext()) {
        addByPriority(vNode->getValue());
        vNode = vNode->getNext();
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    Node<T> *vNode = head;
    while (vNode) {
        Node<T> *tmpNode = vNode->getPrevious();
        delete vNode;
        vNode = tmpNode;
    }
}

template<typename T>
void Queue<T>::addNewNodeBefore(T *value, Node<T> *first) {
    Node<T> *newNode = new Node<T>(value, first, first->getPrevious());
    first->getPrevious()->setNext(newNode);
    first->setPrevious(newNode);
    size++;
}

template<typename T>
void Queue<T>::addByPriority(T *value) {
    Node<T> *node = tail;
    while (*node->getValue() < *value) {
        node = node->getNext();
    }
    addNewNodeBefore(value, node);
}

template<typename T>
void Queue<T>::add(T *value) {
    Node<T> *first = tail->getNext();
    addNewNodeBefore(value, first);
}

template<typename T>
void Queue<T>::remove(T *virus) {
    Node<T> *node = head;
    while (node != nullptr && !node->isEquals(*virus)) {
        node = node->getPrevious();
    }

    if (node == nullptr) {
        return;
    }
    size--;
    node->getNext()->setPrevious(node->getPrevious());
    node->getPrevious()->setNext(node->getNext());
    delete node;
}

template<typename T>
T *Queue<T>::getFirst() {
    cursor = head->getPrevious();
    return head->getPrevious()->getValue();
}

template<typename T>
T *Queue<T>::getlast() {
    cursor = tail->getNext();
    return tail->getNext()->getValue();
}

template<typename T>
int Queue<T>::getSize() const {
    return size;
}

template<typename T>
bool Queue<T>::getNext(T **next) {
    if (cursor->getNext() == nullptr) {
        return false;
    }
    if (cursor->getNext() != head) {
        cursor = cursor->getNext();
        *next = (cursor->getValue());
        return true;
    }
    return false;
}

template<typename T>
bool Queue<T>::getPrevious(T **previous) {
    if (cursor->getPrevious() == nullptr) {
        return false;
    }
    if (cursor->getPrevious() != tail) {
        cursor = cursor->getPrevious();
        *previous = (cursor->getValue());
        return true;
    }
    return false;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, Queue<T> &queue) {
    T *value;
    stream << *queue.getFirst();
    while (queue.getPrevious(&value)) {
        stream << *value;
    }
    stream << std::endl;
    return stream;
}
