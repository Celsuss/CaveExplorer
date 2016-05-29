#include "Game.h"
#include "CollisionManager.h"
#include "GraphicsManager.h"
#include "SFML/System.hpp"
#include "GameState.h"
#include "Level.h"
#include "Menu.h"

Game::Game(){
	m_pCurrentState = nullptr;
	m_pPreviousState = nullptr;
	m_pGlobalState = nullptr;
	m_EndGame = false;
}

Game::~Game(){}

void Game::startGame(){
	update();
}

void Game::setGameState(GameState::State state) {
	if (m_pPreviousState)
		delete m_pPreviousState;

	switch (state) {
	case GameState::State::Level:
		m_pPreviousState = m_pCurrentState;
		m_pCurrentState = new Level();
		//m_pCurrentState = std::make_unique<Level>(Level());
		break;
	case GameState::State::Menu:
		m_pPreviousState = m_pCurrentState;
		m_pCurrentState = new Menu();
		//m_pCurrentState = std::make_unique<Menu>(Menu());
		break;
	}
}

void Game::setGameState(GameState* state) {
	m_pPreviousState = m_pCurrentState;
	m_pCurrentState = state;
}

GameState* Game::getGameState() {
	return m_pCurrentState;
}

void Game::setEndGame(bool end) {
	m_EndGame = end;
}

void Game::update(){
	GraphicsManager::getInstance()->createWindow();
	setGameState(new Menu());
	setGameState(new Level());

	while (GraphicsManager::getInstance()->getWindow()->isOpen() && !m_EndGame){
		sf::Time nowTime = m_Clock.getElapsedTime();
		//deltaT = nowTime.asMilliseconds() - m_LastTime.asMilliseconds();
		float deltaT = nowTime.asSeconds() - m_LastTime.asSeconds();
		m_LastTime = nowTime;

		handleEvents();
		m_pCurrentState->update(this, deltaT);
		CollisionManager::getInstance()->collisionDetection();
		//TimeManager::update();
		//InputManager::update();
		GraphicsManager::getInstance()->update();
	}
}

void Game::handleEvents(){
	sf::Event event;
	while (GraphicsManager::getInstance()->getWindow()->pollEvent(event)){
		if (event.type == sf::Event::Closed)
			GraphicsManager::getInstance()->getWindow()->close();
	}
}
