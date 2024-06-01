#include <iostream> 
#include <string>
using std::string; 



int main() {
    int grade = 95;
    string finalgrade = (grade>90) ? "highgrade" : ((grade<60) ? "fail" : "pass");
    std::cout << finalgrade << std::endl;

    unsigned char bits = 0227; // octal->bin gives 10_010_111
    std::cout << (~bits) << std::endl; // prints -152.
    std::cout << (bits << 8) << std::endl; // prints 38656.
}