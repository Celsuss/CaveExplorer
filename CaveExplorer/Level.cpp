#include "Level.h"
#include "Menu.h"
#include "Game.h"
#include "Actor.h"
#include "Player.h"

Level::Level(){
	m_State = State::Level;
	m_Cave.generateCave(this);
	createActor(new Player(sf::Vector2f(100, 100)));
	//m_Actors.push_back(new Player(sf::Vector2f(100, 100)));
}

Level::~Level(){}

void Level::enter() {

}

void Level::update(Game* game, float dt) {
	m_Cave.draw();
	GameState::update(game, dt);
}

void Level::exit() {

}