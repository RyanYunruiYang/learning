#include <iostream>

template <typename T> void f(T) {
    std::cout << "f(T) called with T\n";
}

template <typename T> void f(const T*) {
    std::cout << "f(const T*) called with const T*\n";
}

template <typename T> void g(T) {
    std::cout << "g(T) called with T\n";
}

template <typename T> void g(T*) {
    std::cout << "g(T*) called with T*\n";
}

int main() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    // Testing g calls
    std::cout << "Testing g calls:\n";
	g(42); g(p); g(ci); g(p2);

    // Testing f calls
    std::cout << "Testing f calls:\n";
	f(42); f(p); f(ci); f(p2);

    return 0;
}
