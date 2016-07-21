#include "Item.h"
#include "InputManager.h"
#include "GraphicManager.h"

Item::Item(std::string name, sf::Vector2f pos, ItemType itemType):
Actor(name, ActorType::Item, pos){
	m_Rect = m_Sprite->getGlobalBounds();
	m_ItemType = itemType;

	sf::Vector2f newPos = pos;
	sf::Vector2f spritePos = m_Sprite->getPosition();
}

Item::~Item(){}

//void Item::update(float dt){}

bool Item::isPressed(sf::Vector2f actorPos) {
	sf::Vector2f mousePos = sf::Vector2f(	sf::Mouse::getPosition(*GraphicManager::getInstance()->getWindow()).x,
											sf::Mouse::getPosition(*GraphicManager::getInstance()->getWindow()).y );
	
	float r = m_Sprite->getLocalBounds().width / 2;
	sf::Vector2f delta = sf::Vector2f(	std::abs(actorPos.x - m_Position.x),
										std::abs(actorPos.y - m_Position.y) );

	if (delta.x > r * 3 || delta.y > r * 3) {
		return false;
	}

	if (InputManager::getInstance()->isKeyPressed(InputManager::Interact) && m_Rect.contains(mousePos)) {
		return true;
	}

	return false;
}