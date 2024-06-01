/*
Exercise 9.18:
Write a program to read a sequence of strings from the standard input
into a deque. Use iterators to write a loop to print the elements in the deque.
*/

#include<iostream>
#include<deque>
using std::string;
using std::deque;


int main() {
    string new_str;
    deque<string> deque_save;

    while(std::cin >> new_str) {
        deque_save.push_back(new_str);
    }

    std::cout << std::endl << "deque: " << std::endl;
    for (const auto& x: deque_save) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}