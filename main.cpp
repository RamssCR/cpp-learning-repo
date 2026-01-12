#include <string>
#include <sstream>
#include <memory>
#include <algorithm>
#include <iostream>
#include <unordered_map>

struct Task {
    explicit Task(const size_t id, std::string title)
        : id_(id), title_(std::move(title)), is_completed_(false) {}

    [[nodiscard]] size_t id() const { return id_; }

    [[nodiscard]] const std::string& title() const { return title_; }

    [[nodiscard]] bool is_completed() const { return is_completed_; }

    void complete() { is_completed_ = true; }

private:
    size_t id_;
    std::string title_;
    bool is_completed_;
};

struct TaskManager {
    std::shared_ptr<Task> create_task(size_t id, const std::string& title) {
        auto task = std::make_shared<Task>(id, title);
        tasks_[id] = task;
        return task;
    }

    void complete_task(const size_t id) {
        if (const auto iter = tasks_.find(id); iter != tasks_.end()) {
            iter->second->complete();
        }
    }

private:
    std::unordered_map<size_t, std::shared_ptr<Task>> tasks_;
};

struct TaskObserver {
    explicit TaskObserver(std::weak_ptr<Task> task) : task_(std::move(task)) {}

    void log() const {
        if (const auto task = task_.lock()) {
            std::cout << task->id() << ": " << task->title() << "\n";
        } else {
            std::cout << "No task found!\n";
        }
    }

private:
    std::weak_ptr<Task> task_;
};

int main() {
    TaskManager task_manager;
    const auto task = task_manager.create_task(1, "Wash the dishes");

    const TaskObserver observer(task);
    observer.log();

    task_manager.complete_task(1);
    observer.log();
}
