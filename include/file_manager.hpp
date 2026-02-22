#pragma once
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class FileManager {
public:
    explicit FileManager(fs::path root);

    void create_base_directory() const;

    void create_file(const std::string& path, std::string_view content) const;

    void append_content(const std::string& path, std::string_view content) const;

    void replace_template(
        const fs::path& in_path,
        const fs::path& out_path,
        std::string_view placeholder,
        std::string_view value
    ) const;

private:
    fs::path root_;

    static void replace_placeholder(
        std::string& search_context,
        std::string_view placeholder,
        std::string_view value
    );
};