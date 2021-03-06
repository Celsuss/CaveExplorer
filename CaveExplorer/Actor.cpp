#include "Actor.h"
#include "HealthBar.h"
#include "GridManager.h"
#include "GraphicManager.h"
#include "TextureManager.h"
#include <math.h>

const float Actor::SIZE_MULTIPLIER = 0.08;

Actor::Actor(const std::string name, const ActorType type, const sf::Vector2f pos, const unsigned int health, const float speed){
	sf::Vector2u* windowSize = &GraphicManager::getInstance()->getWindow()->getSize();
	if (type != ActorType::Cave) {
		m_pSprite = new sf::Sprite();
		m_pSprite->setTexture(*TextureManager::getInstance()->getTexture(name));

		m_pSprite->setOrigin(m_pSprite->getLocalBounds().width / 2, m_pSprite->getLocalBounds().height / 2);
		m_pSprite->setPosition(pos);

		m_pSprite->setScale(windowSize->x / m_pSprite->getTextureRect().width * SIZE_MULTIPLIER,
							windowSize->y / m_pSprite->getTextureRect().height * SIZE_MULTIPLIER);
		
		m_pHealthBar = new HealthBar(health, m_pSprite->getTextureRect().width, m_pSprite->getTextureRect().height, pos);
	}
	m_Type = type;
	m_Position = pos;
	m_MovementSpeed = std::sqrtf((windowSize->x * windowSize->x) + (windowSize->y * windowSize->y)) * speed;
}

Actor::~Actor(){
	if (m_pHealthBar)
		delete m_pHealthBar;
	if (m_pSprite)
		delete m_pSprite;
}

void Actor::update(const float dt) {
	m_PrevPosition = m_Position;
	if (m_pHealthBar)
		m_pHealthBar->update(m_Position);
}

void Actor::draw(){
	if (m_pSprite){
		m_pSprite->setPosition(m_Position);
		GraphicManager::getInstance()->draw(*m_pSprite);
	}
	if (m_pHealthBar)
		m_pHealthBar->draw();
}

const sf::Vector2f& Actor::getPosition() const {
	return m_Position;
}

void Actor::setPosition(sf::Vector2f pos) {
	m_Position = pos;
}

const sf::FloatRect Actor::getSize() const{
	return m_Size;
}

void Actor::setPosition(float x, float y) {
	m_Position.x = x;
	m_Position.y = y;
}

const float Actor::getRadius() const{
	return m_pSprite->getLocalBounds().width / 2;
}

const Actor::ActorType Actor::getActorType() const{
	return m_Type;
}

void Actor::addDamage(const float damage){
	m_pHealthBar->addDamage(damage);
}

const bool Actor::getIsAlive() const{
	if (!m_pHealthBar)
		return true;

	if (m_pHealthBar->getHealth() <=  0)
		return false;
	else
		return true;
}