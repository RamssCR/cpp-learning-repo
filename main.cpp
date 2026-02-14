#include <format>
#include <iostream>
#include <memory>

class Node {
public:
    explicit Node(const int data) : data_(data) {}

    void set_node(const std::shared_ptr<Node>& node) { next_ = node; }

    void print() const {
        if (const auto next_node = next_.lock())
            std::cout << std::format("{}->{}\n", data_, next_node->data_);
        else
            throw std::runtime_error("Next node is gone or was never set");
    }

private:
    std::weak_ptr<Node> next_;
    int data_;
};

int main() {
    const auto node = std::make_shared<Node>(1);
    {
        const auto node2 = std::make_shared<Node>(2);
        node->set_node(node2);
        node->print();
    }

    try {
        node->print();
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}
