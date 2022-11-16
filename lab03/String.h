//
// Created by nimrod on 15-Nov-22.
//

#ifndef CPPCOURSE_STRING_H
#define CPPCOURSE_STRING_H


class String {
private:
    int len;
    char *c_str;
public:
    String();

    String(const char *str);

    void destroy();

    void assign(const String &str);

    void print();

    String copy() const;

    int length() const;

    char at(int index) const;

    String substring(int start, int end) const;

    String substring(int start) const;

    void replace(int index, char c);

    static bool equals(const String &a, const String &b);
};


#endif //CPPCOURSE_STRING_H
