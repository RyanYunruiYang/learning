#include <iostream> 
#include <string>
#include <iterator> // Include the <iterator> header

using std::string;

// const string &manip() { // if you get rid of the &, it works
//     return "Empty";
// }

// Exercise 6.32: Fix this function
int &get(int *arry, int index) {return arry[index];}
void exercise6_32() {
    int ia[10];
    for (int i=0; i != 10; ++i) {
        get(ia, i) = i;
    }
}

// // Broken:
// arrT* func(int i) {
//     int ia[10];
//     for (int j = 0; j < 10; ++j) {
//         ia[j] = i;
//     }
//     return ia;
// }

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) *arrPtr(int i) {
    return (i%2) ? &odd : &even;
}


int main() {
    // string x = manip();
    // std::cout << x << std::endl; // empty?

    // exercise6_32();

    // using arrT = int[10];
    // func(10);


    int *x = *arrPtr(5);

    for (int i=0; i<5; i++) {
        std::cout << x[i] << std::endl;
    }

    // return EXIT_FAILURE;
}