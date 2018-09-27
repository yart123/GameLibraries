#pragma once
#include "engine.h"
#include "singleton.h"
#include <string>

class ENGINE_API FileSystem : public Singleton<FileSystem>
{
public:
	bool Initialize(Engine* engine);
	void Shutdown();
	void Update();

	void SetPathname(const std::string& pathname) { m_pathname = pathname; }
	const std::string& GetPathname() { return m_pathname; }

protected:
	Engine* m_engine;
	std::string m_pathname;
};