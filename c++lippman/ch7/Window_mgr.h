#include <vector>
#include "Screen.h"

class Window_mgr {
public:
    // using ScreenIndex  = std::vector<Screen>::size_type; 
    typedef std::vector<Screen>::size_type ScreenIndex;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24,80, ' ')};
};