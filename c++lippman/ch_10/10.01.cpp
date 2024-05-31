/*
Exercise 10.1: The algorithm header defines a function named count that, like
find, takes a pair of iterators and a value. count returns a count of how often that
value appears. Read a sequence of ints into a vector and print the count of how
many elements have a given value.
*/

#include <iostream>
#include <vector> 
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
    vector<int> searchspace = {1,2,2,3,3,3,4,4,4,4};

    cout << std::count(searchspace.begin(), searchspace.end(), 2) << endl;
    // correctly prints 2
}