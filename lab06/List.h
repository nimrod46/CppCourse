    //
// Created by Abziz on 01/12/2020.
//

#ifndef LAB6_LIST_H
#define LAB6_LIST_H

#include <iostream>

using namespace std;

class List {
public:

	/**
	 * Create an empty list of integers
	 */
	List();

	/* big three */
	List(const List& other);

	List& operator=(const List& rhs);

	~List();

	/**
	 * insert an element to the head of the list
	 * @param elem
	 */
	void insert(int elem);

	/**
	 * remove the first occurrence of elem in the list
	 * @param elem
	 */
	void remove(int elem);

	/**
	 * remove all elements from the list
	 */
	void clear();

	/**
	 * return how many elements are in the list
	 */
	int size() const;

	/**
	 * access an element at a given index
	 * @param index
	 * @return
	 */
	int& operator[](int index);


	/**
	 * return an element at a given index
	 * @param index
	 * @return
	 */
	const int& operator[](int index) const;

	friend ostream& operator<<(ostream& out, const List& list);

private:
	struct Node {
		int data;
		Node* next;

		Node(int data, Node* next);
	};

	Node* head;
	int count;
};

ostream& operator<<(ostream& out, const List& list);

#endif //LAB6_LIST_H
