# Chapter 13: Copy Control
- Chapter 7 discussed class scope, data hiding, and constructors. member functions, implicit `this` pointer, friends, `const`/`static`/`mutable`
    - We extend this with: copy control (13), overloaded operators & conversion operators (14), inheritance & dynamic binding (15), and templates (16) in Part 3
- Chapter 13: we consider the special copy constructor, move constructor, copy-assignment oeprator, move-assignment operator, and destructor

## 13.1 Copy, Assign, and Destroy
- by default, the "synthesized copy constructor" does memberwise copies of nonstatic members
- direct initialization = finding best matched constructor, copy initialization = copying from RHS
- copy initialization happens when:
    - we define variables using an =
    - pass an object as an argument to a parameter of nonreference type
    - return an object with a nonreference type
    - brace initialize the elements in an array or aggregate class
    - when library containers call insert/push (emplace induces direct initialization)
- copy-assignment: used for `Sales_data trans,accum; trans = accum;` and the synthesized version is:
```
Sales_data&
Sales_data::operator=(const Sales_data &rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhis.units_sold;
    revenue = rhs.revenue;
    return *this;
}
```
- destructor: there is only one
    - function body destroyed first, and then members in reverse order of initialization
    - destructors called: when going out of scope, parent object/container destroyed, temporary objects within expression, and delete operator for dynamically allocated objects
- Rule of three/five  = copy,copy-assignment,destructor + move, move-assignment
- Tip: If a class needs a destructor, it also needs the copy-assignment operator and copy constructor
- Tip: The need for copy and copy-assignment are tied together. 
- can explicitly ask for synthesized versions with
    - `Sales_data() = default;`
    - `Sales_data (const Sales_data&) = default`
    - `Sales_data& operator=(const Sales_data &);` and `Sales_data& Sales_data::operator=(const Sales_data&) = default;`
    - `~Sales_data()= default`
- can prevent copying by setting `NoCopy(const NoCopy&) = delete;` which means no copies are allowed
    - CERN FTS achieves this by inheritng from boost:noncopyable
    - destructor should not be deleted

## 13.2 Copy Control and Resource Management
- valuelike behavior
    - copy constructor that copies the string, not just the pointer
    - destructor to free the string
    - a copy-assignment operator to free the object's existing string and copy the string from its right-hand operand
```
// valuelike copy-assignment operator
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}
```

- pointerlike behavior
    - shared data
    - easiest way to implement this is with shared pointers
    - can also achieve it by manually keeping a `std::size_t *use;` pointer to number of references to object
## 13.3 Swap
- classes define swap to support library algorithms which swap objects. can be very optimized compared to naive swap.
```
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
}

inline
void swap (HasPtr &lhs, HasPtr &rhs) {
    using std:: swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
```
- man operators use copy and swap to implement assignment operator
    - notably parameter is not a reference. it is instead passed by value which creates a new copy
    - very exception and memory safe.
```
HasPtr& HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}
```

## 13.4 A Copy-Control Example
TODO:
- Exercises Section 13.4: Message and Folder

## 13.5 Classes That Manage Dynamic Memory
- StrVec example has valuelike behavior
- option 1: move constructors
- option 2: utility::move function
    - calling `alloc.construct(dest++, std;:move(*elem++)) ` will use the move constructor instead of copy constructor, and therefore not copy the values and just transfer membership

## 13.6 Moving Objects
- two motivations: speed (for strings) or forced (IO/unique_ptr classes which cannot have copy constructors)
    - previouly, all classes stored in a container had to be copyable. now they can be copyable or movable
- rvalue reference = reference that must be bound to an rvalue
    - may only be bound to object that is about to be destroyed
    - 
- reminder: lvalue is object's identity, rvalue is object's value
    - lvalues persist, whereas rvalues are literals or temporary objects created in course of evaluating expressions
    - rvalues will be destroyed, and there are no other users
- variables are lvalues
- std::move returns a rvalue reference
    - calling move tells the c ompiler that we have an lvalue we want to treat as if it were an rvalue
- move constructor syntax: `StrVec(StrVec &&) noexcept` declaration and `StrVec::StrVec(StreVec &&s) noexcept : /* member initializers */ { /* constructor body */}`
- exceptions
    - example: vector guarantees that when we call push_back, the vector itself will be unchanged
    - for vectors, therefore, we must tell it that our move constructor is safe with `noexcept`, because otherwise vector will be afraid that we'll throw an exception mid-move
- condition: a moved-from object must be destructible
    - after a move operation, the "moved-from" object must remain a valid, destructible object but users may make no assumptions about its value
- synthesized operations
    - compiler always synthesizes copy constructor/assignment and move constructor/assignment
    - copy operations are default synthesized defined as memberwise copy/assign
    - compiler will only synthesize move operators if (1) the class doesn't define any copy-control members and (2) every nonstatic data member of the class can be moved
        - can always move builtins, and can move classes if they have move operation
    - move constructor is defined as deleted if:
        - (1) class defines copy constructor but not move constructor
        - (2) members do not have move
        - (3) directly deleted/inaccessible 
        - (4) const or reference member
    - if you define move operators, copy operators must also be defined
- ravlues are moved, lvalues are copied ... but rvalues are copied if there is no move constructor
```
hp = hp2; // hp2 is an lvalue, copy constructor used to copy hp2
hp = std::move(hp2); // move constructor moves hp2
```
- Advice: you normally should define either the first three or all five
- move iterators
    - there is no equivalent for unitialized_copy for allocator
    - instead use move iterator
        - `auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);`
        - dereferencing move iterator gives rvalue, so the library will then call move constructor
- Best Practice: You should only use std::move inside class code. don't use it in ordinary user code
- Note: overloaded functions will usually copy with `const T&` and move with `T&&`
```
StrVec vec;
string s = "some string or another";
vec.push_back(s); // calls push_back(const string&)
vec.push_back("done"); // calls push_back(string&&)
```
- a function can be both const and reference qualified
    - const qualified = promises not to change any member variables of the class
    - reference qualified with `&` means it can only be called when the class is an lvalue, `&&` only on rvalues
```
class Foo {
public:
    Foo someMem() & const; // error
    Foo anotherMem() const &; // ok: const qualifier comes first
}
```

## Summary
- Chapter 13: Copy Control. copy and swap, {copy constructor, copy-assignment operator, destructor, move-constructor, move-assignment}, lvalue reference vs rvalue reference, defaults = memberwise copy/assign, std::move, move iterators, synthesized assignment/copy/move operators, reference count, reference qualifiers on functions.