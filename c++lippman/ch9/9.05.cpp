/* 
Exercise 9.4:
Write a function that takes a pair of iterators to a vector<int> and an
int value. Look for that value in the range and return a bool indicating whether it
was found.
*/
/*---------------------------------------------*/
/*
Exercise 9.5:
Rewrite the previous program to return an iterator to the requested element.
Note that the program must handle the case where the element is not found.
*/

#include <vector>
#include <iostream>

std::vector<int>::const_iterator findable(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target) {
    while (begin != end) {
        if (*begin == target) {
            return begin;
        }
        ++begin;
    }
    return end;
}

// Usage example
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    
    int target = 10;
    auto x = findable(numbers.begin(), numbers.end(), target);

    return 0;
}