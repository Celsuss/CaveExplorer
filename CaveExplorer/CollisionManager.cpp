#include "CollisionManager.h"
#include "GridManager.h"
#include "Weapon.h"
#include "Actor.h"
#include "Cell.h"
#include <iostream>

CollisionManager* CollisionManager::m_Instance = new CollisionManager();

CollisionManager::CollisionManager(){}

CollisionManager::~CollisionManager(){}

CollisionManager* CollisionManager::getInstance() {
	return m_Instance;
}

void CollisionManager::collisionDetection(Level* level) {
	actorCaveCollisionDetection();
	actorActorCollisionDetection();
	actorWeaponCollisionDetection();
}

void CollisionManager::addActorToCollision(Actor* actor) {
	m_Actors.push_back(actor);
}

void CollisionManager::addWeaponCollision(Weapon* weapon) {
	m_Weapons.push_back(weapon);
}

void CollisionManager::actorActorCollisionDetection() {
	for (auto it0 : m_Actors){
		for (auto it1 : m_Actors){
			if (it0 == it1)
				continue;

			sf::Vector2f pos0 = it0->getPosition();
			sf::Vector2f pos1 = it1->getPosition();
			float r = it0->getRadius();

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

				it0->setPosition(pos0 - move);
				it1->setPosition(pos1 + move);
			}
		}
	}
}

void CollisionManager::actorCaveCollisionDetection() {
	GridManager::CellVector cells = *GridManager::getInstance()->getCellVector();
	for (auto it : m_Actors) {
		for (auto jt : cells) {
			if (jt->getIsWalkable())
				continue;

			sf::Vector2f posC = it->getPosition();
			sf::Vector2f posR = *jt->getPosition();
			float r = it->getRadius();

			sf::Vector2f delta = sf::Vector2f(std::abs(posC.x - posR.x),
				std::abs(posC.y - posR.y));

			if (delta.x > r * 2 || delta.y > r * 2) //false
				continue;
			else if (delta.x <= r * 2 && delta.x > delta.y) { //true
				delta = posC - posR;
				delta.x > 0 ? delta.x -= r * 2 : delta.x += r * 2;
				posC.x -= delta.x;
				it->setPosition(posC);
			}
			else if (delta.y <= r * 2 && delta.y > delta.x) { //true
				delta = posC - posR;
				delta.y > 0 ? delta.y -= r * 2 : delta.y += r * 2;
				posC.y -= delta.y;
				it->setPosition(posC);
			}

			float deltaCorner = (((delta.x - r / 2) * (delta.x - r / 2)) +
				((delta.y - r / 2) * (delta.x - r / 2)));

			if (deltaCorner > r * 2) //false
				continue;
		}
	}
}

void CollisionManager::actorWeaponCollisionDetection(){
	for (auto it0 : m_Actors){
		for (auto it1 : m_Weapons){
			if (it0->getActorType() == it1->getActorOwnerType())
				continue;
			if (it1->isTargetHit(it0))
				continue;

			sf::Vector2f pos0 = it0->getPosition();
			sf::Vector2f pos1 = it1->getPosition();
			const float r0 = it0->getRadius();
			const float r1 = it1->getRadius();


			sf::Vector2f delta = sf::Vector2f(pos0.x - pos1.x,
												pos0.y - pos1.y);

			if (std::abs(delta.x * delta.x) + std::abs(delta.y * delta.y) < (r0 + r0) * (r1 + r1)) {
				std::cout << "Hit! Deals " << it1->getDamage() << " damage." << std::endl;
				it0->addDamage(it1->getDamage());
				it1->addSwingTarget(it0);
			}
			else
				std::cout << "Miss!" << std::endl;
		}
	}
	m_Weapons.clear();
}

void CollisionManager::pointInRectangle() {

}

void CollisionManager::intersectCircle() {

}