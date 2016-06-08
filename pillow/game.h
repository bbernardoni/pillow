#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "enemy.h"
#include "sword.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using std::vector;

class Game
{
public:
    Game(RenderWindow& rw);
	~Game();

	void init();
	void processEvent(Event event);
	void update(Time deltaTime);
    void draw();

private:
	RenderWindow& window;
	Player player;
	Sword sword;

	vector<Entity*> enimies;

};

#endif