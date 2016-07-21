#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Rect.hpp"
#include <vector>

class Actor;
class Level;
class CaveTile;

class CollisionManager{
public:
	typedef std::vector<Actor*>ActorVector;
	typedef std::vector<CaveTile*>CaveTileVector;

	static CollisionManager* getInstance();
	void collisionDetection(Level* level);
	void addActorToCollision(Actor* actor);
	void addCaveTilesCollision(Actor* caveTile);
private:
	CollisionManager();
	~CollisionManager();
	static CollisionManager* m_Instance;

	void actorActorCollisionDetection(Level* level);
	void actorCaveCollisionDetection(Level* level);

	void pointInRectangle();
	void intersectCircle();

	ActorVector m_Actors;
	ActorVector m_CaveTiles;
};