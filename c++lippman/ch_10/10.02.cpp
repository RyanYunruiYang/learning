/*
Exercise 10.2: Repeat the previous program, but read values into a list of strings
*/

#include <iostream>
#include <vector> 
#include <list> 
#include <algorithm>
#include <string>
using std::vector;
using std::list;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    list<string> searchspace = {"one", "one", "two", "three"};

    cout << std::count(searchspace.begin(), searchspace.end(), "one") << endl;
    // correctly prints 2
}