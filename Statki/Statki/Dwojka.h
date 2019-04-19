#pragma once
#include "Statek.h"
class Dwojka
	:public Statek {
	int x[2];
	int y[2];

public:
	Dwojka();
	void set(int*, int*);
	int *get_tabx();
	int *get_taby();
	int get_size();
	bool traf();
};
