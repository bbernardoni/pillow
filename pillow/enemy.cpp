#include "enemy.h"

Enemy::Enemy(Vector2f pos) :
	playerSpeed(200),
	Entity(Texture(),IntRect(0, 0, 50, 100))
{
	id = enemy;
	sprite.setColor(Color::Green);
	sprite.setOrigin(25, 50);
	sprite.setPosition(pos);
	damaging = true;
	damagable = true;
	addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}

void Enemy::init(){
	dir = Right;
}

void Enemy::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel;
	if (Keyboard::isKeyPressed(Keyboard::Up)){
		vel.y -= playerSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		vel.x -= playerSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)){
		vel.y += playerSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::Right)){
		vel.x += playerSpeed;
	}
	vel *= dt;

	Dir newDir = getDir(vel);
	if (newDir != NoDir)
		dir = newDir;

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