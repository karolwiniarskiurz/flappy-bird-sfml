#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Definitions.hpp"

namespace FlappyBird {
	class Flash {
	public:
		Flash(GameDataRef data);
		void show(float dt);
		void draw();
	private:
		GameDataRef _data;
		sf::RectangleShape _shape;
		bool _flashOn;
	};
}
