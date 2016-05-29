#pragma once
#include "Actor.h"
#include <string>
#include <memory>

class State;

class ActorAgent : public Actor{
public:
	ActorAgent(std::string name, sf::Vector2f pos);
	virtual ~ActorAgent();
	virtual void update(float dt);
	virtual void setState(State* pState);
protected:
	State* m_pCurrentState;
	State* m_pPreviousState;
	State* m_pGlobalState;

	/*std::shared_ptr<State*> m_pCurrentState;
	std::shared_ptr<State*> m_pPreviousState;
	std::shared_ptr<State*> m_pGlobalState;*/
};