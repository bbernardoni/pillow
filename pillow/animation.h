#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <math.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using std::vector;

struct AnimFrame
{
	AnimFrame(IntRect textureRect, Time frameLength = Time::Zero);
	AnimFrame(Vector2f trans, float rot = 0.0f, Vector2f scl = Vector2f(1, 1), Time frameLength = Time::Zero);
	AnimFrame(IntRect textureRect, Vector2f trans, float rot = 0.0f, Vector2f scl = Vector2f(1, 1), Time frameLength = Time::Zero);

	bool changeTex;
	IntRect texRect;

	bool transform;
	Vector2f translate;
	Vector2f scale;
	float rotate;

	Time frameLen;
};

class Animation
{
public:
	Animation(Time frameLength = seconds(1.0));
	void addFrame(AnimFrame animFrame);

	bool update(Sprite& sprite, Time deltaTime);
	void reset();

private:
	vector<AnimFrame> frames;
	unsigned int frame;
	Time frameTime;
	Time frameLen;

	Time getFrameLen(AnimFrame af);
};

#endif