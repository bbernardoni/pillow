#include "sword.h"

Sword::Sword() :
	swingRight(seconds(0.2f)),
	Entity(Texture(), IntRect(0, 0, 100, 10), &swingRight)
{
	swingRight.addFrame(AnimFrame(Vector2f(), -90));
	swingRight.addFrame(AnimFrame(Vector2f(), 90));

	id = sword;
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
	anim.update(deltaTime);
    visible = !anim.paused();
}

void Sword::move(Vector2f vel){
	Dir newDir = getDir(vel);
	if (newDir != NoDir && newDir != dir){
		float dAngle = getDirAngle(newDir) - getDirAngle(dir);
		sprite.rotate(dAngle);
		dir = newDir;
	}

	sprite.move(vel);
}

void Sword::swing(){
	anim.play();
}