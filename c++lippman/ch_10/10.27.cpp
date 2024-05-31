/*
Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library defines function
named unique_copy that takes a third iterator denoting a destination into which
to copy the unique elements. Write a program that uses unique_copy to copy the
unique elements from a vector into an initially empty list.
*/

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using std::vector;
using std::list;


int main() {
    vector<int> container1{1,2,2,3,3,3,1};
    list<int> container2;

    std::sort(container1.begin(), container1.end());
    std::unique_copy(container1.begin(), container1.end(), std::back_inserter(container2));

    for (const auto& x : container2) {
        std::cout << x << " "; // prints 1 2 3
    }
    std::cout << std::endl;
}