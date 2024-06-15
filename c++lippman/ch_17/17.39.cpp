#include <iostream>
#include <fstream>
#include <string>

using std::fstream;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main() {
    fstream inOut("test3.in", fstream::ate | fstream::in | fstream::out); // ate = find end immediately

    if (!inOut) {
        std::cerr << "Unable to openfile!" << std::endl;
    }
    
    auto end_mark = inOut.tellg(); // remember end-of-file pos
    inOut.seekg(0, fstream::beg);
    size_t cnt = 0;
    string line;

    while(inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
        cnt += line.size() + 1;
        auto mark = inOut.tellg(); // save read position
        inOut.seekp(0, fstream::end); // set write marker to the end;
        inOut << cnt;
        if (mark != end_mark) inOut << " ";
        inOut.seekg(mark);
    }
    inOut.seekp(0, fstream::end);
    inOut << "\n";

    return 0;   
}