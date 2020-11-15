#pragma once

#include <SFMl/Graphics.hpp>
#include "Definitions.hpp"
#include "Game.hpp"

namespace FlappyBird {
	class HUD {
	public:
		HUD(GameDataRef data);

		void draw();
		void updateScore(int score);
	private:
		GameDataRef _data;
		sf::Text _scoreText;
	};

}


