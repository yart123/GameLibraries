#pragma once

#include <fmod.hpp>
#include <fmod_common.h>
#include <string>

class Audio
{
public:
	Audio(FMOD::System* fmodSystem) : m_fmodSystem(fmodSystem) {}
	~Audio();

	void Load(const std::string& filename);
	void Play(bool loop = false);
	void Stop();

protected:
	FMOD::System* m_fmodSystem = nullptr;
	FMOD::Sound* m_sound = nullptr;
	FMOD::Channel* m_channel = nullptr;
};