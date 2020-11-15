#include <sstream>
#include "GameOverState.hpp"
#include "Definitions.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

#include <iostream>

namespace FlappyBird {
	GameOverState::GameOverState(GameDataRef data) : _data(data) {

	}

	void GameOverState::init() {
		_data->assets.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		_data->assets.loadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

		_background.setTexture(this->_data->assets.getTexture("Game Over Background"));
		_gameOverTitle.setTexture(this->_data->assets.getTexture("Game Over Title"));
		_gameOverContainer.setTexture(this->_data->assets.getTexture("Game Over Body"));
		_retryButton.setTexture(this->_data->assets.getTexture("Play Button"));


		_gameOverContainer.setPosition(_data->window.getSize().x / 2 - _gameOverContainer.getGlobalBounds().width / 2,
			_data->window.getSize().y / 2 - _gameOverContainer.getGlobalBounds().height / 2);

		_gameOverTitle.setPosition(_data->window.getSize().x / 2 - _gameOverTitle.getGlobalBounds().width / 2,
			_gameOverContainer.getPosition().y - _gameOverTitle.getGlobalBounds().height * 1.2f);

		_retryButton.setPosition(_data->window.getSize().x / 2 - _retryButton.getGlobalBounds().width / 2,
			_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height * 1.2f);
	}

	void GameOverState::handleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
		}

		if (_data->input.isSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
			_data->machine.addState(StateRef(new GameState(_data)));
		}
	}

	void GameOverState::update(float dt) {
	}

	void GameOverState::draw(float delta) {
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_retryButton);

		_data->window.display();
	}
}