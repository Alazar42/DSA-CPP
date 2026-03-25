# DSA in C++ (Learning Gift for Beginners)

A beginner-friendly Data Structures and Algorithms project in modern C++.

This repository is meant as a learning gift for people starting with DSA fundamentals and wanting simple, readable implementations they can run.

## Why This Project

- Learn core DSA concepts by reading real code
- Practice building and running C++ with CMake
- Extend each data structure and algorithm step-by-step
- Use this as a base for interview prep and problem solving

## Tech Stack

- Language: C++17
- Build System: CMake
- Current executable target: DSA

## How To Run Any Module

This project currently builds one source file at a time.

To switch what runs:

1. Open [CMakeLists.txt](CMakeLists.txt)
2. Find the executable line
   add_executable(DSA src/matrix.cpp)
3. Replace [src/matrix.cpp](src/matrix.cpp) with the source file you want to run
4. Rebuild

Examples:
- add_executable(DSA src/stack.cpp)
- add_executable(DSA src/queue.cpp)
- add_executable(DSA src/tree.cpp)

## Current Project Structure

- [CMakeLists.txt](CMakeLists.txt)
- [include/linked_list.hpp](include/linked_list.hpp)
- [include/stack.hpp](include/stack.hpp)
- [include/queue.hpp](include/queue.hpp)
- [include/tree.hpp](include/tree.hpp)
- [include/graph.hpp](include/graph.hpp)
- [include/matrix.hpp](include/matrix.hpp)
- [src/linked_list.cpp](src/linked_list.cpp)
- [src/stack.cpp](src/stack.cpp)
- [src/queue.cpp](src/queue.cpp)
- [src/tree.cpp](src/tree.cpp)
- [src/graph.cpp](src/graph.cpp)
- [src/matrix.cpp](src/matrix.cpp)
- [src/array.cpp](src/array.cpp)

## Quick Start (Windows)

Requirements:
- CMake 3.10+
- A C++17-compatible compiler

Build and run:

1. Configure
   cmake -S . -B build

2. Build
   cmake --build build

3. Run
   build/DSA.exe

## What You Can Learn Here

- Arrays
- Linked List
- Stack
- Queue
- Tree
- Graph
- Matrix

## Current Development Status

- Arrays: available
- Linked List: available
- Stack: available
- Queue: available
- Tree: available
- Graph: in progress (still being worked on)
- Matrix: in progress (more features being added for easier understanding)

## Matrix Notes

The Matrix implementation uses a flat 1D data layout for memory locality and simpler index math.

Current highlights:
- Transpose
- Determinant using LU decomposition with partial pivoting
- Inverse using LU decomposition and forward/back substitution

## For Beginners

Start small:

1. Pick one module in include and src
2. Trace each function with a tiny input
3. Print intermediate states to understand behavior
4. Change one thing and rerun
5. Repeat until the implementation feels natural

Learning DSA is about consistency, not speed. Keep building.
