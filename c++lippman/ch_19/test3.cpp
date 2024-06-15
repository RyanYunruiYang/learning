#include <iostream>

enum color {red=100, yellow=101, green=102}; // Define the enum color

void ff(color x) {
    std::cout << "ff(int) called with " << x << std::endl;
}

int main() {
    // enum color {red=100, yellow=101, green=102};
    // enum stoplight {red, yellow, green2}; // still fails
    ff(red);
    // ff(101); // error: no matching function for call to 'ff'
}