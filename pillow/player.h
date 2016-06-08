#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"
#include "sword.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Player: public Entity
{
public:
    Player();

    void init();
	void update(Time deltaTime);

	void takeDamage(EntityID source);
	void setWeapon(Sword* wp){ weapon = wp; }
private:
	const float playerSpeed;
	Sword* weapon;
};

#endif