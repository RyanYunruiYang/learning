/*
Exercise 9.11: Show an example of each of the six ways to create and initialize a
vector. Explain what values each vector contains.
*/
#include <vector>
using std::vector; 

int main() {
    vector<int> vec1();
    vector<int> vec2(10);
    vector<int> vec3(10,0);
    vector<int> vec4 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> vec5(vec2);
    vector<int> vec6(vec2.begin(), vec2.end());
}