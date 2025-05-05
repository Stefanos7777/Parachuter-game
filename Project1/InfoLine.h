#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>



// Grammi enimerwsis tou paixnidiou (score kai zwes)
class InfoLine : public GameObject
{
	int zwes, score;

public:

	InfoLine(GameState* gs, const std::string& name, int x, int y)
		: GameObject(gs, name,x,y) {

	}


	void draw()
	{
		string text = "Lifes: " + to_string(zwes)+ "  Score: " + to_string(score);
		graphics::Brush br;

		// Portokali xroma
		br.fill_opacity = 1.0;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.0f;

		if (zwes == 0) {
			text = text + "                    GAME OVER  !";
		}

		graphics::drawText(x, y, 25, text, br);
	}

	// Setters
	void setZwes(int z) { zwes = z; }
	void setScore(int s) { score = s; }

};