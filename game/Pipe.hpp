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
		
		void spawnScoringPipe();

		void movePipe(float dt, float speedfactor);

		void randomisePipeOffset();

		const std::vector<sf::Sprite>& getSprites() const;
		std::vector<sf::Sprite>& getScoringPipesSprites();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _sprites;
		std::vector<sf::Sprite> _scoringPipes;

		int _landHeight;
		int _pipeSpawnYOffset;
	};
}