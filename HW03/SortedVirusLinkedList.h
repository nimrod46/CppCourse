//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_SORTEDVIRUSLINKEDLIST_H
#define CPPCOURSE_SORTEDVIRUSLINKEDLIST_H


#include <climits>
#include "VirusOLD.h"

class SortedVirusLinkedList {

private:
    class VirusNode {
        VirusOLD *virus;
        VirusNode *next;
        VirusNode *previous;

    public: //All allocation are handled outside the class wo we don't need big three
        explicit VirusNode(VirusOLD *virus) : VirusNode(virus, nullptr, nullptr) {

        }

        VirusNode(VirusOLD *virus, VirusNode *next, VirusNode *last) {
            this->virus = virus;
            this->next = next;
            this->previous = last;
        }

        bool isEquals(VirusOLD &otherVirus) {
            return virus != nullptr && *virus == otherVirus;
        }

        VirusNode *getNext() {
            return next;
        }

        VirusNode *getPrevious() {
            return previous;
        }

        void setNext(VirusNode *node) {
            this->next = node;
        }

        void setPrevious(VirusNode *node) {
            this->previous = node;
        }

        VirusOLD *getVirus() {
            return virus;
        }
    };

    VirusNode *head;
    VirusNode *tail;
    VirusNode *p;

    int size;


public: //There is no need for move ctor and oper as there is no logic in moving the SortedLinkedList in my code
    SortedVirusLinkedList();

    SortedVirusLinkedList(SortedVirusLinkedList &sortedVirusLinkedList);

    SortedVirusLinkedList &operator=(const SortedVirusLinkedList &rhs);

    ~SortedVirusLinkedList();

    void add(VirusOLD *virus);

    void remove(VirusOLD *virus);

    VirusOLD *getFirst();

    VirusOLD *getlast();

    bool getNext(VirusOLD **next);

    bool getPrevious(VirusOLD **previous);

    int getSize() const;
};


#endif //CPPCOURSE_SORTEDVIRUSLINKEDLIST_H
