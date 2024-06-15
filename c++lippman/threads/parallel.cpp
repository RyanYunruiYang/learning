#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::thread;


std::mutex m1;
std::mutex m2;


void f() {
    std::unique_lock<std::mutex> lck1 {m1};
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> lck2 {m2};
    cout << "Hello ";
}

struct F {
    void operator()() {
        std::unique_lock<std::mutex> lck2 {m2};
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lck1 {m1};
        cout << "Parallel World!\n";
    }
};


void user()
{
    thread t1 {f}; // f() executes in separate thread
    thread t2 {F()}; // F()() executes in separate thread
    t1.join(); // wait for t1
    t2.join(); // wait for t2
}


int main() {
    user();
}