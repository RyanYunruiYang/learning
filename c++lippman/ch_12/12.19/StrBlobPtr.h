#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include "StrBlob.h"

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) :
        wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();    // prefix version
    // bool operator!=(const StrBlobPtr& p) { return curr != p.curr; }
    std::size_t cur_index() const { return curr; }; // RY
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;            // current position within the array
};

#endif