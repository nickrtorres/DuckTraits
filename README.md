## DuckTraits — a poor approximation of Rust's trait bounds in C++

### Building
The good
```
% make
c++ -std=c++11 -c -D GOOD main.cpp -o main.o
c++ -std=c++11 -D GOOD main.o -o main
% ./main
Quack
Robotic quack
```

The bad
```
% make clean && make CXXFLAGS='-D BAD'
c++ -std=c++11 -c -D BAD main.cpp -o main.o
In file included from main.cpp:2:
./Duck.h:45:2: error: static_assert failed due to requirement 'DuckTraits::Quacks<NotDuck>::value' "Must be able to quack!"
        static_assert(DuckTraits::Quacks<T>::value, "Must be able to quack!");
        ^             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
main.cpp:14:11: note: in instantiation of function template specialization 'DuckOps::DoQuack<NotDuck>' requested here
        DuckOps::DoQuack(nd);
                 ^
1 error generated.
make: *** [main.o] Error 1
```
