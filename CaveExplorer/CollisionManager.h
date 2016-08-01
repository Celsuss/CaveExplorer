#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Rect.hpp"
#include <vector>

class Actor;
class Weapon;
class GameState;

class CollisionManager{
public:
	typedef std::vector<Actor*>ActorVector;
	typedef std::vector<Weapon*> WeaponVector;

	static CollisionManager* getInstance();
	void collisionDetection(GameState* gameState);
	void addActorToCollision(Actor* actor);
	void addWeaponCollision(Weapon* weapon);
	void removeActorFromCollision(Actor* actor);
private:
	CollisionManager();
	~CollisionManager();
	static CollisionManager* m_Instance;

	void actorActorCollisionDetection();
	void actorCaveCollisionDetection();
	void actorWeaponCollisionDetection();

	void pointInRectangle();
	void intersectCircle();

	ActorVector m_Actors;
	WeaponVector m_Weapons;
};