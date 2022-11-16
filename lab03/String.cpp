//
// Created by nimrod on 15-Nov-22.
//

#include "String.h"
#include <cstring>
#include <iostream>

String::String() {
    len = 0;
    c_str = nullptr;
}

String::String(const char *str) {
    len = strlen(str);
    c_str = strdup(str);
}

void String::destroy() {
    delete(c_str);
}

void String::assign(const String &str) {
    len = str.len;
    c_str = strdup(str.c_str);
}

void String::print() {
    std::cout << c_str << std::endl;
}

String String::copy() const {
    return String(c_str);
}

int String::length() const {
    return len;
}

char String::at(int index) const {
    return c_str[index];
}

String String::substring(int start, int end) const {
    String new_start = substring(start);
    new_start.replace(end, '\0');
    new_start.len = end - start + 1;
    return new_start;
}

String String::substring(int start) const {
    return String(c_str + start);
}

void String::replace(int index, char c) {
    c_str[index] = c;
}

bool String::equals(const String &a, const String &b) {
    if(a.len != b.len) {
        return false;
    }
    for (int i = 0; i < a.len; ++i) {
        if(a.c_str[i] != b.c_str[i]) {
            return false;
        }
    }
    return true;
}
