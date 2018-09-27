#pragma once
#include "engine.h"
#include "entity.h"

class ENGINE_API UIText : public Entity
{
public:
	UIText(Scene* scene, const ID& id) : Entity(scene, id) {}
	~UIText() {}

	void Create(const Vector2D& position);
	void Update();
};