/*
Exercise 10.6: Using fill_n, write a program to set a sequence of int values to 0.
*/
#include <list>
#include <iostream>
#include <algorithm>

using std::list;
using std::cout;
using std::cin;
using std::endl;


int main() {
    list<int> all_negative(10, -1);

    for (const auto& x : all_negative) {
        std::cout << x << " ";
    }
    std::cout << endl;

    std::fill_n(all_negative.begin(), all_negative.size(), 0);

    for (const auto& x : all_negative) {
        std::cout << x << " ";
    }
    std::cout << endl;    
}
