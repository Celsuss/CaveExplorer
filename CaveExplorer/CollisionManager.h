#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Rect.hpp"
#include <vector>

class Actor;
class Level;
class Weapon;

class CollisionManager{
public:
	typedef std::vector<Actor*>ActorVector;
	typedef std::vector<Weapon*> WeaponVector;

	static CollisionManager* getInstance();
	void collisionDetection(Level* level);
	void addActorToCollision(Actor* actor);
	void addWeaponCollision(Weapon* weapon);
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