#pragma once
#include <string>

struct Song {
    explicit Song(std::string name);

    ~Song();

    void play() const;

    std::string name_;
};