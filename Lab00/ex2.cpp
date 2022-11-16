#include <iostream>

using namespace std;

struct Complex {
    double a;
    double b;
};

//int main() {
//    Complex z1{}, z2{};
//    cout << "z1: a=";
//    cin >> z1.a;
//    cout << "z1: b=";
//    cin >> z1.b;
//
//    cout << "z2: a=";
//    cin >> z2.a;
//    cout << "z2: b=";
//    cin >> z2.b;
//
//    char c;
//    cout << "Operator=";
//    cin >> c;
//
//    if (c == '+') {
//        cout << z1.a + z2.a << "+" << z2.b + z2.b << "i" << endl;
//    } else if (c == '-') {
//        cout << z1.a - z2.a << "+" << z2.b - z2.b << "i" << endl;
//    } else if (c == '*') {
//        cout << z1.a * z2.a - z1.b * z2.b << "+" << z1.a * z2.b + z1.b * z2.a << "i" << endl;
//    }
//    return 0;
//}
