#pragma once
#include <string>
#include <iostream>
using std::string;

class Screen {
public:
    friend class Window_mgr;
    typedef std::string::size_type pos;
    // Constructors
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd),
                                    contents(ht * wd, c) {}
    // Method Declarations
    Screen &set(char);
    Screen &set(pos, pos, char);
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
                   { do_display(os); return *this;}
    pos size() const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const {os << contents;}
};