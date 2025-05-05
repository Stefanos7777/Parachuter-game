#pragma once


#include <string>
#include <cmath>
#include "GameState.h"

using namespace std;



class GameObject
{
	static int m_next_id;
protected:

	int x, y;
	class GameState* m_state;
	std::string m_name;
	int m_id = 0;
	bool m_active = true;

public:
	GameObject(GameState* gs, const std::string& name, int x, int y) {

		m_state = gs;
		m_name = name;
		this->x = x;
		this->y = y;
	}
	
	virtual  void update (float dt) { }
	virtual  void init() { }
	virtual  void draw() { }

	

	void setActive(bool a) {
		m_active = a;
	}

	bool isActive() {
		return m_active;
	}

	
	// Elegxei an exei ginei sigrousi me kapoio allo antikeimeno
	bool isCollide(GameObject* other) {

		// an to antikeimeno den einai energo, tote den ginetai sigrousi
		if(other->m_active == false) {
			return false;
		}

		double dx = x - other->x;
		double dy = y - other->y;
		double d = sqrt(dx * dx + dy * dy);


		if (d < 25) {
			return true;
		}
		else {
			return false;
		}
	}

	// Elegxei an exei ginei sigrousi me kapoio allo antikeimeno orizontia
	bool isCollideHorizontal(GameObject* other) {

		// an to antikeimeno den einai energo, tote den ginetai sigrousi
		if (other->m_active == false) {
			return false;
		}

		double dx = abs(x - other->x);

		if (dx < 25) {
			return true;
		}
		else {
			return false;
		}
	}

	virtual ~GameObject() {

	}
};