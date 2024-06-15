#include "test1.h"
#include <iostream>

int main() {
    MyArray<int, 5> x; // Remove the second argument
    // x[0] = 5;
    // x[1] = 4;
    // x[2] = 3;
    // x[3] = 2;
    // x[4] = 1;
    x.Print();
    std::cout << "\n" << x[0] << " " << x[1] << " " << x[2] << " "  << x[3] << " " << x[4] << std::endl;
}