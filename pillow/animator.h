#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "animation.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Animator
{
public:
	Animator(Animation* anim = NULL, bool looped = false);

	void setAnimation(Animation* anim);

	void update(Sprite& sprite, Time deltaTime);

	void setLooped(bool looped);
	void setSpeed(float animSpeed);
	void restart();
	void play();
	void pause();
	void stop();

	bool paused();

private:
	Animation* animation;

	float speed;
	bool isPaused;
	bool isLooped;
};

#endif