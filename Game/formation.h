#pragma once
#include "entity.h"
#include "enemy.h"

class Formation : public Entity
{
public:
	using Path = std::vector<Vector2D>;

public:
	struct Info
	{
		Enemy::Info enemyInfo;
		float enterTime;
		bool isActive;
	};

public:
	Formation(Scene* scene, const ID& id) : Entity(scene, id) {}
	virtual ~Formation() {}

	void Create(int difficulty);
	void Destroy();
	void Update();
	int GetEnemiesLeft() { return m_enemies.size(); }
	void EnemyDead(Enemy* enemy) 
	{
		auto position = std::find(m_enemies.begin(), m_enemies.end(), enemy);
		if (position != m_enemies.end())
			m_enemies.erase(position);
	}

	void ClearEnemies()
	{
		for (Entity* en : m_scene->GetEntitiesWithTag("enemy"))
		{
			m_scene->RemoveEntity(en, true);
		}
		for (Entity* en : m_scene->GetEntitiesWithTag("enemy_missile"))
		{
			m_scene->RemoveEntity(en, true);
		}
		m_enemies.clear();
	}

	int GetDifficulty() { return m_difficulty; }

	const Path& GetEnterPath(Enemy::eSide side) { return m_enterPaths[side]; }
	const Path& GetRandomAttackPath();

protected:
	std::vector<Info> m_formation;
	float m_timer = 0.0f;
	std::vector<Enemy*> m_enemies;
	int m_difficulty = 0;

	Path m_enterPaths[2];
	std::vector<Path> m_attackPaths;
};