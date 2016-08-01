#include "HealthBar.h"
#include "GraphicManager.h"

HealthBar::HealthBar(const unsigned int maxHealth, const unsigned int width, const unsigned height, sf::Vector2f pos){
	m_MaxHealth = maxHealth;
	m_Health = maxHealth;

	m_DeltaPosY = height / 2;
	pos.y -= m_DeltaPosY;

	m_BarHeight = 5;
	m_BarMaxWidth = width;
	m_BarWidth = width;

	m_Bar.setOrigin(width / 2, height / 2);
	m_Bar.setSize(sf::Vector2f(width, m_BarHeight));
	m_Bar.setPosition(pos);
	m_Bar.setFillColor(sf::Color::Green);
	m_Bar.setOutlineColor(sf::Color::Transparent);
	m_Bar.setOutlineThickness(0);

	m_Border.setOrigin(width / 2, height / 2);
	m_Border.setSize(sf::Vector2f(width, m_BarHeight));
	m_Border.setPosition(pos);
	m_Border.setFillColor(sf::Color::Transparent);
	m_Border.setOutlineColor(sf::Color::Black);
	m_Border.setOutlineThickness(1);
}

HealthBar::~HealthBar(){}

void HealthBar::update(sf::Vector2f pos){
	updateBarSize();
	pos.y -= m_DeltaPosY;
	m_Bar.setPosition(pos);
	m_Border.setPosition(pos);
}

void HealthBar::draw(){
	GraphicManager::getInstance()->draw(m_Bar);
	GraphicManager::getInstance()->draw(m_Border);
}

void HealthBar::setSize(const unsigned int width, const unsigned int height){
	m_BarMaxWidth = width;
	m_BarWidth = width;

	m_Bar.setOrigin(width / 2, height / 2);
	m_Bar.setSize(sf::Vector2f(width, m_BarHeight));
	m_Bar.setFillColor(sf::Color::Green);
	m_Bar.setOutlineColor(sf::Color::Transparent);
	m_Bar.setOutlineThickness(0);

	m_Border.setOrigin(width / 2, height / 2);
	m_Border.setSize(sf::Vector2f(width, m_BarHeight));
	m_Border.setFillColor(sf::Color::Transparent);
	m_Border.setOutlineColor(sf::Color::Black);
	m_Border.setOutlineThickness(1);

	m_DeltaPosY = height / 2;
}

void HealthBar::addDamage(const float damage){
	m_Health -= damage;
}

float HealthBar::getHealth()const{
	return m_Health;
}

void HealthBar::updateBarSize(){
	float health = m_Health / (float)m_MaxHealth;
	m_BarWidth = m_BarMaxWidth * health;
	m_Bar.setSize(sf::Vector2f(m_BarWidth, m_BarHeight));
}