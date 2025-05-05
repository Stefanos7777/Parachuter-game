#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>

class GameState;

class Cloud : public GameObject
{
	string texture;

public:

	Cloud(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name,x,y) {

		// Tyxaia arxikopoiisi twn x kai y
		this->x = rand() % 1000;
		this->y = rand() % 800;

	}

	void update(float dt)
	{
		// To synefo anebainei pros ta panw
		y -= 5;

		// An to synefo exei fygei ektos othonis, to ksanavazw katw
		if (y < -100)
		{
			y = 900;
			x = rand() % 1000;
		}
	}


	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/cloud1.png";
		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 100, 90, br);
	}
};