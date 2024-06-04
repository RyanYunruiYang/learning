# Chapter 14: Overloaded Operations and Conversions


## 14.1 Basic Concepts
- if we're overriding by defining a member function, this is passed implicitly as the first parameter
- cannot override builtins addition
- Best Practice: do not overload comma, address-of, logical AND, logical OR

## 14.2 Input and Output Operators
- always nonmember
- output operator `ostream &operator<<(ostream &os, const Sales_data &item)`
- input operator `istream &operator>>(istream &is, Sales_data &item)`

## 14.3 Arithmetic and Relational Operators
- all nonmember. operator+, operator==, operator!=, 
- you should define != if you define ==
- you shouldn't feel obliged to define <, especially if it doesn't have a fundamental meaning
- guarantee: you should try to guarantee that if a != b, then either a < b or a > b

## 14.4 Assignment Operators
- copy and move assignment can also be equipped for objects of another class type
- example: `vector<string> v;` then `v = {"a", "an", "the"}`
```
StrVec &StrVec::operator=(intializer_list<string> i) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

```

## 14.5 Subscript Operators
- subscript operator returns a reference
    - can be used on left or right side. good idea to define both const and nonconst versions. both `std::string &operator[](std::size_t n)` and `const std::string& operator[](std::size_t n) const`


## 14.6 Increment and Decrement Operators
- ++ and -- are usually class members
- problem: how to distinguish prefix vs. postfix
    - solution: postfix operations have extra int `StrBlobPtr operator++(int);`
    - postfix usually calls prefix
- in explicit calls, `p.operator++(0)` gives postfix and `p.operator++()` gives prefix

## 14.7 Member Access Operators
```
class StrBlobPtr {
public:
    // dereference *:
    std::string& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    // arrow operator
    std::string* operator->() const {
        return & this->operator*();
    }
}
```
- fuzzy to me: so `->` is actually just a unary operator that returns a pointer to the value, which is then called by the function after?
    - writing `point->mem` either means:
        - (*point).mem; if point is a built in pointer type
        - pointer.operator->() -> mem; if point is a class type
            - the result of pointer.operator->() is used to fetch mem, following down until applying ->() gives a built-in pointer, at which point it is seen as a synonym for (*point).mem

## 14.8 Function-Call Operator
- function-call operator must be a member function
- a class can define multiple call operators
- such objects with call operators are called "function objects"
- lambdas are actually function objects!
    - when we write a lambda, the compiler turns it into an unnamed object of unnamed class
    - call operator is by default const member, unless lambda function is mutable
```
// Lambda Formulation
stable_sort(words.begin(), words.end(),
    [](const string &a, const string &b){ return a.size() < b.size(); });

// Function Objects
class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const {
        return s1.size() < s2.size();
    }
}
stable_sort(words.begin(), words.end(), ShorterString());
```
- captures are done by saving the captured values as members of the class
- alternatively, can nuse standard library classes like `plus<int> intAdd;` and use intAdd as a function. total list (Table 14.2): 
    - plus, minus, multiplies, divides, modulus
    - equal_to, not_equal_to, greater, greater_equal, less, less_equal
    - logical_and, logical_or, logical_not
- summary: there are lots of callable objects
    - functions, pointers to functions
    - lambdas
    - objcts created by bind (page 397)
    - classes that overload the function-call operator
- function tables are implemented with a map, something like `map<string, int(*)(int,int)> binops;`
- functional header has library type `function`. this is truly general and allows us to do:
```
int add(int i, int j){
    return i+j;
}
auto mod = [](int i, int j){ return i&j; };

struct divide {
    int operator()(int denominator, int divisor) {
        return denominator/divisor;
    }
};

function<int(int, int)> f1 = add; // function pointer
function<int(int, int)> f2 = divide(); // object of function-object class
function<int(int, int)> f3 = [](int i, int j){ return i&j; };
```


## 14.9 Overloading, Conversions, and Operators
- conversion operators define class-type conversions (such conversions are referred to as user-defined conversions)
- syntax: `operator type() const;`
    - cannot define return type (is implicitly known)
- usually, conversions are only defined to `bool`
    - to still be careful though, the c++11 standard introduced "explicit conversion operators"
```
explicit operator bool() const {
        // Conversion logic
        return some_condition; // Replace with the actual condition
    }
```
- warning: given class should only define at most one conversion from an arithmetic type

```
struct B;
sruct A {
    A() = default;
    A(const B&);
}
struct B {
    operator A() const;
}

A a = f(b); // can be interpreted as either:
// A a1 = f(b.operator A());
// A a2 = f(A(b));
```
- rules of thumb
    - don't define mutually converting classes. if class Fo has a constructor that takes object of class Bar, don't give Bar a conversion operator to type Foo
    - avoid conversions to built-in arithmetic types
    - avoid using anything other than the `explicit` conversion to `bool`
- overloaded operators are overloaded functions, and normal function matching (recall page 233)
    - be wary of `a sym b` being `a.operatorsym(b);` or `operatorsym(a, b);`

## Summary
- overloading operatorsym (Input and Output, Arithmetic and Relational, Assignment, Subscript, Increment and Decrement, Member Access = * and -> operator meaning, Function-Call Operator = lambda objects are function objects, function header for all three types of callables, Conversions = custom type conversions)