#include "app.h"
#include <iostream>

App::App(int argc, char* argv[]):
		window(VideoMode(1600, 900), "SFML Test"),
		game(window),
		maxSlice(milliseconds(40))
{
    window.setFramerateLimit(60);
}

int App::run(){
	clock.restart();
	game.init();
	while (window.isOpen()){
        input();
		update();
		draw();
    }

	return 0;
}

void App::input(){
	Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
		else
			game.processEvent(event);
    }
}

void App::update(){
	Time elapsed = clock.restart();
	for (; elapsed > maxSlice; elapsed -= maxSlice)
		game.update(maxSlice);
	game.update(elapsed);
}

void App::draw(){
	window.clear();
    game.draw();
    window.display();
}
