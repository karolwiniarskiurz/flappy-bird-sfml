#include "Land.hpp"
#include "Definitions.hpp"

namespace FlappyBird {
	Land::Land(GameDataRef data) : _data(data) {
		sf::Sprite sprite(_data->assets.getTexture("Land"));
		sf::Sprite sprite2(_data->assets.getTexture("Land"));
		sprite.setPosition(0, _data->window.getSize().y + -sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y + -sprite.getGlobalBounds().height);

		_sprites.push_back(sprite);
		_sprites.push_back(sprite2);
	}

	void Land::moveLand(float dt, float speedfactor) {

		for (unsigned short int i = 0; i < _sprites.size(); i++) {
			float movement = PIPE_SPEED * dt * speedfactor;
			_sprites.at(i).move(-movement, 0.0f);

			if (_sprites.at(i).getPosition().x < 0 - _sprites.at(i).getGlobalBounds().width) {
				sf::Vector2f position(_data->window.getSize().x, _data-> window.getSize().y - _sprites.at(i).getGlobalBounds().height);
				_sprites.at(i).setPosition(position);
			}
		}

	}

	void Land::drawLand() {
		for (unsigned short int i = 0; i < _sprites.size(); i++) {
			_data->window.draw(_sprites.at(i));
		}
	}

	const std::vector<sf::Sprite>& Land::getSprites() const {
		return _sprites;
	}
}