#include <iostream> 

// Exercise 1.9: use while loop to sum 50+...+100
int exercise1_9(int a, int b) {
    int val = a; 
    int total = 0;
    while (val<=b) {
        total += val; 
        val++;
    }
    return total; 
}

// Exercise 1.10: use -- to sum 10 to 0
// Sol: N

// Exercise 1.11: prompt user for two integers and print number in the range
// Sol: N

// Exercise 1.12:
#include <cassert>
void exercise1_12() {
    int sum = 0;
    for (int i=-100; i<=100; ++i) {
        sum += i;
    }
    std::cout << sum << std::endl; // returns 0.
    assert(sum==0);
}

// Exercise 1.13: Rewrite first two exercises from 1.4.1 using for loops
// Exericse 1.14: compare for and while implementations from 1.13
// Exericse 1.15: familiarize yourself with page 16's errors. 
// Exercise 1.16: Write your own program that prints sum of a set of integers read from cin. 

void example1() {
    int currVal = 0, val = 0;

    if (std::cin >> currVal) {
        int cnt = 1; 
        while (std::cin >> val) {
            if(val == currVal) {
                ++cnt;
            }
            else {
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val; 
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    }
}


// Exercise 

int main() {
    std::cout << "The sum from 50 to 100 is " \
              << exercise1_9(50,100) \
              << std::endl;
    std::cout << "Closed form gives: " << 100*101/2-49*50/2 << std::endl;

    // exercise1_12();
    example1();
    return 0; 
}