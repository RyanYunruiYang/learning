# Chapter 11: Associative Containers

## 11.1 Using an Associative Container
- {set/map} x {unique or dup key} x {order vs. not} = {map, set, multimap, multiset, unordered_map, unordered_set, unordered_multimap, unordered_multiset}
- headers: map, set, unordered_map, unordered_set
- `map`s are lists of `pair`s 

## 11.2 Overview of the Associative Containers
- syntax: `map<string, string> authors = {{"Joyce", "James}, {"Austin", "Jane"}, {"Dickens", "Charles"}}`
- ordered containers need keys to be comparable
    - < must be "strict weak ordering"
    - can pass in special comparison. syntax: `multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn)`
- utility header: `pair` type
    - holds two data members with syntax `pair<string, size_t>`
    - comparing pairs compare .first values first then .second

## 11.3 Operations on Associative Container
- can access `::key_type, ::value_type, ::mapped_type`
- can only change `auto map_it = word_count.begin()`'s second value through `map_it->second`
- generally, generic algorithms are not worth using for associative containers
- insertion:
```
set2.insert({1,3,5,7});
set2.insert(ivec.cbegin(), ivec.cend());

word_count.insert({word, 1});
word_count.insert(make_pair(word, 1));
word_count.insert(pair<string, size_t>(word, 1));
word_count.insert(map<string,size_t>::value_type(word,1));
```
- operations: insert (returns `pair<iterator, bool>`) + emplace
- operations: `c.erase(k)`, `c.erase(p)`, `c.erase(b,e)`
- operations: `c[k]` vs. `c.at(k)`
    - doing `[k]` creates a new element, so to check if it exists you should consider `.find == .end()`
- within multiset, all values with same key are adjacent. for this reason, can check `.count()` after `.find()`
- `.lower_bound(k)` `.upper_bound(k)` create a range on where the keys with value k are
- can run through and print all values with key k with:
```
for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound (search_item);
        beg != end; ++beg)

for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
```
## 11.4 The Unordered Containers
- ordered associative containers are balanced binary serach trees (red-black or AVL). find is O(log n) binary search. unordered sets use hash tables. 
- bucket interface:
    - `.bucket_count()` = current # of buckets in use
    - `.max_bucket_count()` = largest number of buckets possible
    - `.bucket_size(n)` = number of elements in bucket `n`
    - `.bucket(k)` which bucket would key k go to
- local_iterator, begin/end, cbegin/cend to traverse elements within bucket
- can read load_factor with `c.load_factor()` and set it with `c.max_load_factor()`. will reorganize when you call `c.rehash(n)` with n buckets. 

```
size_t hasher(const Sales_data &sd) { return hash<string>()(sd.isbn());}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn()==rhs.isbn(); }

using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>
SD_multiset bookstore(42, hasher, eqOp)
```

## Summary
- pair has two public data members: first, second
- strict weak ordering: reflexivity, transitivity of both < and ~
- types:  value_type, key_type, mapped_type
- [] yields a mapped_type value
- * yields a value_type value