/*
Exercise 10.15: Write a lambda that captures an int from its enclosing function and
takes an int parameter. The lambda should return the sum of the captured int and
the int parameter
*/
#include <iostream> 

template <typename Func>
void elsewhere(int input, Func f) {
    std::cout << f(input) << std::endl;
}


int main() {
    int constant = 5;
    auto sum = [constant](int x)->int{return constant+x;};
    elsewhere(10, sum); // outputs 15

    int y = 1;
    auto successor = [y] (const int &x) { return x + y; };
    std::cout << successor(1) << std::endl; // outputs 2
}