#include <string>
#include <string_view>
#include <iostream>

#include "TrackImplementation.h"
#include "CmdLine.h"

namespace
{
	constexpr std::string_view cmdPlay("play");
	constexpr std::string_view cmdPause("pause");
	constexpr std::string_view cmdPrevious("previous");
	constexpr std::string_view cmdNext("next");
	constexpr std::string_view cmdAdd("add");
	constexpr std::string_view cmdRemoveDuplicate("removeDuplicate");
	constexpr std::string_view cmdShow("show");
	constexpr std::string_view cmdShowTrack("showTrack");
	constexpr std::string_view cmdQuit("quit");
	constexpr std::string_view cmdHelp("help");
	constexpr std::string_view cmdRepeatOn("repeatOn");
	constexpr std::string_view cmdRepeatOff("repeatOff");
	constexpr std::string_view cmdRandomOn("randomOn");
	constexpr std::string_view cmdRandomOff("randomOff");
}

namespace ImaginaryPlayer
{
	CmdLine::CmdLine(Player::Ptr player)
		: m_player(player), isStarting(true)
	{
	}
	void CmdLine::readCmd()
	{
		std::string cmd;
		std::cin >> cmd;
		if (cmd == cmdPlay)
		{
			std::cout << m_player->play() << std::endl;
		}
		else if (cmd == cmdPause)
		{
			m_player->pause();
		}
		else if (cmd == cmdPrevious)
		{
			std::cout << m_player->previous() << std::endl;
		}
		else if (cmd == cmdNext)
		{
			std::cout << m_player->next() << std::endl;
		}
		else if (cmd == cmdAdd)
		{
			std::string trackName;
			std::cout << "enter the title : " << std::endl;
			std::cin >> trackName;
			auto track = std::make_shared<TrackImplementation>(trackName);
			std::cout << m_player->add(track) << std::endl;
		}
		else if (cmd == cmdRemoveDuplicate)
		{
			std::cout << m_player->removeDuplicate() << std::endl;
		}
		else if (cmd == cmdShow)
		{
			std::cout << m_player->show() << std::endl;
		}
		else if (cmd == cmdShowTrack)
		{
			std::cout << m_player->showTrack() << std::endl;
		}
		else if (cmd == cmdQuit)
		{
			isStarting = false;
		}
		else if (cmd == cmdHelp)
		{
			help();
		}
		else if (cmd == cmdRepeatOn)
		{
			std::cout << m_player->setRepeat(true);
		}
		else if (cmd == cmdRepeatOff)
		{
			std::cout << m_player->setRepeat(false);
		}
		else if (cmd == cmdRandomOn)
		{
			std::cout << m_player->setRandom(true);
		}
		else if (cmd == cmdRandomOff)
		{
			std::cout << m_player->setRandom(false);
		}
	}

	void CmdLine::help()
	{
		std::cout << "Usage :" << std::endl;
		std::cout << cmdAdd			<< " : Add a new track in the playlist" << std::endl;
		std::cout << cmdNext		<< " : Play the next track" << std::endl;
		std::cout << cmdPause		<< " : Pause" << std::endl;
		std::cout << cmdPlay		<< " : Play the current track" << std::endl;
		std::cout << cmdPrevious	<< " : Play the previous track" << std::endl;
		std::cout << cmdQuit		<< " : Quit this application" << std::endl;
		std::cout << cmdRemoveDuplicate << " : Remove duplicate track from the playlist" << std::endl;
		std::cout << cmdShow << " : Show the information of the playlist" << std::endl;
		std::cout << cmdShowTrack << " : Show the information about the curent track" << std::endl;
		std::cout << cmdRepeatOn << " : Activate the repeat mode" << std::endl;
		std::cout << cmdRepeatOff << " : Deactivate the repeat mode" << std::endl;
		std::cout << cmdRandomOn << " : Activate the random mode" << std::endl;
		std::cout << cmdRandomOff << " : Deactivate the random mode" << std::endl;
	}

	void CmdLine::process()
	{
		while (isStarting)
		{
			readCmd();
		}
	}
}