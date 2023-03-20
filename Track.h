#pragma once

#include <string>
#include <memory>

namespace ImaginaryPlayer
{
	class Track
	{
	public:
		using Ptr = std::shared_ptr<Track>;

		virtual const std::string title() const = 0;
		virtual const std::string play() const = 0;
		virtual void pause() const = 0;
		virtual const std::string show() const = 0;
	};
}

