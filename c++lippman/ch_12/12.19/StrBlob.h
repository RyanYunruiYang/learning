#ifndef STRBLOB_H
#define STRBLOB_H

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlobPtr begin();  // return StrBlobPtr to the first element
    StrBlobPtr end();    // and one past the last element
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // element access
    std::string& front();
    std::string& back();
    std::string& front() const;
    std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

#endif