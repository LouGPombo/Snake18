/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/
#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "GameScene.hh"
using namespace Logger;

#define CELL_WIDTH 80
#define CELL_HEIGHT 80

GameScene::GameScene(void) : m_grid() {
	m_grid = { { 10, 10, 20,20 }, ObjectID::CANDY_BLUE };//R.Push(objectID, transform);
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_00 };
}

GameScene::~GameScene(void) {
}

void GameScene::OnEntry(void) {

}

void GameScene::OnExit(void) {
}

void GameScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	
	m_grid.transform.x = snake.x;
	m_grid.transform.y = snake.y;
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) {
		Println("down arrow up");
		if (up == false) {
			down = true;
			left = false;
			right = false;
		}
	};

	if (IM.IsKeyUp<KEY_BUTTON_UP>()) {
		Println("down arrow up");
		if (down == false) {
			up = true;
			left = false;
			right = false;
		}
	};

	if (IM.IsKeyUp<KEY_BUTTON_LEFT>()) {
		Println("down arrow up");
		if (right == false) {
			left = true;
			up = false;
			down = false;
		}
	};

	if (IM.IsKeyUp<KEY_BUTTON_RIGHT>()) {
		Println("down arrow up");
		if (left == false) {
			right = true;
			up = false;
			down = false;
		}
	};

	if (down == true && up == false) {
		left, right = false;
		snake.y += 0.001;
	}

	if (up == true && down == false) {
		left, right = false;
		snake.y -= 0.001;
	}

	if (right == true && left == false) {
		up, down = false;
		snake.x += 0.001;
	}

	if (left == true && right == false) {
		up, down = false;
		snake.x -= 0.001;
	}
	/*
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) {
		Println("down arrow up");
		
		down = true;
		up, left, right = false;
	};
	if (IM.IsKeyUp<KEY_BUTTON_UP>()) {
		Println("down arrow up");
		
		up = true;
		down, left, right = false;

	};
	if (IM.IsKeyUp<KEY_BUTTON_LEFT>()) {
		Println("down arrow up");
		
		left = true;
		up, down, right = false;
	};
	if (IM.IsKeyUp<KEY_BUTTON_RIGHT>()) {
		Println("down arrow up");
		
		right = true;
		up, down, left = false;
	};



	if (down == true) {

		snake.y += 0.001;
		//if (m_grid.transform.y <= 728){
		//	cap += 0.01;
	}

	if (up == true) {
		snake.y -= 0.001;
	}

	if (left == true) {
		snake.x -= 0.001;
	}

	if (right == true) {
		snake.x += 0.001;
	}

	*/
	
	//	}
}

void GameScene::Draw(void) {
	m_background.Draw(); // Render background
	m_grid.Draw();

	//Candy.Draw();
	//m_grid.Draw(); // Render grid
	GUI::DrawTextShaded<FontID::FACTORY>("Snake",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.1f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
	GUI::DrawTextBlended<FontID::CANDY>("Score: " + std::to_string(m_score),
	{ W.GetWidth() >> 1, int(W.GetHeight()*.9f), 1, 1 },
	{ 115, 0, 180 }); // Render score that will be different when updated
}
