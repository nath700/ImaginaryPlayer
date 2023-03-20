#pragma once

#include <string>
#include <memory>

#include "Track.h"

namespace ImaginaryPlayer
{

	class Playlist
	{
	public:
		using Ptr = std::shared_ptr<Playlist>;

		virtual const std::string play() const = 0;
		virtual void pause() const = 0;
		virtual const std::string previous() = 0;
		virtual const std::string next() = 0;
		virtual std::string add(Track::Ptr newTrack) = 0;
		virtual std::string removeDuplicate() = 0;
		virtual const std::string show() const = 0;
		virtual const std::string showTrack() const = 0;
		virtual const std::string setRepeat(bool isRepeat) = 0;
		virtual const std::string setRandom(bool isRandom) = 0;
	};
}
