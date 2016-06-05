#include "animator.h"

Animator::Animator(Animation* anim, bool looped):
	animation(anim), isLooped(looped)
{
	speed = 1.0f;
	isPaused = true;
}

void Animator::setAnimation(Animation* anim){
	if (animation == anim){
		animation = anim;
		if (animation)
			animation->reset();
	}
}

void Animator::update(Sprite& sprite, Time deltaTime){
	if (animation && !isPaused){
		if (animation->update(sprite, deltaTime*speed)){
			if (!isLooped)
				isPaused = true;
		}
	}
}

void Animator::setLooped(bool looped){
	isLooped = looped;
}

void Animator::setSpeed(float animSpeed){
	speed = animSpeed;
}

void Animator::restart(){
	isPaused = false;
	if (animation)
		animation->reset();
}

void Animator::play(){
	isPaused = false;
}

void Animator::pause(){
	isPaused = true;
}

void Animator::stop(){
	isPaused = true;
	if (animation)
		animation->reset();
}

bool Animator::paused(){
	return isPaused;
}