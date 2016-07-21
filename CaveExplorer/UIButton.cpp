#include "UIButton.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "GraphicManager.h"

UIButton::UIButton(Event e, sf::Vector2f pos, std::string text){
	m_Sprite = new sf::Sprite();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("UI/Blue_Button_L"));
	sf::FloatRect rect = m_Sprite->getLocalBounds();
	m_Sprite->setTextureRect(sf::IntRect(0, 0, rect.width / 2, rect.height));
	m_Sprite->setOrigin(m_Sprite->getLocalBounds().width / 2, m_Sprite->getLocalBounds().height / 2);
	m_Sprite->setPosition(pos);

	m_Text.setFont(*GraphicManager::getInstance()->getFont());
	m_Text.setCharacterSize(32);
	m_Text.setString(text);
	m_Text.setOrigin(m_Text.getLocalBounds().width / 2,
				 	 (m_Text.getLocalBounds().height / 2) + 10);
	m_Text.setPosition(pos);

	m_Position = pos;
	m_Rect = m_Sprite->getGlobalBounds();
	m_Event = e;
}

UIButton::~UIButton(){}

void UIButton::draw() {
	GraphicManager::getInstance()->draw(*m_Sprite);
	GraphicManager::getInstance()->draw(m_Text);
}

bool UIButton::isPressed() {
	sf::Vector2f mousePos = sf::Vector2f(	sf::Mouse::getPosition(*GraphicManager::getInstance()->getWindow()).x,
											sf::Mouse::getPosition(*GraphicManager::getInstance()->getWindow()).y );

	if (InputManager::getInstance()->isKeyPressed(InputManager::Interact) && m_Rect.contains(mousePos)) {
		m_Sprite->setTextureRect(sf::IntRect(m_Rect.width, 0, m_Rect.width, m_Rect.height));
		return true;
	}

	m_Sprite->setTextureRect(sf::IntRect(0, 0, m_Rect.width, m_Rect.height));
	return false;
}

sf::Sprite* UIButton::getSprite() {
	return m_Sprite;
}

UIButton::Event UIButton::getEvent() {
	return m_Event;
}