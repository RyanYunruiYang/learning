/*
Exercise 8.2: Test your function by calling it, passing cin as an argument.
*/

#include <iostream>
#include <string>
#include <cassert>
using std::string;

std::istream& read_to_end_reset(std::istream& input_stream) {
    string line;
    if(input_stream) {
        while (!input_stream.eof()) {
            input_stream >> line;
            std::cout << line << std::endl;
        }
    }
    input_stream.clear();
    assert(input_stream.good()); // the stream is now valid again
    return input_stream;
}

int main() {
    read_to_end_reset(std::cin);
    // std::cout << "and you can still read!" << std::endl;
    // string line;
    // std::cin >> line;
}