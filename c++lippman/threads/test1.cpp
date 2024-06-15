#include <iostream>
#include <thread>

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Hello from the thread!" << std::endl;
}

int main() {
    std::thread t(threadFunction);

    // Detach the thread
    // t.detach();

    std::cout << "Hello from the main thread!" << std::endl;

    // Sleep to give the detached thread time to finish
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}