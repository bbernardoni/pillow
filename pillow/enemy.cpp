#include "enemy.h"

Enemy::Enemy(Vector2f pos) :
	Character(Texture(), IntRect(0, 0, 50, 100), NULL, pos)
{
	id = enemy;
	damaging = true;
	addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
	hp = 100.0f;
}

void Enemy::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel = getArrowsVel() * dt;

	Uint8 color = (Uint8)(hp / 100.0f * 255.0f);
	sprite.setColor(Color(0, color, 0));

	setDirAngle(vel);
	sprite.move(vel);
}

float Enemy::getDamage(EntityID source){
	return 10;
}

Time Enemy::getInvTime(EntityID source){
	return seconds(0.1f);
}