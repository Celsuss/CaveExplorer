#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include <string>

class Weapon{
public:
	enum AttackType{
		Slash,
		Stab,
		Poke
	};

	Weapon(AttackType type, const unsigned int range, const float damage, const std::string spriteName);
	virtual ~Weapon();
	void update(const float dt, const sf::Vector2f pos, const sf::Vector2f dir, const bool attack);

protected:
	const unsigned int m_cRange;
	const AttackType m_cAttackType;
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