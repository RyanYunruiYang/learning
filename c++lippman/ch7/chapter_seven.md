# Chapter 7: Classes
## 7.1 Defining Abstract Data Types
- fundamental ideas: data abstraction (separation of interface and implementation) + encapsulation (enforces separation)
    - class that does both is called abstract data type
- member functions must be declared inside. they may be defined inside the class or outside the class body. 
- nonmember functions are declared/defined outside
```
std::string isbn() const {return bookNo;}
std::string isbn() const {return this->bookNo;} //equivalent
```
- the const following the parameter list indicates that `this` is a pointer to const. member functions that use const in this way are called "const member functions"
    - need to do this because objects that are const can only call const member functions
- member declarations are compiled, then member functions processed
- can declare member functions outside of class scope as:
```
double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue/units_sold;
    }
    else {
        return 0;
    }
}
```
- default constructor created if class declares no constructors
    - you should create a default constructor if default initializations for members are bad
    - also if class member has class type, the default initialization will need a default constructor for it
- in later chapters, will show how to do our own versions of copy, assignment, and destruction (i.e. line `total = trans;`)
- until you know how to define the operators covered in 

## 7.2 Access Control and Encapsulation
- members after `public` specifier are accessible everyway (the interface)
- members after `private` specifier are accessible to member functions only
- in `struct`, members are by default public. in `class`, members are by default private
- note: while user code that only uses the interface does not need to be rewritten, it does need to be recompiled
- friend syntax: `friend Sales_data add(const Sales_data&, const Sales_data&);` at beginning of class, for a function declared afterwards as `Sales_data add(const Sales_data&, const Sales_data&);`

## 7.3 Additional Class Features
- member functions defined inside class are inline automatically
- best practice is to only specify inline on definition outside of class body
- `mutable size_t access_ctr;` means that it may change even in a `const` object
- see Screen/Window_mgr/main.cpp (everything in the Makefile)

## 7.4 Class Scope
- Exercise 7.33: the declaration `pos size() const;` needs definition `Screen::pos Screen::size() const` because when the compiler is reading the return type, it doesn't know that we're in Screen scope
- member declarations are compiled, and then the body is compiled only after the entire class has been seen (this way you can reference other objects)
- Style Tip: definitions of type names should appear at the beginning of the class
- name in body member search: inside function body -> inside class -> inside scope before member function definition
- Exercise 7.35: change val type to double?

## 7.5 Constructors Revisited
- constructors must initialize sometimes (consts, references, cannot be assigned)
- constructors of class X of the form `X(int val): j(val), i(j)` actually evaluate right to left, so this code is invalid
- you can delegate your work too.
```
class Sales_data {
public:
    Sales_data(std::string s, unsigned cnt, double price):
                bookNo(s), units_sold(cnt), revenue(cnt*price) {}
    Sales_data(): Sales_data("", 0, 0) {}
}
```
- common mistake: calling `Sales_data obj();` does not call the default constructor, and instead declares a function
- implicit class-type conversions happen. can do `string null_book = "9-999";` and then `item.combine(null_book);`, and it'll convert the string to a Sales_data object for you
    - only rue for single argument constructors
- we can prevent implicit conversion with the keyword `explicit Sales_data(std::istream&);` 
    - but you can only put it in the constructor declaration inside the class
    - must be used with syntax `Sales_data item2 = null_book`
    - can still pass in with static_casts.
- aggregate class = (1) all data members public, (2) no constructors, (3) no inclass initializers, (4) no base classes or virtual functions
    - then, one can do braced list initialization
- Literal classes = aggregate class who are all literal OR (all literal members + at least oen constexpr constructor + constexpr in-class initializers + default definition for destructor)
- const expr constructor must have no return (constructor) + only returns in body (constexpr) ==> empty body
- Exercises: NA

## 7.6 `static` Class Members
- static members belong to class.
    - do not have `this` pointer
    - can also not be a const 
    - can not call non`static` members
- do not need to repeat `static` in definition outside of class
- Style Tip: place definition of `static` data members in same file as definitions of class noninline member functions
- Best Practice: `const static` data members should be defined outside the class definition
- `static` exists independently of any other object, and can 
    - have the same type as the class type of which it is a member
