#include <fstream>
#include <iostream>
#include "file_manager.hpp"

FileManager::FileManager(fs::path root) : root_(std::move(root)) {
    if (root_.empty()) throw std::runtime_error("root path is empty");
}

void FileManager::create_base_directory() const {
    fs::create_directories(root_ / "src");
    std::cout << "Base project created at " << fs::absolute(root_) << "\n";
}

void FileManager::create_file(const std::string& path, const std::string_view content) const {
    if (std::ofstream file(root_ / path); file.is_open()) {
        file << content;
        std::cout << "File created successfully" << "\n";
    }
}

void FileManager::append_content(const std::string &path, const std::string_view content) const {
    if (std::ofstream file(root_ / path, std::ios::app); file.is_open()) {
        file << "\n" << content;
        std::cout << "\033[32m" << "OK " << "\033[0m" << "Content appended successfully" << "\n";
    }
}

void FileManager::replace_template(
    const fs::path& in_path,
    const fs::path& out_path,
    const std::string_view placeholder,
    const std::string_view value
) const {
    std::ifstream template_file(root_ / in_path);
    if (!template_file) throw std::runtime_error("No template file found");

    std::stringstream buffer;
    buffer << template_file.rdbuf();
    std::string content{buffer.str()};

    replace_placeholder(content, placeholder, value);

    std::ofstream out_file(root_ / out_path);
    out_file << content;
}

void FileManager::replace_placeholder(
    std::string& search_context,
    const std::string_view placeholder,
    const std::string_view value
) {
    std::size_t position{0};
    while ((position = search_context.find(placeholder, position)) != std::string::npos) {
        search_context.replace(position, placeholder.length(), value);
        position += value.length();
    }
}