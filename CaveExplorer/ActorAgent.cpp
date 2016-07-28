#include "ActorAgent.h"
#include "State.h"
#include "PatrolState.h"
#include "CollisionManager.h"

ActorAgent::ActorAgent(const std::string name, const sf::Vector2f pos, const float speed) :
Actor(name, ActorType::Hostile, pos, speed){
	CollisionManager::getInstance()->addActorToCollision(this);
}

ActorAgent::~ActorAgent(){}

void ActorAgent::update(const float dt) {
	//(*m_pCurrentState)->execute(this, dt);
	m_pCurrentState->execute(this, dt);
	Actor::update(dt);
}

void ActorAgent::setState(State* pState) {
	/*(*m_pCurrentState)->exit(this);
	m_pPreviousState = std::make_shared<State*>(m_pCurrentState);
	m_pCurrentState = std::make_shared<State*>(pState);
	(*m_pCurrentState)->enter(this);*/
	m_pCurrentState->exit(this);
	m_pPreviousState = m_pCurrentState;
	m_pCurrentState = pState;
	m_pCurrentState->enter(this);
}