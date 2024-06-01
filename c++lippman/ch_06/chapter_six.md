# Chapter 6: Functions 
Pages 202-251.
## 6.1 Function Basics
- function call (1) initializes parameters from arguments + (2) transfers control
- return (1) gives result + (2) transfers control out
- functions are nice and will do implicit conversions for inputs
- `void f2(void) {}` means no parameters taken or returned
- local variables cannot have the same name as any parameter
- can have unnamed parameters `void exampleFunction(int, double) { }`
- functions can return pointers to arrays/functions, but not objects themselves
- Exercise 6.2: parameters (declared variables in function header) vs. arguments (values filled in)
- automatic objects = objects that exist only while a block is executing
    - can get around this with local statics, with syntax `static size_t ctr = 0;`, which are destroyed instead when the program terminates
- function may be defined only once but declared multiple times
    - declaration: syntax `return_type function_name(parameter_list);`
    - usually `functions.h` will contain declarations, `functions.cpp` will do `#include "functions.h" and contain actual implementations, and then main.cpp will only need to do #include "functions.h"
- function declarations == function prototype
- including the header file is mainly used to verify that the definition and declaration are consistent
- you can compile together `g++ factMain.cc fact.cc -o main` to create main
- `-c` flag compiles into `.o` object files but does not link them into an executable
- Compiler pipeline
    - preprocessing handles #include, #define, #ifdef; goes from `.cpp` to `.i`
    - compilation turns processed code into assembly; goes from `.i` to `.s`
    - assembler converts assembly language into machine code; maps `.s` to `.o`
    - linking combines object files, resolves references, and creates an executable

## 6.2 Argument passing
- if parameter is a reference, then parameter is bound to its argument (we say that in this case it is "passed by reference" as opposed to copying which is "passed by value")
    - passing by value does not mutate. calling `fact(i)` will not change `i`
- in C, people use pointer parameters to access objects, in c++ we use reference parameters instead
```
void reset(int &i)
{
    i = 0;
}

int j = 42;
reset(j); // j is now 0!
```
- references are also great for avoiding doing large copies
    - but we don't necessarily want to modify the original, so this is why const references are everywhere!! 
```
bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
```
- references are also used for returning multiple values (pass in a reference to write to)
- just like normal, when we copy an argument, top-level consts are ignored
- cannot define both `void fcn(const int i)` and `void fcn(int i)` -- they are considered to be too similar since they take the same inputs
- passing direct reference instead of reference to const limits the types of arguments that can be used with the function
- passing arrays into functions usually turns it into a pointer
```
// Equivalent declarations:
void print(const int*);
void print(const int[]);
void print(const int[10]);
```
- three ways to communicate length of array
    - 1. use marker to mark end. ex: C-style character strings and \0
    - 2. standard library method. pass in beg and end
    - 3. explicitly pass in `size_t`
- usually make both pointers and references low-level `const`s (principle: only give edit access if it is needed!)

- the command line call `prog -d -o ofile data0` is interpreted as:
    - `int main(int argc, char *argv[0])` where argc=5 and
    - argv[0] = "prog", ..., argv[4]="data0", and we are guaranteed that one off the end argv[5] = 0;
- problem: varying number of arguments
    - solution 1: if arguments hvae same type, can pass `intializer_list`
    - solution 2: we can write special function, known as variadic template (16.4, page 699)
    - the `...` parameter type can also pass varying number of arguments (same as exception default type?)
- `initializer_list<T> lst;` or `initializer_list<T> lst{a,b,c,...};` declares
    - can shallow copy `lst2 = lst1` and do .size(), .begin(), .end()
    - is a template style
- syntax: `intializer_list<string> ls` (values will always be const too)
```
void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}

error_msg({"functionX", expected, actual});
```

- ellipses are only used to interface with C library facility named `varargs`. only for types common to C and C++. 

## 6.3 Return Types and `return` statement
- for void returning functions, `return;` is implicitly at the end but can be placed elsewhere as a break
- can prevent copying in the return statement by returning reference
```
const string &shorterString(const string &s1, const string &s2) {
    return s1.size()<=s2.size() ? s1 : s2;
}
```
- you should not return a pointer or reference to a local object
- calls to functions that return references are lvalues, other types are rvalues
    - for example if we have `char &get_val()` you can do `get_val() = 'A'`
- main() does not need to return value (implicitly returns 0)
- main function cannot call itself
- to return array
    - `typdef int arrT[10]` (arrT is synonym for type: array of ten ints)
    - equivalent: `using arrT = int[10]`
    - `arrT* func(int i)`
- `int *p1[10]` is an array of 10 objects of type `int *`
- `int (*p1)[10]` is a pointer to an array of 10 objects of type `int`
- pointer to array: `type (*function(parameter_list))[dimension]`
- `auto func(int i) -> int(*)[10]` takes an int argument and returns a pointer to an array of ten ints

## 6.4 Overloaded Functions
- things that don't count: different return type and const
- functions prefer to pass to nonconst overloaded versions (see .cpp for this file)
- in c++, name lookup happens before type checking, so an overloaded function in local scope with wrong types beats a global scope function with right types


## 6.5 Features for Specialized Uses
Default Arguments
- arguments fill parameters left to right. cannot skip.
- best practice: default arguments should be specified with the function declaration in an appropriate header
- can have weird defaults like `string screen(sz = ht(), sz = wd, char = def);`, where defaults are evaluated at time of call in the scope of the function declaration

Inline
- copy pastes function into where it's called
- syntax: `inline const string &shorterString() {};`

Constexpr
- return type must be literal. each parameter must be literal. function body must contain exactly one return statement. 
- constexpr are all implicitly inline
- useful for if you have a constant `e`, and you want to have access to `e^p mod q`
- constexpr does not have to return a constant expression. (it only has to when writing to constexpr)
- both inline and expr function are normally defined in headers
```
constexpr int new_sz() {
    return 42;
}

constexpr int foo = new_sz();
```

`assert`
- is a preprocessor macro
- if expression is false, writes a message and terminates. if true, does nothing. defined in cassert header.

NDEBUG
- NDEBUG is not defined by default
- if NDEBUG is defined, assert does nothing
- turn off debuging by either providing a #define, or on the command line do `-D NDEBUG` which is equivalent to writing `#define NDEBUG`
can also add
```
void print()
#ifndef NDEBUG
cerr << __func__ << ": array size is " << size << endl;
#endif
```
- where `__func__` prints every function, `__FILE__` contains name of file, `__TIME__` contains time the file was compiled, `__DATE__` contains date file was compiled.

## 6.6 Function Matching
- step 1: find set of candidate functions that are visible
- step 2: select viable functions that could be called
- step 3: chooses best remaining (closer types)
    - there is best match if pareto domination (and one strict ineq)
        - each vonersion is ranked: exact match > const conversion > promotion > arithmetic/pointer conversion > class-type conversion
    - otherwise, call is in error and compiler will complain

```
Record lookup(Acount&);
Record lookup(const Account&);
const Account a;
Account b;
lookup(a); // calls lookup(const). we cannot bind a plain reference to a, so this happens automatically
lookup(b); // calls lookup(Account&) // exact match preferred
```

## 6.7 Pointers to Functions
- `bool lengthCompare(const string &, const string &)` has type `bool(const string&, const string&)` and we can declare a pointer to it as `bool (*pf)(const string &, const string &);`
- function is automatically a pointer. both `pf = lengthCompare;` and `pf = &lengthCompare;` are identical
- we can then call in any of `pf("s1", "s2")` or `(*pf)("s1", "s2")` or `lengthCompare("s1", "s2")`
- compiler uses type of pointer to determine which overloaded function to use. theytype must match exactly
- can directly pass `useBigger(s1, s2, lengthCompare)` and the function will be automatically converted to a pointer
- `using F = int(int*, int)` or `using PF = int(*)(int*, int)` create function type and pointer types

TODO: reread 249-250

## Summary
- automatic objects = objects that only exist during execution of function
- function prototype = no body
- link = compilation of multiple object files
- local static objects
- separate compilation = ability to split program into multiple source files
- trailing return type `auto func(int i) -> int {return i;}`
- () operator can be preceded by either function or function pointer