#ifndef ENEMY_H_
#define ENEMY_H_

#include "entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy: public Entity
{
public:
	Enemy(Vector2f pos);

    void init();
	void update(Time deltaTime);

	void takeDamage(EntityID source);
private:
	const float playerSpeed;

};

#endif