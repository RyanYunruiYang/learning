#include <iostream>
#include <tuple>

int main() {
    // std::tuple<int, int, int> wld{100,2,3};
    std::tuple<int, int, int> wld(100,2,3);
    std::cout << std::get<0>(wld) << std::endl;
}