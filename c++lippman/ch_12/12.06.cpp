/*
Exercise 12.6: Write a function that returns a dynamically allocated vector of ints.
Pass that vector to another function that reads the standard input to give values to
the elements. Pass the vector to another function to print the values that were read.
Remember to delete the vector at the appropriate time.
*/
#include <vector>
#include <iostream>

using std::vector;

vector<int>* factory() {
    return new vector<int>();
}

void read_in(vector<int>* iv) {
    int x;
    while (std::cin >> x) {
        iv->push_back(x);
    }
}

void read_out(vector<int>* iv) {
    for (const auto &x : *iv) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


int main() {
    auto new_vec = factory();
    read_in(new_vec);
    read_out(new_vec);
    delete new_vec;

	// new_vec = nullptr;
	// std::cout << new_vec << '\n';    
}