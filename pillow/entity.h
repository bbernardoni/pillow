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
	static Dir getDir(Vector2f vel);

	virtual void takeDamage(int source) = 0; // source should be a enum eventually
	void collision(Entity& enemy);
	
protected:
	Dir dir;

};

#endif