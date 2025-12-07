# Storage
## Stack
Stack (LIFO) stores static data values.

- It's fast.
- Data's lifecycle is scope-tied.
- Its size is around 1 to 8MB.
- Automatic memory.
- It manages itself.

## Heap
Heap stores data values that depend on a referential identity.

- It's slower (due to manual memory allocation/deallocation and other factors).
- Dynamic memory.
- Its lifecycle ends when someone frees it.
- Bigger than stack.

### How to create a heap-allocated primitive pointer
```c++
// Old style (Not recommended)
int* pointer = new int(10);
// delete pointer;
```
```c++
// Modern style
auto pointer = std::make_unique<int>(10);
```
## When to use one or another
| Case                     | Stack                        | Heap |
|--------------------------|------------------------------|------|
| Local variables          | ✅                            | ❌    |
| `std::vector object`     | ✅                            | ❌    |
| Internal vector data     | ❌                            | ✅    |
| Lambdas (w/out captures) | ✅                            | ❌    |
| Lambdas (w/ captures)    | ✅ (depends on optimizations) | ✅    |