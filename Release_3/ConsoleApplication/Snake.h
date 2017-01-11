#pragma once
#include "Cell.h"
#include "GameConstants.h"
#include <time.h>
#include <vector>
class Snake 
{
private:

public:
	int n;
	int _lives;
	Cell _snake;
	Cell _bodySprite;
	//Cell _tail;
	int _snakeSize;
	int _headXPos;
	int _headYPos;
	//int _tailXPos;
	//int _tailYPos;
	int _body[MAX_COLUMN*MAX_ROW][2];
	int _direction;
	float _snakeSpeed; 
	clock_t beginT = clock()*CLK_TCK;
	//tiempo que transcurre entre movimiento y movimiento (puesto en 0.5segs y cada manzana disminuye ese tiempo en 0.01)
	//std::vector<Snake> cuerpo;  
	
	//struct Seguir {
	//	Cell _body = 0;
	//	int x=0;
	//	int y=0;
	//};
	//std::vector<Seguir> cuerpo;

	//Seguir tmpsnake;
	
	Snake();
	Snake(Cell _body, int headXPos, int headYPos, int direction);
	~Snake();

	//void saveLastPosition();
	void setArrayPosition(int x,int y);
	
	void setSprite();
	void setLive(int l);
	//void setTailXPosition(int x);
	//void setTailYPosition(int y);
	void setXPosition(int x);
	void setYPosition(int y);
	void setDirection(int d);
	void changeSpeed(float s);

	//int getLastX();
	//int getLastY();

	int getLive();

	int getDirection();
	int getSnakeSprite();
	int getXPosition();
	int getYPosition();
	float getSpeed();
};

