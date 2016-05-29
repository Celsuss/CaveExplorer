#include "Actor.h"
#include "GraphicsManager.h"
#include "TextureManager.h"

Actor::Actor(std::string name, ActorType type, sf::Vector2f pos){
	if (type != ActorType::Cave) {
		m_Sprite = new sf::Sprite();
		m_Sprite->setTexture(*TextureManager::getInstance()->getTexture(name));
		m_Sprite->setOrigin(m_Sprite->getLocalBounds().width / 2, m_Sprite->getLocalBounds().height / 2);
		m_Sprite->setPosition(pos);
	}
	m_Type = type;
	m_Position = pos;
	m_MovementSpeed = 2;
}

Actor::~Actor(){}

void Actor::update(float dt) {
	m_PrevPosition = m_Position;
}

void Actor::draw(){
	if (m_Sprite != nullptr){
		m_Sprite->setPosition(m_Position);
		GraphicsManager::getInstance()->draw(m_Sprite);
	}
}

sf::Vector2f& Actor::getPosition() {
	return m_Position;
}

void Actor::setPosition(sf::Vector2f pos) {
	m_Position = pos;
}

void Actor::setPosition(float x, float y) {
	m_Position.x = x;
	m_Position.y = y;
}

float Actor::getRadius() {
	return m_Sprite->getLocalBounds().width / 2;
}

Actor::ActorType Actor::getActorType() {
	return m_Type;
}