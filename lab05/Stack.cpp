////
//// Created by nimrod on 29-Nov-22.
////
//
//#include "Stack.h"
//
//Stack::Stack(int size) {
//    data = new int[size];
//    index = -1;
//}
//
//Stack::Stack(const Stack &stack) {
//    data = new int[stack.index + 1];
//    for (int i = 0; i <= stack.index; ++i) {
//        data[i] = stack.data[i];
//    }
//}
//
//Stack &Stack::operator=(const Stack &rhs) {
//    if (this == &rhs) {
//        return (*this);
//    }
//    delete[] data;
//    index = rhs.index;
//    data = new int[index + 1];
//
//    for (int i = 0; i <= index; i++) {
//        data[i] = rhs.data[i];
//    }
//    return *this;
//}
//
//Stack::Stack(Stack &&rhs) : data(rhs.data), index(rhs.index) {
//    rhs.data = nullptr;
//}
//
//Stack &Stack::operator=(Stack &&rhs) {
//    data = rhs.data;
//    index = rhs.index;
//    rhs.data = nullptr;
//    return *this;
//}
//
//Stack::~Stack() {
//    delete[] data;
//}
//
//void Stack::push(int num) {
//    data[++index] = num;
//}
//
//int Stack::pop() {
//    return data[index--];
//}
//
//int Stack::top() const {
//    return data[index];
//}
//
//bool Stack::empty() const {
//    return index == -1;
//}
//
//void Stack::transfer(Stack &stack) const {
//    for (int i = 0; i <= index; ++i) {
//        stack.push(data[i]);
//    }
//}
//
//int Stack::operator*() const {
//    return top();
//}
//
//void Stack::operator~() {
//    index = 0;
//}
//
//bool Stack::operator!() const {
//    return empty();
//}
//
//void Stack::operator<<(int num) {
//    push(num);
//}
//
//void Stack::operator>>(int &num) {
//    num = pop();
//}
//
//void Stack::operator<<(Stack &stack) {
//    for (int i = 0; i <= stack.index; ++i) {
//        push(stack.data[i]);
//    }
//}
//
//void Stack::operator>>(Stack &stack) {
//    for (int i = 0; i <= index; ++i) {
//        stack.push(data[i]);
//    }
//}
//
//std::ostream &operator<<(std::ostream &stream, Stack& stack) {
//    for (int i = 0; i <= stack.index; ++i) {
//        stream << stack.data[i] << " ";
//    }
//    return stream;
//}
//
//
//
//
//
//
