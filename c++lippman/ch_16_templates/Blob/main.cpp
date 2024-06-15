#include "Blob.h"
#include <iostream>

int main() {
    Blob<int> intBlob;  // Using the default constructor
    Blob<std::string> strBlob = {"Hello", "World"};  // Using the initializer_list constructor

    // Further usage of intBlob and strBlob
    return 0;
}
