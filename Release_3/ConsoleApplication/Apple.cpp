#include "Apple.h"



Apple::Apple()
{
	_apple = 0;
	_appleX = 0;
	_appleY = 0;
}


Apple::~Apple()
{
}


void Apple::setXApplePosition()
{
	srand(time(NULL));
	_appleX = (int)rand() % 33 + 1;
}

void Apple::setYApplePosition()
{
	srand(time(NULL));
	_appleY = (int)rand() % 18 + 1;
}

int Apple::getAppleSprite()
{
	return SPRITE_SNOW;
}

int Apple::getXApplePosition()
{
	return _appleX;
}

int Apple::getYApplePosition()
{
	return _appleY;
}
