#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;


void test1() {
    string s1 = "hiya \0 sdfas"; // prints hiya
    std::cout << s1 << std::endl;
}

void test2() {
    string word;
    while (cin >> word) {
        cout << word << endl;
    }
}

void test3() {
    string s("Hello World!!!");

    // // Will not actually mutate.
    // for (auto c : s)
    //     c = toupper(c);
    // cout << s << endl;

    // Will mutate.
    // Still throws warnings though.
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;

    /*
    Modern usage is:
    // Using a lambda function with std::for_each
    std::for_each(s.begin(), s.end(), [](char& c) {
        c = std::toupper(c);
    });    
    */
}

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}