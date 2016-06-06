#include "enemy.h"

Enemy::Enemy(Vector2f pos) :
	playerSpeed(200),
	body(Sprite(Texture(),IntRect(0, 0, 50, 100)))
{
	body.sprite.setColor(Color::Green);
	body.sprite.setOrigin(25, 50);
	body.sprite.setPosition(pos);
	body.setDamaging(true);
	body.setDamagable(true);
	body.addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
	parts.push_back(&body);
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

	body.sprite.move(vel);
}

void Enemy::draw(RenderTarget& rt){
	body.draw(rt);
}

void Enemy::takeDamage(int source){
	Color c = body.sprite.getColor();
	c.b = (c.b + 10) % 255;
	body.sprite.setColor(c);
}