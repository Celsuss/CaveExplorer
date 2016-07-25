#include "HealthBar.h"
#include "GraphicManager.h"

HealthBar::HealthBar(const unsigned int maxHealth, const unsigned int width, const unsigned height, sf::Vector2f pos){
	m_MaxHealth = maxHealth;
	m_Health = maxHealth;

	m_DeltaY = height / 2;
	pos.y -= m_DeltaY;

	m_Bar.setOrigin(width / 2, height / 2);
	m_Bar.setSize(sf::Vector2f(width, 5));
	m_Bar.setPosition(pos);
	m_Bar.setFillColor(sf::Color::Green);
	m_Bar.setOutlineColor(sf::Color::Transparent);
	m_Bar.setOutlineThickness(0);

	m_Border.setOrigin(width / 2, height / 2);
	m_Border.setSize(sf::Vector2f(width, 5));
	m_Border.setPosition(pos);
	m_Border.setFillColor(sf::Color::Transparent);
	m_Border.setOutlineColor(sf::Color::Black);
	m_Border.setOutlineThickness(1);
}

HealthBar::~HealthBar(){}

void HealthBar::update(const int health, sf::Vector2f pos){
	pos.y -= m_DeltaY;
	m_Bar.setPosition(pos);
	m_Border.setPosition(pos);
}

void HealthBar::draw(){
	GraphicManager::getInstance()->draw(m_Bar);
	GraphicManager::getInstance()->draw(m_Border);
}

void HealthBar::setSize(const unsigned int width, const unsigned int height){
	m_Bar.setOrigin(width / 2, height / 2);
	m_Bar.setSize(sf::Vector2f(width, 5));
	m_Bar.setFillColor(sf::Color::Green);
	m_Bar.setOutlineColor(sf::Color::Transparent);
	m_Bar.setOutlineThickness(0);

	m_Border.setOrigin(width / 2, height / 2);
	m_Border.setSize(sf::Vector2f(width, 5));
	m_Border.setFillColor(sf::Color::Transparent);
	m_Border.setOutlineColor(sf::Color::Black);
	m_Border.setOutlineThickness(1);

	m_DeltaY = height / 2;
}