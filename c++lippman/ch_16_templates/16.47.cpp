/*
Exercise 16.47: Write your own version of the flip function and test it by calling functions that have lvalue and rvalue reference parameters.
*/
#include <iostream>


template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int &v2) {
    std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int &&i, int& j) {
    std::cout << i << " " << j << std::endl;
}

int main() {
    int x = 200;
    flip(f,x,10);
    std::cout << x << std::endl;

    flip(g, x, 100);
}