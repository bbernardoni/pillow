#include "character.h"

Character::Character(const Texture& texture, Animation* anim, Vector2f pos, float speed) :
	charaSpeed(speed),
	Entity(texture, anim)
{
	construct(pos);
}

Character::Character(const Texture& texture, const IntRect& rectangle, Animation* anim, Vector2f pos, float speed) :
	charaSpeed(speed),
	Entity(texture, rectangle, anim)
{
	construct(pos);
}

void Character::construct(Vector2f pos){
	sprite.setPosition(pos);
	damagable = true;
}

void Character::takeDamage(EntityID source){
	if (invTimer.getElapsedTime() < invTime)
		return;
	invTimer.restart();

	//Color c = sprite.getColor();
	//c.b = (c.b + 100) % 255;
	//sprite.setColor(c);
	//invTime = seconds(0.4f);
}