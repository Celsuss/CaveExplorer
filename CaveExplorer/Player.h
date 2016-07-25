#pragma once
#include "AnimatedActor.h"

class PlayerWeapon;

class Player : public AnimatedActor {
public:
	Player(sf::Vector2f pos);
	~Player();
	virtual void update(const float dt);
protected:
	void move();
	PlayerWeapon* m_pWeapon;
};