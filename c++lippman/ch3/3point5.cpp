#include <iostream>
#include <cstddef>
// #include <iterator>

void exercise3_30() {
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 0; ix<array_size; ++ix)
        ia[ix] = ix;
    
    for (auto i : ia) {
        std::cout << i;
    }
    std::cout << std::endl;
}

void example1() {
    int ia[] = {78,1,2,3,4,5,6,7,8,9};
    auto ia2(ia);
    ia2[5] = 100;

    for (auto x : ia) {
        std::cout << x  << " ";
    }
    std::cout << std::endl;

    std::cout << ia2[5] << std::endl;

    int *e = &ia[10];
    e-=2;
    std::cout << *e << std::endl;
    // int *after_e = &ia[11];

    int *beg = std::begin(ia);
    std::cout << *beg << std::endl;

    int *p2 = ia + 100;
    std::cout << *p2 << std::endl;
}

void example2() {
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        std::cout << *cp << std::endl;
        ++cp;
    }
}

int main() {
    // exercise3_30();
    // example1();
    example2();
    return 0;
}