#include "library.hpp"

std::shared_ptr<Song> Library::get_song(const std::string& id) {
    return songs_.at(id);
}

void Library::add_song(const std::string& id, std::string& name) {
    if (songs_.contains(id)) throw std::runtime_error("Song already exists");

    const auto song = std::make_shared<Song>(name);
    songs_[id] = song;
}