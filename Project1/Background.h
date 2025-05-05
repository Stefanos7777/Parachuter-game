#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>


class Background : public GameObject
{
	int width, height;


public:

	Background(GameState* gs, const std::string& name, int x, int y, int w, int h) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
		this->width = w;
		this->height = h;
	}

	void init()
	{
	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/background.png";

		graphics::drawRect(x, y, width, height, br);
	}
};