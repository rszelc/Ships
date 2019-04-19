#include "Trojka.h"
Trojka::Trojka()
{
	value = 3;
}
void Trojka::set(int *tabx, int *taby)
{
	for (int i = 0; i < 3; i++)
	{
		x[i] = tabx[i];
		y[i] = taby[i];
	}

}
bool Trojka::traf()
{
	value--;
	if (value == 0)
		return true;
	else
		return false;
}
int* Trojka::get_tabx()
{
	return x;
}
int* Trojka::get_taby()
{
	return y;
}
int Trojka::get_size()
{
	return 3;
}