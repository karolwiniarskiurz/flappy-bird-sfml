#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

namespace FlappyBird {
	class GameState : public State {
	public:
		GameState(GameDataRef data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float delta);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		Pipe* _pipe;
		Land* _land;
		Bird* _bird;
		Flash* _flash;
		HUD* _hud;

		Collision _collision;

		sf::Clock _clock;

		GameStates _state;

		int _score;
	};
}