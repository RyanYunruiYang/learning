/*
Exercise 11.12: Write a program to read a sequence of strings and ints, storing each
into a pair. Store the pairs in a vector
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
    vector<pair<string, int>> pairvector;

    string word;
    int x;
    while (std::cin >> word && std::cin >> x) {
        pairvector.push_back({word, x});
    }

    for (const auto &pair_si : pairvector) {
        std::cout << pair_si.first << "->" << pair_si.second << " ";
    }
    std::cout << std::endl;
    

}