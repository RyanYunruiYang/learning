#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <iostream>

int main() {
    StrBlob blob{"hello", "world", "this", "is", "a", "test"};
    
    for (StrBlobPtr p = blob.begin(); p.cur_index() != blob.end().cur_index(); p.incr()) {
        std::cout << p.deref() << " ";
    }

    std::cout << std::endl;

    return 0;
}