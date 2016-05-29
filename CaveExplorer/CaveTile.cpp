#include "CaveTile.h"
#include "TextureManager.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"

CaveTile::CaveTile(TileType type, sf::Vector2f pos):
Actor("CaveTile", ActorType::Cave, pos){
	m_Type = type;
	m_IsEmpty = type == TileType::Floor ? true : false;
	m_Sprite = new sf::Sprite();
	loadSprite(type);
	pos += sf::Vector2f(m_Sprite->getGlobalBounds().width / 2,
						m_Sprite->getGlobalBounds().height / 2);
	m_Sprite->setPosition(pos);
	m_Sprite->setOrigin(m_Sprite->getLocalBounds().width / 2, m_Sprite->getLocalBounds().height / 2);
	m_Position = pos;

	if(type != Floor)
		CollisionManager::getInstance()->addCaveTilesCollision(this);
}

CaveTile::~CaveTile(){}

void CaveTile::update(float dt){}

void CaveTile::draw() {
	if (m_Sprite != nullptr) {
		GraphicsManager::getInstance()->draw(m_Sprite);
	}
}

CaveTile::TileType CaveTile::getTileType() {
	return m_Type;
}

void CaveTile::setIsEmpty(bool empty) {
	m_IsEmpty = empty;
}

bool CaveTile::getIsEmpty() {
	return m_IsEmpty;
}

void CaveTile::loadSprite(TileType type) {
	switch (type){
	case Wall:
		m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("brick_dark0"));
		break;
	case Floor:
		m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("floor_vines1"));
		break;
	case Rock:
		m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("stone0"));
		break;
	}
}