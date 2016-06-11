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

Vector2f Character::getWASDvel(){
	Vector2f vel;

	if (Keyboard::isKeyPressed(Keyboard::W)){
		vel.y -= charaSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)){
		vel.x -= charaSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)){
		vel.y += charaSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)){
		vel.x += charaSpeed;
	}

	return vel;
}

Vector2f Character::getArrowsVel(){
	Vector2f vel;

	if (Keyboard::isKeyPressed(Keyboard::Up)){
		vel.y -= charaSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)){
		vel.x -= charaSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)){
		vel.y += charaSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)){
		vel.x += charaSpeed;
	}

	return vel;
}