#pragma once
#include "GameState.h"
#include "Cave.h"
#include <vector>

class Level : public GameState{
public:
	Level();
	~Level();

	virtual void enter();
	virtual void update(Game* game, float dt);
	virtual void exit();
private:
	Cave m_Cave;
};