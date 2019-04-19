#include "Jedynka.h"
Jedynka::Jedynka() {
	value = 1;
}
void Jedynka::set(int *tabx, int *taby)
{
	x[0] = tabx[0];
	y[0] = taby[0];

}
bool Jedynka::traf()
{
	value--;
	if (value == 0)
		return true;
	else
		return false;
}
int* Jedynka::get_tabx()
{
	return x;
}
int* Jedynka::get_taby()
{
	return y;
}
int Jedynka::get_size()
{
	return 1;
}