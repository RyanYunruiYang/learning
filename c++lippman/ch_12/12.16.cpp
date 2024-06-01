/*
Exercise 12.16: Compilers don't always give easy-to-understand error
messages if we attempt to copy or assign a unique_ptr. Write a program that
contains these errors to see how your compiler diagnoses them.
*/

#include <iostream>
#include <memory>

using std::unique_ptr;
using std::cout; 

int main() {
    unique_ptr<int> p1(new int(42));
    cout << *p1 << std::endl;

    unique_ptr<int> p2(p1);
    
    unique_ptr<int> p3;
    p3 = p2;
}