#include <random>
#include <iostream>

using std::default_random_engine;

int main() {
    default_random_engine e;
    std::cout << "running default random engine with range [" << e.min() << ", " << e.max() << "]" << std::endl;
    for (size_t i = 0; i< 10; ++i) {
        std::cout << e() << " ";
    }

    std::uniform_int_distribution<unsigned> u(0,9);
    // default_random_engine e;
    std::cout << "\n uniform distribution in (0,9), inclusive: \n";
    for (size_t i = 0; i < 10; ++i)
        std::cout << u(e) << " ";
    std::cout << std::endl;
}