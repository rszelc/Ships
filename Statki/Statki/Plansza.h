#pragma once
#include "Header.h"
#include "Statek.h"
#include "Jedynka.h"
#include "Dwojka.h"
#include "Trojka.h"
#include "Czworka.h"
#include "Pole.h"
class Plansza {
public:
	int hp = 20;
	int l_czw = 0;
	int l_tr = 0;
	int l_dw = 0;
	int l_j = 0;
	Pole *pola[11][11];
	Statek *statki[10];

	Plansza();
	void generuj_plansze();
	void generuj_plansze_rand();
	void wstaw_jedynke(int&);
	void wstaw_jedynke_rand();
	void wstaw_dwojke(int&);
	void wstaw_dwojke_rand();
	void wstaw_trojke(int&);
	void wstaw_trojke_rand();
	void wstaw_czworke(int&);
	void wstaw_czworke_rand();
	bool is_jedynka(int*, int*);
	bool is_dwojka(int*, int*);
	bool is_trojka(int*, int*);
	bool is_czworka(int*, int*);
	bool is_jedynka_rand(int*, int*);
	bool is_dwojka_rand(int*, int*);
	bool is_trojka_rand(int*, int*);
	bool is_czworka_rand(int*, int*);
	bool traf(int, int);
	bool traf(int, int, bool&, int&, bool&, int&);
	Pole* get_pole(int, int);
	int get_hp();
	void wypisz();
};
