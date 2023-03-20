#pragma once

#include <string>

#include "PLayerImplementation.h"
#include "PlaylistImplementation.h"

namespace ImaginaryPlayer
{
	namespace helper
	{
		Player::Ptr makePlayer(Playlist::Ptr playlist);
		Playlist::Ptr makePlaylist();
	}
}