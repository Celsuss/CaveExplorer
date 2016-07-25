#include "Weapon.h"

Weapon::Weapon(const AttackType type, const unsigned int range, float damage):
m_AttackType(type),
m_Range(range){
	m_Damage = damage;
}

Weapon::~Weapon(){}

void Weapon::update(const float dt){}