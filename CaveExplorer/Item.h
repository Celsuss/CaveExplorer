#pragma once
#include "Actor.h"

class Item : public Actor{
public:
	enum ItemType {
		Stairs
	};

	Item(std::string name, sf::Vector2f pos, ItemType itemType);
	virtual ~Item();
	//virtual void update(float dt);
	virtual bool isPressed(sf::Vector2f actorPos);
protected:
	sf::FloatRect m_Rect;
	ItemType m_ItemType;
};