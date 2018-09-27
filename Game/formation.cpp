#include "formation.h"
#include "timer.h"

void Formation::Create(int difficulty)
{
	m_difficulty = difficulty;
	//m_enterPaths[0] = { Vector2D(200.0f, 400.0f), Vector2D(300.0f, 300.0f), Vector2D(200.0f, 200.0f), Vector2D(100.0f, 300.0f), Vector2D(200.0f, 400.0f) };
	//m_enterPaths[1] = { Vector2D(600.0f, 400.0f), Vector2D(500.0f, 300.0f), Vector2D(600.0f, 200.0f), Vector2D(700.0f, 300.0f), Vector2D(600.0f, 400.0f) };

	m_enterPaths[0] = { Vector2D(500.0f, -64.0f), Vector2D(100.0f, 300.0f), Vector2D(200.0f, 400.0f), Vector2D(300.0f, 300.0f) };
	m_enterPaths[1] = { Vector2D(300.0f, -64.0f), Vector2D(700.0f, 300.0f), Vector2D(600.0f, 400.0f), Vector2D(500.0f, 300.0f) };

	m_attackPaths.push_back({ Vector2D(450.0f, 300.0f), Vector2D(500.0f, 500.0f), Vector2D(600.0f, 600.0f), Vector2D(550.0f, 650.0f) });
	m_attackPaths.push_back({ Vector2D(500.0f, 300.0f), Vector2D(550.0f, 500.0f), Vector2D(650.0f, 600.0f), Vector2D(600.0f, 650.0f) });
	m_attackPaths.push_back({ Vector2D(550.0f, 300.0f), Vector2D(600.0f, 500.0f), Vector2D(700.0f, 600.0f), Vector2D(650.0f, 650.0f) });
	m_attackPaths.push_back({ Vector2D(350.0f, 300.0f), Vector2D(300.0f, 500.0f), Vector2D(200.0f, 600.0f), Vector2D(250.0f, 650.0f) });
	m_attackPaths.push_back({ Vector2D(300.0f, 300.0f), Vector2D(250.0f, 500.0f), Vector2D(150.0f, 600.0f), Vector2D(200.0f, 650.0f) });
	m_attackPaths.push_back({ Vector2D(250.0f, 300.0f), Vector2D(200.0f, 500.0f), Vector2D(100.0f, 600.0f), Vector2D(150.0f, 650.0f) });

	float speed = 300.0f + m_difficulty * 50.0f;

	m_formation =
	{ { { Enemy::BEE, Enemy::RIGHT, speed, Vector2D(100.0f, 80.0f), this }, 0.0f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(100.0f, 120.0f), this }, 0.35f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(100.0f, 160.0f), this }, 0.7f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(100.0f, 200.0f), this }, 1.05f, false },

	{ { Enemy::BUG, Enemy::RIGHT, speed,  Vector2D(140.0f, 80.0f), this }, 0.0f, false },
	{ { Enemy::BUG, Enemy::RIGHT, speed,  Vector2D(140.0f, 120.0f), this }, 0.35f, false },
	{ { Enemy::BUG, Enemy::RIGHT, speed,  Vector2D(140.0f, 160.0f), this }, 0.7f, false },
	{ { Enemy::BUG, Enemy::RIGHT , speed, Vector2D(140.0f, 200.0f), this }, 1.05f, false },

	{ { Enemy::BOSS, Enemy::RIGHT, speed,  Vector2D(180.0f, 80.0f), this },	 1.4f, false },
	{ { Enemy::BOSS, Enemy::RIGHT, speed,  Vector2D(180.0f, 120.0f), this }, 1.75f, false },
	{ { Enemy::BOSS, Enemy::RIGHT, speed,  Vector2D(180.0f, 160.0f), this }, 2.1f, false },
	{ { Enemy::BOSS, Enemy::RIGHT , speed, Vector2D(180.0f, 200.0f), this }, 2.45f, false },

	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(220.0f, 80.0f), this },	 1.4f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(220.0f, 120.0f), this }, 1.75f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(220.0f, 160.0f), this }, 2.1f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(220.0f, 200.0f), this }, 2.45f, false },

	{ { Enemy::BUG, Enemy::RIGHT, speed,  Vector2D(260.0f, 80.0f), this },  2.8f, false },
	{ { Enemy::BUG, Enemy::RIGHT, speed,  Vector2D(260.0f, 120.0f), this }, 3.15f, false },
	{ { Enemy::BUG, Enemy::RIGHT, speed,  Vector2D(260.0f, 160.0f), this }, 3.5f, false },
	{ { Enemy::BUG, Enemy::RIGHT, speed,  Vector2D(260.0f, 200.0f), this }, 3.85f, false },

	{ { Enemy::BOSS, Enemy::RIGHT, speed,  Vector2D(300.0f, 80.0f), this },  2.8f, false },
	{ { Enemy::BOSS, Enemy::RIGHT, speed,  Vector2D(300.0f, 120.0f), this }, 3.15f, false },
	{ { Enemy::BOSS, Enemy::RIGHT, speed,  Vector2D(300.0f, 160.0f), this }, 3.5f, false },
	{ { Enemy::BOSS, Enemy::RIGHT, speed,  Vector2D(300.0f, 200.0f), this }, 3.85f, false },


	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(700.0f, 80.0f), this }, 0.0f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(700.0f, 120.0f), this }, 0.35f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(700.0f, 160.0f), this }, 0.7f, false },
	{ { Enemy::BEE, Enemy::RIGHT, speed,   Vector2D(700.0f, 200.0f), this }, 1.05f, false },

	{ { Enemy::BUG, Enemy::LEFT, speed,  Vector2D(660.0f, 80.0f), this }, 0.0f, false },
	{ { Enemy::BUG, Enemy::LEFT, speed,  Vector2D(660.0f, 120.0f), this }, 0.35f, false },
	{ { Enemy::BUG, Enemy::LEFT, speed,  Vector2D(660.0f, 160.0f), this }, 0.7f, false },
	{ { Enemy::BUG, Enemy::LEFT , speed, Vector2D(660.0f, 200.0f), this }, 1.05f, false },
						   
	{ { Enemy::BOSS,Enemy::LEFT, speed,  Vector2D(620.0f, 80.0f), this },	 1.4f, false },
	{ { Enemy::BOSS,Enemy::LEFT, speed,  Vector2D(620.0f, 120.0f), this }, 1.75f, false },
	{ { Enemy::BOSS,Enemy::LEFT, speed,  Vector2D(620.0f, 160.0f), this }, 2.1f, false },
	{ { Enemy::BOSS,Enemy::LEFT , speed, Vector2D(620.0f, 200.0f), this }, 2.45f, false },
						   
	{ { Enemy::BEE, Enemy::LEFT, speed,   Vector2D(580.0f, 80.0f), this },	 1.4f, false },
	{ { Enemy::BEE, Enemy::LEFT, speed,   Vector2D(580.0f, 120.0f), this }, 1.75f, false },
	{ { Enemy::BEE, Enemy::LEFT, speed,   Vector2D(580.0f, 160.0f), this }, 2.1f, false },
	{ { Enemy::BEE, Enemy::LEFT, speed,   Vector2D(580.0f, 200.0f), this }, 2.45f, false },
						   
	{ { Enemy::BUG, Enemy::LEFT, speed,  Vector2D(540.0f, 80.0f), this },  2.8f, false },
	{ { Enemy::BUG, Enemy::LEFT, speed,  Vector2D(540.0f, 120.0f), this }, 3.15f, false },
	{ { Enemy::BUG, Enemy::LEFT, speed,  Vector2D(540.0f, 160.0f), this }, 3.5f, false },
	{ { Enemy::BUG, Enemy::LEFT, speed,  Vector2D(540.0f, 200.0f), this }, 3.85f, false },
						   
	{ { Enemy::BOSS,Enemy::LEFT, speed,  Vector2D(500.0f, 80.0f), this },  2.8f, false },
	{ { Enemy::BOSS,Enemy::LEFT, speed,  Vector2D(500.0f, 120.0f), this }, 3.15f, false },
	{ { Enemy::BOSS,Enemy::LEFT, speed,  Vector2D(500.0f, 160.0f), this }, 3.5f, false },
	{ { Enemy::BOSS,Enemy::LEFT, speed,  Vector2D(500.0f, 200.0f), this }, 3.85f, false },
	};

	ClearEnemies();
}

void Formation::Destroy()
{

}

void Formation::Update()
{
	m_timer = m_timer + Timer::Instance()->DeltaTime();
	for (Info& info : m_formation)
	{
		if (info.isActive == false && m_timer > info.enterTime)
		{
			info.isActive = true;
			Enemy* enemy = m_scene->AddEntity<Enemy>();
			enemy->Create(info.enemyInfo);
			enemy->SetTag("enemy");
			m_enemies.push_back(enemy);
		}
	}
}

const Formation::Path& Formation::GetRandomAttackPath()
{
	size_t index = rand() % m_attackPaths.size();
	return m_attackPaths[index];
}

