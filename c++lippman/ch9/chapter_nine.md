# Chapter 9: Sequential Containers
## 9.1 Overview of the Sequential Containers
- we'll cover associative containers in Chapter 11
- container = collection of objects of specified type. **sequential** containers are ordered based on programmer control (in contrast to **associative** containers which are based on value/key)
- sequential containers
    - vector
    - deque
    - list
    - forward_list
    - array
    - string
- string/vector hold elements in contiguous memory. makes it hard to edit middle
- list/forward_list are designed to make it fast to add/remove element from anywhere. high memory overhead.
## 9.2 Container Library Overview
- default containers have:
    - some type aliases: iterator, const_iterator, size_type, difference_type, value_type, reference, const_reference
    - constructors
    - assignment/swap
    - size .size()
    - add/remove
- lots of versions of begin: .begin(), .rbegin(), .cbegin(), .crbegin()
- when we initialize a container as a copy of another container, both container type and element type must match.
- can also list initialize `list<string> authors = {"Milton", "Shakespeare", "Austin"};`
- can initialize with two arguments `vector<int> ivec(10,-1);`
- arrays have size as part of type, ex: `array<string, 10>`
- assignment operations
    - c1 = c2. replaces elements in c1 with copies of elements in c2
    - c = {a,b,c,...}
    - swap(c1,c2) swaps the two. much faster than copying (only pointers change)!
    - seq.assign()
- swap does a high level swap without actual modifying elements, except for `arrays`

## 9.3 Sequential Container Operations
- operation support:
    - push_back: all except array and forward_list
    - push_front: list, forward_list, deque
    - insert: vector, deque, list, string
- emplace_front,emplace,emplace_Back construct rather than copy elements
    - overdramatic stack exchange answer: if you want to add a copy of an existing instance of the class to the container, use push. If you want to create a new instance of the class, from scratch, use emplace.
- access operations:
    - .back(), .front(), [n], .at(n)
    - if you do `auto &v = c.back()` you get a reference, if you do `auto v = cback()` you get a copy
- erase:
    - pop_back(), pop_front(). both return void
    - c.erase(p) erases iterator p, c.erase(b,e) erases range
    - c.clear() erases all
- forward_list: insert_after, emplace_after, erase_after
- resize: `c.resize(n)` default initializes at the end to make it bigger, or discards after the end to make it smaller. `c.resize(n,t)` changes the default initialization to `t`
- Advice: minimize time that iterators (reference or pointer) needs to stay valid for.
- do not cache `.end()` values in `deque`, `string`, or `vector`

## 9.4 How a `vector` grows
- each time vector is recopied, it allocates more than what is immediately needed (there's an amortization analysis of this in CLRS or MIT Class 6.1220)
    - for my compiler, to double capacity each time `64 -> 128 -> 256`
    - in practice, vector grows more efficiently than list or deque
- a call to reserve can only increase the capacity
- `c.shrink_fo_fit()` will cause `deque,vector,string` to return unneeded memory
- `c.capacity()` is number of elements before allocation is necessary
- `c.reserve(n)` allocates space for at least n elements
- capacity + size = allocation

## 9.5 Additional `string` operations
- string has additional operations that support C-style character arrays or use indices
- constructors: `string s(cp, n)` copies first n from array at `cp`. `string s(s2, pos2)` copy of characters from s2 starting from index pos2. `string s(s2, pos2, len2)` copies from `pos2` to at most `pos2 + len2`
- `s2.append("abc")` is equivalent to `s.insert(s.size(), "abc")`
- lots of functions
    - search: `.find()`
    - compare: `.compare`
    - conversions: `.stoi(s,p,b)` and `.stod()` parse as int and double

## 9.6 Container Adaptors
- the library also defines three sequential container **adaptors**
- container adaptor functions
     - size_type: type large enough to hold the size of the largest object of this type
     - value_type, container_type
     - declarations `A a;` or `A a(c)`
     - relational operators (==) , .empty(), .size(), .swap()
- `stack` and `queue` are implementd in terms of `deque`, and `priority_queue` is implemented on a vector
    - can override this with `stack<string, vector<string>> str_stk;`
    - cannot use array or forward_list
- stack
    - requires push_back, pop_back, and back. can use list/deque/vector
    - operations: push, pop, top
- queue (FIFO)
    - requires {back, push_back} + {front, push_front} which can build on either list or deque
    - operations: {front/back} + {pop, push/emplace}
- priority queue
    - requires random access + {front, push_back, pop_back}, can be built on deque or vector
    - operations: {top} + {pop, push/emplace}
