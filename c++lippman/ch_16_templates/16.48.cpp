#include <iostream>
#include <sstream>
#include <string>

using std::string;

template <typename T>
string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;

    if (p) {
        ret << " " << debug_rep(*p);
    }
    else {
        ret << " null pointer";
    }
    return ret.str();
}


int main() {
    string s("hellooooo");
    std::cout << debug_rep(s) << std::endl;
    std::cout << debug_rep(&s) << std::endl;
}