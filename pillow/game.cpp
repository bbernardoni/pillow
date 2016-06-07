#include "game.h"

Game::Game(RenderWindow& rw):
	window(rw),
	enemy(Vector2f(1000, 450))
{

}

void Game::init()
{
	player.init();
	enemy.init();
	sword.init();
}

void Game::processEvent(Event event)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
		window.close();
}

void Game::update(Time deltaTime)
{
	player.update(deltaTime);
	enemy.update(deltaTime);
	sword.update(deltaTime);
	player.collision(enemy);
	sword.collision(enemy);
}

void Game::draw()
{
	player.draw(window);                                                             
	enemy.draw(window);                                                            
	sword.draw(window);
}
