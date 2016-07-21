#include "Game.h"
#include "Cell.h"
#include "Menu.h"
#include "Level.h"
#include "GameObject.h"
#include "GridManager.h"
#include "SFML/System.hpp"
#include "GraphicManager.h"
#include <iostream>

bool Game::m_Debug = false;

Game::Game(){
	m_pCurrentState = nullptr;
	m_pPreviousState = nullptr;
	m_pGlobalState = nullptr;
	m_EndGame = false;
	m_Restart = false;

	m_DTimerText.setFont(*GraphicManager::getInstance()->getFont());
	m_DTimerText.setCharacterSize(12);
	m_DTimerText.setColor(sf::Color::White);
	m_DTimerText.setString("0");
}

Game::~Game(){}

// Start the game
void Game::run(){
	setGameState(GameState::Level);
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

// Updates the program and all game objects
void Game::update(){
	GraphicManager::getInstance()->initialize();
	GridManager::getInstance()->initialize();
	initialize();

	while (GraphicManager::getInstance()->getWindow()->isOpen()){
		if (m_Restart){
			initialize();
			m_Restart = false;
		}

		updateDeltaTime();
		handleEvents();
		m_pCurrentState->update(this, m_DeltaTime);

		GraphicManager::getInstance()->draw(m_DTimerText);
		//GraphicManager::getInstance()->draw(m_Text);
		GraphicManager::getInstance()->update();
	}
}

// Initialize the program
void Game::initialize(){
	std::cout << "Initializing game" << std::endl;
	std::cout << "Initializing game done" << std::endl;
}

// Returns true if debugging is true else return false
bool Game::getDebugging(){
	return m_Debug;
}

// Handel events
void Game::handleEvents(){
	sf::Event event;
	while (GraphicManager::getInstance()->getWindow()->pollEvent(event)){
		if (event.type == sf::Event::Closed)
			GraphicManager::getInstance()->getWindow()->close();
		if (event.type == sf::Event::KeyPressed){
			if (event.key.code == sf::Keyboard::R){
				m_Restart = true;
				std::cout << "Restarting" << std::endl << std::endl;
			}
			if (event.key.code == sf::Keyboard::H){
				m_Debug = !m_Debug;
				std::cout << "Debuging " << m_Debug  << std::endl;
			}
		}
	}
}

// Updates the delta time
void Game::updateDeltaTime(){
	sf::Time nowTime = m_Clock.getElapsedTime();
	m_DeltaTime = nowTime.asMilliseconds() - m_LastTime.asMilliseconds();
	m_LastTime = nowTime;

	m_DTimerText.setString(std::to_string(m_DeltaTime));
	m_DTimerText.setPosition(GraphicManager::getInstance()->getWindow()->getSize().x - m_DTimerText.getLocalBounds().width, 0);
}