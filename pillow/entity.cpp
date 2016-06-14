#include "entity.h"

Entity::Entity(const Texture& texture, Animation* anim) :
	sprite(texture), anim(&sprite, anim)
{
	construct();
}

Entity::Entity(const Texture& texture, const IntRect& rectangle, Animation* anim) :
	sprite(texture, rectangle), anim(&sprite, anim)
{
	construct();
}

void Entity::construct(){
	dir = Right;
	visible = true;

	IntRect size = sprite.getTextureRect();
	sprite.setOrigin(size.width * 0.5f, size.height * 0.5f);

	damaging = false;
	damagable = false;
}

void Entity::draw(RenderTarget& rt){
	if (visible)
		rt.draw(sprite);
}

void Entity::addBoundingBox(FloatRect boundingRect){
	boxes.push_back(BoundingBox(boundingRect, &sprite));
}

Entity::Dir Entity::getDir(Vector2f vel) {
	if (vel.y > 0){
		if (vel.x > 0)
			return UpRight;
		else if (vel.x < 0)
			return UpLeft;
		else
			return Up;
	}
	else if (vel.y < 0){
		if (vel.x > 0)
			return DownRight;
		else if (vel.x < 0)
			return DownLeft;
		else
			return Down;
	}
	else{
		if (vel.x > 0)
			return Right;
		else if (vel.x < 0)
			return Left;
		else
			return NoDir;
	}
}

float Entity::getDirAngle(Dir dir){
	return dir * 45.0f;
}

void Entity::setDirAngle(Vector2f vel){
	Dir newDir = getDir(vel);
	if (newDir != NoDir)
		dir = newDir;
}

void Entity::collision(Entity& other){
	if(!visible || !other.visible)
		return;
	bool collides = false;
	for(size_t i=0; i < boxes.size(); i++){
		for(size_t j=0; j < other.boxes.size(); j++){
			if (boxes[i].collides(other.boxes[j])){
				collides = true;
				goto testCollisionDone;
			}
		}
	}
testCollisionDone:
	if (collides){
		if (damaging && other.damagable)
			other.takeDamage(getDamage(other.id), getInvTime(other.id));
		if (damagable && other.damaging)
			takeDamage(other.getDamage(id), other.getInvTime(id));
	}
}