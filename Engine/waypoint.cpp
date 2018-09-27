#include "waypoint.h"
#include "aabbComponent.h"
#include "debugDraw.h"
#include "eventManager.h"

void Waypoint::Create(const Vector2D & position, const Vector2D& size, Entity * owner)
{
	m_owner = owner;

	m_transform.position = position;
	m_transform.scale = size;

	AABBComponent* aabbComponent = AddComponent<AABBComponent>();
	aabbComponent->Create(Vector2D(1.0f, 1.0f));
}

void Waypoint::Update()
{
	Entity::Update();
}
