#include <iostream> 

class A {
public:
    int x = 1;
};

class B {
public:
    int y = 2;
};

class C : public A, public B {
public:
    int z = 3;
};


int main() {
    C obj;
    // obj.x = 10;
    // obj.y = 20;
    // obj.z = 30;

    std::cout << obj.x << std::endl;
    std::cout << obj.y << std::endl;
    std::cout << obj.z << std::endl;
}