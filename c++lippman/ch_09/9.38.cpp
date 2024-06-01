/*
Exercise 9.38: Write a program to explore how vectors grow in the library
you use.
*/

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;


// Page 357
void test1() {
    vector<int> ivec;

    int num_insert = 65;
    for (int i=0; i!=num_insert; i++) {
        ivec.push_back(10);
    }

    // ivec.reserve(100);



    cout << "ivec size: " << ivec.size() 
         << " capacity: " << ivec.capacity() << endl;
}



int main() {
    test1();
    return 0;
}