/*
Exercise 9.20: Write a program to copy elements from a list<int> into two deques.
The even-valued elements should go into one deque and the odd ones into the other.
*/
#include <list>
#include <deque>
#include <iostream>
using std::list;
using std::deque;

int main() {
    list<int> big_list = {1,2,3,5,10,10,10};
    deque<int> odds;
    deque<int> evens;

    for (const auto& x : big_list) {
        if (x % 2 == 0) {
            evens.push_back(x);
        }
        if (x % 2 == 1)  {
            odds.push_back(x);
        }
    }

    // Testing to make sure we used copies
    big_list.front() = 1001;

    // Printing even deque and then odd deque
    std::cout  << "evens: " << std::endl;
    for (const auto& x : evens) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout  << "odds: " << std::endl;
    for (const auto& x : odds) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

}