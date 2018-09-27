#include "engine.h"
#include "renderer.h"
#include "textureManager.h"
#include "textManager.h"
#include "inputManager.h"
#include "audioSystem.h"
#include "fileSystem.h"
#include "physics.h"
#include "timer.h"
#include "vector2D.h"
#include "matrix22.h"
#include "text.h"
#include <assert.h>
#include <iostream>
#include <vector>

bool Engine::Initialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	FileSystem::Instance()->Initialize(this);
	Timer::Instance()->Initialize(this);
	Renderer::Instance()->Initialize(this);
	TextureManager::Instance()->Initialize(this);
	TextManager::Instance()->Initialize(this);
	InputManager::Instance()->Initialize(this);
	AudioSystem::Instance()->Initialize(this);
	Physics::Instance()->Initialize(this);
	
	Physics::Instance()->SetGravity(Vector2D(0.0f, 400.0f));

	m_isDebug = true;

	return true;
}

void Engine::Shutdown()
{
	Physics::Instance()->Shutdown();
	AudioSystem::Instance()->Shutdown();
	InputManager::Instance()->Shutdown();
	TextureManager::Instance()->Shutdown();
	Renderer::Instance()->Shutdown();
	Timer::Instance()->Shutdown();
	FileSystem::Instance()->Shutdown();

	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Engine::Update()
{
	Timer::Instance()->Update();
	Timer::Instance()->SetTimeScale(1.0f);
	InputManager::Instance()->Update();
	AudioSystem::Instance()->Update();
	Physics::Instance()->Update();
	FileSystem::Instance()->Update();

	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		m_isQuit = true;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			m_isQuit = true;
		}
	}

	SDL_PumpEvents();

	if (InputManager::Instance()->GetButtonState(SDL_SCANCODE_GRAVE) == InputManager::eButtonState::PRESSED)
	{
		m_isDebug = !m_isDebug;
	}
}
