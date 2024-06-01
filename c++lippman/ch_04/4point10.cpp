#include <iostream>

int main() {
    int x,y;
    std::cout << (x=5,y=10) << std::endl; // returns the right expression
}