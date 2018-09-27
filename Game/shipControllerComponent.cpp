#include "shipControllerComponent.h"
#include "kinematicComponent.h"
#include "inputManager.h"
#include "audioSystem.h"
#include "entity.h"
#include "missile.h"

void ShipControllerComponent::Create(float speed)
{
	m_speed = speed;
	InputManager::Instance()->AddAction("left", SDL_SCANCODE_A, InputManager::eDevice::KEYBOARD);
	InputManager::Instance()->AddAction("right", SDL_SCANCODE_D, InputManager::eDevice::KEYBOARD);
	InputManager::Instance()->AddAction("fire", SDL_BUTTON_LEFT, InputManager::eDevice::MOUSE);

	AudioSystem::Instance()->AddSound("fire", "laser.wav");
}

void ShipControllerComponent::Destroy()
{
}

void ShipControllerComponent::Update()
{
	Vector2D force = Vector2D::zero;
	if ((InputManager::Instance()->GetActionButton("left") == InputManager::eButtonState::PRESSED) ||
		(InputManager::Instance()->GetActionButton("left") == InputManager::eButtonState::HELD))
	{
		force = force + Vector2D::left;
	}

	if ((InputManager::Instance()->GetActionButton("right") == InputManager::eButtonState::PRESSED) ||
		(InputManager::Instance()->GetActionButton("right") == InputManager::eButtonState::HELD))
	{
		force = force + Vector2D::right;
	}

	KinematicComponent* kinematic = m_owner->GetComponent<KinematicComponent>();
	if (kinematic)
	{
		kinematic->ApplyForce(force * m_speed, KinematicComponent::VELOCITY);
	}

	if (InputManager::Instance()->GetActionButton("fire") == InputManager::eButtonState::PRESSED)
	{
		Missile* missile = new Missile(m_owner->GetScene());
		missile->Create("playermissile", m_owner->GetTransform().position, Vector2D::down, 800.0f);
		m_owner->GetScene()->AddEntity(missile);

		AudioSystem::Instance()->PlaySound("fire");
	}
}
