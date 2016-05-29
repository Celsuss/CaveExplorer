#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class GraphicsManager{
public:
	static GraphicsManager* getInstance();

	void createWindow();
	void update();
	void draw(sf::Sprite* sprite);
	void draw(sf::Text* text);
	sf::RenderWindow* getWindow();
	sf::Font* getFont();
private:
	GraphicsManager();
	~GraphicsManager();
	static GraphicsManager* m_Instance;

	sf::RenderWindow m_Window;
	sf::Font m_Font;
};