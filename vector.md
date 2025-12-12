# Vector in C++
A vector is a list that stores a contiguous set of values.

In C++, a vector (on a x64 bit architecture) contains 3 objects:
- A pointer to the data (`T`, 8 bytes).
- Size of `size_t` representing the amount of items (8 bytes).
- Capacity of `size_t` representing the reserved space (8 bytes).

### In this example

```c++
std::vector numbers{1, 2, 3, 4, 5};
for (const auto* number : numbers) {
    std::cout << i << "\n";
}
```

- `numbers` contain a set of integers stored on heap, looking something
like this: `[1][2][3][4][5]`.
- `const auto* number` is a pointer to each value stored on the vector,
allowing you not to pass a copied value to the stack and use the ones stored
on the vector (heap-located).

## Copy vs. Movement
### Copy
```c++
std::vector numbers{1, 2, 3};
std::vector copied_numbers = numbers; // copies the entire heap
```

### Movement
```c++
std::vector numbers{1, 2, 3};
std::vector moved_numbers = std::move(numbers); // moves the pointer (cheaper)
```

## Lambdas
They are (supposed to be) shorthands for functions, their syntax is shown as
follows:
```c++
const auto substraction = [](int a, int b) {
    return a - b;
};
```

- When the capture list is empty (`[]`), the lambda lives in the stack, allowing
the compiler to optimize it since it's treated as a small object.
- The parameters live on the stack during function instantiation.

## `std::cout`
`std::cout` lives globally in the DATA/BSS space, not stack or heap.