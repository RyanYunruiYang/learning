#include <iostream>
#include <functional> // Include the <functional> header for std::less

template <typename T> int compare (const T &v1, const T &v2) {
    if (std::less<T>()(v1, v2)) return -1; // Use std::less instead of less<T>
    if (std::less<T>()(v2,v1)) return -1; // Use std::less instead of less<T>
    return 0;
}

int main() {
    std::cout << compare<std::string>("hi", "hiii") << std::endl; // Specify template argument as std::string
    std::cout << compare<int>(1,4) << std::endl; // Specify template argument as int
}