/*
Exercise 10.3: Use accumulate to sum the elements in a vector<int>.
*/
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using std::vector;


int main() {
    vector<int> target = {1,2,3,4,5,6,7,8,9,10};

    int sum = std::accumulate(target.cbegin(), target.cend(), 0);
    std::cout << sum << std::endl; // returns 55
}