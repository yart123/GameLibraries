#include "audio.h"
#include "assert.h"

Audio::~Audio()
{
	if (m_sound)
	{
		m_sound->release();
		m_sound = nullptr;
	}
}

void Audio::Load(const std::string& filename)
{
	FMOD::Sound* fmodsound = nullptr;
	FMOD_RESULT result = m_fmodSystem->createSound(filename.c_str(), FMOD_DEFAULT, 0, &m_sound);
	assert(result == FMOD_OK);
}

void Audio::Play(bool loop)
{
	FMOD_MODE mode = (loop) ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
	m_sound->setMode(mode);
	FMOD_RESULT result = m_fmodSystem->playSound(m_sound, 0, false, &m_channel);
	assert(result == FMOD_OK);
}

void Audio::Stop()
{
	if (m_channel->getCurrentSound(&m_sound))
	{
		m_channel->stop();
	}
}