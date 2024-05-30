/* 
Exercise 8.1:
Write a function that takes and returns an istream&. The function should read
the stream until it hits end-of-file. The function should print what it reads
to the standard output. Reset the stream so that it is valid before returning
the stream.
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