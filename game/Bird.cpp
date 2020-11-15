#include "Bird.hpp"

namespace FlappyBird {
	Bird::Bird(GameDataRef data) : _data(data) {
		_animationIterator = 0;
		_animationFrames.push_back(_data->assets.getTexture("Bird 1"));
		_animationFrames.push_back(_data->assets.getTexture("Bird 2"));
		_animationFrames.push_back(_data->assets.getTexture("Bird 3"));
		_animationFrames.push_back(_data->assets.getTexture("Bird 4"));
		_sprite.setTexture(_animationFrames.at(_animationIterator));

		_sprite.setPosition(_data->window.getSize().x / 4 - _sprite.getGlobalBounds().width / 2,
			_data->window.getSize().y / 2 - _sprite.getGlobalBounds().height / 2);

		_state = BirdState::STILL;
		sf::Vector2f origin = sf::Vector2f(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
		_sprite.setOrigin(origin);
		_rotation = 0;
	}

	void Bird::draw() {
		_data->window.draw(_sprite);
	}

	void Bird::animate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()) {
			if (_animationIterator < _animationFrames.size() - 1) {
				_animationIterator++;
			}
			else {
				_animationIterator = 0;
			}

			_sprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Bird::update(float dt) {
		if (_state == BirdState::FALLING) {
			_sprite.move(0, GRAVITY * dt);

			_rotation += ROTATION_SPEED * dt;

			if (_rotation > 30.0f) {
				_rotation = 30.0f;
			}
		}
		else if (_state == BirdState::FLYING) {
			_sprite.move(0, -FLYING_SPEED * dt);

			_rotation -= ROTATION_SPEED * dt;

			if (_rotation < -30.0f) {
				_rotation = -30.0f;
			}
		}

		_sprite.setRotation(_rotation);

		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
			_movementClock.restart();
			_state = BirdState::FALLING;
		}
	}

	void Bird::tap() {
		_movementClock.restart();
		_state = BirdState::FLYING;
	}

	const sf::Sprite& Bird::getSprite() const {
		return _sprite;
	}
}