# Chapter 10: Generic Algorithms
Started 5:05.

## 10.1 Overview
- mostly found in the `algorithm` header and some numerics in `numeric`
- 1: `find(vec.cbegin(), vec.cend(), val)`
    - searches for the value using iterators. returns iterator if found, or the end if not
- iterators make algorithms container independent, but not element-type independent
- Concept: Generic Algorithms never change the size of the underlying container, and most mutate values of elements stored in the container.

## 10.2 A First Look at the Algorithms
- algorithms that take input range always use their first two parameters to denote that range
- read only algorithms
    - examples: find, count, accumulate (takes sum/concatenation), equal (bug in equal is that it asumes equal size)
    - should use `.cbegin(), .cend()`
- algorithms that write
    - examples: fill, fill_n, back_inserter, copy, replace
    - insert iterator: iterator that adds elements
    - `fill_n(back_inserter(vec), 10, 0)` will do the equivalent of pushbacks
- reordering: sort, unique

## 10.3 Customizing Operations
- predicate = expression that can be called and return a value. either unary or binary
    - ex: `sort(words.begin(), words.end(), isShorter)` passes the predicate isShorter as our custom comparator
- stable_sort = maintain alphabetical order among those elements that have the same length
- find_if: finds an element between iterators which satisfies a predicate
- lamdba expressions = unnamed inlined function
    - syntax: `[capture list](parameter list) -> return type {function body}`
    - example: `stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size();});`
    - example: `find_if(words.begin(), words.end(), [sz](const string &a){ return a.size() >=sz;})`
- for each (begin, end, f) calls f(x) for each x in [begin, end)
- capture list only neeeded for local nonstatic variables
- the value of a captured valid is copied when the lambda is created, not when it is called
- implicit captures with `[=]` and `[&]`
- bind exists.
    - syntax: `auto g = bind(f,a,b,_2,c,_1)` turns calls to `g(X,Y)` into calls to `f(a,b,Y,c,X)`

## 10.4 Revising Iterators
- special iterators: insert, sream, reerse, move
    - back_inserter (push_back), front_inserter (push_front), inserter (insert)
- istream _iterators
    - default gives eof
```
istream_iterator<int> in_iter(cin);
istream_iterator<int> eof;
while (in_iter != eof) {
    vec.push_back(*in_iter++);
}

// is equivalent to
istream_iterator<int> in_iter(cin), eof;
vector<int> vec(in_iter, eof);
```
- two liner addition of standard input values:
```
istream_iterator<int> in(cin), eof;
cout  << accumulate(in, eof, 0) << endl;
```
- can write values separated by spaces
```
ostream_iterator<int> out_iter(cout, " ");
for (auto e : vec)
    *out_iter++ = e;
cout << endl
```
- can also print by calling `copy(vec.begin(), vec.end(), out_iter);`
- reverse iterators
    - inverts meaning of increment and decrement
    - exists everywhere except for forward_list. we get these by calling rbegin, rend, cbegin, and crend
    - lets us sort backwards: `sort(vec.rbegin(), vec.rend());`
    - can call `rcomma.base()` to get the normal version of a reverse iterator

## 10.5 Structure of Generic Algorithms
- requirements
    - find: access, increment, compare
    - sort: read, write, random access
- five categories:
    - input iterator: read + single-pass
    - output iterator: write + single-pass
    - forward iterator: r/w + multipass increment only
    - bidirectional iterator: r/w + multipass full
    - random-access iterator: r/w + multi-pass + full iterator arithmetic
- patterns: most have form:
    - alg(beg, end, other args)
    - alg(beg, end, dest, other args)
    - alg(beg, end, beg2, other args)
    - alg(beg, end, beg2, end2)

## 10.6 Container-Specific Algorithms
- list: sort, merge, remove, reverse, unique, splice

## Summary
- ~100 type-independent algorithms that operate on sequences
- ref(), cref() create an object that contains a reference