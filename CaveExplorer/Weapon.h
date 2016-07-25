#pragma once

class Weapon{
public:
	enum AttackType{
		Slash,
		Stab,
		Poke
	};

	Weapon(const AttackType type, const unsigned int range, float damage);
	virtual ~Weapon();
	void update(const float dt);
protected:
	float m_Damage;
	const unsigned int m_Range;
	const AttackType m_AttackType;
};