#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"

using std::string;

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";

        string s;
        if (!(std::cin>>s) || s=="q") {
            break;
        }
        print(std::cout, tq.query(s)) << std::endl;
    }
}


int main () {
    std::ifstream infile("input.txt");
    runQueries(infile);
    return 0;
}