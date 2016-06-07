#include "boundingBox.h"

BoundingBox::BoundingBox(FloatRect rectangle, Sprite* sp):
	rect(rectangle), sprite(sp) {}

void BoundingBox::updatePoints() {
    Transform trans = sprite->getTransform();
    IntRect local = sprite->getTextureRect();
	float left = local.width*rect.left, right  = local.width*(rect.left+rect.width);
	float top  = local.height*rect.top, bottom = local.height*(rect.top+rect.height);

	points[0] = trans.transformPoint(left, top);
    points[1] = trans.transformPoint(right, top);
    points[2] = trans.transformPoint(right, bottom);
    points[3] = trans.transformPoint(left, bottom);
}

void BoundingBox::projectOntoAxis(const Vector2f& axis, float& min, float& max) const {
    min = (points[0].x*axis.x+points[0].y*axis.y);
    max = min;
    for (int j = 1; j<4; j++)
    {
        float projection = (points[j].x*axis.x+points[j].y*axis.y);

        if (projection<min)
            min=projection;
        if (projection>max)
            max=projection;
    }
}

bool BoundingBox::collides(BoundingBox& other) {
    updatePoints();
    other.updatePoints();

    Vector2f axes[4] = {
		Vector2f(points[1].x-points[0].x, points[1].y-points[0].y),
        Vector2f(points[1].x-points[2].x, points[1].y-points[2].y),
        Vector2f(other.points[0].x-other.points[3].x, other.points[0].y-other.points[3].y),
        Vector2f(other.points[0].x-other.points[1].x, other.points[0].y-other.points[1].y)
    };

    for (int i = 0; i<4; i++)
    {
        float MinBB1, MaxBB1, MinBB2, MaxBB2;

        projectOntoAxis(axes[i], MinBB1, MaxBB1);
        other.projectOntoAxis(axes[i], MinBB2, MaxBB2);

        if (!(MinBB2<=MaxBB1 && MaxBB2>=MinBB1))
            return false;
    }
    return true;
}