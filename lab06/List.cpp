#include "List.h"
#include <cstdlib>

List::List() : head(NULL), count(0) {}

void List::insert(int elem) {
	head = new Node(elem, head);
	count++;
}

void List::clear() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	count = 0;
	head = NULL;
}

List::List(const List& other) : head(NULL), count(0) {
	Node* temp = other.head;
	while (temp) {
		insert(temp->data);
		temp = temp->next;
	}
}

List& List::operator=(const List& rhs) {
	if (this != &rhs) {
		clear();
		Node* temp = rhs.head;
		while (temp) {
			insert(temp->data);
			temp = temp->next;
		}
	}
	return *this;
}

List::~List() {
	clear();
}

int& List::operator[](int index) {
	if (index < 0 || index >= count) {
		cerr << "whoa there buddy!" << endl;
		exit(1);
	}
	Node* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp->data;
}

const int& List::operator[](int index) const {
	if (index < 0 || index >= count) {
		cerr << "whoa there buddy" << endl;
		exit(1);
	}
	Node* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp->data;
}

ostream& operator<<(ostream& out, const List& list) {
	List::Node* temp = list.head;
	while (temp) {
		if (temp != list.head) {
			out << ",";
		}
		out << temp->data;
		temp = temp->next;
	}
	return out;
}

void List::remove(int elem) {
	if (!head) { return; }
	Node* temp = head;
	if (temp->data == elem) {
		head = head->next;
		delete temp;
		count--;
		return;
	}
	while (temp->next && temp->next->data != elem) {
		temp = temp->next;
	}
	if (temp->next) {
		Node* victim = temp->next;
		temp->next = victim->next;
		delete victim;
		count--;
	}
}

int List::size() const {
	return count;
}

List::Node::Node(int data, Node* next) : data(data), next(next) {}