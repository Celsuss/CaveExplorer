#include "GraphicsManager.h"

GraphicsManager* GraphicsManager::m_Instance = new GraphicsManager();

GraphicsManager::GraphicsManager(){
	m_Font.loadFromFile("Assets/arial.ttf");
}

GraphicsManager::~GraphicsManager(){}

GraphicsManager* GraphicsManager::getInstance(){
	if (m_Instance == nullptr)
		m_Instance = new GraphicsManager();
	return m_Instance;
}

void GraphicsManager::createWindow() {
	m_Window.create(sf::VideoMode(1200, 900), "CaveHero");
	m_Window.setFramerateLimit(60);		//Set max fps tp 60
}

void GraphicsManager::update(){
	m_Window.display();
	m_Window.clear();
}

void GraphicsManager::draw(sf::Sprite* sprite){
	m_Window.draw(*sprite);
}

void GraphicsManager::draw(sf::Text* text) {
	m_Window.draw(*text);
}

sf::RenderWindow* GraphicsManager::getWindow(){
	return &m_Window;
}

sf::Font* GraphicsManager::getFont() {
	return &m_Font;
}