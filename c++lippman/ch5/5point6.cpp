#include <iostream>
#include <exception>
using std::cin;
using std::cout;
using std::endl;


void exercise5_23() {
    double x,y;
    cin >> x >> y;
    if (y == 0) {
        // throw std::exception();
        throw std::runtime_error("divide by 0");
    }    
    double z = x / y;
    cout << z << endl;    
}

int main() {
    exercise5_23(); // also completes Exercise 5.24.
    

    // Exercise 5.25
    double x,y;
    while (cin >> x >> y) {
        try {
            if (y == 0) {
                throw std::runtime_error("divide by 0");
            }
            cout << x/y << endl;
        }
        catch (std::runtime_error err) {
            std::cerr << "bad!" << endl;
        }
    }
    

}