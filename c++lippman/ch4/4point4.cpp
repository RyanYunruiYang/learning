#include <iostream>

int main() {
    int i;
    double d;
    // d = i = 3.5; // sets i=3, d=3
    i = d = 3.5; // sets d=3.5, i=3

    std::cout << i << " " << d << std::endl; // 3 3.5

    if (i=2024) { // evaluates to true!
        std::cout << i << std::endl;
    }
}