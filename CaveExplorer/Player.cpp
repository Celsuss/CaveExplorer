#include "Player.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "Club.h"

Player::Player(sf::Vector2f pos):
	AnimatedActor("Player", ActorType::Player, pos, 100, 0.2, 4, 4){
	CollisionManager::getInstance()->addActorToCollision(this);
	m_Direction = sf::Vector2f(0, 1);
	m_pWeapon = new Club(m_Type);
}

Player::~Player(){}

void Player::update(const float dt){
	move(dt);
	m_pWeapon->update(dt, m_Position, m_Direction, InputManager::getInstance()->isKeyPressed(InputManager::UseItem));
	AnimatedActor::update(dt);
}

void Player::move(const float dt) {
	if (InputManager::getInstance()->isKeyPressed(InputManager::Up)) {
		m_Position.y -= m_MovementSpeed * dt;
		m_SpriteRect.top = 3;
		m_Direction = sf::Vector2f(0, -1);
	}
	else if (InputManager::getInstance()->isKeyPressed(InputManager::Right)) {
		m_Position.x += m_MovementSpeed * dt;
		m_SpriteRect.top = 2;
		m_Direction = sf::Vector2f(1, 0);
	}
	else if (InputManager::getInstance()->isKeyPressed(InputManager::Down)) {
		m_Position.y += m_MovementSpeed * dt;
		m_SpriteRect.top = 0;
		m_Direction = sf::Vector2f(0, 1);
	}
	else if (InputManager::getInstance()->isKeyPressed(InputManager::Left)) {
		m_Position.x -= m_MovementSpeed * dt;
		m_SpriteRect.top = 1;
		m_Direction = sf::Vector2f(-1, 0);
	}
}