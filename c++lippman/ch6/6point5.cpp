#define NDEBUG

#include <cassert>

int main() {
    // g++ -D NDEBUG -std=c++11 6point5.cpp 
    assert(2+2 == 5);    
}