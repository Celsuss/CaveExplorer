#pragma once
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include <map>

class InputManager{
public:
	enum Action{
		Up,
		Left,
		Down,
		Right,
		Attack,
		Secendary,
		UseItem
	};
	typedef std::map<Action, sf::Keyboard::Key> KeyMap;
	typedef std::map<Action, sf::Mouse::Button> ButtonMap;

	static InputManager* getInstance();
	bool isKeyPressed(Action action);
private:
	InputManager();
	~InputManager();
	static InputManager* m_Instance;

	KeyMap m_Keys;
	ButtonMap m_Buttons;
};