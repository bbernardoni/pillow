#include "player.h"

Player::Player() :
	playerSpeed(200),
	Entity(Texture(), IntRect(0, 0, 50, 100))
{
	id = player;
	sprite.setColor(Color::Red);
	sprite.setOrigin(25, 50);
	damagable = true;
	addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}

void Player::init(){
	dir = Right;
}

void Player::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel;
	if(Keyboard::isKeyPressed(Keyboard::W)){
		vel.y -= playerSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::A)){
		vel.x -= playerSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::S)){
		vel.y += playerSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::D)){
		vel.x += playerSpeed;
	}
	vel *= dt;

	Dir newDir = getDir(vel);
	if (newDir != NoDir)
		dir = newDir;

	sprite.move(vel);
	if(weapon){
		weapon->move(vel);
		if (Keyboard::isKeyPressed(Keyboard::J)){
			weapon->swing();
		}
	}
}

void Player::takeDamage(EntityID source){
	switch(source){
	case enemy:
		Color c = sprite.getColor();
		c.b = (c.b + 10) % 255;
		sprite.setColor(c);
		break;
	}
}