#include "InputManager.h"
#include <map>

InputManager* InputManager::m_Instance = new InputManager();

InputManager::InputManager(){
	m_Keys[Action::Up] = sf::Keyboard::W;
	m_Keys[Action::Left] = sf::Keyboard::A;
	m_Keys[Action::Down] = sf::Keyboard::S;
	m_Keys[Action::Right] = sf::Keyboard::D;
	m_Buttons[Action::Interact] = sf::Mouse::Left;
	m_Buttons[Action::Secendary] = sf::Mouse::Right;
	m_Keys[Action::UseItem] = sf::Keyboard::E;
}

InputManager::~InputManager(){}

InputManager* InputManager::getInstance(){
	return m_Instance;
}

bool InputManager::isKeyPressed(Action action){
	if (m_Keys.find(action) != m_Keys.end()) {
		if (sf::Keyboard::isKeyPressed(m_Keys[action])) {
			return true;
		}
	}

	if (m_Buttons.find(action) != m_Buttons.end()) {
		if (sf::Mouse::isButtonPressed(m_Buttons[action]))
			return true;
	}

	return false;
}