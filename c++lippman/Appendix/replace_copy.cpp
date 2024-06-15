#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 3, 5, 3, 6};
    std::vector<int> result;

    // Using replace_copy to replace all 3s with 99
    std::replace_copy(vec.begin(), vec.end(), std::back_inserter(result), 3, 99);

    std::cout << "Original vector: ";
    for(int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::cout << "Result vector: ";
    for(int v : result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

