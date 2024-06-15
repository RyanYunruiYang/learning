#include <iostream>
#include <iomanip> // Include the <iomanip> header to access std::setw

using std::cout;

int main() {
    int i = -16;
    double d = 3.14159;

    cout << "i: " << std::setw(12) << i << "next col" << '\n'
         << "d: " << std::setw(12) << d << "next col" << '\n';

    cout << std::left
         << "i: " << std::setw(12) << i << "next col" << '\n'
         << "d: " << std::setw(12) << d << "next col" << '\n'
         << std::right;

    cout << std::internal
         << "i: " << std::setw(12) << i << "next col" << '\n'
         << "d: " << std::setw(12) << d << "next col" << '\n';
    
    cout << std::setfill('#')
         << "i: " << std::setw(12) << i << "next col" << '\n'
         << "d: " << std::setw(12) << d << "next col" << '\n'
         << std::setfill(' ');         
}