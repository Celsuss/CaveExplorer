#pragma once
#include "Player.h"
#include "GameState.h"
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"
#include <memory>

class Game{
public:
	Game();
	~Game();
	void startGame();
	void setGameState(GameState::State state);
	void setGameState(GameState* state);
	GameState* getGameState();
	void setEndGame(bool end);
private:
	void update();
	void handleEvents();

	GameState* m_pCurrentState;
	GameState* m_pPreviousState;
	GameState* m_pGlobalState;
	/*std::unique_ptr<GameState> m_pCurrentState;
	std::unique_ptr<GameState> m_pPreviousState;
	std::unique_ptr<GameState> m_pGlobalState;*/

	sf::Clock m_Clock;
	sf::Time m_LastTime;
	bool m_EndGame;
};