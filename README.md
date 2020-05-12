## DuckTraits — a poor approximation of Rust's trait bounds in C++

### Building
The good
```
% make
% ./main
```

The bad
```
% make clean && make CXXFLAGS='-D BAD'
```
