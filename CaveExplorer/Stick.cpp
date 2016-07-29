#include "Stick.h"

Stick::Stick(const Actor::ActorType actorType) :
Weapon(actorType, AttackType::Slash, 35, 10, ""){}

Stick::~Stick(){}