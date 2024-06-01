#include <iostream>

void exercise2_36() {
    int a = 1, b = 100;
    decltype(a) c = a;
    decltype((b)) d = a;
    c+=10;
    d+=50;

    std::cout << "a: " << a
              << " b: " << b
              << " c: " << c
              << " d: " << d;
}


int main () {
    exercise2_36();
    return 0;
}