/* 
Exercise 9.4:
Write a function that takes a pair of iterators to a vector<int> and an
int value. Look for that value in the range and return a bool indicating whether it
was found.
*/
#include <vector>
#include <iostream>

bool findable(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target) {
    while (begin != end) {
        if (*begin == target) {
            return true;
        }
        ++begin;
    }
    return false;
}

// Usage example
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    
    int target = 10;
    if (findable(numbers.begin(), numbers.end(), target)) {
        std::cout << target << " was found!" << std::endl;
    } else {
        std::cout << target << " was not found!" << std::endl;
    }

    return 0;
}