#pragma once
#include <memory>
#include <vector>
#include "song.hpp"

struct Playlist {
    void add_track(const std::weak_ptr<Song>& track);

private:
    std::vector<std::weak_ptr<Song>> tracks_;
};