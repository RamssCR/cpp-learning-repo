#include "active_player.hpp"
#include <iostream>

void ActivePlayer::play(const std::weak_ptr<Song>& track) {
    if (const auto locked = track.lock()) {
        current_track_ = locked;
        current_track_->play();
    } else {
        std::cout << "Song no longer exists" << "\n";
    }
}
