# Chapter 8: The IO Library
## 8.1 The IO Classes
- Types
    - Header: iostream (io), fstream (file), sstream (string)
    - i+header = read, o+header=write, io+header = read/write
    - w+prev = wide characters for `wchar_t`
- the f and string versions inherit from the stream version
- you cannot assign (out1 = out2), initialize (ofstream print(ofstream1)) or copy (out2 = print(out2))
    - instead pass with nonconst references
- iostate has values:
    - badbit: system-level failure. permanently dead.
    - failbit: recoverable. ex: reading character when numeric expected
    - eofbit: hit end of file
    - goodbit: always 0
    - can call these with s.bad(), s.fail(), s. eof(), s.good().
    - can also s.clear()

- buffer will be flushed when: (1) return from main, (2) buffer full, (3) manipulators, (4) unit buf, (5) action from tied stream
    - note: this is why usaco writeups always do `cin.tie(0)->sync_with_stdio(0);` which should really be written as `cin.tie(nullptr)->sync_with_stdio(false);`
- `endl` writes newline + flush, `flush` just flushes, `ends` writes null + flush
- can set stream to auto flush with `cout << unitbuf;` and turn it off with `cout << nounitbuf`

## 8.2 File Input and Output
- can use object of inherited type in places where object of original type expected. that means we can pass in `fstream` wherever `iostream` was expected
- can open and close files. open is called upon init by default
- when an fstream object is destroyed, `close` is called automatically
- file modes: in, out, app (append), ate, trunc (truncate), binary
    - need to specify `app` or else original contents of ofstream target file are discarded

## 8.3 `string` streams
- istringstream read, ostringstream writes, stringstream reads and writes
- `.str()` converts ostringstream to `string`. this is the killer app

## Summary
- both fstream and stringstream inherit from iostream