#pragma once
#include "controllerComponent.h"
#include "vector2D.h"
#include <vector>

class Waypoint;

class ENGINE_API WaypointControllerComponent : public IControllerComponent
{
public:
	WaypointControllerComponent(Entity* owner) : IControllerComponent(owner) {}

	void Create(const std::vector<Vector2D>& points, float speed, float turnRate, bool setPositionAtStart = false);
	void Destroy();
	void Update();

	void SetNextWaypoint();

	bool IsComplete() { return m_isComplete; }

protected:
	bool m_isComplete = false;
	float m_speed = 0.0f;
	float m_turnRate = 0.0f;

	std::vector<Waypoint*> m_waypoints;
	Waypoint* m_waypoint = nullptr;
	size_t m_waypointIndex;
};
