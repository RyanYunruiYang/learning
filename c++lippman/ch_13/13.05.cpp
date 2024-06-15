/*
Exercise 13.5: Given the following sketch of a class, write a copy constructor that
copies all the members. Your constructor should dynamically allocate a new string
(§ 12.1.2, p. 458) and copy the object to which ps points, rather than copying ps itself.
*/
#include <string>
#include <iostream>

class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
        HasPtr(const HasPtr &rhs): ps(new std::string(*rhs.ps)), i(rhs.i) {};
        
        void print() const {
            std::cout << "String: " << *ps << ", Int: " << i << std::endl;
        }

        std::string* getPs() const { return ps; } 
    private:
        std::string *ps;
        int i;
};

int main() {
    // Creating an object of HasPtr
    HasPtr obj1("Hello, world!");
    obj1.print();

    // Using the copy constructor
    HasPtr obj2 = obj1;
    obj2.print();

    // Modifying the copied object to check if it's a deep copy
    *obj2.getPs() = "Goodbye, world!";
    obj2.print();
    obj1.print(); // obj1 should remain unchanged

    return 0;
}