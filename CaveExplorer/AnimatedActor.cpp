#include "AnimatedActor.h"
#include "GraphicManager.h"
#include "HealthBar.h"

AnimatedActor::AnimatedActor(std::string name, ActorType type, sf::Vector2f pos, int frameCountWidth, int frameCountHeight) :
	Actor(name, type, pos){
	sf::Vector2u* windowSize = &GraphicManager::getInstance()->getWindow()->getSize();

	m_SpriteRect.left = 0;
	m_SpriteRect.top = 0;
	m_SpriteRect.width = m_pSprite->getLocalBounds().width / frameCountWidth;
	m_SpriteRect.height = m_pSprite->getLocalBounds().height / frameCountHeight;

	m_Size = (sf::FloatRect)m_SpriteRect;

	m_pSprite->setOrigin(m_SpriteRect.width / 2, m_SpriteRect.height / 2);
	m_pSprite->setPosition(pos);
	m_pSprite->setScale(windowSize->x / m_Size.width * SIZE_MULTIPLIER,
						windowSize->y / m_Size.height * SIZE_MULTIPLIER);

	m_pHealthBar->setSize(m_Size.width, m_Size.height);

	m_SpriteSheetWidth = m_pSprite->getLocalBounds().width;
	m_AnimationSpeed = std::sqrtf((windowSize->x * windowSize->x) + (windowSize->y * windowSize->y)) / 15;
	m_AnimationCountdown = 0;
}

AnimatedActor::~AnimatedActor(){}

void AnimatedActor::update(float dt) {
	updateAnimation(dt);
	m_pSprite->setTextureRect(sf::IntRect(m_SpriteRect.left * m_SpriteRect.width,
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