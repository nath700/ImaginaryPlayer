#pragma once

#include <string>

#include "Track.h"
#include <filesystem>


namespace ImaginaryPlayer
{
    using TrackPath = std::filesystem::path;

    class TrackImplementation final :
        public Track
    {
    public:
        TrackImplementation();
        TrackImplementation(const std::string& title);
    protected:
        std::string m_title;
        std::string m_codec;
        std::string m_album;
        TrackPath m_path;
        int m_duration; // in second

    public:
        const std::string play() const;
        void pause() const {};
        const std::string show() const;

        const std::string title() const { return m_title; }
        const std::string codec() const { return m_codec; }
        const std::string album() const { return m_album; }
        const TrackPath path() const { return m_path; }
        const int duration() const { return m_duration; }
    };
}
