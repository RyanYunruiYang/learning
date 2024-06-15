#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include "Sales_data.h" // Include the header file for the Sales_data class
#include <algorithm> // Include the header file for the algorithm library
#include <numeric> // Include the header file for the numeric library
#include <sstream> // Include the header file for stringstream

using std::vector;
using std::tuple;
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator, 
              vector<Sales_data>::const_iterator> matches;


bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
    return lhs.isbn() < rhs.isbn();
}

vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
    vector<matches> ret;

    for (auto it = files.begin(); it != files.end(); ++it)
    {
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)
        {
            ret.push_back(make_tuple(
               it-files.cbegin(), found.first, found.second 
            ));
        }
    }
    return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files) {
    string s;
    while (in >> s)
    {
        auto trans = findBook(files, s);
        if (trans.empty()) {
            cout << s << " not found in any stores" << endl;
            continue;
        }
        else {
            for (const auto& store: trans) {
                os << "store " << std::get<0>(store) << " sales: "
                   << std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s)) << endl;
            }
        }
    }
}

int main() {
    // // Test case 1: No input
    // std::istringstream input1("");
    // std::ostringstream output1;
    // std::vector<std::vector<Sales_data>> files1;
    // reportResults(input1, output1, files1);
    // // Expected output: No output

    // // Test case 2: Book not found in any stores
    // std::istringstream input2("book1");
    // std::ostringstream output2;
    // std::vector<std::vector<Sales_data>> files2;
    // reportResults(input2, output2, files2);
    // // Expected output: "book1 not found in any stores\n"

    // Test case 3: Book found in one store
    std::istringstream input3("book2");
    std::ostringstream output3;
    std::vector<std::vector<Sales_data>> files3 = {
        {Sales_data("book2"), Sales_data("book2"), Sales_data("book3")}
    };
    reportResults(input3, output3, files3);
    // Expected output: "store 0 sales: book2\n"

    // // Test case 4: Book found in multiple stores
    // std::istringstream input4("book4");
    // std::ostringstream output4;
    // std::vector<std::vector<Sales_data>> files4 = {
    //     {Sales_data("book4"), Sales_data("book4")},
    //     {Sales_data("book4"), Sales_data("book5")}
    // };
    // reportResults(input4, output4, files4);
    // // Expected output: "store 0 sales: book4\nstore 1 sales: book4\n"

    return 0;
}