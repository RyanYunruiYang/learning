# Chapter 4: Expressions
## 4.1: Fundamentals
Started 8:11, ended 8:23
- componetns: expressions, operators, operands
- unary operators and binary operators
- operands are generally promoted
- historically, lvalues could stand on the left side and rvalues cannot. in c++ this distinction is not so. const lvalues cannot be on the left of assignment for example
    - roughly, rvalue is object's value/contents, lvalue is its identity/location
    - can use lvalue for rvalue, but not vice versa
- some operators guarantee order: AND, OR, as well as conditional (? :) and comma (,) operators


lvalues (more robust):
- in `const int ci = i;`, `ci` is a non-modifiable lvalue

rvalues:
- literals (like 1024)
- arithmetic expressions

## 4.2: Arithmetic Operators
Started 8:23, finished 8:29.
- unary operators generally have higher preference. 
- to do unary +/-, bools will promote to ints first, operate, and then demote
- negative quotients are rounded towards 0 (truncated)

## 4.3: Logical and Relational Operators
Started 8:29, Finished 8:38.

- bool false iff =0
- `(i<j<k)` will actually compare `(i<j)` to `k`

## 4.4 assignment operators
- assignment is right associative (you can y=z=0 and it'll call z=0 first and then do y=z).
- assignment has low precedence
- key idea: everything is an expression

## 4.5 increment and decrement operators
Started again 10:29am, finished 10:35.
- `++x` returns incremented amount as lvalue
- `x++` returns original amount as rvalue

```
auto pbeg = v.begin();
while (pbeg != v.end() && *beg >= 0) {
    cout << *pbeg++ << endl;
}
```
- this expression is equivalent to *(pbeg++)

## 4.6 The Member Access Operators
```
string s1 = "a string", *p = &s1;
auto n = s1.size();
n = (*p).size();
n = p->size();
```

## 4.7 The Conditional Operator
- syntax: `string finalgrade = (grade<60) ? "fail" : "pass";`
- you can nest: `string finalgrade = (grade>90) ? "highgrade" : ((grade<60) ? "fail" : "pass");`
- but you shouldn't nest more than two or three. they're pretty unreadable

# 4.8 The Bitwise Operators
- doing left shift on a char promotes it to int
- `<<` and `>>` for i/o are just overloaded version of bit shifts

## 4.9 sizeof operator
- right associative
- does not evaluate! you can have a fake pointer `Sales_date *p` and still call `sizeof (*p)`. 
- syntax is either `sizeof(type)` or `sizeof expression`.
- sizeof reference gives size of object referenced
- sizeof pointer gives size of the pointer itself
- sizeof a dereferenced pointer gives size of object
- sizeof array = (size of element) * (# of elements in array)
    - can get length as `constexpr size_t sz = sizeof(ia)/sizeof(*ia);`
- sizeof string/vector gives only fixed size

## 4.10 Comma Operator
- evaluates both left and right expressions, but returns the right hand expression

## 4.11 Type Conversions
- usually things are promoted
- unsigned int is promoted to int
- integrals promoted to floatings
- often, array is automatically converted to a pointer to the first el ement
    - not performed when &, sizeof, typeid, or decltype
```
int ia[10];
int* ip = ia;
```
- automatically convert a lot of objects to bool. for example cin is true if last read succeeded
- explicit conversions syntax: `cast-name<type>(expression);`
- cast-name can be static_cast, dynamic_cast, const_cast, and reinterpret_cast
- `static_cast` works for any well-defined type conversion **without low-level const**
    - can be used to suppress error messages about loss of precision. if j is an int, can do `static_cast<double>(j)`
    - static_cast can also retrieve values from void* pointers p as `double *dp = stati_cast<double*>(p);`
- `const_cast` changes only a low-level const in its operand
    - converts const to nonconst. cannot switch types. that's it. it's in the name the only thing this thing does is change the const-ness.
    - `const char *pc;` can be converted with `char *p = const_cast<char*> pc;`
    - mainly useful for overloaded functions. other uses indicate design flaw.
- `reinterpret_cast` directly changes the type. bare metal reinterpretation
- old-style casts have syntax `type (expr)` or `(type) expr`

## Summary
- lvalue = expression that yields an object or function. any nonconst lvalue can be the left-hand operand of assignment
- rvalue = expression that yields value, but no location attached
- compiler is free to evaluate operands in any  order
