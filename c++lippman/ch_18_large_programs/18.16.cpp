/*
Exercise 18.16: Explain the following code assuming using declarations for all the
members of namespace Exercise are located at the location labeled position 1. What
if they appear at position 2 instead? Now answer the same question but replace the
using declarations with a using directive for namespace Exercise.
*/
namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;
// position 1
// using Exercise::ivar;
// using Exercise::dvar;
// using Exercise::limit;    
void manip() {
    // position 2
    // using Exercise::ivar;
    // using Exercise::dvar;
    // using Exercise::limit;   

    // option 3
    // using namespace Exercise;
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
}


/*
Answer:
- declarations for all at position 1: compile error on ivar.
- declarations for all at position 2: compile error at dvar
- directive at position 2: collision on ivar
*/