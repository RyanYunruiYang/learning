#include <iostream>

int main() {
    double x = 5.0;
    double y = -3.0;
    int z = x/y;


    std::cout << z << std::endl; // gives -1

    short short_value = 32767;
    short_value += 1;
    std::cout << "short_value: " << short_value << std::endl; // -32768


    // Exercise 4.4
    std::cout << (12/3*4+5*15+24%4/2) << std::endl; // 91
}