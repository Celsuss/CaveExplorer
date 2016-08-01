#include "Level.h"
#include "Rat.h"
#include "Menu.h"
#include "Game.h"
#include "Actor.h"
#include "Player.h"
#include "GridManager.h"
#include "CollisionManager.h"

Level::Level(){
	m_State = State::Level;
	GridManager::getInstance()->initialize();
	//createActor(new Player(sf::Vector2f(100, 100)));
	m_Actors.push_back(new Player(sf::Vector2f(100, 100)));
	m_Actors.push_back(new Rat(sf::Vector2f(300, 300)));
}

Level::~Level(){}

void Level::enter() {
	GameState::enter();
}

void Level::update(const Game* game, const float dt) {
	deleteDeadActors();
	GridManager::getInstance()->update();
	//GameState::update(game, dt);
	for (auto it : m_Actors){
		it->update(dt);
		it->draw();
	}

	CollisionManager::getInstance()->collisionDetection(this);
}

void Level::exit() {
	GameState::exit();
}