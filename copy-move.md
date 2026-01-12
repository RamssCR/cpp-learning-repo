# Copy/Move
When creating a resource using `class` that contains
more than just a constructor, one must define its rules and
implementations.

In other languages, a `class` is usually seen as an object with
properties and methods that their respective Garbage Collector
is responsible for destroying after its usage.

In C++ though, one must handle its destruction manually, since
such Garbage Collector does not exist here.

## Rule of 3 (Ro3)
Given a `Buffer` class responsible for the resource's creation
and destruction. A common misused implementation is defining its
constructor and destructor only.

```c++
class Buffer {
public:
    Buffer(const size_t size) : size_(size_t), data(new int[size]) {}

    ~Buffer() { delete data_; }
private:
    size_t size_;
    int* data_;
};
```

### What happens here?
When instantiating the `Buffer` class and attempting to copy it...

```c++
Buffer buffer(10);
Buffer copy = buffer;
```

- Both objects point to the same block.
- Upon destruction, both objects will double call the same destructor.
- Meaning Undefined Behavior.

In order to properly copy a class with destructor is by defining both a
copy constructor and copy assignment, followed by the Rule of 3.

> If an object defines a destructor, it possibly needs a copy constructor
> and copy assignment as well.

```c++
class Buffer {
public:
    Buffer(const size_t size) : size_(size_t), data(new int[size]) {}

    Buffer(Buffer& other) : size_(other.size), data(new int[other.data]) {
        std::copy(other.data, other.data + other.size, _data);
    }
    
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;
        
        delete[] data_;
        size_ = other.size;
        data_ = other.data;
        
        std::copy(other.data_, other.data + _size, _data);
        return *this;
    }
    
    ~Buffer() { delete data_; }
private:
    size_t size_;
    int* data_;
};
```

Now, when copying again, both objects will be independent resources,
both having their own constructors and destructors.

## Rule of 5 (Ro5)
Copying resources oftentimes is expensive or not a good decision, due to
the resource sometimes needing its own authenticity. Meaning? Instead of copying
the entire resource, we move its pointer to another instance by using a move
constructor and move assignment, that's why a rule implemented in consequence is
the rule of 5.

> If the rule of 3 is implemented upon a resource, it also possibly needs a
> move constructor and a move assignment.

```c++
class Buffer {
public:
    Buffer(const size_t size) : size_(size_t), data(new int[size]) {}

    Buffer(const Buffer& other) : size_(other.size), data(new int[other.data]) {
        std::copy(other.data, other.data + other.size, _data);
    }
    
    Buffer(Buffer&& other) noexcept : size(other.size), data_(other.data) {
        other.size = 0;
        other.data = nullptr;
    }
    
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;
        
        delete[] data_;
        size_ = other.size;
        data_ = other.data;
        
        std::copy(other.data_, other.data + _size, _data);
        return *this;
    }
    
    Buffer& operator=(Buffer&& other) noexcept {
        if (this == &other) return *this;
        
        delete[] data_
        data_ = other.data;
        size_ = other.size;
        
        other.data = nullptr;
        other.size = 0;
        
        return *this;
    }
    
    ~Buffer() { delete data_; }
private:
    size_t size_;
    int* data_;
};
```

By doing this:
```c++
Buffer buffer(10);
Buffer moved = std::move(buffer);
```

The first instance is successfully emptied and all its resources moved intact
to the new instance.

## Rule of 0 (Ro0)
The vast majority of times, you normally handle resources whose owner is not
exactly you, oftentimes borrowed - Like memory, to give an example. That where
the rule of zero comes in and says:

> If the resource is not yours, neither a destructor nor copy/move integrations
> must be implemented, since there is already another owner who already handles
> those rules for you.

Rule of Zero relies purely on the Standard Template Library (STD) and the C++'s
RAII dogma (Resource Acquisition is Initialization).

```c++
class Buffer {
    std::unique_ptr<int[]> data_;
};
```

Here:
- `Buffer` already counts with its own destructor, copy and move integrations.
- `Buffer` is destroyed once the scoped it was instantiated reaches its end.
- `std::unique_ptr<T>` handles its lifecycle properly.