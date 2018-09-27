#pragma once
#include "vector2d.h"

struct Variant
{
	enum eType
	{
		INTEGER,
		FLOAT,
		BOOL,
		VECTOR2D
	};

	eType type;

	union
	{
		int asInteger;
		float asFloat;
		bool aBool;
		Vector2D asVector2D;
	};

	Variant() {}
};