#pragma once

#include "Player.h"

namespace ImaginaryPlayer
{
	class CmdLine
	{
	protected:
		Player::Ptr m_player;

		void help();

		bool isStarting;
	public:
		CmdLine(Player::Ptr player);

		void readCmd();
		void process();
	};
}
