#include "animation.h"

AnimFrame::AnimFrame(IntRect textureRect, Time frameLength) :
	texRect(textureRect), 
	frameLen(frameLength) 
{
	changeTex = true;
	transform = false;
}

AnimFrame::AnimFrame(Vector2f trans, float rot, Vector2f scl, Time frameLength) :
	translate(trans), 
	rotate(rot), 
	scale(scl), 
	frameLen(frameLength) 
{
	changeTex = false;
	transform = true;
}

AnimFrame::AnimFrame(IntRect textureRect, Vector2f trans, float rot, Vector2f scl, Time frameLength) :
	texRect(textureRect), 
	translate(trans), 
	rotate(rot), 
	scale(scl), 
	frameLen(frameLength) 
{
	changeTex = true;
	transform = true;
}


Animation::Animation(Time frameLength):
	frameLen(frameLength)
{
	reset();
}

void Animation::addFrame(AnimFrame animFrame){
	frames.push_back(animFrame);
}

bool Animation::update(Sprite& sprite, Time deltaTime){
	for (AnimFrame curFrame = frames[frame]; frameTime + deltaTime > getFrameLen(curFrame); curFrame = frames[frame]){
		Time totalLen = getFrameLen(curFrame);
		Time animLen = totalLen - frameTime;
		if (curFrame.transform){
			float ratio = animLen / totalLen;
			sprite.rotate(curFrame.rotate * ratio);
			Vector2f scaleBy(pow(curFrame.scale.x, ratio), pow(curFrame.scale.y, ratio));
			sprite.scale(scaleBy);
			sprite.move(curFrame.translate * ratio);
		}
		deltaTime -= animLen;
		frameTime = Time::Zero;
		frame++;
		if (frame >= frames.size()){
			reset();
			if (curFrame.changeTex){
				sprite.setTextureRect(curFrame.texRect);
			}
			return true;
		}
	}
	AnimFrame curFrame = frames[frame];
	Time totalLen = getFrameLen(curFrame);
	if (curFrame.transform){
		float ratio = deltaTime / totalLen;
		sprite.rotate(curFrame.rotate * ratio);
		Vector2f scaleBy(pow(curFrame.scale.x, ratio), pow(curFrame.scale.y, ratio));
		sprite.scale(scaleBy);
		sprite.move(curFrame.translate * ratio);
	}
	if (curFrame.changeTex){
		sprite.setTextureRect(curFrame.texRect);
	}
	frameTime += deltaTime;
	return false;
}

void Animation::reset(){
	frame = 0;
	frameTime = Time::Zero;
}

Time Animation::getFrameLen(AnimFrame af){
	Time curFrameLen = af.frameLen;
	if (curFrameLen == Time::Zero)
		return frameLen;
	return curFrameLen;
}