#pragma once
#include "AnimatedActor.h"

class Weapon;

class Player : public AnimatedActor {
public:
	Player(sf::Vector2f pos);
	~Player();
	virtual void update(const float dt);
private:
	void move(const float dt);
	Weapon* m_pWeapon;
};