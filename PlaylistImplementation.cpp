#include <sstream>
#include <algorithm>

#include "Track.h"
#include "PlaylistImplementation.h"

namespace ImaginaryPlayer
{
	PlaylistImplementation::PlaylistImplementation()
		: m_name(), m_isRandom(false), m_isRepeat(false), m_currentTrack(0)
	{
	}
	const std::string PlaylistImplementation::play() const
	{
		return m_tracklist.at(m_currentTrack)->play();
	}

	void PlaylistImplementation::pause() const
	{}

	const std::string PlaylistImplementation::previous()
	{
		if (m_currentTrack == 0)
		{
			if (m_isRepeat)
			{
				int tracklistSize = std::size(m_tracklist);
				m_currentTrack = tracklistSize - 1;
				return m_tracklist.at(m_currentTrack)->play();
			}
		}
		else
		{
			return m_tracklist.at(++m_currentTrack)->play();
		}
		m_currentTrack = 0;
		return std::string("end of playlist.");
	}

	const std::string PlaylistImplementation::next()
	{
		int tracklistSize = std::size(m_tracklist);
		if (m_currentTrack == tracklistSize - 1)
		{
			if (m_isRepeat)
			{
				m_currentTrack = 0;
				return m_tracklist.at(m_currentTrack)->play();
			}
		}
		else if (m_isRandom)
		{
			m_currentTrack = std::rand() % tracklistSize;
			return m_tracklist.at(m_currentTrack)->play();
		}
		else
		{
			++m_currentTrack;
			return m_tracklist.at(m_currentTrack)->play();
		}
		m_currentTrack = 0;
		return std::string("end of playlist.");
	}
	std::string PlaylistImplementation::add(Track::Ptr newTrack)
	{
		m_tracklist.push_back(newTrack);
		std::stringstream msg;
		msg << "add : " << newTrack->title() << std::endl;
		return msg.str();
	}
	std::string PlaylistImplementation::removeDuplicate()
	{
		std::sort(m_tracklist.begin(), m_tracklist.end());
		auto last = std::unique(m_tracklist.begin(), m_tracklist.end());
		m_tracklist.erase(last, m_tracklist.end());
		return std::string("Remove duplicate track");
	}
	const std::string PlaylistImplementation::show() const
	{
		std::stringstream info;
		info << "Playlist name : " << m_name << std::endl;
		info << "number of tracks : " << std::size(m_tracklist) << std::endl;
		info << "Tracks :" << std::endl;

		for (const auto track : m_tracklist)
		{
			info << track->show() << std::endl;
		}
		return info.str();
	}

	const std::string PlaylistImplementation::showTrack() const
	{
		return m_tracklist.at(m_currentTrack)->show();
	}

	const std::string PlaylistImplementation::setRepeat(bool isRepeat)
	{
		m_isRepeat = isRepeat;
		std::stringstream msg;
		if (m_isRepeat)
		{
			msg << "repeat : On" << std::endl;
		}
		else
		{
			msg << "repeat : off" << std::endl;
		}
		return msg.str();
	}

	const std::string PlaylistImplementation::setRandom(bool isRandom)
	{
		m_isRandom = isRandom;
		std::stringstream msg;
		if (m_isRandom)
		{
			msg << "Random : On" << std::endl;
		}
		else
		{
			msg << "Random : Off" << std::endl;
		}
		return msg.str();
	}

	
}