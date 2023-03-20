#pragma once
#include <memory>

#include "Playlist.h"
#include "Player.h"

namespace ImaginaryPlayer
{
    class PlayerImplementation final:
        public Player
    {
    public:
        PlayerImplementation(Playlist::Ptr playlist);

        const std::string play() const;
        void pause() const;
        const std::string previous();
        const std::string next();
        std::string add(Track::Ptr newTrack);
        std::string removeDuplicate();
        const std::string show() const;
        const std::string showTrack() const;
        const std::string setRepeat(bool isRepeat);
        const std::string setRandom(bool isRandom);
    protected:
        Playlist::Ptr m_playlist;
    };
}
