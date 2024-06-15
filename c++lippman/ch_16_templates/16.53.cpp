#include <iostream>
using std::ostream;

template<typename T>
ostream &print(ostream &os, const T&t) {
    return os << t;
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args& ... ret) {
    os << t << ", ";
    return print(os, ret...);
}


int main() {
    print(std::cout, 1, 2, 3, "hello", 4.5);
    return 0;
}