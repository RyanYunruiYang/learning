# Chapter 5: Statements
Started 1:00.

## 5.1 Simple Statements 
- expression + `;` = expression statement. this causes the expression to be evaluated and its result discarded.
- null statement = `;`
- you can put two semicolons, the second will just form a null statement
- a block is a scope. names introduced inside are accessible only in that block and blocks inside the block
- empty block of null statement

## 5.2 Statement Scope
- variables defined in the control structure are only visible there (for example values declared in for loop header)

## 5.3 Conditional Statements
- the "dangling else problem" (of more ifs than elses causing nonunique matchings) is solved by matching each `else` with the closest preceding unmatched `if`
- switch syntax:
```
switch (ch) {
    case 'a': 
        ++aCnt;
        break;
    case 'e':
        ++eCnt;
        break;
    ...
}
```
- expression input to swtich is always converted to integral type
- execution continues normally until break.
- `case 'a'` is called a "case label". they must be distinct, integral, and constant (cannot have `case 3.14` or `case ival`).
- default case exists too. syntax is `default: ` which is matched when no case label matches the value of the `switch` expression
```
// to count total number of vowels
switch (ch) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        ++vowelCnt;
        break;
}
```
- illegal to jump from a palce where a variable with an initializer is out of scope to a place where the variable is in scope
    - solved by defining a block for the declarations

## 5.4 Iterative Statements
- while
    - syntax: `while(condition) expression`
    - variables defined in condition or body are created and destroyed on each iteration
    - useful for keeping variables around
- for
    - syntax: `for (initializer; condition; expression) statement`
    - init is exeecuted once at the start of the loop
        - condition is evaluated
        - if condition is true, body executes
        - then expression is evaluated
    - can declare multiple variables in initializer all of same type
- for each
    - in below code, the value of end is cached, which is why we sait that we cannot use a range for to add elements to a vector
```
for (auto beg = v.begin(), end = v.end(); beg != end; ++beg) {
    auto &r = *beg;
    r *= 2;
}
```
- do while
    - syntax: `do {} while ();`
    - cannot define variables in condiion 
    - cannot define variables in body to be used in the condition
    - 

## 5.5 Jump Statements
- four jumps: `break`, `continue`, `goto`, and `return`
- break
    - terminates the nearest enclosing {while, do while, for, switch}. execution resumes at following statmeent. 
- continue
    - terminates current iteration of nearest enclosing {for, while, do while}. aka just skips this round
    - does not apply to switch
- goto 
    - syntax: `goto label;` where a label is `label: return;`
    - label identifiers are independent of variable names. can have collisions w/ no problem
    - forward jumps over declarations throw error
    - backwards jumps over definitions destroys the variable
- return (see page 222, 6.3)

## 5.6 `try` blocks and `Exception` handling
three components: throw, try blocks + catch clauses, exception classes
- throw
    - syntax: `throw runtime_error("Data must refer to same ...");`
    - throwing an exception terminates current function and transfers control to a handler
    - runtime_error from stdexcept header is common
- try block
    - `catch (runtime_error err)` 
    - each library exception class defines a member function named `what`, returns a copy of the `string` used to initialize the particular object
    - search for handler: keep breaking functions until matching match is found. if none are found, execution is transferred to the library function `terminate`
        - matches by type. first exact, then base, then default `catch (...)`. 
    - programs that properly clean up during exception handling are called "exception safe" (this is hard!)
```
try {

}
catch (exception-declaration-1) {
    handler-statements-1
}
catch (exception-declaration-2) {
    handler-statements-2
}
```
- standard exceptions
    - exception. only that exception occurred.
    - stdexcept header defines:
        - `std::exception`
            - `std::runtime_error`: range_error, overflow_error, underflow_error
            - `std::logic_error`: domain_error, invalid_argument, length_error, out_of_range
    - new header defines: `bad_alloc`
    - type_info header defines: `bad_cast`
    - can only create/copy/assign objects
    - can only default initialize base exception/bad_alloc/bad_cast. others can only be initialized from string or C-style string

## Summary
- compound statement = block
- exception handler = catch clause
- throwing exception = raising exception