#pragma once
#include "Actor.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"

class Item;

class CaveTile : public Actor{
public:
	enum TileType {
		Wall,
		Floor,
		Rock
	};

	CaveTile(TileType type, sf::Vector2f pos);
	~CaveTile();
	virtual void update(float dt);
	virtual void draw();
	TileType getTileType();
	void setIsEmpty(bool empty);
	bool getIsEmpty();
private:
	void loadSprite(TileType type);

	TileType m_Type;
	bool m_IsEmpty;
};