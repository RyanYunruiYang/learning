#include <iostream>
#include <string> 
using std::string;

const string &shorterString(const string &s1, const string &s2) {
    std::cout << "using const version" << std::endl;
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2) {
    std::cout << "using nonconst version" << std::endl;
    auto &r = shorterString(const_cast<const string&>(s1),
                            const_cast<const string&>(s2));
    return const_cast<string&>(r);
}

int main() {
    // Will only not break if we give it two nonconsts!
    string x = "short";
    string y = "longerrrr";
    std::cout << shorterString(x,y) << std::endl;
    
    shorterString(x,y) = "mutate!";

    std::cout << x << "-" << y << std::endl;

}