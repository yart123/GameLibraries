#include "explosion.h"
#include "spriteComponent.h"
#include "animationComponent.h"
#include "audioSystem.h"
#include "eventManager.h"

void Explosion::Create(const Vector2D & position, eType type)
{
	m_transform.position = position;
	m_type = type;
	m_transform.scale = Vector2D(2.0f, 2.0f);
	SpriteComponent* spriteComponent = AddComponent<SpriteComponent>();
	spriteComponent->Create("", Vector2D(0.5f, 0.5f));
	AnimationComponent* animationComponent = AddComponent<AnimationComponent>();
	std::vector<std::string> textureNames;
	if (type == eType::ENEMY)
		textureNames = { "enemy-explosion01.png", "enemy-explosion02.png", "enemy-explosion03.png", "enemy-explosion04.png", "enemy-explosion05.png" };
	else
		textureNames = { "ship-explosion01.png", "ship-explosion02.png", "ship-explosion03.png", "ship-explosion04.png"};
	animationComponent->Create(textureNames, 1.0f / 10.0f, AnimationComponent::ePlayback::ONE_TIME_DESTROY);

	AudioSystem::Instance()->AddSound("explosion", "enemy-hit01.wav");
	AudioSystem::Instance()->PlaySound("explosion");
}

void Explosion::Update()
{
	Entity::Update();
}

void Explosion::Destroy()
{
	if (m_type == PLAYER)
	{
		Event _event;
		_event.eventID = "end_game";
		EventManager::Instance()->SendGameMessage(_event);
	}
	Entity::Destroy();
}
