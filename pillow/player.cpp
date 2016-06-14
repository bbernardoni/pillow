#include "player.h"

Player::Player() :
	Character(Texture(), IntRect(0, 0, 50, 100), NULL, Vector2f(400, 400))
{
	id = player;
	addBoundingBox(FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
	hp = 100.0f;
}

void Player::update(Time deltaTime){
	float dt = deltaTime.asSeconds();
	Vector2f vel = getWASDvel() * dt;

	setDirAngle(vel);
	sprite.move(vel);

	Uint8 color = (Uint8) (hp / 100.0f * 255.0f);
	color = ((color % 256) + 256) % 256;
	sprite.setColor(Color(color, 0, 0));

	if(weapon){
		weapon->move(vel);

		if (Keyboard::isKeyPressed(Keyboard::J)){
			weapon->swing();
		}
	}
}
