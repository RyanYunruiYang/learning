/* 
Exercise 10.14: Write a lambda that takes two ints and returns their sum.
*/
#include <iostream>

int main() {
    auto sum = [](int x, int y)->int{return x+y;};

    std::cout << sum(2,2) << std::endl; // returns 4
    std::cout << sum(2.5,2.5) << std::endl; // returns 4
}