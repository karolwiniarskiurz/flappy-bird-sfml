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
		_data->assets.loadTexture("Scoring Pipe", PIPE_SCORING_FILEPATH);
		_data->assets.loadFont("Flappy Font", FLAPPY_FONT_FILEPATH);


		_pipe = new Pipe(_data);
		_land = new Land(_data);
		_bird = new Bird(_data);
		_flash = new Flash(_data);
		_hud = new HUD(_data);

		_background.setTexture(this->_data->assets.getTexture("Game Background"));

		_score = 0;
		_hud->updateScore(_score);

		_state = GameStates::READY;
	}

	void GameState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window) ||
				sf::Event::KeyPressed == event.type && event.key.code == sf::Keyboard::Space) {
				if (_state != GameStates::OVER) {
					_state = GameStates::PLAYING;
					_bird->tap();
				}
			}
		}
	}

	void GameState::update(float dt) {
		if (_state != GameStates::OVER) {
			_bird->animate(dt);
			_land->moveLand(dt);

		}

		if (_state == GameStates::PLAYING) {
			_pipe->movePipe(dt);

			if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
				_pipe->randomisePipeOffset();
				_pipe->spawnInvisiblePipe();
				_pipe->spawnBottomPipe();
				_pipe->spawnTopPipe();
				_pipe->spawnScoringPipe();

				_clock.restart();
			}
			_bird->update(dt);

			std::vector<sf::Sprite> landSprites = _land->getSprites();

			for (int i = 0; i < landSprites.size(); i++) {
				if (_collision.checkCollision(_bird->getSprite(), 0.7f, landSprites.at(i), 1.0f)) {
					_state = GameStates::OVER;
				}
			}

			std::vector<sf::Sprite> pipeSprites = _pipe->getSprites();
			for (int i = 0; i < pipeSprites.size(); i++) {
				if (_collision.checkCollision(_bird->getSprite(), 0.61f, pipeSprites.at(i), 1.0f)) {
					_state = GameStates::OVER;
				}
			}

			if (_state == GameStates::PLAYING) {
				std::vector<sf::Sprite>& scoringPipeSprites = _pipe->getScoringPipesSprites();
				for (int i = 0; i < scoringPipeSprites.size(); i++) {
					if (_collision.checkCollision(_bird->getSprite(), 0.61f, scoringPipeSprites.at(i), 1.0f)) {
						_score++;

						_hud->updateScore(_score);

						scoringPipeSprites.erase(scoringPipeSprites.begin() + i);
					}
				}
			}
		}

		if (_state == GameStates::OVER) {
			_flash->show(dt);
		}
	}

	void GameState::draw(float delta) {
		_data->window.clear();

		_data->window.draw(_background);

		_pipe->drawPipes();
		_land->drawLand();
		_bird->draw();
		_flash->draw();
		_hud->draw();

		_data->window.display();
	}
}