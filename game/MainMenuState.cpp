#include <sstream>
#include "MainMenuState.hpp"
#include "Definitions.hpp"

#include <iostream>

namespace Sonar {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data) {

	}

	void MainMenuState::init() {
		_data->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.loadTexture("Main Menu Message", MAIN_MENU_MESSAGE_FILEPATH);

		_background.setTexture(this->_data->assets.getTexture("Main Menu Background"));
		_message.setTexture(this->_data->assets.getTexture("Main Menu Message"));

		_message.setPosition((SCREEN_WIDTH / 2 - _message.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - _message.getGlobalBounds().height / 2);
	}

	void MainMenuState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
				std::cout << "Go to play" << std::endl;
			}
		}
	}

	void MainMenuState::update(float dt) {
	}

	void MainMenuState::draw(float delta) {
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.draw(_message);

		_data->window.display();
	}
}