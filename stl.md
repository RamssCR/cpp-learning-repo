# Standard Template Library
> A set of data structures, algorithms and objects ready to use that come with C++.

## What does the STL contain
### Containers
- `std::vector` - List.
- `std::array` - Fixed array.
- `std::list` - double linked list.
- `std::deque` - double queue.
- `std::map` - ordered dictionary.
- `std::unordered_map` - hash map.
- `std::set` - set.

They all live on the heap.

### Algorithms
STL does not force you to create loops by-hand.
```c++
#include <algorithm>

std::sort(vector.begin(), vector.end());
std::find(vector.begin(), vector.end(), 10);
```
It's like LINQ but at a lower level.

### Iterators
They're the "glue" between containers and algorithms.

```c++
vector.begin()
vector.end()
```

They're objects that point to positions within a container.

### Utilities
Util objects that aren't containers.

- `std::optional`
- `std::variant`
- `std::pair`
- `std::tuple`
- `std::chrono`
- `std::filesystem`

## Why is it important

- It's natively optimized.
- It's portable.
- It follows standards.
- It avoids bugs from reinventing the wheel.
- It's used in real industry.