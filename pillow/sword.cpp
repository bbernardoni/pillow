#include "sword.h"

Sword::Sword() :
	swingRight(seconds(0.2f)),
	Entity(Texture(), IntRect(0, 0, 100, 10), &swingRight)
{
	swingRight.addFrame(AnimFrame(Vector2f(), -90));
	swingRight.addFrame(AnimFrame(Vector2f(), 90));

	sprite.setColor(Color::Blue);
	sprite.setOrigin(-50, 5);
	sprite.rotate(45);
	damaging = true;
	addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}

void Sword::init(){
	dir = Right;
}

void Sword::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel;
	if (Keyboard::isKeyPressed(Keyboard::W)){
		vel.y -= 200;
	}
	if(Keyboard::isKeyPressed(Keyboard::A)){
		vel.x -= 200;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)){
		vel.y += 200;
	}
	if(Keyboard::isKeyPressed(Keyboard::D)){
		vel.x += 200;
	}
	vel *= dt;

	if (Keyboard::isKeyPressed(Keyboard::J)){
		anim.play();
	}

	Dir newDir = getDir(vel);
	if (newDir != NoDir)
		dir = newDir;

	sprite.move(vel);
	anim.update(deltaTime);

    visible = !anim.paused();
}

void Sword::draw(RenderTarget& rt){
	if (visible)
		rt.draw(sprite);
}
