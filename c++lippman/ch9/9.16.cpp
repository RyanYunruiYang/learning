/* 
Exercise 9.15:
Repeat the previous program, but compare elements in a list<int> to a vector<int>
*/
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<int> v1 = {1,2,3,5};
    std::vector<int> v2 = {1,2,3,4};

    std::cout << "v1==v2 is: " << ((std::vector<int>(v1.begin(), v1.end())==v2)?"true":"false") << std::endl;
}