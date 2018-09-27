#pragma once

#include "engine.h"
#include "singleton.h"
#include "audio.h"
#include <fmod.hpp>
#include <fmod_common.h>
#include <string>
#include <vector>
#include <map>

class ENGINE_API AudioSystem : public Singleton<AudioSystem>
{
public:
	bool Initialize(Engine* engine);
	void Shutdown();
	void Update();
	
	void AddSound(const std::string& id, const std::string& audioname);
	void PlaySound(const std::string& id, bool loop = false);
	void RemoveSound(const std::string& id);

	friend Singleton<AudioSystem>;

protected:
	AudioSystem() {}

private:
	Engine * m_engine;

	FMOD::System* m_fmodSystem;
	//std::vector<Audio*> m_sounds;
	std::map<std::string, FMOD::Sound*> m_sounds;
};
