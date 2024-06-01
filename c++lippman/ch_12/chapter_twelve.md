# Chapter 12: Dynamic Memory
Pages 449 to 490.
## 12.1 Dynamic Memory and Smart Pointers
- static memory: static objects, class static data members, and variables outside any function
- stack memory: nonstatic objects inside functions
- static/stack memory are automaticlaly destroyed when the program ends. but there is another source, called free store or heap
    - programs use the heap for objects that they dynamically allocate
- all in `memory` header:
- shared_ptr
    - syntax: `shared_ptr<string> p1;` is a shared_ptr that can point at a string
    - default initialization is a null pointer
    - safest method: `shared_ptr<int> p3= make_shared<int>(42);` (these arguments are used in the same way as it would be in an emplace)
    - maintains a reference count.
        - increments when copied, used in rvalue, or passed to function
        - decrements when shared_ptr is destroyed, or when `p=q` is called where p,q are shared_ptrs
        - memory automatically frees when counter goes to 0 (calls the destructor) 
        - `p.unique()`returns if count is 1 and `p.use_count()` returns number of objects sharing with p
    - note: should erase() the elements you put in a container to delete references
- three use cases: 
    - 1: don't know how many objects they'll need
    - 2: don't know type
    - 3: want to share data between several objects
- to achieve 3, we need shared_ptr
```
Blob<string> b1;
{
    Blob<string> b2 = {"a", "an", "the"};
    b1 = b2;
} // b2 should not be destroyed so that b1 will still point at the right things
```
- by default, dynamically allocated objects are default initalized

- manual: calls `new` and `delete`
    - `int *p1 = new int;` or `int *p2 = new (nothrow) int;`. can then call `delete p;`
- dangling pointer = pointer that refers to memory that once held an object but no longer does
- problems:
    - 1: forgetting to delete causes memory leaks
    - 2: using object after it has been deleted
    - 3: deleting same memory twice
- limited protection
- delete can delete consts

- can also initialize smart pointer from new `shared_ptr<int> p2(new int(42));`
- `.get()` returns a built-in pointer to object that smart pointer is managing
- smarter pointers are also great because they are properly freed when exceptions occur
- by default, shared_ptrs assume they point to dynamic memory
- we need to define our own destructors
    - can pass a deleter to `shared_ptr<connection> p(&c, end_connection)` where `connection c = connect(&d)`
- unique_ptr
    - unique ownership.
    - must use direct form initialization, bound to a pointer returned by new (cannot copy or assign)
    - can transfer ownership from p1 to p2 `unique_ptr<string> p2(p1.release());` which sets p1 to null
    - we have responsibility for deleting if we call `p2.release()` without passing it on to another
    - can declare deleter `unique_ptr<objT, delT> P (new objT, fcn);`
- weak_ptr
    - weak_ptr points to object managed by shared_Ptr
    - to access, `wp.lock()` returns a shared_ptr to the shared object (or null if deleted)

## 12.2 Dynamic Arrays
- can allocate array with syntax `int *pia = new int[get_size()];`
    - or through `typedef int arrT[42];`, and then `int *p = new arrT;`
    - can induce value initialization with `int *pia = new int[10]();` which sets all to 0
    - size 0 arrays are fine `char *cp = new char[0]`, but cannot be dereferenced but won't throw too many errors (unlike illegal `char arr[0]`) 
- delete dynamically allocated array with `delete [] pa`
    - elements are destroyed in reverse order
- can manage them with `unique_ptr<int[]> up(new int[10]);`, which automatically calls `delete []` with `up.release()`
- can also manually specify `shared_ptr<int> sp(new int[10], [](int *p){ delete[] p; });`
- allocator:
    - limitations in new combining allocating/constructing, and delete combining destruction/deallocation
    - syntax: `allocator<string> alloc;`, then `auto const p = alloc.allocate(n);`
    - must `alloc.construct(q, "hi!")` before use, and `alloc.destroy(q)` afterwards, and then `alloc.deallocate(p, n)`
    - can copy/fill with `unitialized x {copy, fill} x {(b,e,b2), _n(b,n,t)}`


## 12.3 Using the Library: A Text-Query Program
- placement new = new (arguments=nothrow,...) int
- `new [n] T` allocates n objects of type T
- 