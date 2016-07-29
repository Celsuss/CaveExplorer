#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class HealthBar{
public:
	HealthBar(const unsigned int maxHealth, const unsigned int width, const unsigned height, sf::Vector2f pos);
	~HealthBar();
	void update(sf::Vector2f pos);
	void draw();
	void setSize(const unsigned int width, const unsigned int height);
	void addDamage(const float damage);
private:
	void updateBarSize();

	unsigned int m_BarHeight;
	unsigned int m_BarMaxWidth;
	float m_MaxHealth;
	float m_Health;
	float m_BarWidth;
	int m_DeltaPosY;
	sf::RectangleShape m_Bar;
	sf::RectangleShape m_Border;
};