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
		_data->assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

		_pipe = new Pipe(_data);

		_background.setTexture(this->_data->assets.getTexture("Game Background"));
	}

	void GameState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
				_pipe->spawnInvisiblePipe();
				_pipe->spawnBottomPipe();
				_pipe->spawnTopPipe();
			}
		}
	}

	void GameState::update(float dt) {
		_pipe->movePipe(dt);
	}

	void GameState::draw(float delta) {
		_data->window.clear();

		_data->window.draw(_background);

		_pipe->drawPipes();

		_data->window.display();
	}
}