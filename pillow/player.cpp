#include "player.h"

Player::Player() :
	playerSpeed(200),
	body(Sprite(Texture(), IntRect(0, 0, 50, 100))),
	swingRight(seconds(0.2f)),
	sword(Sprite(Texture(), IntRect(0, 0, 100, 10)), &swingRight)
{
	body.sprite.setColor(Color::Red);
	body.sprite.setOrigin(25, 50);

	swingRight.addFrame(AnimFrame(Vector2f(), -90));
	swingRight.addFrame(AnimFrame(Vector2f(), 90));

	sword.sprite.setColor(Color::Blue);
	sword.sprite.setOrigin(-50, 5);
	sword.sprite.rotate(45);
}

void Player::init(){
	dir = Right;
}

void Player::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel;
	if (Keyboard::isKeyPressed(Keyboard::W)){
		vel.y -= playerSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::A)){
		vel.x -= playerSpeed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)){
		vel.y += playerSpeed;
	}
	if(Keyboard::isKeyPressed(Keyboard::D)){
		vel.x += playerSpeed;
	}
	vel *= dt;

	if (Keyboard::isKeyPressed(Keyboard::J)){
		sword.play();
	}

	Dir newDir = getDir(vel);
	if (newDir != NoDir)
		dir = newDir;

	body.sprite.move(vel);
	sword.sprite.move(vel);
	sword.update(deltaTime);
}

void Player::draw(RenderTarget& rt){
	body.draw(rt);
	if (!sword.paused())
		sword.draw(rt);
}

void Player::takeDamage(int source){

}
