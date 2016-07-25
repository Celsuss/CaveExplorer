#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class HealthBar{
public:
	HealthBar(const unsigned int maxHealth, const unsigned int width, const unsigned height, sf::Vector2f pos);
	~HealthBar();
	void update(const int health, sf::Vector2f pos);
	void draw();
	void setSize(const unsigned int width, const unsigned int height);
private:
	unsigned int m_MaxHealth;
	int m_Health;
	int m_DeltaY;
	sf::RectangleShape m_Bar;
	sf::RectangleShape m_Border;
};