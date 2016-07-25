#include "PlayerWeapon.h"
#include "InputManager.h"

PlayerWeapon::PlayerWeapon(const AttackType type, const unsigned int range, float damage):
Weapon(type, range, damage){}

PlayerWeapon::~PlayerWeapon(){}

void PlayerWeapon::update(const float dt){
	if (InputManager::getInstance()->isKeyPressed(InputManager::Attack)){
		Weapon::update(dt);
	}
}