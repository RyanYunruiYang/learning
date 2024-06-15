/*
Exercise 17.28: Write a function that generates and returns a uniformly distributed
random unsigned int each time it is called.
*/
#include <random>
#include <iostream>
#include <ctime>

unsigned rng() {
    static std::default_random_engine e(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<unsigned> u(0,99);

    // std::cout << "Seed value: " << e.seed() << std::endl;
    return u(e);
}

int main () {
    for (int i = 0; i < 10; ++i) {
        std::cout << rng() << std::endl;
    }
    return 0;
}