#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "animation.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using std::vector;

class Animator
{
public:
	Animator(Sprite* sp = NULL, Animation* anim = NULL);
	
	void setSprite(Sprite* sp){ sprite = sp; }
	void setAnimation(Animation* anim);
	Animation* getAnimation() { return animation; }

	void update(Time deltaTime);

	void setLooped(bool looped){ isLooped = looped; }
	void setSpeed(float animSpeed){ speed = animSpeed; }
	void play(){ isPaused = false; }
	void pause(){ isPaused = true; }
	void restart();
	void stop();

	bool paused(){ return isPaused; }

private:
	Animation* animation;
	Sprite* sprite;

	float speed;
	bool isPaused;
	bool isLooped;
};

#endif