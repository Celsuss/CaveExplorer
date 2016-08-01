#include "GameState.h"
#include "CollisionManager.h"
#include "UIButton.h"
#include "Player.h"
#include "Level.h"
#include "Actor.h"
#include "Item.h"
#include "Game.h"

GameState::GameState(){}

GameState::~GameState(){}

void GameState::enter() {

}

void GameState::update(const Game* game, const float dt) {
	/*Player* player = game->getGameState()->getPlayer();
	for (auto i = m_Items.begin(); i != m_Items.end(); i++) {
		if ((*i)->isPressed(player->getPosition())) {
			int kalle = 0;
		}
		(*i)->update(dt);
		(*i)->draw();
	}
	for (auto i = m_Actors.begin(); i != m_Actors.end(); i++) {
		(*i)->update(dt);
		(*i)->draw();
	}
	for (auto i = m_UIButtons.begin(); i != m_UIButtons.end(); i++) {
		if ((*i)->isPressed()) {
			handleButtonEvent(game, (*i)->getEvent());
		}
		(*i)->draw();
	}*/
}

void GameState::exit() {
	for (auto it = m_Actors.begin(); it != m_Actors.end();){
		CollisionManager::getInstance()->removeActorFromCollision(*it);
		delete *it;
		it = m_Actors.erase(it);
	}
	for (auto it = m_Items.begin(); it != m_Items.end();){
		delete *it;
		it = m_Items.erase(it);
	}
	for (auto it = m_UIButtons.begin(); it != m_UIButtons.end();){
		delete *it;
		it = m_UIButtons.erase(it);
	}
}

void GameState::createActor(Actor* actor) {
	switch (actor->getActorType())
	{
	case Actor::Player:
		m_Player = (Player*)actor;
	case Actor::Friendly:
	case Actor::Hostile: {
		m_Actors.push_back(actor);
	}
	break;

	case Actor::Item: {
		m_Items.push_back((Item*)actor);
	}
	break;

	default:
		break;
	}
}

Player* GameState::getPlayer() {
	return m_Player;
}

GameState::ActorVector& GameState::getActors(){
	return m_Actors;
}

void GameState::handleButtonEvent(Game* game, UIButton::Event e) {
	switch (e) {
	case UIButton::Start: {
		game->setGameState(State::Level);
	}
	break;
	case UIButton::Exit: {
		game->setEndGame(true);
	}
	break;
	default: {}
	break;
	}
}

void GameState::deleteDeadActors(){
	auto it = m_Actors.begin();
	while (it != m_Actors.end()){
		if (!(*it)->getIsAlive()){
			CollisionManager::getInstance()->removeActorFromCollision(*it);
			delete *it;
			it = m_Actors.erase(it);
		}
		else
			it++;
	}
}