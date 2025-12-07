#include <iostream>
#include <vector>

int main() {
    std::vector numbers{1, 2, 3, 4, 5};

    for (const auto& number : numbers) {
        std::cout << number << std::endl;
    }

    auto add = [](int a, int b) {
        return a + b;
    };

    std::cout << "My addition result is: " << add(3, 4) << std::endl;

    return 0;
}
