#include "file_manager.hpp"

int main() {
    const FileManager file_manager{"backend-app"};
    file_manager.append_content(".gitignore", R"(# Temporary Files
request.http
request-soap.http
    )");

    file_manager.replace_template(
        "src/main.cpp.tmpl",
        "src/main.cpp",
        "{{NAME}}",
        "RamssC"
    );
}
