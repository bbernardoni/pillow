#ifndef PLAYER_H_
#define PLAYER_H_

#include "character.h"
#include "sword.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Player: public Character
{
public:
    Player();

	void update(Time deltaTime);

	void takeDamage(EntityID source);
	float getDamage(EntityID source){ return 0.0f; }
	Time getInvTime(EntityID source){ return Time::Zero; }

	void setWeapon(Sword* wp){ weapon = wp; }

private:
	Sword* weapon;

};

#endif