#include "Czworka.h"
Czworka::Czworka() {
	value = 4;
}
void Czworka::set(int *tabx, int *taby)
{
	for (int i = 0; i < 4; i++)
	{
		x[i] = tabx[i];
		y[i] = taby[i];
	}

}
bool Czworka::traf()
{
	value--;
	if (value == 0)
		return true;
	else
		return false;
}
int* Czworka::get_tabx()
{
	return x;
}
int* Czworka::get_taby()
{
	return y;
}
int Czworka::get_size()
{
	return 4;
}