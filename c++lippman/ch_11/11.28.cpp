/*
Exercise 11.28: Define and initialize a variable to hold the result of calling find on a
map from string to vector of int.
*/

#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <utility>

using std::vector;
using std::list;
using std::map;
using std::string;
using std::pair;


int main() {
    map<string,vector<int>> big_map;

    for (int i = 0; i < 10; i++) {
        vector<int> vec;
        for (int j = 0; j <= i; j++) {
            vec.push_back(j);
        }
        big_map.insert(pair<string, vector<int>>("entry" + std::to_string(i), vec));
    }

    // std::cout << big_map["entry4"][3] << std::endl;

    map<string, vector<int>>::iterator result = big_map.find("entry4");
    if (result != big_map.end()) {
        for (int num : result->second) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}