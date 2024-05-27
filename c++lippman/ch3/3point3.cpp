#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;


void example1() {
    vector<string> v6{10};
    std::cout << v6.size() << std::endl;    
}

void example2() {
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto &i : v)
        i *= i;
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    example2();
    return 0;
}