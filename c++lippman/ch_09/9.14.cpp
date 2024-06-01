/*
Exercise 9.14: Write a program to assign the elements from a list of char* 
pointers to C-style character strings to a vector of strings.
*/
#include <list>
#include <vector>
#include <string>
#include <iostream>
using std::list;
using std::vector;
using std::string;

int main() {
    list<char *> range1 = {
        (char*)"string1",
        (char*)"string2",
        (char*)"string3"
    };

    vector<string> range2;
    range2.assign(range1.begin(), range1.end());

    for (const auto& x : range2) {
        std::cout << x << std::endl;
    }
}