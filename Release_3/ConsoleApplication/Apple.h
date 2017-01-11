#pragma once
#pragma once
#include "Cell.h"
#include "GameConstants.h"
#include <stdio.h>     
#include <stdlib.h> 
#include <time.h>
class Apple
{
private:
	Cell _apple;
	int _appleX;
	int _appleY;

public:
	Apple();
	~Apple();

	
	void setXApplePosition();
	void setYApplePosition();
	int getAppleSprite();
	int getXApplePosition();
	int getYApplePosition();
	

};

/*class Snake 
{
private:
	Cell _snake;
	int _headXPos;
	int _headYPos;
	int _direction;

public:
	Snake();
	Snake(Cell snake, int headXPos, int headYPos, int direction);
	~Snake();
	
	void setXPosition(int x);
	void setYPosition(int y);
	void setDirection(int d);

	int getDirection();
	int getSnakeSprite();
	int getXPosition();
	int getYPosition();
};

*/