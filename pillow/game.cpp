#include "game.h"

Game::Game(RenderWindow& rw):
	window(rw)
{

}

void Game::init()
{
	player.init();
}

void Game::processEvent(Event event)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
		window.close();
}

void Game::update(Time deltaTime)
{
	player.update(deltaTime);
}

void Game::draw()
{
	player.draw(window);
}
