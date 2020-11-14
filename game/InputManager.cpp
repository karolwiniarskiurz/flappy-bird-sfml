#include "InputManager.hpp"
namespace FlappyBird {
	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect rect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (rect.contains(sf::Mouse::getPosition(window))) {
				return true;
			}
		}

		return false;

	}

	sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}
}

