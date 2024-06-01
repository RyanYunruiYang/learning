/*
 * Exercise 12.2: Write your own version of the StrBlob class including the
 * const versions of front and back.
 */


#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

using std::vector;
using std::string;
using std::make_shared;
using std::initializer_list;
using std::out_of_range;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    // element access
    std::string &front();
    std::string &back();
    const std::string &front() const;  // const version
    const std::string &back() const;   // const version    

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front() {
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

int main() {
    const StrBlob s1({"tree", "cat", "fall"});
    std::cout << "Const StrBlob:" << std::endl;
    std::cout << "Front: " << s1.front() << std::endl;
    std::cout << "Back: " << s1.back() << std::endl;
    std::cout << "Size: " << s1.size() << std::endl;

    // s1.front() = "this will not compile";

    StrBlob s2;
    s2.push_back("tall");
    s2.push_back("ball");
    s2.push_back("wall");

    std::cout << "\nNon-const StrBlob:" << std::endl;
    std::cout << "Front: " << s2.front() << std::endl;
    std::cout << "Back: " << s2.back() << std::endl;
    std::cout << "Size: " << s2.size() << std::endl;

    // Modifying elements in non-const StrBlob
    s2.front() = "small";
    s2.back() = "call";
    std::cout << "\nModified Non-const StrBlob:" << std::endl;
    std::cout << "Front: " << s2.front() << std::endl;
    std::cout << "Back: " << s2.back() << std::endl;
    std::cout << "Size: " << s2.size() << std::endl;

    return 0;
}