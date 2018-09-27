#pragma once

#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)

#ifdef ENGINE_EXPORTS  
#define ENGINE_API DLL_EXPORT
#else  
#define ENGINE_API DLL_IMPORT
#endif 

#pragma warning(disable:4251)

#include <sdl.h>
#include <sdl_ttf.h>

class ENGINE_API Engine
{
public:
	Engine() {}
	~Engine() {}

	bool Initialize();
	void Shutdown();

	void Update();
	
	SDL_Window * GetWindow() { return m_window; }

	bool IsQuit() { return m_isQuit; }
	bool IsDebug() { return m_isDebug; }

protected:
	bool m_isQuit = false;
	bool m_isDebug = false;
	SDL_Window * m_window = nullptr;
};
