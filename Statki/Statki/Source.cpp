#include "Header.h"
#include "Plansza.h"
void start_game();
void wypisz(Plansza*, Plansza*);
int main()
{
	srand(time(NULL));
	start_game();
	system("pause");
}
void start_game()
{
	Plansza *A = new Plansza();
	Plansza *B = new Plansza();
	
	B->generuj_plansze_rand();
	A->generuj_plansze_rand();
	int x, y, a, b;
	int g = 0;
	string iks;
	bool poz = false;
	bool pion = false;
	bool z = false;
	bool t = false;
	int t2 = 0;
	while (1)
	{
		
		do
		{
			if (B->get_hp() == 0)
			{
				cout << "Wygrales!" << endl;
				wypisz(A, B);
				system("pause");
				exit(0);
			}
			wypisz(A,B);
			while (1) {
				cout << "Wybierz pole: ";
				getline(cin >> ws, iks);
				if (iks.length() == 2)
				{
					x = int(iks[0]) - 96;
					y = atoi(iks.substr(1, 2).c_str());
					break;
				}
				else if (iks.length() == 3)
				{
					x = int(iks[0]) - 96;
					y = atoi(iks.substr(1, 3).c_str());
					break;
				}
				else
				{
					cout << "Zle wspolrzedne! Podaj jeszcze raz: ";
				}
			}
			system("cls");
		} while (B->traf(x,y) == true);
		do
		{
			if (g == 4)
				g = 0;
			if (g == 5)
				g = 1;
			if (A->get_hp() == 0)
			{
				cout << "Przegrales!" << endl;
				wypisz(A, B);
				
				system("pause");
				exit(0);
			}
			if (z == false)
			{
				g = 0;
				a = rand() % 10 + 1;
				b = rand() % 10 + 1;
			}
			else if (z == true)
			{
					if (g == 0)
					{
						b--;
						if(t2>1)
							poz = true;
					}
					if (g == 1)
					{
						if (t2<2)
						{
							b++;
							a--;
							if (t2 > 1)
								pion = true;
						}
						else
							a--;
					}
					if (g == 2)
					{
						if (t2<2)
						{
							b++;
							a++;
							if (t2 > 1)
								poz = true;
						}
						else 
							b++;
					}
					if (g == 3)
					{
						if (t2<2)
						{
							b--;
							a++;
							if (t2 > 1)
								pion = true;
						}
						else
							a++;
					}
			}
			system("cls");
		} while (A->traf(a, b, z, g, t, t2) == true);
	}
}
void wypisz(Plansza *A, Plansza *B)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (j < 11)
			{
				if (i == 0 && j == 0)
					cout << "   ";
				else if (j != 0 && i == 0)
					cout << "| " << j << " ";
				else if (j == 0 && i != 0)
					cout << " " << char(i + 64) << " |";
				else if (j != 0 && i != 0)
				{
					if (A->get_pole(i, j)->get_val() == 0)
						cout << "   |";
					else if (A->get_pole(i, j)->get_val() == 2)
						cout << " " << "X" << " |";
					else if (A->get_pole(i, j)->get_val() == 3)
						cout << " " << char(250) << " |";
					else
						cout << char(219) << char(219) << char(219) << "|";
				}
			}
			else
			{
				if (i == 0 && j == 11)
					cout << "       ";
				else if (j != 11 && i == 0)
					cout << "| " << j-11 << " ";
				else if (j == 11 && i != 0)
					cout << "   | " << char(i + 64) << " |";
				else if (j != 11 && i != 0)
				{
					if (B->get_pole(i, j-11)->get_val() == 0)
						cout << "   |";
					else if (B->get_pole(i, j-11)->get_val() == 2)
						cout << " " << "X" << " |";
					else if (B->get_pole(i, j-11)->get_val() == 3)
						cout << " " << char(250) << " |";
					else
						cout << "   " << "|";
				}
			}
		}
		cout << endl;
		cout << "---+---+---+---+---+---+---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+" << endl;
	}

}