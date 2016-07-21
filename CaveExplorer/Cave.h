#pragma once
//#include "CaveTile.h"
#include <vector>

/*class Level;
class Cell;

class Cave{
public:
	typedef std::vector<Cell*>CellVector;

	static const int CAVE_WIDTH = 20;
	static const int CAVE_HEIGHT = 20;

	static Cave* getInstance();

	void update();
	void draw();
	void generateCave(Level* level);

	void clearCellValues();
	Cell* getRandomCell();
	Cell* getRandomWalkableCell();
	Cell* getCell(int index);
	Cell* getCell(sf::Vector2f gridPos);
	Cell* getClosestCell(sf::Vector2f worldPos);
private:
	Cave();
	~Cave();
	static Cave* m_Instance;

	void generateCaveWalls(Level* level);
	void generateCaveMonsters(Level* level);
	void clearCaveTilesIsFull();

	CaveTile* getRandomEmptyCaveTile();

	CellVector m_Cells;
	float m_CaveLevel;
};*/