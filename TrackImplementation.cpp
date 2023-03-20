#include "TrackImplementation.h"

#include <sstream>

namespace ImaginaryPlayer
{

	TrackImplementation::TrackImplementation() :
		m_title(), m_codec(), m_album(), m_path(), m_duration(0)
	{}

	TrackImplementation::TrackImplementation(const std::string& title)
		:m_title(title), m_codec("mp3"), m_album(), m_path("c:/default"), m_duration(180)
	{}

	const std::string TrackImplementation::play() const
	{
		return m_title;
	}

	const std::string TrackImplementation::show() const
	{
		std::stringstream info;
		info << "title : " << m_title << std::endl;
		info << "code : " << m_codec << std::endl;
		info << "album : " << m_album << std::endl;
		info << "file : " << m_path << std::endl;
		info << "duration : " << m_duration << std::endl;

		return info.str();
	}
}