# Data Types in C++ (version 20)
From version 20 on, C++ has better ways to initialize variables.
This is helpful for better data recognition from the compiler.

## Brace Initialization
Variables are declared using brace symbols and avoids conversion
errors.
```c++
int age{20};
bool isActive{true};
```

## `auto` declared variables
Similar to `var` in C#, `auto` allows C++ compiler to deduce the type
of value passed by the developer.

```c++
auto year = 2025; // int
auto price = 490.99; // double
auto email = std::string{"example@example.com"}; // char*
```

It also recognizes pointers (references).
```c++
auto& ref = year;
const auto& cref = year;
```

## `if` conditional
C++ supports the classic `if-else` conditional statement.
```c++
auto temperature = 30;

if (temperature < 30) {
    std::cout << "It's cold" << std::endl;
} else {
    std:cout << "It's hot" << std::endl;
}
```

## Modern loops in C++
```c++
std::vector<int> numbers{1, 2, 3, 4, 5};
for (const auto& i : numbers) {
    std::cout << "i = " << i << std:endl;
}
```

## Modern functions in C++
```c++
int add(int a, int b) {
    return a + b;
}

int result = add(5, 10);
```

## Lambdas in C++
```c++
auto multiply = [](int a, int b) {
    return a * b;
};

int result = multiply(5, 10);
```

