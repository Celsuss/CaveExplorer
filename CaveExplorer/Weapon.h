#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "Actor.h"
#include <string>
#include <vector>

class Weapon{
public:
	typedef std::vector<Actor*>ActorVector;

	enum AttackType{
		Slash,
		Stab,
		Poke
	};

	Weapon(const Actor::ActorType actorType, const AttackType attackType, const unsigned int range, const float damage, const std::string spriteName);
	virtual ~Weapon();
	virtual void update(const float dt, const sf::Vector2f pos, const sf::Vector2f dir, const bool attack);
	virtual const sf::Vector2f& getPosition() const;
	virtual const float getRadius() const;
	virtual const Actor::ActorType& getActorOwnerType() const;
	virtual const float getDamage() const;

	virtual void addSwingTarget(Actor* actor);
	virtual bool isTargetHit(Actor* actor);
protected:
	ActorVector m_SwingTargets;
	const Actor::ActorType m_cActorOwnerType;
	const AttackType m_cAttackType;
	unsigned int m_Range;
	float m_Damage;
	bool m_Attack;

	sf::Sprite m_Sprite;
	sf::IntRect m_SpriteRect;
	int m_SpriteSheetWidth;
	float m_AnimationSpeed;
	float m_AnimationCountdown;

private:
	void updateAnimation(const float dt);
	void setPosition(sf::Vector2f pos, const sf::Vector2f dir);
	void setRotation(const sf::Vector2f dir);
};