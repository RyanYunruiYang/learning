/*
Exercise 10.7: Determine if there are any errors in the following programs and, if so,
correct the error(s):
(a) 
    vector<int> vec; list<int> lst; int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), vec.begin());
(b)
    vector<int> vec;
    vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
    fill_n(vec.begin(), 10, 0);
*/
#include <vector>
#include <list>
#include <iostream>
#include <iterator> // Include the <iterator> header
using std::vector;
using std::list;


int main() {
    vector<int> vec; list<int> lst; int i;
    while(std::cin >> i) {
        lst.push_back(i);
    }
    copy(lst.cbegin(), lst.cend(), std::back_inserter(vec)); // Use std::back_inserter to create a back insert iterator for vec

    for (const auto& x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}