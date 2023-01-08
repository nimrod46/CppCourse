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
    Node<T> *p;

    int size;
public:
public: //There is no need for move ctor and oper as there is no logic in moving the SortedLinkedList in my code
    Queue(T &defaultMinValue, T &defaultMaxValue);

    Queue(Queue &queue);

    Queue &operator=(const Queue &rhs);

    ~Queue();

    void add(T *value);

    void remove(T *virus);

    T *getFirst();

    T *getlast();

    bool getNext(T **next);

    bool getPrevious(T **previous);

    int getSize() const;

    template<class U> friend std::ostream &operator<<(std::ostream &stream, Queue<U> &queue);
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
    p = head;
    head->setNext(tail);
    tail->setPrevious(head);

}

template<typename T>
Queue<T>::Queue(Queue &rhs) {
    head = nullptr;
    tail = nullptr;
    p = nullptr;
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
    delete p;

    head = new Node<T>(new T(rhs.head->getValue()));
    tail = new Node<T>(new T(rhs.tail->getValue()));
    size = 0;
    p = head;
    head->setNext(tail);
    tail->setPrevious(head);
    if (rhs.size == 0) {
        return *this;
    }

    Node<T> *vNode = rhs.tail->getPrevious();
    while (vNode->getPrevious()) {
        add(vNode->getValue());
        vNode = vNode->getPrevious();
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    Node<T> *vNode = head;
    while (vNode) {
        Node<T> *tmpNode = vNode->getNext();
        delete vNode;
        vNode = tmpNode;
    }
}

template<typename T>
void Queue<T>::add(T *value) {
    Node<T> *node = head;
    while (*node->getValue() < *value) {
        node = node->getNext();
    }
    auto *newNode = new Node<T>(value, node, node->getPrevious());
    node->getPrevious()->setNext(newNode);
    node->setPrevious(newNode);
    size++;
}

template<typename T>
void Queue<T>::remove(T *virus) {
    Node<T> *node = head;
    while (node != nullptr && !node->isEquals(*virus)) {
        node = node->getNext();
    }

    if (node == nullptr) {
        return;
    }
    size--;
    node->getPrevious()->setNext(node->getNext());
    node->getNext()->setPrevious(node->getPrevious());
    delete node;
}

template<typename T>
T *Queue<T>::getFirst() {
    p = head->getNext();
    return head->getNext()->getValue();
}

template<typename T>
T *Queue<T>::getlast() {
    p = tail->getPrevious();
    return tail->getPrevious()->getValue();
}

template<typename T>
int Queue<T>::getSize() const {
    return size;
}

template<typename T>
bool Queue<T>::getNext(T **next) {
    if (p->getNext() == nullptr) {
        return false;
    }
    if (p->getNext() != tail) {
        p = p->getNext();
        *next = (p->getValue());
        return true;
    }
    return false;
}

template<typename T>
bool Queue<T>::getPrevious(T **previous) {
    if (p->getPrevious() == nullptr) {
        return false;
    }
    if (p->getPrevious() != head) {
        p = p->getPrevious();
        *previous = (p->getValue());
        return true;
    }
    return false;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, Queue<T>& queue) {
    T *value;
    stream << *queue.getFirst();
    while (queue.getNext(&value)) {
        stream << *value;
    }
    stream << std::endl;
    return stream;
}




