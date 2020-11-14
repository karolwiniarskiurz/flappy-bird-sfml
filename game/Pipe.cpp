#include "Pipe.hpp"
namespace FlappyBird {
	Pipe::Pipe(GameDataRef data) : _data(data) {}

	void Pipe::drawPipes() {
		for (unsigned short int i = 0; i < _pipeSprites.size(); i++) {
			_data->window.draw(_pipeSprites[i]);
		}
	}

	void Pipe::spawnTopPipe() {
		sf::Sprite sprite(_data->assets.getTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x, 0);

		_pipeSprites.push_back(sprite);
	}

	void Pipe::spawnBottomPipe() {
		sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data -> window.getSize().y - sprite.getGlobalBounds().height);

		_pipeSprites.push_back(sprite);
	}

	void Pipe::spawnInvisiblePipe() {
		sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
		sprite.setPosition(0, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		_pipeSprites.push_back(sprite);
	}

	void Pipe::movePipe(float dt) {
		for (unsigned short int i = 0; i < _pipeSprites.size(); i++) {
			sf::Vector2f position = _pipeSprites.at(i).getPosition();
			float movement = PIPE_SPEED * dt;

			_pipeSprites.at(i).move(-movement, 0);
		}
	}
}