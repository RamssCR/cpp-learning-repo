# Pointers
A pointer is a memory address to a referenced variable.

```c++
auto health = 10;
auto* ptr = health&; // gets the memory address of `health`.
```

## Raw Pointers
In modern C++, raw pointers are commonly avoided for basic tasks, but
they are essential for these specific tasks:

### A. Dynamic Memory (The Heap)
When the amount of memory that will be used in a program is of unknown size.

```c++
Enemy* wave = new Enemy[numberOfMemories];
// using it...
delete[] wave;
```

### B. Linked Structures (Nodes)
When building a linked list/tree, each node needs a pointer to the next one.
Without them, it will try to contain itself, which is impossible.

### C. Polymorphism
A pointer to a base class can point to any derived class.

Say you have a `Shape*` pointer, it could actually be pointing to a `Circle`,
a `Square` or a `Triangle`. This allows to loop through a list of different
shapes and call `.draw()` on them.

## Smart Pointers (> C++ 11)
Since manual memory management can lead to memory leaks or crashes, modern C++
(C++ 11 or later) uses Smart Pointers.

- `std::unique_ptr`: For when one part of the code owns the object, it destroys itself after going out of scope.
- `std::shared_ptr`: For when multiple parts of the code need to point to the same object. It deletes the object when the last pointer is gone.