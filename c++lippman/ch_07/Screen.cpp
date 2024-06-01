#include "Window_mgr.h"
#include "Screen.h"

/* 
Note: I previously had put inline in the declaration
but this did not get put into the function table and
was thus invisible to main.
*/
Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width; 
    cursor = row + c;
    return *this;
}

Screen::pos Screen::size() const {
    return height * width;
}