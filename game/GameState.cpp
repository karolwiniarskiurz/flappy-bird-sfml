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
		_data->assets.loadTexture("Land", LAND_BASE_FILENAME);
		_data->assets.loadTexture("Bird 1", BIRD_1_FILEPATH);
		_data->assets.loadTexture("Bird 2", BIRD_2_FILEPATH);
		_data->assets.loadTexture("Bird 3", BIRD_3_FILEPATH);
		_data->assets.loadTexture("Bird 4", BIRD_4_FILEPATH);


		_pipe = new Pipe(_data);

		_land = new Land(_data);

		_bird = new Bird(_data);

		_background.setTexture(this->_data->assets.getTexture("Game Background"));
	}

	void GameState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window) ||
				sf::Event::KeyPressed == event.type && event.key.code == sf::Keyboard::Space) {
				_bird->tap();
			}
		}
	}

	void GameState::update(float dt) {
		_pipe->movePipe(dt);
		_land->moveLand(dt);

		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
			_pipe->randomisePipeOffset();
			_pipe->spawnInvisiblePipe();
			_pipe->spawnBottomPipe();
			_pipe->spawnTopPipe();

			_clock.restart();
		}
		_bird->animate(dt);
		_bird->update(dt);
	}

	void GameState::draw(float delta) {
		_data->window.clear();

		_data->window.draw(_background);

		_pipe->drawPipes();
		_land->drawLand();
		_bird->draw();

		_data->window.display();
	}
}