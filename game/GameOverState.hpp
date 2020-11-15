#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace FlappyBird {
	class GameOverState : public State {
	public:
		GameOverState(GameDataRef data, int score);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float delta);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _gameOverTitle;

		sf::Sprite _gameOverContainer;

		sf::Sprite _retryButton;

		sf::Sprite _medal;

		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;
	};
}