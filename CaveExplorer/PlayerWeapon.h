#pragma once
#include "Weapon.h"

class PlayerWeapon : public Weapon{
public:
	PlayerWeapon(const AttackType type, const unsigned int range, float damage);
	virtual ~PlayerWeapon();
	void update(const float dt);
};