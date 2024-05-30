#include <vector>
#include <iostream>
#include <string>
using std::vector;
using std::cout;
using std::cin;
using std::endl;


// Page 357
void test1() {
    vector<int> ivec;

    int num_insert = 65;
    for (int i=0; i!=num_insert; i++) {
        ivec.push_back(10);
    }

    // ivec.reserve(100);




}

void test2() {
    vector<std::string>svec;
    svec.reserve(1000);

    // std::string word;
    // while (cin >> word) {
    //     svec.push_back(word);
    // }
    for(int i=0; i<1048; i++) {
        svec.push_back("hi");
    }
    
    svec.resize(svec.size()+svec.size()/2);

    cout << "svec size: " << svec.size() 
         << " capacity: " << svec.capacity() << endl;

}



int main() {
    // test1();
    test2();
    return 0;
}