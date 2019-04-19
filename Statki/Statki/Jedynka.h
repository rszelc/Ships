#pragma once
#include "Statek.h"
class Jedynka 
	:public Statek{
	int x[1];
	int y[1];
public:
	Jedynka();
	void set(int*, int*);
	int *get_tabx();
	int *get_taby();
	int get_size();
	bool traf();
};
