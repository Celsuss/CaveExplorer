#pragma once
#include "UIButton.h"
#include <vector>

class Player;
class Actor;
class Item;
class Game;

class GameState{
public:
	enum State {
		Level,
		Menu,
		Paused
	};

	typedef std::vector<Actor*> ActorVector;
	typedef std::vector<Item*> ItemVector;
	typedef std::vector<UIButton*> UIButtonVector;
	//typedef std::vector<std::shared_ptr<Actor>> ActorVector;

	GameState();
	virtual ~GameState();

	virtual void enter();
	virtual void update(Game* game, float dt);
	virtual void exit();

	virtual void createActor(Actor* actor);
	virtual Player* getPlayer();
protected:
	void handleButtonEvent(Game* game, UIButton::Event e);

	ActorVector m_Actors;
	ItemVector m_Items;
	UIButtonVector m_UIButtons;
	State m_State;
	Player* m_Player;
};