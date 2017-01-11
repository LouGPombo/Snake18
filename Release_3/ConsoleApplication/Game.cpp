
#include "Game.h"

Game::Game(std::string windowTitle, int screenWidth, int screenHeight) :
	_windowTitle(windowTitle),
	_screenWidth(screenWidth),
	_screenHeight(screenHeight),
	_gameState(GameState::INIT) {}

Game::~Game()
{
}


void Game::run() {
	//Prepare the game components
	init();
	//Start the game if everything is ready
	gameLoop();
}

/*
* Initialize all the components
*/
void Game::init() {
	
	_map.snake.setLive(3);
	//std::cout << _map.snake.getLive();
	
	_map.snake._snakeSize = 0;
	_map.snake.changeSpeed(0.5);
	_map.snake.setDirection(3);
	//std::cout << _map.getSpeed() << std::endl;
	_map.snake.setXPosition(2);
	_map.snake.setYPosition(2);
	_map.snake.setLive(3);
	srand((unsigned int)time(NULL));
	//Create a window
	_graphic.createWindow(_windowTitle, _screenWidth, _screenHeight, false);
	_graphic.setWindowBackgroundColor(255, 255, 255, 255);
	
	_graphic.loadTexture(SPRITE_HERO, "../sharedResources/images/characters/Hero.png");
	_graphic.loadTexture(SPRITE_ROAD, "../sharedResources/images/terrain/roadh.bmp");
	//hero.setInitialValues(500, 500, SPRITE_HERO, 0, 1);
	_graphic.loadTexture(SPRITE_GRASS, "../sharedResources/images/terrain/grass1.bmp");
	_graphic.loadTexture(SPRITE_DIRT, "../sharedResources/images/terrain/dirt.bmp");
	//_graphic.loadTexture(SPRITE_BAR, "../sharedResources/images/objects/bar.bmp");

	_graphic.setFontStyle(TTF_STYLE_NORMAL);

	//init map
	_map.initMap(&_graphic);

}


/*
* Game execution: Gets input events, processes game logic and draws sprites on the screen
*/
void Game::gameLoop() {

	_gameState = GameState::MENU;

	while (_gameState != GameState::EXIT) {
		//Detect keyboard and/or mouse events
		_graphic.detectInputEvents();

		if (_gameState == GameState::MENU && _gameState != GameState::GAMEMENU && _gameState != GameState::PLAY) {
			executeMenuCommands();
		}
		else if (_gameState == GameState::GAMEMENU && _gameState != GameState::MENU && _gameState != GameState::PLAY) {
			executeGameMenuCommands();
		}
		else if (_gameState == GameState::PLAY && _gameState != GameState::MENU && _gameState != GameState::GAMEMENU) {
			//Execute the player commands 

			executePlayerCommands();
			//Update the game physics
			doPhysics();
		}//Render game
		renderGame();
	}

}

void Game::executeMenuCommands() {
	glm::ivec2 mouseCoords;

	if (_graphic.isKeyPressed(SDL_BUTTON_LEFT)) {
		mouseCoords = _graphic.getMouseCoords();
		//::cout << "Screen (" << mouseCoords.x << ", " << mouseCoords.y << ")" << std::endl;

		if (mouseCoords.x >= 300 && mouseCoords.x <= 350 && mouseCoords.y >= 250 && mouseCoords.y <= 270) {
			_gameState = GameState::GAMEMENU;
		}
		if (mouseCoords.x >= 300 && mouseCoords.x <= 350 && mouseCoords.y >= 350 && mouseCoords.y <= 370) {
			_gameState = GameState::EXIT;
		}
	}
}

void Game::executeGameMenuCommands() {
	glm::ivec2 mouseCoords;

	if (_graphic.isKeyPressed(SDL_BUTTON_LEFT)) {
		mouseCoords = _graphic.getMouseCoords();
		//std::cout << "Screen (" << mouseCoords.x << ", " << mouseCoords.y << ")" << std::endl;

		if (mouseCoords.x >= 300 && mouseCoords.x <= 350 && mouseCoords.y >= 250 && mouseCoords.y <= 270) {
			_map._easy = true;
			_map.snake.changeSpeed(0.5);
			_map.setLevel(1);
			_map.setTime(240);
			_gameState = GameState::PLAY;
		}
		if (mouseCoords.x >= 300 && mouseCoords.x <= 395 && mouseCoords.y >= 300 && mouseCoords.y <= 319) {
			_map._medium = true;
			_map.snake.changeSpeed(0.25);
			_map.setLevel(1);
			_map.setTime(120);
			_gameState = GameState::PLAY;
		}
		if (mouseCoords.x >= 300 && mouseCoords.x <= 350 && mouseCoords.y >= 350 && mouseCoords.y <= 370) {
			_map._hard = true;
			_map.snake.changeSpeed(0.125);
			_map.setLevel(1);
			_map.setTime(60);
			_gameState = GameState::PLAY;
		}
	}
}


void Game::executePlayerCommands() {
	//std::cout << "x: " << hero.getXAtWorld() << std::endl;
	//std::cout << "y: " << hero.getYAtWorld() << std::endl;
	glm::ivec2 mouseCoords;


	if (_graphic.isKeyPressed(SDL_BUTTON_LEFT)) {
		mouseCoords = _graphic.getMouseCoords();
		std::cout << "Screen (" << mouseCoords.x << ", " << mouseCoords.y << ")" << std::endl;
	}
	

	if (_graphic.isKeyPressed(SDLK_ESCAPE) ) {
		pause = !pause;
		
	}

	if (_graphic.isKeyDown(SDLK_UP) && _map.snake.getDirection()!=2) {
		
		_map.snake.setDirection(1);
		
		/*if (hero.getYAtWorld() >= 0) {
			hero.setPositionAtWorld(hero.getXAtWorld(), hero.getYAtWorld() - 5);
			_map.change(2);
		}*/
	
	}

	if (_graphic.isKeyDown(SDLK_LEFT) && _map.snake.getDirection() != 3) {
		_map.snake.setDirection(4);
		
	}
	if (_graphic.isKeyDown(SDLK_DOWN) && _map.snake.getDirection() != 1) {
		_map.snake.setDirection(2);
	}

	if (_graphic.isKeyDown(SDLK_RIGHT) && _map.snake.getDirection() != 4) {
		_map.snake.setDirection(3);
	}


	
}

/*
* Execute the game physics
*/
void Game::doPhysics() {
//Realese 2
}

/**
* Render the game on the screen
*/


void Game::gameOver() {
	//std::cout << _map.snake.getLive();

	if (_map.snake.getLive() == 0) {
		//snake.setLive(2);
		//std::cout << "WHAT THE FUCK" << snake.getLive()<< std::endl;
		//_graphic.drawRectangle(WHITE,0,0,1000,1000);
		_gameState = GameState::MENU;
		_map.snake.setLive(3);
	}
}

clock_t snakeBegin = clock()*CLK_TCK;

void Game::renderGame() {
	
	

	//TODO hacer que la pausa pare el time
	

	//Clear the screen
	_graphic.clearWindow();
	//std::chrono::seconds dura(1);
	//Draw the screen's content based on the game state
	if (_gameState == GameState::MENU) {
		drawMenu();
	}

	if (_gameState == GameState::GAMEMENU) {
		drawGameMenu();
	}

	if (_gameState == GameState::PLAY) {
		//clock_t begin = clock()*CLK_TCK;
		if (pause == false) {
			gameOver();
			clock_t t(clock() * CLK_TCK);
			clock_t snakeEnd(clock() * CLK_TCK);
			snakeTimer = (snakeEnd - snakeBegin) / (1000);
			timer = (t - _map.snake.beginT) / (1000 * 1000);
			crono = _map._levelTime - (timer);
			minutes = (int)crono / 60;
			seconds = (int)crono % 60;


			if (_map.checkApple(_map.apple.getXApplePosition(), _map.apple.getYApplePosition(), _map.snake.getXPosition(), _map.snake.getYPosition()) == true) {
				//std::cout << "HOOOOOOOOOOOO" << std::endl;
				_map.snake.changeSpeed(_map.eatApple(_map.snake.getSpeed()));
			}




			//std::cout << _map.snake.getSpeed() << std::endl;

			if (snakeTimer > _map.snake.getSpeed() * 1000) {
				snakeBegin = clock()*CLK_TCK;

				if (_map.snake.getDirection() == 1) {//arriba
								//_map.snake.setTailXPosition(_map.snake.getXPosition());
								//_map.snake.setTailYPosition(_map.snake.getYPosition());
					_map.snake.setArrayPosition(_map.snake.getXPosition(), _map.snake.getYPosition());

					_map.snake.setYPosition(_map.snake.getYPosition() - 1);
					
					//snakeTimer = 0;
					//std::this_thread::sleep_for(dura);
				}
				if (_map.snake.getDirection() == 2) {//abajo

					//std::cout << " ??? " << _map.snake.getYPosition() << std::endl;
								//_map.snake.setTailXPosition(_map.snake.getXPosition());
								//_map.snake.setTailYPosition(_map.snake.getYPosition());

					_map.snake.setArrayPosition(_map.snake.getXPosition(), _map.snake.getYPosition());
					_map.snake.setYPosition(_map.snake.getYPosition() + 1);
					//snakeTimer = 0;

					//std::this_thread::sleep_for(dura);
				}
				if (_map.snake.getDirection() == 3) {//derecha
								//_map.snake.setTailXPosition(_map.snake.getXPosition());
								//_map.snake.setTailYPosition(_map.snake.getYPosition());
					_map.snake.setArrayPosition(_map.snake.getXPosition(), _map.snake.getYPosition());

					_map.snake.setXPosition(_map.snake.getXPosition() + 1);
					//snakeTimer = 0;
					//std::this_thread::sleep_for(dura);
				}
				if (_map.snake.getDirection() == 4) {//izquierda
								//_map.snake.setTailXPosition(_map.snake.getXPosition());
								//_map.snake.setTailYPosition(_map.snake.getYPosition());
					_map.snake.setArrayPosition(_map.snake.getXPosition(), _map.snake.getYPosition());

					_map.snake.setXPosition(_map.snake.getXPosition() - 1);
					//snakeTimer = 0;
					//	std::this_thread::sleep_for(dura);
				}
			}


			//_map.moveSnake(snake);
			drawGame();
		}
		else if (pause == true) {
			drawGame();
			_graphic.drawText("PAUSE", BLACK, WHITE, 300, 250);
		}
	}
	//Refresh screen
	_graphic.refreshWindow();
}

/*
* Draw the game menu
*/
void Game::drawMenu() {
	
	_graphic.drawText(" ¡¡SNAKE!!", RED, WHITE, 225, 20);
	_graphic.drawText("PLAY", BLACK, WHITE, 300, 250);
//	_graphic.drawText("OPTIONS", BLACK, WHITE, 300, 300);
	_graphic.drawText("EXIT", BLACK, WHITE, 300, 350);
	
}

void Game::drawGameMenu() {

	_graphic.drawText(" ¡¡SNAKE!!", RED, WHITE, 225, 20);
	_graphic.drawText("EASY", BLACK, WHITE, 300, 250);
	_graphic.drawText("MEDIUM", BLACK, WHITE, 300, 300);
	_graphic.drawText("HARD", BLACK, WHITE, 300, 350);

}

/*
* Draw the game, winner or loser screen
*/
void Game::drawGame() {
	//_map.initMap(&_graphic);
	_map.drawMap();
	
		//std::cout << "x " << _map.getXPosition() << std::endl;
		//std::cout << "y" << _map.getYPosition() << std::endl;
	//std::cout<<" TIME " << seconds << std::endl;
	_map.moveSnake(_map.snake.getXPosition(), _map.snake.getYPosition());
	_graphic.drawText("SCORE:" + std::to_string(_map.getScore()), BLACK, WHITE, 0, 600);
	_graphic.drawText("LEVEL:" + std::to_string(_map.getLevel()), BLACK, WHITE, 0, 550);
	_graphic.drawText("LIVES:" + std::to_string(_map.snake._lives), BLACK, WHITE, 0, 500);
	_graphic.drawRectangle(BLACK,77,448,minutes*60 + seconds,30);
	_graphic.drawText("TIME: " , BLACK, WHITE, 0, 450);
	
	
	//drawSprite(hero);
	
}

void Game::drawSprite(Sprite & sprite) {
	_graphic.drawTexture(sprite.getSpriteId(), SPRITE_DEFAULT_WIDTH*sprite.getCurrentFrame(), 0, SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT
		, sprite.getXAtWorld(), sprite.getYAtWorld(), SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT);
}

