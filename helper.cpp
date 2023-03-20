#include <memory>

#include "helper.h"

namespace ImaginaryPlayer
{
	namespace helper
	{
		Player::Ptr makePlayer(Playlist::Ptr playlist)
		{
			auto player = std::make_shared<PlayerImplementation>(playlist);
			return std::move(player);
		}

		Playlist::Ptr makePlaylist()
		{
			auto playlist = std::make_shared<PlaylistImplementation>();
			return std::move(playlist);
		}
	}
}