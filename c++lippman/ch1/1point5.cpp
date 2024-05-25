#include <iostream> 
#include "Sales_item.h"

void example1() {
    Sales_item book;

    std::cin >> book;
    std::cout << book << std::endl;    
}

void example2() {
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1+item2 << std::endl;
}

int main() {
    example2();
    return 0;    
}