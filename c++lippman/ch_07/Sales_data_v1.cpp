/* Exercise 7.1 */

#include <iostream>
#include <string>
using std::string;

struct Sales_data {
    // Constructors
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &);

    // Operations on Sales_data objects
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const; 

    // Data Members:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue/units_sold;
    }
    else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << "Book: " << item.isbn() << " "
                   << item.units_sold << " "
                   << item.avg_price() << std::endl;;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main() {
    Sales_data total;
    
    double price;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.bookNo == trans.bookNo) {
                total.combine(trans);
            }
            else {
                print(std::cout, total);
                total = trans;
            }
        }
        print(std::cout, total);
    }
    return 0;
}

/* 
Succesfully ran mapping in1.txt -> out1.txt.

*/