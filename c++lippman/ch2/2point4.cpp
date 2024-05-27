#include <iostream> 

int main() {
    int i = 0; 
    int *const p1 = &i; // can assign *p1 but not p1

    int j = 5;
    // p1 = &j;
    *p1 = 10;

    const int ci = 42;
    const int *p2 = &ci; 

    std::cout << i << std::endl;
}