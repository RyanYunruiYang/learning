#include <typeinfo>
#include <iostream>
#include <string>
#include "../ch_17/Sales_data.h"

class Base {
    friend bool operator==(const Base&, const Base&);
public: 
    // interface members
protected:
    virtual bool equal(const Base &) const = 0; // Define the equal function
};

class Derived: public Base {
public:
    Derived() = default;
    Derived(int value) : value(value) {}

    // interface members
protected:
    bool equal(const Base& other) const override {
        const Derived* derivedPtr = dynamic_cast<const Derived*>(&other);
        return derivedPtr && (this->value == derivedPtr->value);
    }
private:
    int value;
};

bool operator==(const Base &lhs, const Base &rhs) 
{
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}


int main() {
    int arr[10];
    Derived d;
    Base *p = &d;


    std::cout << typeid(42).name() << ", "
              << typeid(arr).name() << ", "
              << typeid(Sales_data).name() << ", "
              << typeid(std::string).name() << ", "
              << typeid(p).name() << ", "
              << typeid(*p).name() << ", " << std::endl;
}