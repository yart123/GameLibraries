#include "WaypointControllerComponent.h"
#include "kinematicComponent.h"
#include "timer.h"
#include "waypoint.h"
#include "debugDraw.h"

void WaypointControllerComponent::Create(const std::vector<Vector2D>& points, float speed, float turnRate, bool setPositionAtStart)
{
	m_speed = speed;
	m_turnRate = turnRate;

	// create waypoints
	for (Vector2D point : points)
	{
		Waypoint* waypoint = m_owner->GetScene()->AddEntity<Waypoint>();
		waypoint->Create(point, Vector2D(30.0f, 30.0f), m_owner);
		m_waypoints.push_back(waypoint);
	}

	m_waypointIndex = 0;
	m_waypoint = m_waypoints[m_waypointIndex];

	if (setPositionAtStart)
	{
		m_owner->GetTransform().position = m_waypoint->GetTransform().position;
	}
}

void WaypointControllerComponent::Destroy()
{
	for (Waypoint* waypoint : m_waypoints)
	{
		waypoint->SetState(Entity::DESTROY);
	}
}

void WaypointControllerComponent::Update()
{
	float dt = Timer::Instance()->DeltaTime();

	if (m_owner->Intersects(m_waypoint))
	{
		SetNextWaypoint();
	}

	DEBUG_DRAW_LINE(m_owner->GetTransform().position, m_waypoint->GetTransform().position, Color::white)

	Vector2D direction = m_waypoint->GetTransform().position - m_owner->GetTransform().position;
	float rotation = (Vector2D::GetAngle(direction) * Math::RadiansToDegrees + 90.0f);
	m_owner->GetTransform().rotation = Math::LerpDegrees(m_owner->GetTransform().rotation, rotation, m_turnRate * dt);
	Vector2D force = Vector2D::Rotate(Vector2D::up, m_owner->GetTransform().rotation * Math::DegreesToRadians + Math::PI);

	KinematicComponent* kinematic = m_owner->GetComponent<KinematicComponent>();
	if (kinematic)
	{
		kinematic->ApplyForce(force * m_speed, KinematicComponent::VELOCITY);
	}
}

void WaypointControllerComponent::SetNextWaypoint()
{
	m_waypointIndex++;
	if (m_waypointIndex < m_waypoints.size())
	{
		m_waypoint = m_waypoints[m_waypointIndex];
	}
	else
	{
		m_isComplete = true;
		m_waypointIndex = 0;
		m_waypoint = m_waypoints[m_waypointIndex];
	}
}
