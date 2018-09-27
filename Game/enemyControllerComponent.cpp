#include "enemyControllerComponent.h"
#include "kinematicComponent.h"
#include "vector2D.h"
#include "entity.h"
#include "timer.h"
#include "missile.h"
#include "_math.h"

void EnemyControllerComponent::Create(float speed)
{
	m_speed = speed;
	m_timer = Math::GetRandomRange(m_fireRateMin, m_fireRateMax);
}

void EnemyControllerComponent::Destroy()
{

}

void EnemyControllerComponent::Update()
{
	Vector2D force = Vector2D::up;

	Entity* player = m_owner->GetScene()->GetEntityWithID("player");
	if (player)
	{
		float dx = player->GetTransform().position.x - m_owner->GetTransform().position.x;
		if (dx < -32.0f) force.x = -0.7f;
		if (dx >  32.0f) force.x =  0.7f;
	}

	KinematicComponent* kinematic = m_owner->GetComponent<KinematicComponent>();
	if (kinematic)
	{
		kinematic->ApplyForce(force * m_speed, KinematicComponent::VELOCITY);
	}

	float dt = Timer::Instance()->DeltaTime();
	m_timer = m_timer - dt;
	if (m_timer <= 0.0f)
	{
		m_timer = Math::GetRandomRange(m_fireRateMin, m_fireRateMax);

		Missile* missile = new Missile(m_owner->GetScene());
		missile->Create("enemymissile", m_owner->GetTransform().position, Vector2D::up, 800.0f);
		missile->SetTag("enemy_missile");
		m_owner->GetScene()->AddEntity(missile);
	}
}