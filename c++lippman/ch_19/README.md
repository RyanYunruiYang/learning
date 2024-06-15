# Chapter 19: Specialized Tools and Techniques
## 19.1 Controlling Memory Allocation (820-825)
- an action like `string *sp = new string("a value");` is actually composed of three steps:
    - 1: calls `operator new` to allocator memory
    - 2: consructs object in memory
    - 3: returns pointer to said object
- `deletes sp` has steps (1) destroy object, (2) call `operator delete` or `operator delete[]`
- interface:
```
// these versions might throw an exception
void *operator new(size_t); // allocate an object
void *operator new[](size_t); // allocate an array
void *operator delete(void*) noexcept; // free an object
void *operator delete[](void*) noexcept; // free an array
// versions that promise not to throw; see § 12.1.2 (p. 460)
void *operator new(size_t, nothrow_t&) noexcept;
void *operator new[](size_t, nothrow_t&) noexcept;
void *operator delete(void*, nothrow_t&) noexcept;
void *operator delete[](void*, nothrow_t&) noexcept;
```
- C++ inherits `malloc()` and `free()` from C (found in cstdlib)
- malloc takes `size_t` of how many bytes to allocate, and returns poitner to memory (or 0 if fail)
- free takes `void *` that malloc() returned
- placement new = allocate, explicit call to destructor `sp->~string()` is same as destroy
- placement new: `new (place_address) type [size] { braced initializer list }`
    - lets you choose where to construct the value with `place_address`

## 19.2 Run-Time Type Identification (825-832)
- RTTI: `typeid` operator and `dynamic_cast` operator
    - both tell you the *dynamic* types
```
dynamic_cast<type*>(e);
dynamic_cast<type&>(e);
dynamic_cast<type&&>(e);
```
- type must be either type, a base version or a derived version
    - if casting pointer base to derived, the cast will return 0 if it fails
    - if casting reference base to derived, fails will throw `std::bad_cast`
- `typeid`
    - returns reference to const of object `type_info`
    - usually used to compare types of two expressions
    - typeid of a pointer returns static compile-time type

## 19.3 Enumerations (832-835)
- enumerations are literal types
- scoped enumeration has syntax `enum class open_modes {input, output, append};` (unscoped doesn't have class/struct keyword)
- enumerators are const expr
- unscoped enumeartors can be implicitly converted to int (scoped cannot)
- forward declarations must specify underlying sum
- generally enumerator type objects are converted to primitve types, but not the other way around


## 19.4 Poitner to Class Member (835-843)
- you can do `auto pdata = &Screen::contents;` to get a pointer to a member
- using `mem_fn` seems like the easiest way to convert such pointers to callables
- `bind` also works

## 19.5 Nested Classes (843-847)
- The name of a nested class is visible within its enclosing class scope but not outside the class.
- Although a nested class is defined in the scope of its enclosing class, it is important to understand that there is no connection between the objects of an enclosing class and objects of its nested classe(s).
- Shared name lookup: nested class can use definitions from enclosing class

```
class TextQuery {
public:
    class QueryResult; // nested class to be defined later
    // other members as in § 12.3.2 (p. 487)
};

class TextQuery::QueryResult {
    // in class scope, we don’t have to qualify the name of the QueryResult parameters
    friend std::ostream&
           print(std::ostream&, const QueryResult&);
public:
    // no need to define QueryResult::line_no; a nested class can use a member
    // of its enclosing class without needing to qualify the member’s name
    QueryResult(std::string,
                std::shared_ptr<std::set<line_no>>,
                std::shared_ptr<std::vector<std::string>>);
    // other members as in § 12.3.2 (p. 487)
};
```

## 19.6 `union`: A Space-Saving Class (847-852)
- A union may have multiple data members, but at any point in time, only one of the members may have a value.
- unions can neither be a base or inherit from a base
- enough memory allocated to hold largest member
- cannot have references as members
- 

```
union Token {
    // members are public by default
    char cval;
    int ival;
    double dval;
};

// ANON VERSION
union { // anonymous union
    char cval;
    int ival;
    double dval;
}; // defines an unnamed object, whose members we can access directly

cval = ’c’; // assigns a new value to the unnamed, anonymous union object
ival = 42; // that object now holds the value 42
```
- idiomatic usage uses a discriminant to track
```
class Token {
public:
    // copy control needed because our class has a union with a string member
    // defining the move constructor and move-assignment operator is left as an exercise
    Token(): tok(INT), ival{0} { }
    Token(const Token &t): tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token&);

    // if the union holds a string, we must destroy it; see § 19.1.2 (p. 824)
    ~Token() { if (tok == STR) sval.~string(); }

    // assignment operators to set the differing members of the union
    Token &operator=(const std::string&);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
private:
    enum {INT, CHAR, DBL, STR} tok; // discriminant
    union { // anonymous union
        char cval;
        int ival;
        double dval;
        std::string sval;
    }; // each Token object has an unnamed member of this unnamed union type

    // check the discriminant and copy the union member as appropriate
    void copyUnion(const Token&);
};
```

## 19.7 Local Classes (852-854)
- A class can be defined inside a function body. Such a class is called a local class
- A local class can access only type names, static variables (§ 6.1.1, p. 205), and enumerators defined within the enclosing local scopes.
- Not very useful.

## 19.8 Inherently Nonportable Features (854-862)
- A nonportable feature is one that is machine specific
- Example 1: Bit-Fields. We indicate that a member is a bit-field by
following the member name with a colon and a constant expression specifying the
number of bits:
```
typedef unsigned int Bit;
class File {
    Bit mode: 2; // mode has 2 bits
    Bit modified: 1; // modified has 1 bit
    Bit prot_owner: 3; // prot_owner has 3 bits
    Bit prot_group: 3; // prot_group has 3 bits
    Bit prot_world: 3; // prot_world has 3 bits
    // operations and data members of File
public:
    // file modes specified as octal literals; see § 2.1.3 (p. 38)
    enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };
    File &open(modes);
    void close();
    void write();
    bool isRead() const;
    void setWrite();
};
```
- For example, in the preceding declaration, the five bit-fields
will (probably) be stored in a single unsigned int. Whether and how the bits are
packed into the integer is machine dependent.
- `volatile` qualifier
    - An object should be declared volatile when its value might be changed in ways outside the control or detection of the program. The volatile keyword is a directive to the compiler that it should not perform optimizations on such objects
    - 
```
volatile int v; // v is a volatile int
int *volatile vip; // vip is a volatile pointer to int
volatile int *ivp; // ivp is a pointer to volatile int
volatile int *volatile vivp; // vivp is a volatile pointer to volatile int

int *ip = &v; // error: must use a pointer to volatile
*ivp = &v; // ok: ivp is a pointer to volatile
vivp = &v; // ok: vivp is a volatile pointer to volatile
```
- If a class wants to allow volatile objects to be copied, moved, or assigned, it must define its own versions of the copy or move operation
- Linkage Directives: extern "C"
    - `extern "C" size_t strlen(const char *);`
    - can also do `extern "Ada", extern "FORTRAN"`

```
// illustrative linkage directives that might appear in the C++ header <cstring>
// single-statement linkage directive
extern "C" size_t strlen(const char *);
// compound-statement linkage directive
extern "C" {
    int strcmp(const char*, const char*);
    char *strcat(char*, const char*);
}

// compound-statement linkage directive
extern "C" {
#include <string.h> // C functions that manipulate C-style strings
}

// FC is a pointer to a C function
extern "C" typedef void FC(int);
// f2 is a C++ function with a parameter that is a pointer to a C function
void f2(FC *);

// By using the linkage directive on a function definition, we can make a C++ function
available to a program written in another language:
// the calc function can be called from C programs
extern "C" double calc(double dparm) { /* ... */ }

// error: two extern "C" functions with the same name
extern "C" void print(const char*);
extern "C" void print(int);


```
- A pointer to a C function cannot be initialized or be assigned to point to
a C++ function (and vice versa). 
- can check if we are compiling in C++ with `#ifdef __cplusplus`
## Summary
- Ch 19. Specialized Functions. 
- memory: operator new, operator delete (overloading new/delete). malloc + free. operator new[] vs. operator new. placement new expression takes specification of where object should be constructed.
- RTTI dynamic types. dynamic_cast from base to derived. typeid, dynamic_cast, type_info
- enumerators: scoped vs. unscoped.
- pointer to class members. mem_fn for pointers to members. pointer to member `T C::*pmem = &C::member;` 
- nested classes (in class) vs. local classes (in function).
- union vs. anonymous union. discriminant idiom for unions.
- bit-fields and volatile. linkage directive extern "C".
