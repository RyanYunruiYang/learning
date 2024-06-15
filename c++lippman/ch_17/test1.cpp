#include <iostream>
#include <regex>
#include <string> 

using std::string; 

int main() {
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    std::regex r(pattern);
    std::smatch results; 
    string test_str = "receipt freind theif receive";
    if (regex_search(test_str, results, r)) {
        std::cout << results.str() << std::endl; // only prints friend.
    }
}