#include <format>
#include <iostream>
#include "song.hpp"

Song::Song(std::string name) : name_(std::move(name)) {}

Song::~Song() {
    std::cout << "Song deleted" << "\n";
}

void Song::play() const {
    std::cout << "Playing song: " << name_ << "\n";
}
