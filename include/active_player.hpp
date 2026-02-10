#pragma once
#include <memory>
#include "song.hpp"

struct ActivePlayer {
    void play(const std::weak_ptr<Song>& track);

private:
    std::shared_ptr<Song> current_track_;
};