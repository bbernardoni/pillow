#ifndef ENTITY_H_
#define ENTITY_H_

#include "animator.h"
#include "boundingBox.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using std::vector;

class Entity
{
public:
	Entity(const Texture& texture, Animation* anim = NULL);
	Entity(const Texture& texture, const IntRect& rectangle, Animation* anim = NULL);

	virtual void update(Time deltaTime) = 0;
	void draw(RenderTarget& rt);

	void addBoundingBox(FloatRect boundingRect);

	enum Dir { Right, UpRight, Up, UpLeft, Left, DownLeft, Down, DownRight, NoDir };
	static Dir getDir(Vector2f vel);
	static float getDirAngle(Dir dir);
	void setDirAngle(Vector2f vel);
	
	enum EntityID { sword, player, enemy };
	virtual void takeDamage(EntityID source) = 0;
	void collision(Entity& other);
	
protected:
	Dir dir;
	bool visible;

	Sprite sprite;
	Animator anim;

	EntityID id;
	vector<BoundingBox> boxes;
	bool damaging;
	bool damagable;

private:
	void construct();
};

#endif