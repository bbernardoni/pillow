#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"
#include "animation.h"
#include "animator.h"
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
	Dir dir;
	const float playerSpeed;

	Sprite body;

	Sprite sword;
	Animation swingRight;
	Animator animator;

};

#endif