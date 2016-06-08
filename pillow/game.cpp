#include "game.h"

Game::Game(RenderWindow& rw):
	window(rw)
{
	enimies.push_back(new Enemy(Vector2f(1000, 450)));
	enimies.push_back(new Enemy(Vector2f(800, 350)));

	player.setWeapon(&sword);
}

Game::~Game(){
	for(size_t i=0; i < enimies.size(); i++){
		delete enimies[i];
	}
}

void Game::init()
{
	player.init();
	sword.init();
	for(size_t i=0; i < enimies.size(); i++){
		enimies[i]->init();
	}
}

void Game::processEvent(Event event)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
		window.close();
}

void Game::update(Time deltaTime)
{
	player.update(deltaTime);
	sword.update(deltaTime);
	for(size_t i=0; i < enimies.size(); i++){
		enimies[i]->update(deltaTime);
	}
	for(size_t i=0; i < enimies.size(); i++){
		enimies[i]->collision(player);
		enimies[i]->collision(sword);
	}
}

void Game::draw()
{
	player.draw(window);
	sword.draw(window);
	for(size_t i=0; i < enimies.size(); i++){
		enimies[i]->draw(window);
	}
}
