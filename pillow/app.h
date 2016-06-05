#ifndef APP_H_
#define APP_H_

#include "game.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class App
{
public:
	App(int argc, char* argv[]);
	int run();

private:
    RenderWindow window;
	Clock clock;
	Game game;

	const Time maxSlice;
	
	void input();
	void update();
	void draw();
};

#endif