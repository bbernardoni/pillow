#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
using namespace sf;

class Entity
{
public:
	virtual void init(){}
	virtual void update(Time deltaTime) = 0;
	virtual void draw(RenderTarget& rt) = 0;

	enum Dir { Up, Down, Left, Right, UpLeft, UpRight, DownLeft, DownRight, NoDir };
	template <typename T>
	static Dir getDir(Vector2<T> vel);
	
protected:
	Dir dir;

};

template <typename T>
Entity::Dir Entity::getDir(Vector2<T> vel) {
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

#endif