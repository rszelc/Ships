#include "Pole.h"
Pole::Pole()
{
	val = 0;
}
Pole::~Pole()
{

}
void Pole::set()
{
	val = 1;
}
void Pole::kill()
{
	val = 2;
}
void Pole::miss()
{
	val = 3;
}
int Pole::get_val()
{
	return val;
}