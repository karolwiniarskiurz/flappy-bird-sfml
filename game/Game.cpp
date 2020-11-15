#include "Game.hpp"
#include "State.hpp"
#include "MainMenuState.hpp"
#include <stdlib.h>
#include <time.h>

namespace FlappyBird {
	Game::Game(int width, int height, std::string title) {
		srand(time(NULL));

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.addState(StateRef(new MainMenuState(this->_data)));
		this->run();
	}

	void Game::run() {
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();

		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) {
			this->_data->machine.processStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt) {
				this->_data->machine.getActiveState()->handleInput();
				this->_data->machine.getActiveState()->update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.getActiveState()->draw(interpolation);
		}
	}
}