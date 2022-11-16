//
// Created by nimrod on 15-Nov-22.
//

#include <iostream>
#include "String.h"


bool is_poli(String a, int first, int last) {
    if (first >= last) {
        return true;
    }

    if (a.at(first) != a.at(last)) {
        return false;
    }

    return is_poli(a, ++first, --last);
}

//int main() {
//
//    String s1 = "123321";
//    String s2 = s1.copy();
//    String s3 = s1.copy();
//
//    s2.replace(3, '2');
//    s3.replace(3, '3');
//
//    s1.print();
//    s2.print();
//    s3.print();
//
//    //std::cout << String::equals(s1, s2);
//
//    std::cout << is_poli(s1, 0, s1.length() - 1) << std::endl;
//
//    s1 = s1.substring(0, 1);
//    s1.print();
//
//
//}
