#include <iostream>
#include <vector>

int main() {
    int x{5};
    int y{10};

    int& r{x};
    int* p{&x};

    p = &y;
    *p = 30;

    r = 30;
}
