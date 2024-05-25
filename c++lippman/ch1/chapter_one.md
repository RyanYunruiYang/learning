# Chapter 1: Getting Started
Preface: 10:41 - 10:48

## Section 1.1 (first)
Started 10:49, Finished 11:02

```
int main() {
    return 0;
}
```
Question: What happens if you write a piece of code with `bool main()`? \
Answer: error: 'main' must return 'int'

- valued returned from main() is status indicator. 0 means success 
- suffixes include: .cc, .cxx, .cpp, .cp, and .C
- `./a.out` is used to signify that the file is in the current directory
- doing `echo $?` returns the result of `main()`! it also seems to be a uint_8 (-1 wrapped around to 255)
- if you don't compile with a -o flag like `g++ -o executable_name file_name.cpp`, then it by default goes to `a.out`

## Section 1.2 (i/o)
Started 11:02, finished 11:21
- iostream library. two main types are `istream` and `ostream`
- `cin` is object of type `istream`
- `cout, cerr, clog` are objects of type `ostream` 
- `g++` is better at linking standard libraries than `gcc`
- in `#include <iostream>`, iostream is a "header" (include cannot appear inside a function)
- The operand `ostreamobject << string` returns the original ostream object. Thus, `std::cout << a << b;` is equivalent to `(std::cout << a) << b;`.
- strings, characters enclosed with double quotation marks, are called "string literals." The `endl` value is called a "manipulator" (manipulates stream itself) and flushes the buffer associated with that device and is actually written. (N.B.: when a program crashes, the output will be stuck in the buffer)
- prefix `std::` means that the names are defined inside the "namespace" named std. `::` is called the scope operator
- similar to ostream, `istream object >> x` reads data from the istream object and saves it in `x` and returns the istream object

## Section 1.3 (comments)
Started 11:22, Ended 11:31.
- two types of comments. `//` and:
```
/*
 * This is a 
 * multiline comment.
 */
```

## Section 1.4 (flow of control)
Started 11:31, Ended 12:00. Started again 1:46
- block is zero or more statements inside of { } (kinda like latex!)
- Question: what is the difference between `++val` and `val++`
- for loops = init-statement + condition + expression 
- an `istream` in a condition returns valid if it hasn't encountered an error, and becomes invalid when we hit end-of-file or an invalid input
- on mac, end-of-file is ctrl+D!

## Section 1.5 (classes intro)
started 1:57, ended 2:12
- data structure = class
- class = name + where defined + what operations it supports
- header files have a suffice of .h, .H, .hpp, or .hxx
- headers from standard library get the brackets `<>`, while all others use double quotes `" "`
- you can run directly with `./executable_name<input_file>output_file`
- `item.isbn()` calls a member function named isbn (also referred to as methods)
- dot operator `.` is only used on classes. `()` operator is called call operator.

# Section 1.6 (book store program)
NA

# Defined Terms
ended 2:19.
- argument, assignment
- block ({statements inside brackets}), buffer (region of storage used to hold data. reading `cin` flushes `cout`)
- built-in type
- namespaces
- character string literal = string literal
