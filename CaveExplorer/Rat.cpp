#include "Rat.h"
#include "PatrolState.h"
#include "AttackState.h"
#include "CollisionManager.h"

Rat::Rat(sf::Vector2f pos):
ActorAgent("Rat", pos, 0.1) {
	//m_pCurrentState = new PatrolState();
	m_pCurrentState = new AttackState();
}

Rat::~Rat(){}