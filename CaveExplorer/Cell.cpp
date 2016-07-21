#include "Cell.h"
#include "TextureManager.h"
#include "GraphicManager.h"
#include "Game.h"

Cell::Cell(const sf::Vector2f pos, const float width, const float height){
	m_pWallShape = nullptr;
	m_pSprite = new sf::Sprite(*TextureManager::getInstance()->getTexture("Grid_G"));
	m_pSprite->setPosition((sf::Vector2f)pos);

	m_CellShape.setSize(sf::Vector2f(width, height));
	m_CellShape.setPosition(pos);
	m_CellShape.setFillColor(sf::Color::Transparent);
	m_CellShape.setOutlineColor(sf::Color::Green);
	m_CellShape.setOutlineThickness(1);

	m_Position = sf::Vector2f(pos);

	m_GridPos = sf::Vector2f(0,0);
	m_ParentCell = nullptr;
	m_IsWalkable = true;
	m_GCost = 0;
	m_HCost = 0;
	m_FCost = 0;
	m_Index = 0;

	m_IndexText.setFont(*GraphicManager::getInstance()->getFont());
	m_IndexText.setCharacterSize(12);
	m_IndexText.setColor(sf::Color::White);
	m_IndexText.setString(std::to_string(m_Index));
	m_IndexText.setPosition(m_Position);
}

Cell::~Cell(){}

// If debugging is false draw the rectangle shape
// If debugging is true draw the sprite and index text
void Cell::draw(){
	GraphicManager::getInstance()->draw(m_CellShape);
	if (Game::getDebugging()){
		//GraphicManager::getInstance()->draw(*m_pSprite);
		GraphicManager::getInstance()->draw(m_IndexText);
	}
	else if (m_pWallShape)
		GraphicManager::getInstance()->draw(*m_pWallShape);
}

// Returns the sprite
sf::Sprite* Cell::getSprite(){
	return m_pSprite;
}

// Returns the position in the world
sf::Vector2f* Cell::getPosition(){
	return &m_Position;
}

// Returns the index in the grid
int Cell::getIndex(){
	return m_Index;
}

// Returns the cells parent cell
Cell* Cell::getParentCell(){
	return m_ParentCell;
}

// Returns the cells position as a Vector2f
sf::Vector2f* Cell::getGridPosition(){
	return &m_GridPos;
}

// Returns the G cost
float Cell::getGCost(){
	return m_GCost;
}

// Returns the H cost
float Cell::getHCost(){
	return m_HCost;
}

// Returns the F cost
float Cell::getFCost(){
	m_FCost = m_GCost + m_HCost;
	return m_FCost;
}

// Returns is walkable
bool Cell::getIsWalkable(){
	if (!m_IsWalkable)
		int kalle = 0;
	return m_IsWalkable;
}

// Set the texture of the sprite
void Cell::setSpriteTexture(sf::Texture* pTexture){
	m_pSprite->setTexture(*pTexture);
}

// Set is walkable and change sprite
void Cell::setIsWalkable(bool walkable){
	m_IsWalkable = walkable;
	if (walkable){
		m_pSprite->setTexture(*TextureManager::getInstance()->getTexture("Grid_G"));
		createWallShape();
	}
	else{
		m_pSprite->setTexture(*TextureManager::getInstance()->getTexture("Grid_R"));
		delete m_pWallShape;
		m_pWallShape = nullptr;
	}
}

// Set G cost
void Cell::setGCost(float g){
	m_GCost = g;
	m_FCost = m_GCost + m_HCost;
}

// Set H cost
void Cell::setHCost(float h){
	m_HCost = h;
	m_FCost = m_GCost + m_HCost;
}

// Set parent cell
void Cell::setParentCell(Cell* pParent){
	m_ParentCell = pParent;
}

// Set the G, H and F cost to 0 and set partent to nullptr
void Cell::clearValues(){
	m_GCost = 0;
	m_HCost = 0;
	m_FCost = 0;
	m_ParentCell = nullptr;
}

// Create a rectangle shape that is as big as the sprite
void Cell::createWallShape(){
	m_pWallShape = new sf::RectangleShape(sf::Vector2f(m_pSprite->getLocalBounds().width, m_pSprite->getLocalBounds().height));
	m_pWallShape->setPosition(m_pSprite->getPosition());
}