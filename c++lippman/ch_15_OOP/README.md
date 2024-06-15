# Chapter 15: Object-Oriented Programming
## 15.1 OOP: An Overview
- OOP main ideas are: data abstraction, inheritance, and dynamic binding
- terms: inheritance, base class, derived classes
- the base class defines as virtual those functions it expects its derived classes to define for themselves
- class derivation list: colon followed by comma-separated list of base classes
    - the public in the following example means that we can use objects of type Bulk_quote as if they were Quote obejcts
```
class Bulk_quote : public Quote {
    double net_price(std::size_t) const override; // Bulk_quote is defining a virtual function
}
```
- dynamic binding is known as "run-time binding" because the decision of which version to run, for virtual functions, cannot be made until runtime

## 15.2 Defining Baes and Derived Classes
- Note: Base classes ordinarily define a virtual destructor
- a base class specifies that a member function should be dynamically bound by preceding its declaration with the keyword virtual
    - any non`static` member function other than a constructor may be virtual
- member functions that are not declared as `virtual` are resolved at compile time, as opposed to run time
- access specifier determines whether users of a derived class are allowed to know that the derived class inherits from its base class
- if a derived class does not override a virtual from its base, then, like any other member, the derived class inherits the version defined in its base class
- derived object contains subobjects for its base classes
```
/* derived-to-base conversions: */

Quote item; // object of base type
Bulk_quote bulk; // object of derived type
Quote *p = &item;
p = &bulk; // p points to the quote part of bulk
Quote &r = bulk; // r bound to the Quote part of bulk
```
- scope of a derived class is nested inside the scope of its base class
- declarations of derived classes do not include its derivation list
- class must be defined before we can use it as a base class
- direct base = in the derivation list, indirect base = inherited through a chain of direct base classes
- if we don't want our class to be inherited from, we can say `class NoDerived final` or `class Last final: Base`
- static type vs. dynamic type
    - always same for things that aren't references or pointers
    - however, dynamic type can be a derived class of static type
- cannot convert base to derived, even if the base type is actually just a temporarily embarassed derived type
```
Bulk_quote bulk;
Quote *itemP = &bulk; // itemP has static type Quote, and dynamic type Bulk_quote
Bulk_quote *bulkP = itemP; // static type violation. compiler only looks at static types.
```
- one can use static_cast if we know the conversion is safe, and dynamic_cast to request the conversion to be checked at runtime
```
/* slicing down */
Bulk_quote bulk;
Quote item(bulk); // calls Quote::Quote(const Quote&)
item = bulk; // calls Quote::operator=(const Quote&)
```

## 15.3 Virtual Functions
- Three Key Concepts on Conversion Among Types Related by Inheritance
    - 1: the conversion from derived to base applies only to pointer/reference types
    - 2: no implicit conversion from base-class type to derived type
    - 3: derived-to-base conversion may be inaccessible due to access controls
- note that dynamic binding only happens through pointers or references, i.e. if `Quote base; Bulk_quote derived; base = derived;` is called, then base is now wholly an object of type `Quote`
- calls to nonvirtual functions are bound at compile time
- once a function is declared as virtual it remains vritual in all the derived classes
- virtual in derived classes must have exact same parameter types, and usually have to have the same return type
- compiler will help us reject a program if a function marked override does not override an existing virtual function
- functions can also be final
```
struct D2 : B {
    void f1(int) const final;
}
```
- Virtual functions will always use the default arguments provided by the base class

## 15.4 Abstract Base Classes
- we sometimes want to define classes that will be used for future inheritance, but we don't want to actually be constructible
```
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,  // we still need this constructor because derived classes will use it
                std::size_t qty, double disc):
                    Quote(book, price),
                    quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0; // <--- pure virtual function
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
```
- classes with pure virtuals are abstract base classes
- Refactoring: Adding Disc_quote to the Quote hierarchy is an example of refactoring, which involves redesigning a class hierarchy to move operations and/or data from one class to another.

## 15.5 Access Control and Inheritance 
- a derived class member or friend may access the protected members of the base class only through a derived object
- the derivation access specifier has no effect on whether members (and friends) of a derived class may acccess the members of its own direct base class
- rather, the purpose of the derivation access specifier is to control the access that users of the derived class have of the base class
- conversion from D to B
    - user code may use ... only if D inherits publicly from B (not private or protectedd)
    - member functions and friends of D may use ... alwyas
    - member functions / friends of {classes derived from D} may use ... if D inherits with public/protected from B
```
class Base {
    friend class Pal;
}

class Pal {
    int f(Base b) {return b.prot_mem;} // ok
    int f2(Sneaky s) {return s.j;} // error
    int f3(Sneaky s) {return s.prot_mem;} // ok: Pal is friend of Base
}
```
- friendship is not inherited (mostly)
- a derived class may provide a using declaration for names it is permitted to access
```
class Derived : private Base {
public:
    using Base::size;
protected:
    using Base::n;
}
```
- by default `struct D1 : Base` is public inheritance, and `class D2 : Base` is private inheritance

## 15.6 Class Scope under Inheritance
- attributes search class itself, then parent classes, and so on (just like in python!)
- static type determines what members are visible (name lookup happens at compile time)
- derived classes generally should not reuse names defined in its base class
- Name Lookup Process: given call `p->mem()` or `obj.mem()`
    - 1: determine static type of `p` (or `obj`)
    - 2: look for `mem` in the class, then base class, etc
    - 3: once found, do normal type checking to check if call is legal
    - 4: generates code
        - if mem is virtual, and call is made through reference/pointer, the compiler generates code at runtime
        - if nonvirtual or not reference/pointer, compiler generates a normal function call
- inner scope function hides even if they have different parameter lists
- virtual functions differ from just hiding in that it allows us to use the dynamic type, instead of static type

## 15.7 Constructors and Copy Control
- recall: destructor is run when we `delete` a pointer to a dynamically allocated object
- we want it to delete based on dynamic type, so we almost always define a virtual destructor for base classes
- synthesized Bulk_quote default constructor runs Disc_Quote default constructor which runs the Quote default constructor
- `delete`ing functions in Base will tend to delete them in derived
- destructors, unliek constructors and assignment operators, are not responsible for destorying the resources allocated by the base clase
- we can inherit constructors by doing
```
class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote; // inherits all of Disc_quote's constructors
    double net_price(std::size_t) const;
}
```
- compiler generated constructors have form `derived(parms): base(args) { }`
    - if derived class has any data members of its own, those members are default initialized
- characteristics of inherited constructor
    - access level (private/public/protected) is always same as in base
    - can't specify explicit/constexpr
    - default arguments are split into multiple constructors, for example `B(x, y=0)` gives `D(x)` and `D(x,y)`
    - derived class can still override constructors
- default, copy, and move constructors are not inherited

## 15.8 Containers and Inheritance
- hard to put Bulk_quote objects into `vector<Quote>` without them getting sliced down. use pointers instead
```
vector<shared_ptr<Quote>> basket;

basket.push_back(make_shared<Quote>("isbn1", 50));
basket.push_back(make_shared<Bulk_quote>("isbn2", 50, 10, 0.25));
```
- smarter poitner to derived types easily convert to smart pointer of base-class type
- inheritance vs. composition = is A vs. has A


## 15.9 Text Queries Revisited

## Summary
- Chapter 15: OOP. inheritnce grants overriding, dynamic binding allows for function selection based on runtime type (only applies to virtual functions called through reference/pointer), derived classes contain subobject that is the base, inherited objects construct/copy/move/assign using base parts, destructors similarly. base classes need to define virtual destructor. public/private/protected protection levels, and their relationship with friendship and inheritance. abstract base class = class containing virtual function. class derivation list, derived-to-base conversion rules. direct vs. indirect base class. static vs. dynamic type. override, final. sliced down.