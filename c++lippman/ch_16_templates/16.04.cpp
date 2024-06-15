/*
Exercise 16.4: Write a template that acts like the library find algorithm. The function will need two template type parameters, one to represent the function’s iterator
parameters and the other for the type of the value. Use your function to find a given
value in a vector<int> and in a list<string>.
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>


template <typename T, typename V>
T custom_find (T begin, T end, V target) {
    for (T it = begin; it != end; ++it) {
        if (*it == target) {
            return it;
        }
    }
    return end;
}

int main() {
    std::vector<int> vec1{1,2,3,4,5};
    auto vit = custom_find(vec1.begin(), vec1.end(), 3);
    std::cout << *vit << std::endl;


    std::list<std::string> list1{"one", "two", "three"};
    auto ls = custom_find(list1.begin(), list1.end(), "four");
    std::cout << *ls << std::endl;
}