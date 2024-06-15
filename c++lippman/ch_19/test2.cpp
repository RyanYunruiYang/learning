#include <iostream>
#include <typeinfo>

class Base {
    friend bool operator==(const Base&, const Base&);
public: 
    // interface members
protected:
    virtual bool equal(const Base &) const = 0; // Define the equal function
};

class Derived: public Base {
public:
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
    Derived d1(10);
    Derived d2(10);
    Derived d3(20);

    if (d1 == d2) {
        std::cout << "d1 is equal to d2" << std::endl;
    } else {
        std::cout << "d1 is not equal to d2" << std::endl;
    }

    if (d1 == d3) {
        std::cout << "d1 is equal to d3" << std::endl;
    } else {
        std::cout << "d1 is not equal to d3" << std::endl;
    }

    return 0;
}
