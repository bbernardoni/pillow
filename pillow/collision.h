#ifndef COLLISION_H_
#define COLLISION_H_

#include "entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Collision
{
	bool testCollision(const Entity& attack, const Entity& defend);
};

#endif