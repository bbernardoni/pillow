#ifndef ANIM_OBJECT_H_
#define ANIM_OBJECT_H_

#include "animation.h"
#include "boundingBox.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using std::vector;

class AnimObject
{
public:
	AnimObject(Sprite sp, Animation* anim = NULL, bool looped = false);

	void addBoundingBox(FloatRect boundingRect);
	void setSprite(Sprite sp){ sprite = sp; }
	void setAnimation(Animation* anim);

	void update(Time deltaTime);
	void draw(RenderTarget& rt);

	void setDamaging(bool dmging)  { damaging = dmging; }
	void setDamagable(bool dmgable){ damagable = dmgable; }

	bool getDamaging() { return damaging; }
	bool getDamagable(){ return damagable; }

	void setLooped(bool looped){ isLooped = looped; }
	void setSpeed(float animSpeed){ speed = animSpeed; }
	void play(){ isPaused = false; }
	void pause(){ isPaused = true; }
	void restart();
	void stop();

	bool paused(){ return isPaused; }
	bool collides(AnimObject& other);

	Sprite sprite;

private:
	Animation* animation;

	float speed;
	bool isPaused;
	bool isLooped;

	vector<BoundingBox> boxes;
	bool damaging;
	bool damagable;
};

#endif