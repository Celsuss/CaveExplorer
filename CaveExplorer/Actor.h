#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include <string>

class HealthBar;

class Actor{
public:
	static const float SIZE_MULTIPLIER;

	enum ActorType{
		Player,
		Friendly,
		Hostile,
		Item,
		Cave
	};

	Actor(std::string name, ActorType type, sf::Vector2f pos);
	virtual ~Actor();
	virtual void update(const float dt);
	virtual void draw();
	virtual sf::Vector2f& getPosition();
	virtual void setPosition(sf::Vector2f pos);
	virtual void setPosition(float x, float y);
	virtual sf::FloatRect getSize() const;
	virtual float getRadius();
	virtual ActorType getActorType();

protected:
	ActorType m_Type;
	sf::Sprite* m_pSprite;
	sf::Vector2f m_Position;
	sf::Vector2f m_PrevPosition;
	sf::Vector2f m_Rotation;
	float m_MovementSpeed;
	HealthBar* m_pHealthBar;
	sf::FloatRect m_Size;
};