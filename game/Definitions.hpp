#pragma once

constexpr auto SCREEN_WIDTH = 768;
constexpr auto SCREEN_HEIGHT = 1024;
constexpr auto GAME_NAME = "Flappy bird";

constexpr auto MAIN_MENU_BACKGROUND_FILEPATH = "Resources/sprites/background-day.png";
constexpr auto MAIN_MENU_MESSAGE_FILEPATH = "Resources/sprites/message.png";

constexpr auto GAME_BACKGROUND_FILEPATH = "Resources/sprites/background-day.png";
constexpr auto PIPE_UP_FILEPATH = "Resources/sprites/pipe-up-green.png";
constexpr auto PIPE_DOWN_FILEPATH = "Resources/sprites/pipe-down-green.png";
constexpr auto PIPE_SCORING_FILEPATH = "Resources/sprites/pipe-scoring.png";
constexpr auto PIPE_SPEED = 200;
constexpr auto PIPE_SPAWN_FREQUENCY = 2.0f;

constexpr auto BIRD_1_FILEPATH = "Resources/sprites/bird-01.png";
constexpr auto BIRD_2_FILEPATH = "Resources/sprites/bird-02.png";
constexpr auto BIRD_3_FILEPATH = "Resources/sprites/bird-03.png";
constexpr auto BIRD_4_FILEPATH = "Resources/sprites/bird-04.png";
constexpr auto BIRD_ANIMATION_DURATION = 0.5f;

constexpr auto LAND_BASE_FILENAME = "Resources/sprites/base.png";

constexpr auto GAME_OVER_BACKGROUND_FILEPATH = "Resources/sprites/background-day.png";

enum BirdState {
	STILL,
	FALLING,
	FLYING
};
constexpr auto GRAVITY = 400.0f;
constexpr auto FLYING_SPEED = 350.0f;
constexpr auto FLYING_DURATION = 0.25f;
constexpr auto ROTATION_SPEED = 100.0f;

enum GameStates {
	READY,
	PLAYING,
	OVER
};

constexpr auto FLASH_SPEED = 1000.0f;
