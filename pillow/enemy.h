#ifndef ENEMY_H_
#define ENEMY_H_

#include "character.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy: public Character
{
public:
	Enemy(Vector2f pos);

	void update(Time deltaTime);
	
	float getDamage(EntityID source);
	Time getInvTime(EntityID source);

private:

};

#endif