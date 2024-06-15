/*
Exercise 13.11: Add a destructor to your HasPtr class from the previous exercises.
*/


#include <string>
#include <iostream>

class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        HasPtr(const HasPtr &rhs): ps(new std::string(*rhs.ps)), i(rhs.i) 
                {std::cout << "copy constructor called\n";}

        HasPtr& operator=(const HasPtr &rhs) {
            std::cout << "copy-assignment called\n";
            if (this != &rhs) { // self-assignment check
                delete ps; // free existing memory
                ps = new std::string(*rhs.ps); // allocate new memory and copy
                i = rhs.i+1;
            }
            return *this;
        }
        void print() const { std::cout << "String: " << *ps << ", Int: " << i << std::endl;}
        std::string* getPs() const { return ps; }
        ~HasPtr() { 
            delete ps; 
            std::cout << "destructor called\n";
        }
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

    // Testing copy assignment
    HasPtr obj3;
    obj3 = obj1;
    obj3.print();

    return 0;
}
