#include "Weapon.h"
#include "Actor.h"
#include "AnimatedActor.h"
#include "GraphicManager.h"
#include "TextureManager.h"

Weapon::Weapon(const AttackType type, const unsigned int range, const float damage, const std::string spriteName) :
m_cAttackType(type),
m_cRange(range){
	m_Damage = damage;
	m_Attack = false;

	sf::Vector2u* windowSize = &GraphicManager::getInstance()->getWindow()->getSize();
	
	const unsigned int frameCountWidth = 3;
	const unsigned int frameCountHeight = 1;

	m_Sprite.setTexture(*TextureManager::getInstance()->getTexture(spriteName));

	m_SpriteRect.left = 0;
	m_SpriteRect.top = 0;
	m_SpriteRect.width = m_Sprite.getLocalBounds().width / frameCountWidth;
	m_SpriteRect.height = m_Sprite.getLocalBounds().height / frameCountHeight;

	sf::FloatRect size = (sf::FloatRect)m_SpriteRect;

	m_Sprite.setOrigin(m_SpriteRect.width / 2, m_SpriteRect.height / 2);
	m_Sprite.setPosition(0, 0);
	m_Sprite.setScale(windowSize->x / size.width * Actor::SIZE_MULTIPLIER,
					windowSize->y / size.height * Actor::SIZE_MULTIPLIER);

	m_SpriteSheetWidth = m_Sprite.getLocalBounds().width;
	m_AnimationSpeed = std::sqrtf((windowSize->x * windowSize->x) + (windowSize->y * windowSize->y)) * (AnimatedActor::ANIMATION_SPEED_MULTIPLIER * 0.05);
	m_AnimationCountdown = m_AnimationSpeed;
}

Weapon::~Weapon(){}

void Weapon::update(const float dt, const sf::Vector2f pos, const sf::Vector2f dir, const bool attack){
	if (attack && !m_Attack){
		m_Attack = attack;
		setPosition(pos, dir);
		setRotation(dir);
	}
	if (!m_Attack)
		return;

	setPosition(pos, dir);
	setRotation(dir);
	updateAnimation(dt);
	GraphicManager::getInstance()->draw(m_Sprite);
}

void Weapon::updateAnimation(const float dt){
	m_AnimationCountdown -= dt;
	if (m_SpriteRect.left * m_SpriteRect.width >= m_SpriteSheetWidth){
		m_Attack = false;
		m_SpriteRect.left = 0;
		m_AnimationCountdown = m_AnimationSpeed;
	}

	if (m_AnimationCountdown <= 0) {
		m_AnimationCountdown = m_AnimationSpeed;
		m_SpriteRect.left += 1;
	}

	m_Sprite.setTextureRect(sf::IntRect(m_SpriteRect.left * m_SpriteRect.width,
							m_SpriteRect.top * m_SpriteRect.height,
							m_SpriteRect.width,
							m_SpriteRect.height));
}

void Weapon::setPosition(sf::Vector2f pos, const sf::Vector2f dir){
	pos.x += dir.x * m_cRange;
	pos.y += dir.y * m_cRange;
	m_Sprite.setPosition(pos);
}

void Weapon::setRotation(const sf::Vector2f dir){
	if (dir.x == 1){
		m_Sprite.setRotation(0);
	}
	else if (dir.y == 1){
		m_Sprite.setRotation(90);
	}
	else if (dir.x == -1){
		m_Sprite.setRotation(180);
	}
	else if (dir.y == -1){
		m_Sprite.setRotation(270);
	}
}