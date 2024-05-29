#include <iostream>


/* Exercise 6.25: Write a main function that takes two arguments
 * Concatenate the supplied arguments and print the resulting
 * string 
 */
int main(int argc, char *argv[]) {
    if (argc == 3)
        std::cout << argv[1] << argv[2] << std::endl;
    else {
        std::cout << "not the right number of arguments!" << std::endl;
    }
}