#ifndef ENEMY_H_
#define ENEMY_H_

#include "entity.h"
#include "animation.h"
#include "animObject.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy: public Entity
{
public:
	Enemy(Vector2f pos);

    void init();
	void update(Time deltaTime);
    void draw(RenderTarget& rt);

	void takeDamage(int source);
private:
	const float playerSpeed;

	AnimObject body;

};

#endif