#include <iostream> 
#include <initializer_list>
using std::initializer_list;

void print(const int* x) {
// void print(int* x) {
    std::cout << x << std::endl;
}


// // Passing in by reference forces argument to be array of ten ints
// void print(int (&arr)[10]) {
//     for (auto elem : arr) {
//         std::cout << elem << std::endl;
//     }
// }

// Exercise 6.27: Function that takes in initializer_list<int> and produces sum
int sum(initializer_list<int> il) {
    int total = 0;
    for (const auto elem : il) {
        // std::cout << elem << " ";
        total += elem;
    }
    return total;
}


int main() {
    // int j[2] = {0,1};
    // print(j);

    // Exercise 6.27:
    std::cout << sum({1,2,3}) << std::endl;

    return 0;
}