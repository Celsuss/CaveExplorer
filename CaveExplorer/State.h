#pragma once

class ActorAgent;

class State{
public:
	State();
	virtual ~State();

	virtual void enter(ActorAgent* actor) = 0;
	virtual void execute(ActorAgent* actor, float dt) = 0;
	virtual void exit(ActorAgent* actor) = 0;
};