#pragma once
#include "Header.h"
#include "Statek.h"
class Pole {
	int val;
	int x;
	int y;
	Statek *statek;
	friend class Plansza;
public:
	Pole();
	void set();
	void kill();
	void miss();
	int get_val();
	~Pole();
};
