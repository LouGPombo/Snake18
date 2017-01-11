#pragma once

//Game general information
#define GAME_SPEED 0.1f
#define GAME_TEXTURES 7
#define MAX_MONSTERS 10
#define MONSTER_REFRESH_FREQUENCY 1000

//Sprite information
#define SPRITE_SPEED 0.01f
#define SPRITE_DEFAULT_WIDTH 20
#define SPRITE_DEFAULT_HEIGHT 20
#define SPRITE_HERO 0
#define SPRITE_FIRE 1
#define SPRITE_GRASS 2
#define SPRITE_ROAD 3
#define SPRITE_HELLO 4
#define SPRITE_DIRT 5
#define SPRITE_SNOW 6
#define SPRITE_BAR 7
//Color information
#define GAME_BASIC_COLORS 8
#define RED 0
#define GREEN 1
#define BLUE 2
#define BLACK 3
#define WHITE 4
#define MAX_ROW 35
#define MAX_COLUMN 20


//Game has four possible states: INIT (Preparing environment), PLAY (Playing), EXIT (Exit from the game) or MENU (Game menu)
enum class GameState { INIT, PLAY, EXIT, MENU, GAMEMENU };
//enum class GameLevel { INIT, PLAY, EXIT, MENU, GAMEMENU };


enum movement {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NOMOVE
};