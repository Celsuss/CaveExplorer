#pragma once
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class Cell{
public:
	Cell(const sf::Vector2f pos, const float width, const float height, const sf::Vector2u gridPos);
	~Cell();
	void draw();
	sf::Sprite* getSprite();
	sf::Vector2f* getPosition();
	int getIndex();

	Cell* getParentCell();
	sf::Vector2f* getGridPosition();
	float getGCost();
	float getHCost();
	float getFCost();
	bool getIsWalkable();
	void setSpriteTexture(sf::Texture* pTexture);
	void setIsWalkable(bool walkable);
	void setGCost(float g);
	void setHCost(float h);
	void setParentCell(Cell* pParent);
	void clearValues();
private:

	sf::Sprite* m_pSprite;
	sf::RectangleShape m_CellShape;
	sf::Vector2f m_Position;
	sf::Text m_IndexText;
	sf::Vector2f m_GridPos;
	Cell* m_ParentCell;
	bool m_IsWalkable;
	float m_GCost;
	float m_HCost;
	float m_FCost;
	int m_Index;
};