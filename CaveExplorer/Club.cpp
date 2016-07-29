#include "Club.h"

Club::Club(const Actor::ActorType actorType) :
Weapon(actorType, AttackType::Slash, 32, 10, "Club"){}

Club::~Club(){}