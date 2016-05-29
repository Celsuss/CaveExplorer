#pragma once
#include "CaveTile.h"
#include <vector>

class Level;

class Cave{
public:
	typedef std::vector<CaveTile*> TileVector;
	typedef std::vector<TileVector> TileMatrix;

	Cave();
	~Cave();
	void update();
	void draw();
	void generateCave(Level* level);
private:
	void generateCaveWalls(Level* level);
	void generateCaveMonsters(Level* level);
	void clearCaveTilesIsFull();

	CaveTile* getRandomEmptyCaveTile();

	TileMatrix m_Tiles;
	float m_CaveLevel;
};