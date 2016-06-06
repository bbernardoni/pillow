#include "animObject.h"

AnimObject::AnimObject(Sprite sp, Animation* anim, bool looped) :
	sprite(sp),
	animation(anim), isLooped(looped)
{
	speed = 1.0f;
	isPaused = true;
}


void AnimObject::setSprite(Sprite sp){
	sprite = sp;
}

void AnimObject::setAnimation(Animation* anim){
	if (animation == anim){
		animation = anim;
		if (animation)
			animation->reset();
	}
}

void AnimObject::update(Time deltaTime){
	if (animation && !isPaused){
		if (animation->update(sprite, deltaTime*speed)){
			if (!isLooped)
				isPaused = true;
		}
	}
}

void AnimObject::draw(RenderTarget& rt){
	rt.draw(sprite);
}

void AnimObject::setLooped(bool looped){
	isLooped = looped;
}

void AnimObject::setSpeed(float animSpeed){
	speed = animSpeed;
}

void AnimObject::restart(){
	isPaused = false;
	if (animation)
		animation->reset();
}

void AnimObject::play(){
	isPaused = false;
}

void AnimObject::pause(){
	isPaused = true;
}

void AnimObject::stop(){
	isPaused = true;
	if (animation)
		animation->reset();
}

bool AnimObject::paused(){
	return isPaused;
}