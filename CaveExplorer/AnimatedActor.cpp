#include "AnimatedActor.h"

AnimatedActor::AnimatedActor(std::string name, ActorType type, sf::Vector2f pos, int frameCountWidth, int frameCountHeight) :
	Actor(name, type, pos){
	m_SpriteRect.left = 0;
	m_SpriteRect.top = 0;
	m_SpriteRect.width = m_Sprite->getLocalBounds().width / frameCountWidth;
	m_SpriteRect.height = m_Sprite->getLocalBounds().height / frameCountHeight;

	m_Sprite->setOrigin(m_SpriteRect.width / 2, m_SpriteRect.height / 2);
	m_Sprite->setPosition(pos);

	m_SpriteSheetWidth = m_Sprite->getLocalBounds().width;
	m_AnimationSpeed = 0.2;
	m_AnimationCountdown = 0;
}

AnimatedActor::~AnimatedActor(){}

void AnimatedActor::update(float dt) {
	updateAnimation(dt);
	m_Sprite->setTextureRect(	sf::IntRect(m_SpriteRect.left * m_SpriteRect.width,
								m_SpriteRect.top * m_SpriteRect.height,
								m_SpriteRect.width,
								m_SpriteRect.height ));
	Actor::update(dt);
}

void AnimatedActor::updateAnimation(float dt) {
	if(m_Position != m_PrevPosition)
		m_AnimationCountdown -= dt;
	else
		m_SpriteRect.left = 0;

	if (m_AnimationCountdown <= 0) {
		m_AnimationCountdown = m_AnimationSpeed;
		m_SpriteRect.left += 1;
	}

	if (m_SpriteRect.left * m_SpriteRect.width >= m_SpriteSheetWidth) {
		m_SpriteRect.left = 0;
	}
}