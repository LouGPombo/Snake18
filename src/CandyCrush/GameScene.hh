/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#pragma once
#include "Grid.hh"
#include "Scene.hh"

// GameScene class with the main gameplay mode
class GameScene : public Scene {
public:
	explicit GameScene();
	~GameScene() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;

private:
	Sprite m_grid;
	Sprite m_background;
	struct position{
		float x = 50;
		float y = 50;
	};

	position snake;
	//float cap{ 0 };
	int m_score{ 0 };
	bool up = false , down = false, left = false, right = false;
};