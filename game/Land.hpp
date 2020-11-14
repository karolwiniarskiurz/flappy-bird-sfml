#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace FlappyBird {
	class Land {
	public:
		Land(GameDataRef data);

		void moveLand(float dt);

		void drawLand();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite>_landSprites;
	};
}