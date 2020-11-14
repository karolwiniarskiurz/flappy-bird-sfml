#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace FlappyBird {
	class SplashState : public State {
	public: 
		SplashState(GameDataRef data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float delta);

	private:
		GameDataRef _data;
		sf::Clock _clock;

		sf::Sprite _background;
	};
}