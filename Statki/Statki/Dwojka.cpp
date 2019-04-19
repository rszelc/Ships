#include "Dwojka.h"
Dwojka::Dwojka() {
	value = 2;
}
void Dwojka::set(int *tabx, int *taby)
{
	for (int i = 0; i < 2; i++)
	{
		x[i] = tabx[i];
		y[i] = taby[i];
	}

}
bool Dwojka::traf()
{
	value--;
	if (value == 0)
		return true;
	else
		return false;
}
int* Dwojka::get_tabx()
{
	return x;
}
int* Dwojka::get_taby()
{
	return y;
}
int Dwojka::get_size()
{
	return 2;
}