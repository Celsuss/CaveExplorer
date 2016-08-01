#pragma once
#include "GameState.h"
#include <vector>

class Level : public GameState{
public:
	Level();
	~Level();

	virtual void enter();
	virtual void update(const Game* game, const float dt);
	virtual void exit();
private:
};