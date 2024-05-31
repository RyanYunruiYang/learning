/*
Exercise 11.16: Using a map iterator, write an expression that assigns a value to an element. 
*/
#include <map>
#include <iostream>

using std::map;

int main() {
    map<int, int> map = {{1,1}, {2,2}};
    auto start = map.begin();
    start->second = 1000;

    std::cout << map[1] << std::endl;
}