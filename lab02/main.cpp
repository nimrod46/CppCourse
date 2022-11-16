//
// Created by nimrod on 08-Nov-22.
//
#include <iostream>
#include <sstream>

using namespace std;

void rev_printer() {
    string line;
    if (!getline(cin, line)) {
        return;
    }
    rev_printer();
    cout << line << endl;
}

bool string_to_int(string s, int &num) {
    int dem = 1;
    int res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        // Print current character
        if (s[i] > '9' || s[i] < '0') {
            return false;
        }
        res += (s[i] - '0') * dem;
        dem *= 10;
    }
    num = res;
    return true;
}

void str_to_ints(string str, int (&nums)[100]) {
    stringstream s(str);
    string line;
    int i = 0;
    while (getline(s, line, ' ')) {
        int num;
        string_to_int(line, num);
        nums[i] = num;
        i++;
    }
}

//int main() {
//    //rev_printer();
//    int num;
//    // string_to_int("12", num);
//    int nums[100];
//    str_to_ints("12 4 5 8 56", nums);
//
//    return 0;
//}

