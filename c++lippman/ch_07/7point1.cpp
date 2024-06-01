/* Exercise 7.1 */

#include <iostream>
#include <string>
using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data total;
    
    double price;
    if (std::cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;

            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else {
                std::cout << "Book: " << total.bookNo << " "
                                      << total.units_sold << " "
                                      << total.revenue/total.units_sold
                                      << std::endl;
                // total = trans
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        std::cout << "Book: " << total.bookNo << " "
                                << total.units_sold << " "
                                << total.revenue/total.units_sold
                                << std::endl;        
    }
    return 0;
}

/* 
Succesfully ran mapping in1.txt -> out1.txt.

*/