#pragma once

#include <vector>
#include <string>

#include "Playlist.h"

namespace ImaginaryPlayer
{

    using TrackList = std::vector<Track::Ptr>;

    class PlaylistImplementation final :
        public Playlist
    {
    protected:
        bool m_isRepeat;
        bool m_isRandom;
        std::string m_name;
        TrackList m_tracklist;
        int m_currentTrack;

    public:
        PlaylistImplementation();

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
    };
}
