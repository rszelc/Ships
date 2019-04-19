#pragma once
#include "Statek.h"
class Trojka
	:public Statek{
	int x[3];
	int y[3];
public:
	Trojka();
	void set(int*, int*);
	int *get_tabx();
	int *get_taby();
	int get_size();
	bool traf();
};
