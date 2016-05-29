#pragma once
#include "Item.h"

class Usable : public Item{
public:
	Usable(sf::Vector2f pos);
	virtual ~Usable();
};