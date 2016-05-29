#include "Rat.h"
#include "PatrolState.h"
#include "CollisionManager.h"

Rat::Rat(sf::Vector2f pos):
ActorAgent("Rat", pos) {
	m_pCurrentState = new PatrolState();
}

Rat::~Rat(){}