#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Character : public Entity
{
public:
	Character(const Texture& texture, Animation* anim = NULL, Vector2f pos = Vector2f(0.0f, 0.0f), float speed = 200);
	Character(const Texture& texture, const IntRect& rectangle, Animation* anim = NULL, Vector2f pos = Vector2f(0.0f, 0.0f), float speed = 200);

	void takeDamage(EntityID source);

protected:
	Vector2f getWASDvel();
	Vector2f getArrowsVel();

	const float charaSpeed;

	Clock invTimer;
	Time invTime;

private:
	void construct(Vector2f pos);

};

#endif