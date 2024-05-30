/* 
Exercise 9.13: 
How would you initialize a vector<double> from a list<int>? From a vector<int>? 
Write code to check your answers.
*/
#include <vector>
#include <list>
#include <iostream>
using std::vector;
using std::list;


int main() {
    vector<double> original_version = {1.0, 2.3, 3.5};

    list<int> new_version(original_version.begin(), original_version.end());

    for (auto x : new_version) {
        std::cout << x << std::endl;
    }
    // Prints 1 2 3.
}