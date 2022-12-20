//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_SORTEDVIRUSLINKEDLIST_H
#define CPPCOURSE_SORTEDVIRUSLINKEDLIST_H


#include <climits>
#include "Virus.h"

class SortedVirusLinkedList {

private:
    class VirusNode {
        Virus *virus;
        VirusNode *next;
        VirusNode *previous;

    public:
        explicit VirusNode(int defaultScore) : VirusNode(new Virus(defaultScore), nullptr, nullptr) {

        }

        VirusNode(Virus *virus, VirusNode *next, VirusNode *last) {
            this->virus = virus;
            this->next = next;
            this->previous = last;
        }

        bool isEquals(Virus &otherVirus) {
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

        Virus *getVirus() {
            return virus;
        }
    };

    VirusNode *head;
    VirusNode *tail;
    VirusNode *p;

    int size;


public:
    SortedVirusLinkedList();

    SortedVirusLinkedList(SortedVirusLinkedList &sortedVirusLinkedList);

    void add(Virus *virus);

    void remove(Virus *virus);

    Virus *getFirst();

    Virus *getlast();

    bool getNext(Virus **next);

    bool getPrevious(Virus **previous);

    int getSize() const;
};


#endif //CPPCOURSE_SORTEDVIRUSLINKEDLIST_H