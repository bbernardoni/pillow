#include "player.h"

Player::Player() :
	Character(Texture(), IntRect(0, 0, 50, 100), NULL, Vector2f(400, 400))
{
	id = player;
	sprite.setColor(Color::Red);
	addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}

void Player::init(){
	dir = Right;
}

void Player::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel;
	if(Keyboard::isKeyPressed(Keyboard::W)){
		vel.y -= charaSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::A)){
		vel.x -= charaSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::S)){
		vel.y += charaSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::D)){
		vel.x += charaSpeed;
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
	if(invTimer.getElapsedTime() < invTime)
		return;
	invTimer.restart();
	switch(source){
	case enemy:
		Color c = sprite.getColor();
		c.b = (c.b + 10) % 255;
		sprite.setColor(c);
		invTime = seconds(0.05f);
		break;
	}
}