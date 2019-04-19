#pragma once
#include "Statek.h"
class Czworka: public Statek{
	int x[4];
	int y[4];
public:
	Czworka();
	void set(int*, int*);
	int *get_tabx();
	int *get_taby();
	int get_size();
	bool traf();
};
