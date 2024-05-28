#include <iostream> 

int main() {
    // Exercise 4.9
    const char *cp = "Hello World";
    if (cp && *cp) {
        std::cout << "yay!" << std::endl;
        std::cout << (long) cp << std::endl;
        std::cout << (long) *cp << std::endl;

    }

    int x;
    std::cout << (x=5) << std::endl; // 5
    std::cout << x++ << std::endl; // 5
    std::cout << x++ << std::endl; // 6
    std::cout << x << std::endl; // 7
    // woah (x=5) actually returns the value 5
    // and x++ returns x, but does actually modify

    
    // pg145: asignment is associative 
    int y,z;
    y = z = 0;
    
}