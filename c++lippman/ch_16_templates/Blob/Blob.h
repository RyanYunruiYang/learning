#ifndef BLOB_H
#define BLOB_H

#include <memory>
#include <vector>
#include <initializer_list>

// Template class definition
template <typename T>
class Blob {
public:
    Blob();  // Default constructor
    Blob(std::initializer_list<T> il);  // Constructor with initializer_list

    // Additional member functions can be declared here
private:
    std::shared_ptr<std::vector<T>> data;
};

// Default constructor
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {
    // Constructor body
}

// Constructor with initializer_list
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {
    // Constructor body
}

// Any additional member function definitions would go here

#endif // BLOB_H