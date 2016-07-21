#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"

class GameObject{
public:
	enum Type{
		AI,
		Wall,
		Goal
	};

	GameObject();
	virtual ~GameObject();

	virtual void draw() = 0;
	virtual sf::Vector2f* getPosition();
	virtual Type getGameObjectType();
protected:
	sf::Vector2f m_Position;
	Type m_Type;
private:
};