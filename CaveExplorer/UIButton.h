#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Text.hpp"

class UIButton{
public:
	enum Event {
		Start,
		Exit
	};

	UIButton(Event e, sf::Vector2f pos, std::string text);
	~UIButton();
	void draw();
	bool isPressed();
	sf::Sprite* getSprite();
	Event getEvent();
private:
	sf::Vector2f m_Position;
	sf::Sprite* m_Sprite;
	sf::Text m_Text;
	sf::FloatRect m_Rect;
	Event m_Event;
};