#include "game.h"
#include "engine.h"
#include "renderer.h"
#include "scene.h"
#include "ship.h"
#include "enemy.h"
#include "fileSystem.h"
#include "spriteComponent.h"
#include "animationComponent.h"
#include "textComponent.h"
#include "eventManager.h"
#include "stateMachine.h"
#include "states.h"

bool Game::Initalize()
{
	bool success = m_engine->Initialize();
	FileSystem::Instance()->SetPathname("..\\content\\galaga\\");

	EventManager::Instance()->SetGameEventReceiver(this);
	
	m_scene = new Scene();
	m_stateMachine = new StateMachine(m_scene);

	m_stateMachine->AddState("title", new TitleState(m_stateMachine));
	m_stateMachine->AddState("enter_stage", new EnterStageState(m_stateMachine));
	m_stateMachine->AddState("game", new GameState(m_stateMachine));
	
	m_stateMachine->SetState("title");

	Entity* entity = new Entity(m_scene, "score");
	entity->GetTransform().position = Vector2D(20.0f, 20.0f);
	TextComponent* textComponent = entity->AddComponent<TextComponent>();
	textComponent->Create("00000", "emulogic.ttf", 18, Color::white);
	textComponent->SetDepth(100);
	m_scene->AddEntity(entity);

	Ship* ship = new Ship(m_scene, "player");
	ship->Create(Vector2D(400, 580));
	m_scene->AddEntity(ship);

	for (int i = 0; i < 3; i++)
	{
		Entity* heart = new Entity(m_scene);
		heart->GetTransform().position = Vector2D(30 + i * 30, 60);
		SpriteComponent* sprite = heart->AddComponent<SpriteComponent>();
		sprite->Create("ship.png", Vector2D::one / 2);
		m_hearts[i] = heart;
		m_scene->AddEntity(heart);
	}

	m_lives = 3;

	m_running = success;

	return success;
}

void Game::Shutdown()
{
	m_engine->Shutdown();
}

void Game::Update()
{
	m_running = !m_engine->IsQuit();
	m_engine->Update();

	Entity* scoreEntity = m_scene->GetEntityWithID("score");
	if (scoreEntity)
	{
		TextComponent* textComponent = scoreEntity->GetComponent<TextComponent>();
		std::string score = std::to_string(m_score);
		while (score.length() < 5) score = "0" + score;
		textComponent->SetText(score);
	}

	assert(m_stateMachine);
	m_stateMachine->Update();

	Renderer::Instance()->SetColor(Color::black);
	Renderer::Instance()->BeginFrame();

	m_scene->Update();
	m_scene->Draw();

	Renderer::Instance()->EndFrame();
}

void Game::OnEvent(const Event & event)
{
	if (event.eventID == "add_score")
	{
		m_score = m_score + event.variants[0].asInteger;
	}
	if (event.eventID == "end_game")
	{
		m_lives--;
		if (m_lives >= 0)
		{
			Ship* ship = new Ship(m_scene, "player");
			ship->Create(Vector2D(400, 580));
			m_scene->AddEntity(ship);
			m_hearts[m_lives]->GetComponent<SpriteComponent>()->SetVisible(false);
		}
		else
		{
			m_score = 0;
			m_lives = 3;
			for (int i = 0; i < 3; i++)
				m_hearts[i]->GetComponent<SpriteComponent>()->SetVisible(true);
			m_stateMachine->SetState("title");

			Ship* ship = new Ship(m_scene, "player");
			ship->Create(Vector2D(400, 580));
			m_scene->AddEntity(ship);
		}
	}
}

// Game Over