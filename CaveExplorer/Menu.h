#pragma once
#include "GameState.h"
#include "UIButton.h"
#include "Level.h"
#include <vector>

class Menu : public GameState{
public:
	Menu();
	virtual ~Menu();

	virtual void enter();
	virtual void exit();
};