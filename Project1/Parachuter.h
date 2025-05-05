#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>

class GameState;

class Parachuter : public GameObject
{
	int direction = 0;

 public:

	Parachuter(GameState* gs, const std::string& name, int x, int y)
		: GameObject(gs,name,x,y) {
	}

	void update(float dt)
	{
		// An patithei to deksi i aristero koumpi
		if (graphics::getKeyState( graphics::SCANCODE_RIGHT ) == true) {

			x += 5;
			direction = 1;
		}
		else if (graphics::getKeyState(graphics::SCANCODE_LEFT) == true) {

			x -= 5;
			direction = -1;
		}
		else {
			direction = 0;
		}

		// An vgei ektos oriwn tou parathurou
		if (x < 0) {
			x = 0;
		}
		else if (x > 800) {
			x = 800;
		}
	}


	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/parasuter.png";
		br.outline_opacity = 0.0f;

		// An h kateuthinsi tou parachuter einai 1
		if (direction == -1 )
		{
			graphics::setOrientation(10);
		}
		else if (direction == 1)
		{
			graphics::setOrientation(-10);
		}
		else
		{
			graphics::setOrientation(0);
		}
		


		graphics::drawRect(x, y, 200, 200, br);

		graphics::resetPose();
	}
};