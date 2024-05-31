/*
Exercise 10.29: Write a program using stream iterators to read a text file into a vector
of strings.
*/

#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>
using std::vector;
using std::string;


int main() {
    std::ifstream myfile ("10.29.in");
    std::istream_iterator<string> in_iter(myfile), eof;

    vector<string> save_strings(in_iter, eof);

    for(const auto& x: save_strings) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}