#include "PLayerImplementation.h"

ImaginaryPlayer::PlayerImplementation::PlayerImplementation(Playlist::Ptr playlist)
	: m_playlist(playlist)
{

}

const std::string ImaginaryPlayer::PlayerImplementation::play() const
{
	return m_playlist->play();
}

void ImaginaryPlayer::PlayerImplementation::pause() const
{
}

const std::string ImaginaryPlayer::PlayerImplementation::previous()
{
	return m_playlist->previous();
}

const std::string ImaginaryPlayer::PlayerImplementation::next()
{
	return m_playlist->next();
}

std::string ImaginaryPlayer::PlayerImplementation::add(Track::Ptr newTrack)
{
	return m_playlist->add(newTrack);
}

std::string ImaginaryPlayer::PlayerImplementation::removeDuplicate()
{
	return m_playlist->removeDuplicate();
}

const std::string ImaginaryPlayer::PlayerImplementation::show() const
{
	return m_playlist->show();
}

const std::string ImaginaryPlayer::PlayerImplementation::showTrack() const
{
	return m_playlist->showTrack();
}

const std::string ImaginaryPlayer::PlayerImplementation::setRepeat(bool isRepeat)
{
	return m_playlist->setRepeat(isRepeat);
}

const std::string ImaginaryPlayer::PlayerImplementation::setRandom(bool isRandom)
{
	return m_playlist->setRandom(isRandom);
}
