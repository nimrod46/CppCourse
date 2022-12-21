//
// Created by nimrod on 20/12/2022.
//

#include "SortedVirusLinkedList.h"

SortedVirusLinkedList::SortedVirusLinkedList() {
    head = new VirusNode(INT_MIN);
    tail = new VirusNode(INT_MAX);
    size = 0;
    p = head;
    head->setNext(tail);
    tail->setPrevious(head);

}

SortedVirusLinkedList::SortedVirusLinkedList(SortedVirusLinkedList &sortedVirusLinkedList) {
    head = new VirusNode(INT_MIN);
    tail = new VirusNode(INT_MAX);
    size = 0;
    p = head;
    head->setNext(tail);
    tail->setPrevious(head);
    add(sortedVirusLinkedList.getlast());
    Virus *virus;
    while (sortedVirusLinkedList.getPrevious(&virus)) {
        add(virus);
    }
}

void SortedVirusLinkedList::add(Virus *virus) {
    VirusNode *node = head;
    while (*node->getVirus() < *virus) {
        node = node->getNext();
    }
    auto *newNode = new VirusNode(virus, node, node->getPrevious());
    node->getPrevious()->setNext(newNode);
    node->setPrevious(newNode);
    size++;
}

void SortedVirusLinkedList::remove(Virus *virus) {
    VirusNode *node = head;
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

Virus *SortedVirusLinkedList::getFirst() {
    p = head->getNext();
    return head->getNext()->getVirus();
}

Virus *SortedVirusLinkedList::getlast() {
    p = tail->getPrevious();
    return tail->getPrevious()->getVirus();
}

int SortedVirusLinkedList::getSize() const {
    return size;
}

bool SortedVirusLinkedList::getNext(Virus **next) {
    if (p->getNext() == nullptr) {
        return false;
    }
    if (p->getNext() != tail) {
        p = p->getNext();
        *next = (p->getVirus());
        return true;
    }
    return false;
}

bool SortedVirusLinkedList::getPrevious(Virus **previous) {
    if (p->getPrevious() == nullptr) {
        return false;
    }
    if (p->getPrevious() != head) {
        p = p->getPrevious();
        *previous = (p->getVirus());
        return true;
    }
    return false;
}



