#include <string>
#include <iostream>

using std::string;


int main() {
    string s("hello world");
    string& z = s;
    std::cout << z << " has "<< z->length() << "letters" << std::endl;
}