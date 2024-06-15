# Chapter 16: Templates and Generic Programming
## 16.1: Defining a Template (26 pages. 652-677)
```
template <typename T>
int compare(const T &v1, const T&v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

```
- the compiler uses the deduced template parameters to "instantiate" a specific version of the function
- `<typename T, class U>` do broadly the same thing.
- nontype template parameters: represent value instead of type. parameters are replaced by the value supplied by the user (must be constexpr to be instantiated at compile time)
    - may be integral type. must be constexpr.
    - or pointer/(lvalue)reference to object or function type. must have static lifetime. 
- template can be made inline as `template <typename T> inline T min(const T&, const T&);`
- BestPractice: minimize requirements on argument types
```
template <typename T> int compare (const T &v1, const T &v2) {
    if (less<T>()(v1, v2)) return -1;
    if (less<T>()(v2,v1)) return -1;
    return 0;
}
```
- USEFUL: ordinarily, compiler only needs to see declaration for functions but not definitions for functions, and class definitions but not member definitions. that's why we put class definitions and function declarations in header files, and definitions of ordinary and class-member functions in source files
    - templates are different: the compiler needs to have the code that defines a function template or class template member function
- Key Concept: Authors of templates should provide a header that contains the template definitions along with declarations for all the names used in the classs template or in the definitions of its members. Users of the template must include the header for the template and for any types used to instantiate the template
- when the compiler instantiates a class from our Blob template, it rewrites the template replacing each instance of the template parameter T by the given template argument
- member functions of class templates
```
// General Syntax:
template <typename T>
ret-type Blob<T>::member-name(parm-list)

// Example
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const { 
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
```
- when in class template scope, all references to the template itself do not need to contain the parameters
```
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) { // out of scope in declaration, so needs parameters
    BlobPtr ret = *this; // in scope, so does not need parameters
}
```
- can give friends to other templates of same type: `friend class BlobPtr<T>;`
- to friend a specific instantiation of template (if class C or template on T): `friend class Pal<C>` or `friend class Pal<T>`. to friend all instantiations use some unused variable `T` or `X` and do `template <typename T> friend class Pal2;` or ``template <typename X> friend class Pal2;`
- c++11 allows for type alias of class template: `template<typename T> using twin = pair<T, T>;` with usage `twin<int> win_loss;` creating a `pair<int,int>`
- static variables are connected to specific instantiations
- the actual names of the template parameters are not important, all three of the following are the same:
```
(a) template <typename T> T calc(const T&, const T&);
(b) template <typename U> U calc (const U&, const U&)
(c) template <typename Type>
    Type calc(const Type& a, const Type& b) { /* */ }
```
- Best Practices: all the templates should appear together at beginning of file
- Problem: is `T::size_type * p` a declaration of a pointer p, or multiplying a static data member named `size_type` by a variable named p.
- Solution: By default compiler assumes that names are not types, and we must explicitly tell the compiler that the name is a type
```
template <typename T>
typename T::value_type top(const T& c) {
    if (!c.empty()) {
        return c.back();
    }
    else {
        return typename T::value_type();
    }
}
```
- can pass "default template arguments"
```
template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F()) {
    if (f(v1,v2)) return -1;
    if (f(v2,v2)) return 1;
    return 0;
}
```
- must use empty brackets `<>` if we want to use all defaults
- member templates are members of a {class or template} that are themselves templates
- can do explicit instantiation
    - `explicit template declaration` is a promise that there will be a non`extern` use elsewhere
- 

## 16.2: Template Argument Deduction (16 pages)
- trailing return types let us declare the return type after the parameter list is seen
```
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg) {
    return *beg;
}
```
- remove_reference maps X& and X&& to X
- add_const maps

Cool: The standard defines move as follows:
```
template<typename T>
typename remove_reference<T>::type&& move(T&& t) //takes anything as input and returns rvalue reference
{
    return static_cast<typename remove_reference<T>::type&&>(t);
}

// instantiation for calling std::move(string("bye!)):
string&& move(string &&t) {
    return static_cast<string&&>(t);
}
// instantiation for std::move(s1);
string&& move(string &t)
```
- we can preserve type paramters referenceness with templates like:
```
template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 && t2) {
    f(t2, t1);
}
```
- Note: In general, a function parameter that is an rvalue reference to a template type parameter (ie T&&) preserves the `const`ness and lvalue/rvalue property of its corresponding argument
- we can use another function from the `<utility>` header: `forward`
    - return type of `std::forward<T>` is T&&
    - recall that T& && is equivalent to T&, so this preserves lvalue/rvalue

## 16.3: Overloading and Template (5 pages)
- candidate functions for a call include function-template instantiation for which template argument deduction succeeds
- viable functions are ranked. if one dominates, it is chosen. otherwise
    - ties are broken towards singular nontemplate
    - otherwise ambiguous
- Note: when several overloaded templates provide equally good match for call, the most specialized version is preferred
- array to pointers are considered exact matches for function-matching purposes (page 245)

## 16.4: Variadic Templates (7 pages)
- variadic templates take varying numbers of parameters, known as a parameter pack
- `...` is the "pack expansion" operator
- generic syntax:
```
template <typename T, typename... Args>
void foo(const T &t, const Args&... rest);
```
- forwarding parameter packs
```
class StrVec {
public:
    template <class... Args> void emplace_back(Args&&...);
    // remaining members from page 526
};

template <class... Args> inline
void StrVec::emplace_back(Args&&... args) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}
```

## 16.5: Template Specialization (7 pages)
```
// specializing std::hash fro Sales_data
namespace std {
template<> // <--- IMPORTANT. this declares that this is a specialization
struct hash<Sales_data>
{
    typedef size_t result_type;
    typedef Sales_data argument_type;
    size_t operator()(const Sales_data& s) const;
};
size_t
hash<Sales_data>::operator()(const Sales_data& s) const {
    return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
}
}
```
- note: Sales_data class will need to mark the specialization as a friend
- `remove_reference` is an example of specialization


## Summary
- Chapter 16: Templates. Blueprint for compiler auto-generating code for class type or functions (instantiation). Variadic Templates, Template Specialization (Partial Specialization too). Explicit Template Arguments vs. Conversions. default template arguments. Explicit instantiation (extern, avoid multiple instantiations). Function parameter packs. Member Templates. Nontype parameters (ex: Array Length). Template argument deduction.