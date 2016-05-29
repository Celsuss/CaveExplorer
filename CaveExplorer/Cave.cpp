#include "Cave.h"
#include "Rat.h"
#include "Level.h"
#include "Stairs.h"
#include <time.h>
#include <stdlib.h>

Cave::Cave(){
	srand(time(NULL));
	m_CaveLevel = 1;
}

Cave::~Cave(){}

void Cave::update() {
	
}

void Cave::draw() {
	for (auto i0 = m_Tiles.begin(); i0 != m_Tiles.end(); i0++) {
		for (auto i1 = i0->begin(); i1 != i0->end(); i1++) {
			(*i1)->draw();
		}
	}
}

void Cave::generateCave(Level* level) {
	generateCaveWalls(level);
	clearCaveTilesIsFull();
	generateCaveMonsters(level);
	
	CaveTile* tile = getRandomEmptyCaveTile();
	tile->setIsEmpty(false);
	level->createActor(new Stairs(tile->getPosition()));
}

void Cave::generateCaveWalls(Level* level) {
	int size = 22;
	for (int i0 = 0; i0 < size; i0++) {
		m_Tiles.push_back(TileVector());
		for (int i1 = 0; i1 < size; i1++) {
			sf::Vector2f pos = sf::Vector2f(i0 * 32, i1 * 32);
			if (i0 == 0 || i0 == size - 1 || i1 == 0 || i1 == size - 1) {
				m_Tiles[i0].push_back(new CaveTile(CaveTile::Wall, pos));
			}
			else {
				m_Tiles[i0].push_back(new CaveTile(CaveTile::Floor, pos));
			}
		}
	}
}

void Cave::generateCaveMonsters(Level* level) {
	int monsters = 2;

	for (int i = 0; i < monsters; i++) {
		CaveTile* tile = getRandomEmptyCaveTile();
		tile->setIsEmpty(false);
		level->createActor(new Rat(tile->getPosition()));
	}
}

void Cave::clearCaveTilesIsFull() {
	for (auto i0 = m_Tiles.begin(); i0 != m_Tiles.end(); i0++) {
		for (auto i1 = i0->begin(); i1 != i0->end(); i1++) {
			if((*i1)->getTileType() == CaveTile::Floor)
				(*i1)->setIsEmpty(true);
			else
				(*i1)->setIsEmpty(false);
		}
	}
}

CaveTile* Cave::getRandomEmptyCaveTile() {
	sf::Vector2f gridPos = sf::Vector2f(rand() % m_Tiles.size(),
										rand() % m_Tiles.back().size());
	CaveTile* tile = m_Tiles[gridPos.x][gridPos.y];

	while (!tile->getIsEmpty()) {
		gridPos = sf::Vector2f(	rand() % m_Tiles.size(),
								rand() % m_Tiles.back().size() );
		tile = m_Tiles[gridPos.x][gridPos.y];
	}
	return tile;
}