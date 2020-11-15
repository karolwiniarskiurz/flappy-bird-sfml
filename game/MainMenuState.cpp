#include <sstream>
#include "MainMenuState.hpp"
#include "Definitions.hpp"
#include "GameState.hpp"

#include <iostream>

namespace FlappyBird {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data) {

	}

	void MainMenuState::init() {
		_data->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.loadTexture("Main Menu Title", MAIN_MENU_TITLE_FILEPATH);
		_data->assets.loadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);

		_background.setTexture(this->_data->assets.getTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.getTexture("Main Menu Title"));
		_button.setTexture(this->_data->assets.getTexture("Play Button"));

		_title.setPosition(_data->window.getSize().x / 2 - _title.getGlobalBounds().width / 2,
			_data->window.getSize().y / 4 - _title.getGlobalBounds().height);
		_button.setPosition(_data->window.getSize().x / 2 - _button.getGlobalBounds().width / 2,
			_data->window.getSize().y / 2 - _button.getGlobalBounds().height / 2);
	}

	void MainMenuState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.isSpriteClicked(_button, sf::Mouse::Left, _data->window)) {
				_data->machine.addState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::update(float dt) {
	}

	void MainMenuState::draw(float delta) {
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.draw(_title);
		_data->window.draw(_button);

		_data->window.display();
	}
}