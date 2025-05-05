#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>

class GameState;

// Keravnos
class Thunder : public GameObject
{
private:

	float m_lastActiveTime = 0.0f;
	bool strike_parachute = false;

public:

	Thunder(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name, x, y) {

		// Tyxaia arxikopoiisi tou wste na einai konta sto kentro
		this->x = rand() % 400 + 250;
		this->y = 300;

		m_active = false;
	}

	void update(float dt)
	{
		// Ginetai active ana 8 deuterolepta
		if (graphics::getGlobalTime() - m_lastActiveTime > 8000.0f) {
			m_active = true;
			m_lastActiveTime = graphics::getGlobalTime();
		}

		// An den einai active, den tha akougetai
		if (m_active == true) {
			graphics::playSound("assets/thunder.wav", 0.5f, false);
		}

		// Einai active gia 2 deuterolepta
		if (graphics::getGlobalTime() - m_lastActiveTime > 2000.0f) {
			m_active = false;
			strike_parachute = false;

			// Wste na einai konta sto kentro
			this->x = rand() % 400+250;
		}
	}

	bool getStrikeParachute() {
		return strike_parachute;
	}
	
	void setStrikeParachute(bool strike_parachute) {
		this->strike_parachute = strike_parachute;
	}

	void draw()
	{
		// An den einai active, den tha emfanizetai
		if ( m_active == false ) {
			return;
		}

		graphics::Brush br;

		br.texture = "assets/thunder.png";
		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 200, 800, br);
	}
};