Callbacks in C++
================

Overview
--------

The examples in this repository show how callbacks can be implemented in C++.
A C++11 capable compiler is required, such as `GCC` or `Clang`.

The first example shows how `std::function` can be used as a callback. This is
a common approach that is simple and works in many cases.

The second example shows how `std::function` callbacks can be stored in a
collection (an `std::vector` in this case).

The third example shows how to create overloaded wrapper functions to invoke
different types of callbacks.

The fourth example shows how different types of callbacks (i.e. callbacks with
different types of arguments) can be stored in a single collection (a
`std::map` in this case).

Please see the implementation in the respective files. You may use the example
code freely in your code.

Compilation
-----------

Each example file is a self contained C++ program with a `main()` function. The
following command can be used to compile and run the examples. The command is for
the first example and the `Clang` compiler.

~~~
clang++ -std=c++11 -o callback1 callback1.cc
./callback1
~~~
