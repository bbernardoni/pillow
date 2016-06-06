#include "animObject.h"

AnimObject::AnimObject(Sprite sp, Animation* anim, bool looped) :
	sprite(sp),
	animation(anim), isLooped(looped)
{
	speed = 1.0f;
	isPaused = true;
	damaging = false;
	damagable = false;
}

void AnimObject::addBoundingBox(FloatRect boundingRect){
	boxes.push_back(BoundingBox(boundingRect, &sprite));
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

void AnimObject::restart(){
	isPaused = false;
	if (animation)
		animation->reset();
}

void AnimObject::stop(){
	isPaused = true;
	if (animation)
		animation->reset();
}

bool AnimObject::collides(AnimObject& other){
	for (BoundingBox thisBox : boxes){
		for (BoundingBox otherBox : other.boxes){
			if (thisBox.collides(otherBox))
				return true;
		}
	}
	return false;
}