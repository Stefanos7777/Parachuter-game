#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>

class GameState;

// Einai pontoi pou mazeuei o paixtis
class Point : public GameObject
{
	string texture;

public:

	Point(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name, x, y) {

		// Tyxaia arxikopoiisi twn x kai y
		this->x = rand() % 1000;
		this->y = rand() % 800;

		// Tyxaia arxikopoiisi tou texture
		int r = rand() % 3;
		if (r == 0)
			texture = "assets/baloon.png";
		else if (r == 1)
			texture = "assets/baloon2.png";
		else
			texture = "assets/kite1.png";
	}

	void update(float dt)
	{
		// O pontos anebainei pros ta panw
		y -= 3;

		// An to synefo exei fygei ektos othonis, to ksanavazw katw
		if ( y < -100 )
		{
			y = 900;
			x = rand() % 1000;
		}
	}

	void init()
	{
		y = 900;
		x = rand() % 1000;
	}

	void draw()
	{
		graphics::Brush br;

		br.texture = texture;
		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 50, 50, br);
	}
};