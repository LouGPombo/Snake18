#pragma once
#include "Cell.h"
#include "SDLInterface.h"
#include "GameConstants.h"
#include "Snake.h"
#include "Apple.h"
class Map 
{
private:

	
public:
	Cell * * _arrayCells;
	//camera source;
	//camera target;
	int _needToEat;
	int _score;
	bool _init;
	int _xElements;
	int _yElements;
	int _levelTime;
	SDLInterface *_graphic;
	Snake snake;
	Apple apple;
	int _level; //Hare los niveles directamente desde map ya que tengo aquí la mayoría de funciones y me gustaría mantener en Game solo los bucles para correr el juego
	bool _easy, _medium, _hard;//haré las modificaciones de grid,velocidad, tiempo y alimentos directamente en sus funcioes en lugar de crear un enum en GameConstant.
	Map();		
	Map(Cell ** arrayCells, int _xElements, int _yElements);
	~Map();
	void initMap(SDLInterface *_graphic);
	void drawMap();
	void change(int direction);
	void moveSnake(int x, int y);
	
	float eatApple(float speed);
	bool checkApple(int appleX, int appleY, int snakeX, int snakeY);

	//void fillSnakeInMap(Snake snake);

	//Snake snakeNextSegment(Snake snake, int i);

	//void snakeMovesBy(Snake snake);

	//void grow();
	void snakeDeath();
	
	void setScore(int s);
	int getScore();
	void printSnakeInMap();
	void setLevel(int l);
	int getLevel();
	void changeLevel(int a);
	//int controlTiming();
	//void setBool(int a);
	void setTime(int t);
	//int getTime();*/
	//void moveSnake(Snake snake);
};

