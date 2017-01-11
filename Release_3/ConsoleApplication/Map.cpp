#include "Map.h"
#include "Game.h"


Map::Map() {

	_arrayCells = 0;
}

Map::Map(Cell **arrayCells, int _xElements, int _yElements)
{
	this->_arrayCells = arrayCells;
}


Map::~Map()
{
	for (int i = 0; i < _xElements; i++) {
		delete[] _arrayCells[i];
	}
	delete[] _arrayCells;
}

void Map::initMap(SDLInterface  *graphicGame) {
	_graphic = graphicGame;
	
	if (_init == false) {
		apple.setXApplePosition();
		apple.setYApplePosition();
		_init = true;
	}
	//source.x = 0;
	//source.y = 0;
	//target.x = 12;
	//target.y = 10;

	_xElements = MAX_ROW;
	_yElements = MAX_COLUMN;
	
	_arrayCells = new Cell*[_xElements];

	if (_arrayCells == 0)
		throw std::exception("System was not able to allocate memory");

	for (int i = 0; i < _xElements; i++) {
		_arrayCells[i] = new Cell[_yElements];
		if (_arrayCells[i] == 0)
			throw std::exception("System was not able to allocate memory");
	}
	


	

	//Poner a cada casilla del map un ID de la textura
	for (int a = 0; a < MAX_ROW; a++) {
		for (int b = 0; b < MAX_COLUMN; b++) {
			_arrayCells[a][b].setMaterial(SPRITE_GRASS);
		}
	}
	for (int a = 0; a < MAX_ROW; a++) {
		_arrayCells[a][0].setMaterial(SPRITE_DIRT);
		_arrayCells[a][19].setMaterial(SPRITE_DIRT);
	}

	for (int a = 0; a < MAX_COLUMN; a++) {
		_arrayCells[0][a].setMaterial(SPRITE_DIRT);
		 _arrayCells[34][a].setMaterial(SPRITE_DIRT);
	}
	//_arrayCells[2][2].setMaterial(SPRITE_DIRT);

	/*
	snake.setXPosition(2);
	snake.setYPosition(2);
	snake.getSnakeSprite().setMaterial(SPRITE_DIRT);
	_arrayCells[snake.getXPosition()][snake.getYPosition()].setMaterial(SPRITE_DIRT);*/
/*
	for (int i = 2; i < 8; i++) {
		_arrayCells[2][i].setMaterial(SPRITE_DIRT);
	}

	for (int i = 3; i < 9; i++) {
		_arrayCells[i][2].setMaterial(SPRITE_DIRT);
	}

	for (int i = 2; i < 8; i++) {
		_arrayCells[i][8].setMaterial(SPRITE_DIRT);
	}

	for (int i = 3; i < 9; i++) {
		_arrayCells[8][i].setMaterial(SPRITE_DIRT);
	}
	
	for (int i = 3; i <= 7; i++) {
		for (int j = 3; j < 8;j++) {
			_arrayCells[j][i].setMaterial(SPRITE_DIRT);
		}
	}

	for (int i = 4; i <= 6; i++) {
		for (int j = 4; j < 7;j++) {
			_arrayCells[j][i].setMaterial(SPRITE_DIRT);
		}
	}*/

}





void Map::drawMap() {

	int numColumnas = MAX_ROW;
	int numFilas = MAX_COLUMN;
	for (int x = 0; x < numColumnas; x++) {
		for (int y = 0; y < numFilas; y++) {
			_graphic->drawTexture(_arrayCells[x][y].getMaterial(), 0, 0, 20, 20, x*SPRITE_DEFAULT_HEIGHT, y*SPRITE_DEFAULT_WIDTH, 20, 20);
		}

	}

	if (snake.getXPosition() == 0 || snake.getYPosition() == 0 || snake.getXPosition() == MAX_ROW - 1 || snake.getYPosition() == MAX_COLUMN - 1) {
		snakeDeath();
	}
	

	for (int i = 1; i <= snake._snakeSize; i++) {
		if (snake._body[snake.n - i][0] == snake.getXPosition() && snake._body[snake.n - i][1] == snake.getYPosition()) { snakeDeath(); }
		//_arrayCells[snake._body[snake.n - i][0]][snake._body[snake.n - i][1]].setMaterial(snake.getSnakeSprite());
		//::cout << "i " << i << std::endl;
	}

	//if (snake._body[snake.n - snake._snakeSize][0] == snake.getXPosition() && snake._body[snake.n - snake._snakeSize][1] == snake.getYPosition()) {
	//	std::cout << "< SSSSSSSSSSEEEEEEEEEEE" << std::endl;
		//::cout << "< snake._body[snake.n - snake._snakeSize][0]" << snake._body[snake.n - snake._snakeSize][0] << std::endl;
		//std::cout << " snake.getXPosition()" << snake.getXPosition() << std::endl;
	}

	
	//moveSnake(x2,y2);
	
//	snake.setXPosition(2);
	//snake.setYPosition(2);
	//std::cout << "x " << snake.getXPosition() << std::endl;
	//std::cout << "y" << snake.getYPosition() << std::endl;
	
//}

void Map::change(int direction) {
	
}

void Map::moveSnake(int x, int y)
{
	initMap(_graphic);
	/*_arrayCells[10][2].setMaterial(SPRITE_SNOW);

	if (x == 11) {
		_arrayCells[10][2].setMaterial(SPRITE_DIRT);
	}*/
	
	_arrayCells[apple.getXApplePosition()][apple.getYApplePosition()].setMaterial(SPRITE_SNOW);
	_arrayCells[x][y].setMaterial(snake.getSnakeSprite());
//	_arrayCells[snake.getXPosition()][snake.getXPosition()].setMaterial(snake.getSnakeSprite());
	printSnakeInMap();

	
}


int i = 0;
float Map::eatApple(float speed) {
	if (getLevel() == 1) {
		setScore(getScore()+100);
		snake._snakeSize++;
		if (speed >= 0.01) {
			speed -= 0.01;
			apple.setXApplePosition();
			apple.setYApplePosition();
		}
		setLevel(2);
		snake.n = snake.n++; return speed;
	}
	if (getLevel() == 2) {
		
		if (i == 0) {
			setScore(getScore() + 100);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			i = 1;
			snake.n = snake.n++; return speed;
		}
		if (i == 1) {
			setScore(getScore() + 200);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			i = 2;
			setLevel(3);
			snake.n = snake.n++; return speed;
		}
	}
	if (getLevel() == 3) {
		
		if (i == 2) {
			setScore(getScore() + 100);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			i = 3;
			snake.n = snake.n++; return speed;
		}
		if (i == 3) {
			setScore(getScore() + 200);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			i = 4;
			snake.n = snake.n++; return speed;
		}
		if (i == 4) {
			setScore(getScore() + 300);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			setLevel(4);
			i = 5;
			snake.n = snake.n++; return speed;
		}
	}

	if (getLevel() == 4) {
		
		if (i == 5) {
			setScore(getScore() + 100);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			i = 6;
			snake.n = snake.n++; return speed;
		}
		if (i == 6) {
			setScore(getScore() + 200);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			i = 2;
			snake.n = snake.n++; return speed;
		}
		if (i == 7) {
			setScore(getScore() + 300);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			i = 8;
			snake.n = snake.n++; return speed;
		}
		if (i == 8) {
			setScore(getScore() + 400);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			setLevel(5);
			
			snake.n = snake.n++; return speed;
		}
	}
	if (getLevel() == 5) {
		
			setScore(getScore() + 100);
			snake._snakeSize++;
			if (speed >= 0.01) {
				speed -= 0.01;
				apple.setXApplePosition();
				apple.setYApplePosition();
			}
			snake.n = snake.n++; return speed;
		
	}

}

bool Map::checkApple(int appleX, int appleY, int snakeX, int snakeY) {
	if (appleX == snakeX && appleY == snakeY) {

		return true;
	}
	
}
//////////////////////////////////////////////
/*
void Map::fillSnakeInMap(Snake snake) {

	for (int i = 0; i < snake._snakeSize; i++) {
		int a, b;
		//snake._body[i][1]; 
		//_arrayCells[snake._body[i][1]].setMaterial(snake.getSnakeSprite());
		//
		_arrayCells[snake._body[i][1]] = _arrayCells[a][b].setMaterial(snake.getSnakeSprite());
			_arrayCells[1][1].setMaterial(snake.getSnakeSprite()); //ESTA MAL, TIENE QUE LLAMAR A SNAKE._BODY
		_arrayCells[snake._body[i][2]];
	}
	_arrayCells[snake._body[0][1]];
}

Snake Map::snakeNextSegment(Snake snake,int i) {
	snake._body[i][1];
	snake._body[i][2];
	return snake;
}

void Map::snakeMovesBy(Snake snake) {
	for (int i= snake._snakeSize-1; i > 0; --i) {
		_arrayCells[snakeNextSegment(snake,i)._body[i][1]];
		_arrayCells[snakeNextSegment(snake, i)._body[i][2]];
		//snakeNextSegment(snake, i);
	}
	snake._body[0][1] = snake.getXPosition();
	snake._body[0][1] = snake.getYPosition();
}*/

//void Map::grow()
//{
/*	if (snake._snakeSize > 0) {
		for (int i = 0; i < snake._snakeSize; i++) {
			_arrayCells[snake.cuerpo[i].x][snake.cuerpo[i].y] = 0;
				
		}
		for (int i = snake._snakeSize - 1; i != 0; i--) F
			snake.cuerpo[i]._body = snake._body;
			snake.cuerpo[i].x = snake.cuerpo[i - 1].x;
			snake.cuerpo[i].y = snake.cuerpo[i - 1].y;
		}
		snake.cuerpo.front()._body = snake._body;
		snake.cuerpo.back()._body = snake._tail;
		snake.cuerpo.front().x = snake._headXPos;
		snake.cuerpo.front().y = snake._headYPos;
		for (int i = 0; i < snake.cuerpo.size(); i++) {
			_arrayCells[snake.cuerpo[i].x][snake.cuerpo[i].y] = 4;
		}
	}*/
//
//}

void Map::snakeDeath()
{
	changeLevel(getLevel());
	snake.setLive(snake.getLive()-1);
	snake.setXPosition(2); 
	snake.setYPosition(2);
	snake.setDirection(3);
	snake.changeSpeed(snake.getSpeed());
	apple.setXApplePosition(); 
	apple.setYApplePosition();
	snake.n = 1;
	//memset(mapGrid,0,sizeof(mapGrid));
	//snake.cuerpo.clear();
	snake._snakeSize = 0;
	setScore(0);
	snake.beginT = clock()*CLK_TCK;

}

void Map::setScore(int s)
{
	_score = s;
}

int Map::getScore()
{
	return _score;
}


void Map::printSnakeInMap() {
	//for (int i = 0; i < 10; i++) {
	//for (int i = 1; i < 2; i++) {
	//std::cout << "SIZE " << snake._snakeSize << std::endl;
	for (int i = 1; i <= snake._snakeSize; i++) {
		_arrayCells[snake._body[snake.n - i][0]][snake._body[snake.n - i][1]].setMaterial(snake.getSnakeSprite());
		//::cout << "i " << i << std::endl;
	}
}
	//}
	//}

void Map::setLevel(int l) {
	_level = l;
}

int Map::getLevel() {
	return _level;
}

/*for (int i = 1; i <= snake._snakeSize; i++) {   
		if (snake._body[snake.n - i][0] == snake.getXPosition() || snake._body[snake.n - i][1] == snake.getYPosition()) {
			snakeDeath();
		}
		//_arrayCells[snake._body[snake.n - i][0]][snake._body[snake.n - i][1]].setMaterial(snake.getSnakeSprite());
		
	}*/
/*
int Map::controlTiming() {
	int t = 60;
	if (_easy == true) {
		return 240;
	}
	else if (_medium == true) {
		//2t
		return 120;
	}
	else if (_hard == true) {
		//t
		return 60;
	}
}

void Map::setBool(int a) {
	if (a == 1) {
		_easy = true;
	}
}


int Map::getTime() {
	return _levelTime;
}*/
void Map::setTime(int t) {
	_levelTime = t;
}
void Map::changeLevel(int a) {
	_level = a;
}