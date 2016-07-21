#pragma once
#include "State.h"

class AttackState : public State
{
public:
	AttackState();
	~AttackState();

	virtual void enter(ActorAgent* actor);
	virtual void execute(ActorAgent* actor, float dt);
	virtual void exit(ActorAgent* actor);
};