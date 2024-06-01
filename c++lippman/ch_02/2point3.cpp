#include <iostream> 

void exercise2_17() {
    int i;
    int &ri = i; 
    i=5;
    ri = 10;

    int z = 5, y = 3;
    // int &ri = z; // fails because it says it has already been initialized. 
    std::cout << i << " " << ri << std::endl;
}

void example1() {
    int i = 0;

    int* dp = &i;
    *dp = 5; 
    std::cout << dp << " " << *dp << std::endl;    
    std::cout << &i << " " << i << std::endl;    
}

void example2() {
    double dval = 3.14; 
    const int &ri = dval; 

    std::cout << dval << " " << ri << std::endl;

    dval = 6.28;

    std::cout << dval << " " << ri << std::endl;

}

int main() {
    // exercise2_17();
    example2();
    // int ival = 1024;
    // int *pi2 = &ival;
    // std::cout << pi2 << std::endl; // prints 0x16b20b178




    return 0;
}