#pragma once

#include <vector>
#include "GameObject.h"
#include "Parachuter.h"
#include "InfoLine.h"
#include "Cloud.h"
#include "Point.h"
#include "Thunder.h"

using namespace std;

class GameState
{
	private:
		int zwes, score;
		

		int width = 850;
		int height = 650;

		InfoLine* infoline;
		Parachuter* parachuter;
		Thunder* thunder;

		vector < GameObject * > game_objetcs;

	public:

		GameState() {
			// Dimiourgia synefwn
			for (int i = 0; i < 5; i++) {
				Cloud* cloud = new Cloud(this, "Cloud", 100 + i * 150, 100);
				game_objetcs.push_back(cloud);
			}

			// Dimiourgia parachuter
			parachuter = new Parachuter(this, "Parachuter", width / 2, 150);
			game_objetcs.push_back(parachuter);

			// Dimiourgia 20 points
			for (int i = 0; i < 20; i++) {
				Point* point = new Point(this, "Point", 100 + i * 30, 100);
				game_objetcs.push_back(point);
			}

			// Dimiourgia keravnou
			thunder = new Thunder(this, "Thunder", 100, 100);
			game_objetcs.push_back(thunder);

			// Dimiourgia infoline
			infoline = new InfoLine(this, "Infoline", 30, 50);
			game_objetcs.push_back(infoline);

		}

		

		void draw()
		{
			// Background color
			graphics::Brush br;

			// Xroma tou ouranou
			br.fill_color[0] = 0.0f;
			br.fill_color[1] = 0.5f;
			br.fill_color[2] = 1.0f;

			br.fill_secondary_color[0] = 0.0f;
			br.fill_secondary_color[1] = 1.5f;
			br.fill_secondary_color[2] = 1.0f;

			br.fill_opacity = 1.0f;

			br.gradient = true;
			br.gradient_dir_v = 0.5f;

			graphics::drawRect(width / 2, height / 2, width, height, br);

			for (int i = 0; i < game_objetcs.size(); i++)
			{
				game_objetcs[i]->draw();
			}

		}

		void update(float ms)
		{
			// Pernaei tis zwes kai to score stin grammi pliroforiwn
			infoline->setZwes(zwes);
			infoline->setScore(score);

			if (zwes == 0) {
				return;
			}

			for (int i = 0; i < game_objetcs.size(); i++)
			{
				game_objetcs[i]->update(ms);
			}

		

			// An exei epafi me kapoio antikeimeno
			for (int i = 0; i < game_objetcs.size(); i++) {
				if ( dynamic_cast<Point*>(game_objetcs[i]) != nullptr) {

					if (parachuter->isCollide(game_objetcs[i]) == true) {
						score++;
						graphics::playSound("assets/hit.wav", 0.5f, false);
						game_objetcs[i]->init();
					}
				}

				// An exei ginei orizontia epafi me ton keravno
				if (parachuter->isCollideHorizontal(thunder) == true) {
						
					// An ton exei xtypisei mia fora
					if( thunder->getStrikeParachute() == false ) {
						zwes--;
						thunder->setStrikeParachute(true);
					}

				}

			}
		}

		void init() {

			zwes = 3;
			score = 0;
		}

		~GameState() {

			// Diagrafei ta antikeimena
			for (int i = 0; i < game_objetcs.size(); i++) {
				delete game_objetcs[i];
			}

		}
};