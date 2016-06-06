#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"
#include "animation.h"
#include "animObject.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Player: public Entity
{
public:
    Player();

    void init();
	void update(Time deltaTime);
    void draw(RenderTarget& rt);

private:
	const float playerSpeed;

	AnimObject body;

	Animation swingRight;
	AnimObject sword;

};

#endif