#pragma once
#include "Weapon.h"

class Stick : public Weapon{
public:
	Stick(const Actor::ActorType actorType);
	virtual ~Stick();
};