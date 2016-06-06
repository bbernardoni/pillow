#include "entity.h"

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

void Entity::collision(Entity& enemy){
	for (AnimObject* attackObject : parts){
		if (attackObject->getDamaging()){
			for (AnimObject* defendObject : enemy.parts){
				if (defendObject->getDamagable()){
					if (attackObject->collides(*defendObject)){
						enemy.takeDamage(0);
					}
				}
			}
		}
	}
	for (AnimObject* attackObject : enemy.parts){
		if (attackObject->getDamaging()){
			for (AnimObject* defendObject : parts){
				if (defendObject->getDamagable()){
					if (attackObject->collides(*defendObject)){
						takeDamage(1);
					}
				}
			}
		}
	}
}