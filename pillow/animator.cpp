#include "animator.h"

Animator::Animator(Sprite* sp, Animation* anim){
	setSprite(sp);
	setAnimation(anim);
	speed = 1.0f;
	isPaused = true;
	isLooped = false;
}

void Animator::setAnimation(Animation* anim){
	if (animation != anim){
		animation = anim;
		if (animation)
			animation->reset();
	}
}

void Animator::update(Time deltaTime){
	if (!isPaused && animation && sprite){
		if (animation->update(*sprite, deltaTime*speed)){
			if (!isLooped)
				isPaused = true;
		}
	}
}

void Animator::restart(){
	isPaused = false;
	if (animation)
		animation->reset();
}

void Animator::stop(){
	isPaused = true;
	if (animation)
		animation->reset();
}
