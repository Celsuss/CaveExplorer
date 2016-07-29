#pragma once
#include "Weapon.h"

class Club : public Weapon{
public:
	Club(const Actor::ActorType actorType);
	virtual ~Club();
};