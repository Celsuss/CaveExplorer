#pragma once
#include "Actor.h"
#include "SFML/Graphics/Rect.hpp"

class AnimatedActor : public Actor{
public:
	static const float ANIMATION_SPEED_MULTIPLIER;

	AnimatedActor(const std::string name, const ActorType type, const sf::Vector2f pos, const float speed, const unsigned int frameCountWidth, const unsigned int frameCountHeight);
	virtual ~AnimatedActor();
	virtual void update(const float dt);

protected:
	sf::IntRect m_SpriteRect;
	int m_SpriteSheetWidth;
	float m_AnimationSpeed;
	float m_AnimationCountdown;

private:
	void updateAnimation(const float dt);
};