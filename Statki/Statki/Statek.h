#pragma once
#include "Header.h"
class Statek {
public:
	int value = 1;
	friend class Plansza;


	Statek();
	virtual void set(int*, int*) = 0;
	virtual bool traf() = 0;
	virtual int *get_tabx() = 0;
	virtual int *get_taby() = 0;
	virtual int get_size() = 0;
	virtual ~Statek();
};
