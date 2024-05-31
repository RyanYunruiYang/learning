/*
Exercise 10.34: Use reverse_iterators to print a vector in reverse order.
*/
#include <vector>
#include <iterator>
#include <iostream>

using std::vector;

int main() {
    vector<int> original{1,2,3};

    for (auto r_iter = original.crbegin(); r_iter != original.crend(); r_iter++) {
        std::cout << *r_iter << " "; // prints 3 2 1.
    }
}