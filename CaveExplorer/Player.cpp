#include "Player.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "Stick.h"

Player::Player(sf::Vector2f pos):
	AnimatedActor("Player", ActorType::Player, pos, 4, 4){
	CollisionManager::getInstance()->addActorToCollision(this);
	m_pWeapon = new Stick();
}

Player::~Player(){}

void Player::update(const float dt){
	move();
	AnimatedActor::update(dt);
	m_pWeapon->update(dt);
}

void Player::move() {
	if (InputManager::getInstance()->isKeyPressed(InputManager::Left)) {
		m_Position.x -= m_MovementSpeed;
		m_SpriteRect.top = 1;
	}
	else if (InputManager::getInstance()->isKeyPressed(InputManager::Up)) {
		m_Position.y -= m_MovementSpeed;
		m_SpriteRect.top = 3;
	}
	else if (InputManager::getInstance()->isKeyPressed(InputManager::Right)) {
		m_Position.x += m_MovementSpeed;
		m_SpriteRect.top = 2;
	}
	else if (InputManager::getInstance()->isKeyPressed(InputManager::Down)) {
		m_Position.y += m_MovementSpeed;
		m_SpriteRect.top = 0;
	}
}