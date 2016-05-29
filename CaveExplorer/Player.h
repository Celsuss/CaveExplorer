#pragma once
#include "AnimatedActor.h"

class Player : public AnimatedActor {
public:
	Player(sf::Vector2f pos);
	~Player();
	virtual void update(float dt);
protected:
	void move();
};