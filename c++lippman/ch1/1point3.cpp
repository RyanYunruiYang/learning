#include <iostream> 

// Exercise 1.7: incorrect nested comments
// int exercise1_7() {
//     /*
//      *
//      * /* Inside comment */

//     return 0;    
// }

// Exercise 1.8:
void exercise1_8() {
    std::cout << "/*";
    std::cout << "*/";
    // std::cout << /* "*/" */; // <-- the one fail
    std::cout << /* "*/" /* "/*" */;
}

int main() {
    exercise1_8();
    std::cout << "hello" << std::endl;
    return 0;
}