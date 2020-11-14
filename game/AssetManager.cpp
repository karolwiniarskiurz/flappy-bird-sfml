#include "AssetManager.hpp"

namespace Sonar {
	void AssetManager::loadTexture(std::string name, std::string fileName) {
		sf::Texture texture;

		if (texture.loadFromFile(fileName)) {
			this->_textures[name] = texture;
		}
	}

	sf::Texture& AssetManager::getTexture(std::string name) {
		return this->_textures.at(name);
	}

	void AssetManager::loadFont(std::string name, std::string fileName) {
		sf::Font texture;

		if (texture.loadFromFile(fileName)) {
			this->_fonts[name] = texture;
		}
	}

	sf::Font& AssetManager::getFont(std::string name) {
		return this->_fonts[name];
	}
}