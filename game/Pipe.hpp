#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "Definitions.hpp"

namespace FlappyBird {
	class Pipe {
	public:
		Pipe(GameDataRef data);

		void drawPipes();

		void spawnTopPipe();

		void spawnBottomPipe();

		void spawnInvisiblePipe();

		void movePipe(float dt);

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _pipeSprites;
	};
}