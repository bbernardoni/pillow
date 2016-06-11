#include "enemy.h"

Enemy::Enemy(Vector2f pos) :
	Character(Texture(), IntRect(0, 0, 50, 100), NULL, pos)
{
	id = enemy;
	sprite.setColor(Color::Green);
	damaging = true;
	addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}

void Enemy::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel = getArrowsVel() * dt;

	setDirAngle(vel);
	sprite.move(vel);
}

void Enemy::takeDamage(EntityID source){
	if(invTimer.getElapsedTime() < invTime)
		return;
	invTimer.restart();
	switch(source){
	case sword:
		Color c = sprite.getColor();
		c.b = (c.b + 100) % 255;
		sprite.setColor(c);
		invTime = seconds(0.4f);
		break;
	}
}