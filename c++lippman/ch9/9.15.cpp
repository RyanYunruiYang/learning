/* 
Exercise 9.15:
Write a program to determine whether two vector<int>s are equal
*/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1,2,3,4};
    std::vector<int> v2 = {1,2,3,4};

    std::cout << "v1==v2 is: " << ((v1==v2)?"true":"false") << std::endl;
}