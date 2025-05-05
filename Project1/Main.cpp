// VASILIKI MOUDOURI AM: P3210262
// STEFANOS FRAGOULIS AM: P3210212 
#include <graphics.h>
#include <iostream>

#include "GameState.h"

GameState game;


void draw()
{
	game.draw();
}

void update(float ms)
{
	game.update( ms );
}



int main()
{
	srand(0);
	graphics::createWindow(1024, 768, "The Parashuter");


	game.init();

	graphics::Brush br;

	// Xroma tou ouranou
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 1.0f;

	
	graphics::setWindowBackground(br);


	graphics::setUserData( &game );
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(800.0f, 600.0f);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	graphics::setFont("assets\\orange juice 2.0.ttf");

	graphics::startMessageLoop();
	graphics::destroyWindow();

	return 0;
}
