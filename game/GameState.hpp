#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace FlappyBird {
	class GameState : public State {
	public:
		GameState(GameDataRef data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float delta);

	private:
		GameDataRef _data;

		sf::Sprite _background;
	};
}