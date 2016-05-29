#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Rect.hpp"
#include <vector>

class Actor;
class CaveTile;

class CollisionManager{
public:
	typedef std::vector<Actor*>ActorVector;
	typedef std::vector<CaveTile*>CaveTileVector;

	static CollisionManager* getInstance();
	void collisionDetection();
	void addActorToCollision(Actor* actor);
	void addCaveTilesCollision(Actor* caveTile);
private:
	CollisionManager();
	~CollisionManager();
	static CollisionManager* m_Instance;

	void actorActorCollisionDetection();
	void actorCaveCollisionDetection();

	void pointInRectangle();
	void intersectCircle();

	ActorVector m_Actors;
	ActorVector m_CaveTiles;
};