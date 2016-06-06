#ifndef ANIM_OBJECT_H_
#define ANIM_OBJECT_H_

#include "animation.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class AnimObject
{
public:
	AnimObject(Sprite sp, Animation* anim = NULL, bool looped = false);

	void setSprite(Sprite sp);
	void setAnimation(Animation* anim);

	void update(Time deltaTime);
	void draw(RenderTarget& rt);

	void setLooped(bool looped);
	void setSpeed(float animSpeed);
	void restart();
	void play();
	void pause();
	void stop();

	bool paused();

	Sprite sprite;

private:
	Animation* animation;

	float speed;
	bool isPaused;
	bool isLooped;

	//boxes
	//damaging/able
};

#endif