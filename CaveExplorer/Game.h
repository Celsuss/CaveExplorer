#pragma once
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include "GameState.h"
#include <vector>

class Goal;
class GameObject;

class Game{
public:
	typedef std::vector<GameObject*>GameObjectVector;

	Game();
	~Game();
	void run();

	void setGameState(GameState::State state);
	void setGameState(GameState* state);
	GameState* getGameState();
	void setEndGame(bool end);

	static bool getDebugging();
	static sf::Font* getFont();
private:
	void update();
	void initialize();
	void handleEvents();
	void updateDeltaTime();

	GameState* m_pCurrentState;
	GameState* m_pPreviousState;
	GameState* m_pGlobalState;

	sf::Text m_Text;
	sf::Text m_DTimerText;
	sf::Clock m_Clock;
	sf::Time m_LastTime;
	sf::Time m_DeltaTime;
	bool m_Restart;
	bool m_EndGame;

	static bool m_Debug;
};