#include "Land.hpp"
#include "Definitions.hpp"

namespace FlappyBird {
	Land::Land(GameDataRef data) : _data(data) {
		sf::Sprite sprite(_data->assets.getTexture("Land"));
		sf::Sprite sprite2(_data->assets.getTexture("Land"));
		sprite.setPosition(0, _data->window.getSize().y + -sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y + -sprite.getGlobalBounds().height);

		_landSprites.push_back(sprite);
		_landSprites.push_back(sprite2);
	}

	void Land::moveLand(float dt) {

		for (unsigned short int i = 0; i < _landSprites.size(); i++) {
			float movement = PIPE_SPEED * dt;
			_landSprites.at(i).move(-movement, 0.0f);

			if (_landSprites.at(i).getPosition().x <= 0 - _landSprites.at(i).getGlobalBounds().width) {
				sf::Vector2f position(_data->window.getSize().x, _data-> window.getSize().y - _landSprites.at(i).getGlobalBounds().height);
				_landSprites.at(i).setPosition(position);
			}
		}

	}

	void Land::drawLand() {
		for (unsigned short int i = 0; i < _landSprites.size(); i++) {
			_data->window.draw(_landSprites.at(i));
		}
	}
}