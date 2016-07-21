#include "Menu.h"
#include "Game.h"
#include "Level.h"
#include "GraphicManager.h"

Menu::Menu(){
	m_State = State::Menu;

	sf::Vector2f pos = sf::Vector2f(GraphicManager::getInstance()->getWindow()->getSize().x / 2,
									GraphicManager::getInstance()->getWindow()->getSize().y / 2);

	m_UIButtons.push_back(new UIButton(UIButton::Start, pos, "Start"));

	pos.y *= 1.2;
	m_UIButtons.push_back(new UIButton(UIButton::Exit, pos, "Exit"));
}

Menu::~Menu(){}

void Menu::enter() {

}

void Menu::exit() {

}