#include "player.h"

Player::Player() :
	playerSpeed(200),
	body(Texture(),IntRect(0, 0, 50, 100)),
	sword(Texture(), IntRect(0, 0, 100, 10)),
	swingRight(seconds(0.2f)),
	animator(&swingRight)
{
	body.setColor(Color::Red);
	body.setOrigin(25, 50);

	sword.setColor(Color::Blue);
	sword.setOrigin(-50, 5);
	sword.rotate(45);

	swingRight.addFrame(AnimFrame(Vector2f(), -90));
	swingRight.addFrame(AnimFrame(Vector2f(),  90));
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
		animator.play();
	}

	Dir newDir = getDir(vel);
	if (newDir != NoDir)
		dir = newDir;

	body.move(vel);
	sword.move(vel);
	animator.update(sword, deltaTime);
}

void Player::draw(RenderTarget& rt){
	rt.draw(body);
	if (!animator.paused())
		rt.draw(sword);
}
