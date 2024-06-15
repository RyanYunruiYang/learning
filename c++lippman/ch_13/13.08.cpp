/*
Exercise 13.8: Write the assignment operator for the HasPtr class from exercise 13.5
in § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should
copy the object to which ps points.
*/


#include <string>
#include <iostream>

class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
        HasPtr(const HasPtr &rhs): ps(new std::string(*rhs.ps)), i(rhs.i) 
                {std::cout << "copy constructor called \n";};
        
        void print() const {
            std::cout << "String: " << *ps << ", Int: " << i << std::endl;
        }

        std::string* getPs() const { return ps; }

        HasPtr& operator=(const HasPtr&rhs) {
            std::cout << "copy-assignment called \n";
            ps = rhs.ps;
            i = rhs.i;
            return *this;
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

    HasPtr obj3;
    obj3 = obj1;
    obj3.print();

    return 0;
}