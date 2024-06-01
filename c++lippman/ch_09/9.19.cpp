/*
Exercise 9.19: Rewrite the program from the previous exercise to use a list. List the
changes you needed to make.
*/


#include<iostream>
#include<list>
using std::string;
using std::list;


int main() {
    string new_str;
    list<string> list_save;

    while(std::cin >> new_str) {
        list_save.push_back(new_str);
    }

    std::cout << std::endl << "list: " << std::endl;
    for (const auto& x: list_save) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}