# Chapter 17: Specialized Library Facilities
## 17.1: The `tuple` type
- the tuple constructor is explicit, so you cannot do `tuple<size_t, size_t, size_t> threeD = {1,2,3}`
    - if you want to do copy initialization you have to do `auto item = make_tuple(1,2,3);`
- use `.get<i>(t)` to access `i`th data member
- common use case for tuples is to return multiple values from a function

## 17.2: The `bitset` type
- syntax: `bitset<32> bitvec(1U);`
    - size must be specified with a constexpr (32 is a literal which is a constexpr)
    - low order vs. high order bits
```
bitset<13> bitvec1(0xbeef); // bits are truncated to 1_1110_1110_1111
bitset<20> bitvec2(0xbeef); // bits are padded to 0000_1011_1110_1110_1111
bitset<128> bitvec3(~0ULL) // bits 0 to 63 are 0, 63 to 127 are one.
```
- when we initialize from string, characters with lowest indicies in the string correspond to higher-order bits.
- bitset operations
    - b.any(), b.all(), b.none(), b.count()
    - b.size()
    - b.test(pos), b.set(pos, v), b.set(), b.reset(pos), b.reset(), b.flip(pos), b.flip(), b[pos]
    - b.to_ulong(), b.to_ullong(), b.to_string(zero, one)
    - os << b, is >> b

## 17.3: Regular Expressions (17)
- everything is under the `<regex>` header
- components: class (regex), functions  (regex_match, regex_search, regex_replace), string (sregex_iterator, smatch, ssub_match)
- regex_match: returns true if the entire input sequence matches
- regex_serach: returns true if there is substring that matches
- the default language is ECMAScript
    - can also specify regex::basic, extended, awk, grep, egrep (all POSIX)
- `*` means 0 or more, `+` means 1 or more
- to find cpp files, do `regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase)` which ignores case, allows for 1+ alnum characters, escapes a `\\. = .`, checks for one of three types, and ignores case
- regularexpressions are compiled at runtime
- regex class holds char, wregex holds wchar_t
- increment a `sregex_iterator it; ++it;` calls `regex_search`
- parentheses denote a `(subexpression)`
    - results.str(0) will hold the entire name, but for i>= 1 you can get the ith subexpression with `results.str(i)`
- in ECMAscript
    - `\{d}` represents a single digit and `\{d}{n}` is n digits
    - collection of characters in `[-. ]` match to any -- here a dash,dot, or space
    - ? after a component means it's optional

## 17.4: Random Numbers (7)
- old c++ used the C library "rand" which gave a pseudorandom integer in [0, max=2^15-1]
- new c++: `<random>` header
    - random-number engines: random unsigned integers
    - random-number distribution classes: use engine to return numbers according to particular probability distribution
```
default_random_engine e;
for (size_t i = 0; i< 10; ++i>) {
    std::cout << e() " ";
}
```
- engine types and distribution types are function-object classes
    - always pass engine object itself to the distribution object
- Problem/Feature: engine will return same value it runs each time
    - thus, one should always make the engine and distributions static
- to get distribution on unit interval [0,1], do not just take default_random_engine and divide by RAND_MAX
    - instead `uniform_real_distribution<double> u(0,1);` works better
    - if you don't put a type, the default for `uniform_real_distribution<>` is double (and int for uniform_int_distribution)

## 17.5: The IO Library Revisited (15)
- IO objects have format state
    - (1) controlling the presentation of numeric values    
    - (2) controlling the amount and placement of padding
- things to do
    - integer
        - boolalpha: displays bools (undo with noboolalpha)
        - oct, hex, dec change how integral values are displayed
        - showbase adds {0x,0} as prefix for decimal/oct
        - uppercase turns hex a-f to A-F
    - floating-point
        - by default, floating-point values are printed with 6 digits of precision
        - `cout.precision()`, `cout.precision(12)` are functions, `setprecision(3)` manipulator
        - defaultfloat/scientific/fixed/hexfloat
        - showpoint/noshowpoint
        - padding
            - setw, left, right, internal setfill
    - input
        - noskipws: doesn't skip ws
        - can do single-byte operations `while(cin.get(ch)) { cout.put(ch); }`
        - can `peek` (look without mutating state), `unget` to put value back, `putback` to put back
        - `.get()` returns int (promoted from unsigned) char except for EOF, EOF is negative.
        ```
        int ch;
        while ((ch=cin.get()) != EOF) cout.put(ch);
        ```
        - `is.get(sink,size,delim)` reads until size bytes; it leaves the delimeter as the next character, where `getline(sink, size, delim)` reads and discards. can also do `is.read(sink, size)` to directly read into sink.
        - `is.gcount()` returns number of bytes read in last unformatted read operation (useful following `getline` for example)
        - `os.write()` writes size bytes from character array source to os. `is.ignore()` ignores `size` characters
        - Caution: DONT USE LOW LEVEL ROUTINES
            - example: `(ch=cin.get()) != EOF` will break only when the character is `\377` and not on EOF
- seek and tell functions: only use on fstream and sstream types (not istream/ostream!!)
    - output: tellp returns marker of output stream. p = putting, g getting
    - seekp(pos), seekp(off, from) reposition the marker
    - Note: There is only one marker. Because there is only a single marker, we must do a seek to reposition the marker whenever we switch between reading and writing.
```
// use case:
ostringstream writeStr;
ostringstream::pos_type mark = writeStr.tellp();

if (cancelEntry) {
    writeStr.seekp(mark);
}
```

## Summary
- tuple: bundle together, make_tuple, `get<i>`
- bitset: collections of bits. easy translation from string, and easy bit operations. 
- regular expressions. hard. C++ uses ECMAScript by default. {regex_search, regex_match}, take {regex object, character sequence} and detect matching subsequences. can iterate with regex_search. regex_replace lets us automatically replace.
    - cmatch = info on match with `const char*`, cregex_iterator, csub_match,
- random numbers: RNG paradigm = engine (uniform int) + distribution class (gaussian, bernoulli, poisson, etc). same seed each time, need to use chronos, and engine should be static.
- IO
    - formatted IO: using types of objects to do operations. nice padding for columns!
    - unformatted IO: byte-by-byte.
    - manipulators: lots