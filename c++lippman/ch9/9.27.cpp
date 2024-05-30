/*
Exercise 9.27: Write a program to find and remove the odd-valued elements in a
forward_list<int>.
*/
#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> input_list = {1,2,3,3,3,4,5,5,10,10,10,10};

    auto prev = input_list.before_begin();
    auto cur = input_list.begin();

    while(cur != input_list.end()) {
        if (*cur % 2 == 1) {
            cur = input_list.erase_after(prev);
        }
        else {
            prev = cur++;
        }
    }

    for (const auto& x : input_list) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // Correctly gives 2,4,10,10,10,10.
}