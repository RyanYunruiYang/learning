/*
Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive, into three
other containers. Use an inserter, a back_inserter, and a front_inserter,
respectivly to add elements to these containers. Predict how the output sequence varies
by the kind of inserter and verify your predictions by running your programs.
*/

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <deque>
#include <forward_list>
#include <set>
using std::vector;
using std::list;


int main() {
    vector<int> original{1,2,3,4,5,6,7,8,9};
    // std::sort(original.begin(), original.end());


    list<int> ilist;
    std::unique_copy(original.begin(), original.end(), std::back_inserter(ilist));
    for (const auto& x : ilist) {
        std::cout << x << " "; // prints 1 2 3 4 5 6 7 8 9
    }
    std::cout << std::endl;

    std::set<int> iset;
    std::unique_copy(original.begin(), original.end(), std::inserter(iset, iset.begin()));
    for (const auto& x : iset) {
        std::cout << x << " "; // prints 1 2 3 4 5 6 7 8 9 
    }
    std::cout << std::endl;

    std::forward_list<int> ifl;
    std::unique_copy(original.begin(), original.end(), std::front_inserter(ifl));
    for (const auto& x : ifl) {
        std::cout << x << " "; // prints 9 8 7 6 5 4 3 2 1 
    }
    std::cout << std::endl;    

}