#ifndef BOUNDING_BOX_H_
#define BOUNDING_BOX_H_

#include <SFML/Graphics.hpp>
using namespace sf;

class BoundingBox
{
public:
    BoundingBox(FloatRect rectangle, Sprite* sp);

	void updatePoints();
    void projectOntoAxis(const Vector2f& axis, float& min, float& max) const;
	bool collides(BoundingBox& other);

	Vector2f points[4];

private:
	Sprite* sprite;
	FloatRect rect;
};

#endif