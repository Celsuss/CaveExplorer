#pragma once
#include "Actor.h"
#include "SFML/Graphics/Rect.hpp"

class AnimatedActor : public Actor{
public:
	AnimatedActor(std::string name, ActorType type, sf::Vector2f pos, int frameCountWidth, int frameCountHeight);
	virtual ~AnimatedActor();
	virtual void update(float dt);

protected:
	sf::IntRect m_SpriteRect;
	int m_SpriteSheetWidth;
	float m_AnimationSpeed;
	float m_AnimationCountdown;;

private:
	void updateAnimation(float dt);
};