#include <tuple>
#include <vector>
#include <string>
#include <utility> // for pair
#include <initializer_list> // Add this line

using std::tuple; 
using std::string;
using std::make_pair;
using std::make_tuple;

int main() {
    tuple<string, std::vector<string>, std::pair<string, int>> tuple1 = make_tuple("hi", std::vector<string>{"one", "two"}, make_pair("hi", 10));
}