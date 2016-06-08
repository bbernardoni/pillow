#ifndef SWORD_H_
#define SWORD_H_

#include "entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Sword: public Entity
{
public:
    Sword();

    void init();
	void update(Time deltaTime);

	void takeDamage(EntityID source){}
	void move(Vector2f vel);
	void swing();

private:
	Animation swingRight;

};

#endif