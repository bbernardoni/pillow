#ifndef ENEMY_H_
#define ENEMY_H_

#include "character.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy: public Character
{
public:
	Enemy(Vector2f pos);

    void init();
	void update(Time deltaTime);

	void takeDamage(EntityID source);

private:

};

#endif