#include "Level.h"
#include "Menu.h"
#include "Game.h"
#include "Actor.h"
#include "Player.h"
#include "GridManager.h"

Level::Level(){
	m_State = State::Level;
	GridManager::getInstance()->initialize();
	createActor(new Player(sf::Vector2f(100, 100)));
}

Level::~Level(){}

void Level::enter() {

}

void Level::update(Game* game, float dt) {
	GridManager::getInstance()->update();
	GameState::update(game, dt);
}

void Level::exit() {

}