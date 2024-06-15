/*
Exercise 16.52: Write a program to check your answer to the previous question.
*/
#include <iostream>
#include <string>
using std::string;

template <typename T, typename... Args>
void foo(const T&, const Args& ... rest) {
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(rest) << std::endl;
}

int main() {
    int i=0; double d=3.14; string s ="how now brown cow";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
}