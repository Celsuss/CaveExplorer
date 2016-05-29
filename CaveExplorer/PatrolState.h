#pragma once
#include "State.h"

class PatrolState : public State{
public:
	PatrolState();
	~PatrolState();

	virtual void enter(ActorAgent* actor);
	virtual void execute(ActorAgent* actor, float dt);
	virtual void exit(ActorAgent* actor);
};