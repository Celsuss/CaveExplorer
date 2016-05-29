#include "CollisionManager.h"
#include "CaveTile.h"
#include "Actor.h"

CollisionManager* CollisionManager::m_Instance = new CollisionManager();

CollisionManager::CollisionManager(){}

CollisionManager::~CollisionManager(){}

CollisionManager* CollisionManager::getInstance() {
	return m_Instance;
}

void CollisionManager::collisionDetection() {
	actorCaveCollisionDetection();
	actorActorCollisionDetection();
}

void CollisionManager::addActorToCollision(Actor* actor) {
	m_Actors.push_back(actor);
}

void CollisionManager::addCaveTilesCollision(Actor* caveTile) {
	m_CaveTiles.push_back(caveTile);
}

void CollisionManager::actorActorCollisionDetection() {
	for (auto i0 = m_Actors.begin(); i0 != m_Actors.end(); i0++) {
		for (auto i1 = m_Actors.begin(); i1 != m_Actors.end(); i1++) {
			if (i0 == i1)
				continue;

			sf::Vector2f pos0 = (*i0)->getPosition();
			sf::Vector2f pos1 = (*i1)->getPosition();
			float r = (*i0)->getRadius();

			sf::Vector2f delta = sf::Vector2f(	pos0.x - pos1.x,
												pos0.y - pos1.y);

			if (std::abs(delta.x * delta.x) + std::abs(delta.y * delta.y) < (r + r) * (r + r)) {
				sf::Vector2f move = sf::Vector2f(0, 0);
				if (std::abs(delta.x) > std::abs(delta.y)) {
					move.x = delta.x > 0 ? delta.x - (r * 2) : (delta.x + (r * 2)) * -1;
					move.x *= 0.5;
				}
				else{
					move.y = delta.y > 0 ? delta.y - (r * 2) : (delta.y + (r * 2)) * -1;
					move.y *= 0.5;
				}

				(*i0)->setPosition(pos0 - move);
				(*i1)->setPosition(pos1 + move);
			}
		}
	}
}

void CollisionManager::actorCaveCollisionDetection() {
	for (auto ia = m_Actors.begin(); ia != m_Actors.end(); ia++) {
		for (auto ic = m_CaveTiles.begin(); ic != m_CaveTiles.end(); ic++) {
			sf::Vector2f posC = (*ia)->getPosition();
			sf::Vector2f posR = (*ic)->getPosition();
			float r = (*ia)->getRadius();

			sf::Vector2f delta = sf::Vector2f(	std::abs(posC.x - posR.x),
												std::abs(posC.y - posR.y));

			if (delta.x > r * 2 || delta.y > r * 2) //false
				continue;
			else if (delta.x <= r * 2 && delta.x > delta.y) { //true
				delta = posC - posR;
				delta.x > 0 ? delta.x -= r * 2 : delta.x += r * 2;
				posC.x -= delta.x;
				(*ia)->setPosition(posC);
			}
			else if (delta.y <= r * 2 && delta.y > delta.x) { //true
				delta = posC - posR;
				delta.y > 0 ? delta.y -= r * 2 : delta.y += r * 2;
				posC.y -= delta.y;
				(*ia)->setPosition(posC);
			}

			float deltaCorner = (((delta.x - r / 2) * (delta.x - r / 2)) +
				((delta.y - r / 2) * (delta.x - r / 2)));

			if (deltaCorner > r * 2) //false
				continue;
		}
	}
}

void CollisionManager::pointInRectangle() {

}

void CollisionManager::intersectCircle() {

}