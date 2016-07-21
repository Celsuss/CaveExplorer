#pragma once
#include "GameState.h"
#include <vector>

class Level : public GameState{
public:
	typedef std::vector<Actor*> ActorVector;

	Level();
	~Level();

	virtual void enter();
	virtual void update(const Game* game, const float dt);
	virtual void exit();
	ActorVector& getActors();
private:
	ActorVector m_Actors;
};