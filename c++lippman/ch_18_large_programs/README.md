# Chapter 18: Tools for Large Programs
## 18.1 Exception Handling (772-785)
- key goal: one part of the program can detect a problem and pass the job of resolving that problem to another part of the program
- the selected handler for each exception is: the one nearest in the call chain that matches the type of the thrown exception
    - functions along the call chain may be prematurely exited
    - when a handler is entered, objects created along the call chain will have been destroyed
- stack unwinding: keep going up function calls until we find a function that was in a try-catch -- or until we hit main
    - execution will continue at the point immediately after the last catch clause associated with that try block
- Note: an exception that is not caught terminates the program
- compiler guarantees that objects created in block exited during stack unwinding are properly destroyed
- destructor will always be called -- so we should do freeing there. but if a destructor does an operation that might throw, it should always wrap that operation and handle it itself
- Warning: Throwing a pointer requires that the object to which the pointer points exists wherever the corresponding handler resides.
- the parameter in the catch is a copy of the exception object! `catch` is just a function?
    - if the header was not a reference, then it would get sliced down. that's why we always make it a reference.
- the only conversions allowed in finding a matching handler are:
    - (1) conversion from nonconst to const
    - (2) conversions from derived type to base type
    - (3) array to pointer to type of array, function to pointer to function type
- Note: multiple `catch` clauses with types related by inheritance must be ordered from most derived type to least derived
- empty `throw;` is called a "rethrow". must be in catch or `terminate` is directly called. 
    - modifications to parameter in rethrow only happen for reference
- catch-call = `catch(...)`
- can use "function try block" to catch errors in initialization phase of constructor
```
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) try:
              data(std::make_shared<std::vector<T>>(il)) {

              } catch(const std::bad_alloc &e) { handle_out_of_memory(e); }
```
- `void recoup(int) noexcept;` has  "nonthrowing specification"
- if error thrown in `noexcept` function, `terminate` is immediately called
    - old syntax was `void recoup(int) throw();`. very deprecated now though.
- `void recoup(int) noexcept(bool);` won't throw iff bool=true. 
    - this lets us do stuff like `void f() noexcept(noexcept(g()));` which says that f has the same exception specifier as g.
- for virtual functions, derived class must have stricter noexcept rules
- inheritance hierarchy starts at exception (page 783)

## 18.2 Namespaces (785-802)
- namespaces do not end with semicolons, are a scope, can be discontiguous
- members inside namespace may use unqualified names
- template specializations must be defined in the same namespace that contains the original template
```
namespace std {
    template <> // in namespace since it's a specialization
    struct hash<Sales_data>;
}
```
- `inline namespace FifthEd` does not require the qualifying scopes, can be used directly.
- unnamed namespaces are local to a particular file
    - same as normal declaration, only difference is that you enforce that they are local to the file (alternative to C's use of "file statics")
- namespace alias: `namespace short_name = cpluplus_prime_we_already_defined::QueryLib;`
- using declaration, i.e. `using MyNamespace::func;` , vs. using directive `using namespace MyNamespace;`
    - using directives are handled by imagining that when we called `usign namespace A;`, that in fact the names in `A` had been in global scope already
    - compiler will throw error if both global scope and used namespace have collisions
- Note: Headers should not contain `using` directives OR declarations except inside functions/namespaces
- when we pass an object of class type to a function, compiler searches the namespace in which the argument's class is defined too!
- by default, friends of a funtion are assumed to be a member of the closest enclosing namespace
- when we write a using declaration, all overloaded versions of that function are brought in

## 18.3 Multiple and Virtual Inheritance (802-816)
- `class Panda : public Bear, public Engangered { /* */ };`
    - pointer/reference to ZooAnimal, Bear, or Endangered can be bound to a Panda object
- cannot inherit the same constructor from more than one base class
- reminder: destructors are always invoked in reverse order of constructors.
- reminder: destructor in derived class does not have to deal with destroying base class
- name lookup with multiple inheritance happens simultaneously among all the direct base classes
    - potential ambiguity is fine s long as no object ever calls without specifying `ZooAnimal::max_weight` for example
- solution:
```
double Panda::max_weight() const
{
    return std::max(ZooAnimal::max_weight(), Endangered::max_weight());
}
```
- same base class can appear as subobject multiple times (diamond dependency-esque structure)
    - solve this problem with "virtual inheritance"
- Note: virtual derivation affect the classes that subsequently derive from a class with a virtual base; it doesn't affect the derived class itself.
- syntax:
```
class Racccoon: public virtual ZooAnimal { /* */ };
class Bear: virtual public ZooAnimal { /* */ };
class Panda: public Bear, public Raccoon, public Endangered {
    /* */
};
```
- if D1 and D2 both define x, and D inherits from D1 and D2, D should just define its own version of x to handle ambiguity
- Panda's constructor should initializze ZooAnimal
```
Panda::Panda (std::string name, bool onExhibiti):
    ZooAnimal(name, onExhibit, "Panda"),
    Bear(name, onExhibit),
    Raccoon(name, onExhibit),
    Endangered(Endagered::critical),
    sleeping_flag(false);
```
- construction order: virtual base subparts initialized first, then by order in derivation list for direct base subparts.
## Summary
- exceptions: catch(...). exception declaration (copied if not reference!), exceptions are normal, quite simple objects, function try blocks for constructors, noexcept() operator, `noexcept`, rethrowing, terminate, 
- namespaces: file static = unnamed namespace, inline namespace, namespace alias, using declaration vs. directive, 
- multiple/virtual inheritance: constructor order rules, multiple inheritance, virtual base, 