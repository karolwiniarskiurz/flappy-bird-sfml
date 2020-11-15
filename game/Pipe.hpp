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

		void randomisePipeOffset();

		const std::vector<sf::Sprite>& getSprites() const;

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _sprites;

		int _landHeight;
		int _pipeSpawnYOffset;
	};
}