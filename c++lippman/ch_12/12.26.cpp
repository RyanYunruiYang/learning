/*
Exercise 12.26: Rewrite the program on page 481 using an allocator.
*/

#include <memory>
#include <string>
#include <iostream>

using std::allocator;
using std::string;
using std::cin;

void original(int n) {
    // Found on page 481, using dynamically allocated arrays.
    string *const p = new string[n];
    string s;
    string *q = p;
    while (cin >> s && q != p+n) {
        *q++ = s;
    }
    const size_t size = q-p;
    delete [] p;
}

void revised(int n) {
    // Allocate
    allocator<string> alloc;
    auto const p = alloc.allocate(n);

    // Read
    auto q = p;
    string s;
    while (cin >> s && q != p+n) {
        alloc.construct(q++, s);
    }
    const size_t size = q - p;

    // Print
    for (auto i = p; i != q; ++i) {
        std::cout << *i << std::endl;
    }

    // Destroy
    for (auto i = p; i != q; ++i) {
        alloc.destroy(i);
    }
    // Deallocate
    alloc.deallocate(p, n);
}


int main() {
    original(5);
    revised(5);
}