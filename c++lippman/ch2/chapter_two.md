# Chapter 2: Variables and Basic Types
## Section 2.1
Started 3:53, finished 4:23. 
- bool

- short < int < long < long long
- unsigned int, unsigned short, etc.
- char, wchar_t, char16_t, char32_t

- float (word), double (two words), long double (3 or four words)
- on some machines, double-precision calculations are faster than single (but long double isn't necessary)

- smallest chunk of addressable memory is byte
- word = 32 or 64 bits (4 or 8 bytes)

- you can only assign out of range values to unsigned objects. breaks for signed.

- literal = eself-evident value

- 20 (decimal) = 024 (octal) = 0x14 (hexadecimal)
- octal numbers start with 0
- floating point default = double
- 'A' is just the character, "A" is A + \0
- string literals that are separated only by spaces/tabs/newlines are concatenated
- known: `\n, \t, \\, \r, \", \'`
- weird: `\v, \b, \?, \f, \a`
- Table 2.2
    - u = char16_t, U = char32_t, L = wchar_t, u8 = char
    - u or U = unsigned
    - l or L = long
    - ll or LL = long long
    - f or F = float
    - l or L = long double

# Section 2.2  (Variables)
Started 8:15am, finisehd 9:02am
- assignment vs. initialization subtley different
- four ways to initialize integers
```
int x = 0;
int x = {0};
int x{0};
int x(0);
```
- variables outside function body are initialized to 0. those inside functions are uninitialized
- declaration makes name known
- definition creates the associated entity
- `extern int i` declares but doesn't define `i` 
- `int j` declares and defines `j` 
- to use a variable in multiple files, must define it in one place, and everywhere else declare but not define it
- c++ is statically types (types are checked at compile time)
- identifiers cannot contain `__`, cannot begin with an underscore outsidee of a function
- classes usually begin with uppercase leter
- Table 2.3 has c++ keywords (page 47)
- doing `::reused` searched for reused in the global scope

# Section 2.3 (compound types)
Started 2:54, 
ended 5:24. 
- references `int &x = y` makes it so that `x` has the same value as `y` always.
- `int i = 42;`
- `int &r = i;` (`r` is a reference)
- `int *p;` (`p` is a pointer)
- `p = &i` (address of operator)
- `*p = i` 
- `int &r2 = *p;`
- Null pointer: `int *p1 = nullptr` (or 0, or NUL with #include cdstdlib)
- `void *pv` pointers hold an address without an associated type
- you can have a pointer to a pointer but not a pointer to a reference
- `int *&r` means that r is a `&`(reference) to a `*`(pointer) to an int

# Section 2.4 (const qualifier)
Started 7:36
Ended 10:35
- const means can't modify. otherwise can treat the same.
- `const int bufSize = 512;` will substitute directly at compile time
- `const` files must be local to file
- to use in multiple files, do `extern const int bufSize = fcn()` in one spot, and declare it as `extern const int bufSize;` elsewhere
- to do a reference need to do `const int &r1 = ci` if `ci` is const
- `double dval = 3.14; const int &ri = dval;` is legal, but they will not track each other. this is because the latter is shorthand for `const int temp = dval;` and then `const int &ri = temp;`
- the only way to save a pointer to `const double pi = 3.14` is with `const double *cptr = &pi` (can reassign cptr but cannot modify its value)
- const pointers are pointers that *think* they refer to a const
- top-level const = pointer itself is a const
- low-level const = pointer points to const
- constant expressions are `const int x = 5;` but not `const int x = get_x();`
- `constexpr int x = 20;` or `constexpr int x = size();` are feasible if `size()` is defined to be simple enough to be evaluated at copmile time. 
- types that can be used with `constexpr` are called the "literal types"
- `const int *p = nullptr;` is a pointer to a const int
- `constexpr int *q = nullptr;` is a const pointer to int
- `constexpr const int *p = &i` is a constant pointer to const int i
- "const reference" is colloquial way of saying "reference to const"

# Section 2.5 (dealing with types)
Started 10:40, ended 11:10
- ```
  typedef double wages;
  using SI = Sales_item;
  wages hourly, weekly; // same as double hourly, weekly;
  SI item; // same as Sales_item item
  ```
- `auto` must be consistent for single line declarations. `auto sz = 0, pi = 3.14` would be inconsistent
- `auto` ignores top-level consts
- `decltype(f()) sum = x;` initializes sum with type of `f()` and value from `x`. decltype is the only text in which a variable defined as a reference is not treated as a synonym for the object to which it refers
- `int i = 42, *p = &i, *r = i`
- `decltype(*p) c;` fails because the type returned by dereference is `int&`
- `decltype((variable))` is always a reference type

# Section 2.6 (defining data structures)
Started 11:10
```
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```
- class body defines the members of the class
- our class has only data members. modifying data members of one object does not change the data in any other Sales_data object
- you can define limited classes inside functions (p. 852)
- preprocessor runs before the compiler
    - when it sees #include it replaces it with the contents of the header
    - header guards use `#define`, `#ifdef`, `#ifndef` and elif,else, `#endif`
    - defines preprocessor variables (also known as macros)
    - macros are just used to automatically substitute into the code before handing off to compiler. never actually saved. 

## Terms
- definition = actual action of allocating storage for a variable
- top-level const = object may not be changed
- low-level = object may be changed but the thing it points to cannot
- type alias done with `typedef`