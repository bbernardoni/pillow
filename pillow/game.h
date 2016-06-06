#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "enemy.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Game
{
public:
    Game(RenderWindow& rw);

	void init();
	void processEvent(Event event);
	void update(Time deltaTime);
    void draw();

private:
	RenderWindow& window;
	Player player;
	Enemy enemy;

};

#endif