#include "Screen.h"
#include "Window_mgr.h"

int main() {
    // Screen myscreen;
    Screen myscreen = Screen(5, 10, 'x');
    char ch = myscreen.get();
    std::cout << ch << std::endl;
    myscreen.set((char)'p');
    std::cout << myscreen.get() << std::endl;

    myscreen.set(0, 3, 'o');

    myscreen.display(std::cout); // calls non const version
    std::cout << std::endl;

    const Screen blank(5,3,'_');
    blank.display(std::cout); // calls const version
    std::cout << std::endl;

}