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

	Actor(const std::string name, const ActorType type, const sf::Vector2f pos, const float speed);
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
	sf::Vector2f m_Direction;
	float m_MovementSpeed;
	HealthBar* m_pHealthBar;
	sf::FloatRect m_Size;
};