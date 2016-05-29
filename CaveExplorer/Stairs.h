#pragma once
#include "Item.h"

class Stairs : public Item{
public:
	Stairs(sf::Vector2f pos);
	virtual ~Stairs();
	virtual void update(float dt);
};