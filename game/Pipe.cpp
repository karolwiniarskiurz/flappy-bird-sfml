#include "Pipe.hpp"
#include <iostream>

namespace FlappyBird {
	Pipe::Pipe(GameDataRef data) : _data(data) {
		_landHeight = _data->assets.getTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}

	void Pipe::drawPipes() {
		for (unsigned short int i = 0; i < _sprites.size(); i++) {
			_data->window.draw(_sprites[i]);
		}
	}

	void Pipe::spawnTopPipe() {
		sf::Sprite sprite(_data->assets.getTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);

		_sprites.push_back(sprite);
	}

	void Pipe::spawnBottomPipe() {
		sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getLocalBounds().height - _pipeSpawnYOffset);

		_sprites.push_back(sprite);
	}

	void Pipe::spawnInvisiblePipe() {
		sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		_sprites.push_back(sprite);
	}

	void Pipe::spawnScoringPipe() {
		sf::Sprite sprite(_data->assets.getTexture("Scoring Pipe"));

		sprite.setPosition(this->_data->window.getSize().x, 0);

		_scoringPipes.push_back(sprite);
	}

	void Pipe::movePipe(float dt) {
		for (unsigned short int i = 0; i < _sprites.size(); i++) {
			if (_sprites.at(i).getPosition().x < 0 - _sprites.at(i).getLocalBounds().width) {
				_sprites.erase(_sprites.begin() + i);
			}
			else {
				float movement = PIPE_SPEED * dt;
				_sprites.at(i).move(-movement, 0);
			}
		}

		for (unsigned short int i = 0; i < _scoringPipes.size(); i++) {
			if (_scoringPipes.at(i).getPosition().x < 0 - _scoringPipes.at(i).getLocalBounds().width) {
				_scoringPipes.erase(_scoringPipes.begin() + i);
			}
			else {
				float movement = PIPE_SPEED * dt;
				_scoringPipes.at(i).move(-movement, 0);
			}
		}
	}

	void Pipe::randomisePipeOffset() {
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}

	const std::vector<sf::Sprite>& Pipe::getSprites() const {
		return _sprites;
	}

	std::vector<sf::Sprite>& Pipe::getScoringPipesSprites() {
		return _scoringPipes;
	}

}