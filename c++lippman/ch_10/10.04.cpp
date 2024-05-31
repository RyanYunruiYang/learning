/*
Exercise 10.4: Assuming v is a vector<double>, what, if anything, is wrong with
calling accumulate(v.cbegin(), v.cend(), 0)?

Answer: Will truncate doubles to integers.
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using std::vector;


int main() {
    vector<double> target = {1.9, 2.9};

    int sum = std::accumulate(target.cbegin(), target.cend(), 0);
    std::cout << sum << std::endl; // returns 3. truncated
}