#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "song.hpp"

struct Library {
    std::shared_ptr<Song> get_song(const std::string& id);

    void add_song(const std::string& id, std::string& name);

private:
    std::unordered_map<std::string, std::shared_ptr<Song>> songs_;
};