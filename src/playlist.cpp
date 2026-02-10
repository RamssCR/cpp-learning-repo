#include "playlist.hpp"

void Playlist::add_track(const std::weak_ptr<Song>& track) {
    tracks_.push_back(track);
}