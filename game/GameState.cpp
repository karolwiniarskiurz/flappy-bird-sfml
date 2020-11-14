#include <sstream>
#include "GameState.hpp"
#include "Definitions.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace FlappyBird {
	GameState::GameState(GameDataRef data) : _data(data) {

	}

	void GameState::init() {
		_data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.getTexture("Game Background"));
	}

	void GameState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
		}
	}

	void GameState::update(float dt) {
	}

	void GameState::draw(float delta) {
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}
}