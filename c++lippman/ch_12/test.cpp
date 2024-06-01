#include <iostream>

void function() {
    static int localVar=1000; // Local variable on the stack
    ++localVar;
    std::cout << "Local Variable: " << localVar << std::endl;
}

int main() {
    function();
    function();
    function();
    return 0;
}