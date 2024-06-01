# Chapter 3: Strings, Vectors, and Arrays
- string and vector both extend native array class
## 3.1 (namespace `using` declarations)
Started 1:10, ended 1:18

- doing `using namespace::name`, for example `using std::cin` means that you can say `cin` instead of `std::cin`
- headers should not include `using` declarations

## 3.2 (library `string` type)
Started 1:19, Ended 2:06
- `#include <string>` and `using std::string;` needed
- `string s4(10,'c')` gives `cccccccccc`

Ways to initialize:
```
string s1; (default)
string s2(s1); (deep copy)
string s2 = s1;
string s3("value");
string s3 = "value";
string s4(n, 'c');
```
- String Operations
    - os << s and is >> s
    - getline(is, s); reads line of input from is into s
        - normal cin>>s separates by whitespace, whereas getline separates by `\n`
    - s.empty(); boolean
    - s.size(); number of characters
        - actually returns a `string::size_type` value and not `int`
    - s[n]; character at position n
    - `+,=,==,!=,<,<=,>,>=`
        - cannot add character string literals together directly. need each `+` to touch a string
        - string literals != library `strings` !
- if c has `ctype.h`, then c++ uses `cctype` (that way it's easier to remember which library names are from c and which are from c++)
- `for (declaration : expresion)` is a `range for` statement
- given a string, we can do `for (auto c : str)` to run through all characters
- can check if: isalnum, isalpha, iscntrl, isdigit, isgraph, islower, isprint, ispunct, isspace, isupper, isxdigit, and can call tolower(c) or toupper(c)
- need to do `for (auto &c : s)` in order to mutate.
- `[]` is subscriptoperator


# 3.3 (library `vector` type)
Pages 96-105.
Started 2:10, ended 2:37.
Average time: 2.7 minutes/page.

- vector is a container
- vector is a class template (won't learn that until chapter 16)
- process of creating classes/functions from templates is called "instantiation"
- when you call `vector<int>` or `vector<Sales_item>`, the compiler generates a distinct type from the `vector` template
- cannot have `vector` references. most others work though
```
vector<T> v1;
vector<T> v2(v1); == vector<T>v2 = v1;
vector<T> v3(n, val);
vector<T> v4(n)
vector<T> v5{a,b,c,...}; == vector<T> vt = {a,b,c,...};
```
- `()` for function, `{}` for lis tinitialization
- there seems to be some c++11 specific behavior around `vector<string> v6{10}`
- `push_back` adds element to back. 

# 3.4 (iterators)
Pages 106-112.
Started 2:37, Ended 2:55. 
2.57 minutes/page.
- `auto b = v.begin(), e = v.end();` (e is off the end)
- for iterators, one can
    - access `*iter` or `iter->mem` (equivalent to `(*iter).mem`)
    - `++iter` or `--iter`
    - compare with == or !=
- library defines types `string::iterator` and `string::const_iterator`, where the latter can read but not write characters
- usually `.begin()` will just reflect `const`ness of vector/string, but you can force it to be a const_iterator with `.cbegin()`
- `it->mem` is a synonym for `(*it).mem`
- vector/string are extra supported with additional iterator arithmetic
    - can +n or -n, +=n or -=n, can do >, >=, <, <=
    - can subtract iterators, which gives a `difference_type` (signed)

# 3.5 (arrays)
Pages 113-125.
Started 2:56. Ended 3:16.
Started 3:50, Ended 4:27.
- for initialization, can specify dimension `int arr[10]` or `int arr[constexpr]`, or with list initialization, or both `int a3[5] = {0,1,2}` is equivalent to `a3[] = {0,1,2,0,0}` 
- character arrays are string literals
    - contains null `const char a4[6] = "Daniel";` will error
- no arrays of references (cannot do `int &refs[10] = ???`)
- can have pointers and references to arrays
    - `int (*Parray)[10] = &arr` is a pointer to an array of ints
    - `int (&arrayRef)[10] = arr` is a reference to an array of ints
    - `int *(&arry)[10]] = ptrs;` makes arry a reference to an array of ten pointers
- arrays use `size_t` for index subscripts (type is defined in cstddef)
- you can still do `for (auto i : scores)` (array handles length becaues it knows length)
- arrays are kindof pointers. less so than in C. but `string *p2 = nums;` is still equivalent to `p2 = &nums[0];`
    - also auto will think that arrays are pointers
- `<iterator>` header has `begin(ia), end(ia)`
- result of subtracting two pointers is `ptrdiff_t` (in cstddef header)
- `p[-2]` is the same as `ia[0]`
- `cstring` is our version of `string.h`
- can get C-style strings with `char characterarray[] = "a string example;`
- can back acommodate with `const char *str = s.c_str();`
- can also use array to initialize vector
```
int int_arr[] = {0,1,2,3,4,5};
vector<int> ivec(begin(int_arr), end(int_arr));
```
- Note: modern C++ should use (vectors and iterators and strings) instead of (built-in arrays and pointers or C-style char strings)

# 3.6 (multidimensional arrays)
Pages 126-132.
Started 4:27, Ended 4:40.

- Syntax: `int ia[3][4] = { {0,1,2,3}, {4,5,6,7}, {8,9,10,11}};`
- in a range for loop, all but the innermost array must have references
```
for (const auto &row : ia)
    for (auto col : row)
        cout << col << endl;
```
- because otherwise row would be a type `int*`

TODO: review how to search over 2d list.

## Terms
- compiler extension = compiler specific feature. does not translate
- container = type whose objects hold a collection of objects of a given type
- direct vs. copy initialization