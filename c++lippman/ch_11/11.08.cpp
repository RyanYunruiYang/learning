/*
 * Exercise 11.8: Write a program that stores the excluded words in a vector
 * instead of in a set. What are the advantages to using a set?
 */

#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>

using std::vector;
using std::list;
using std::map;
using std::string;

int main() {
    map<string, size_t> word_count;
    vector<string> exclude = {"The", "But", "And", "Or", "An", "A",
                               "the", "but", "and", "or", "an", "a"};
    
    string word;
    while (std::cin >> word) { 
        if (count(exclude.begin(), exclude.end(), word) == 0) {
            ++word_count[word];
        }
    }

    for (const auto &w : word_count) {
        std::cout << w.first << " occurs " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
    }
}