#include "Plansza.h"
Plansza::Plansza() {
	statki[0] = new Czworka();
	statki[1] = new Trojka();
	statki[2] = new Trojka();
	statki[3] = new Dwojka();
	statki[4] = new Dwojka();
	statki[5] = new Dwojka();
	statki[6] = new Jedynka();
	statki[7] = new Jedynka();
	statki[8] = new Jedynka();
	statki[9] = new Jedynka();
}
void Plansza::generuj_plansze() {
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			pola[i][j] = new Pole;
		}
	}
	string iks;
	int x;
	int KO = 0;;
	while (KO < 20)
	{
		wypisz();
		cout << "1. Wstaw Jedynke" << endl;
		cout << "2. Wstaw Dwojke" << endl;
		cout << "3. Wstaw Trojke" << endl;
		cout << "4. Wstaw Czworke" << endl;
		getline(cin >> ws, iks);
		x = atoi(iks.c_str());
		switch (x)
		{
		case 1:
			if (l_j < 4)
				wstaw_jedynke(KO);

			else
				cout << "Brak dostepnych statkow" << endl;
			system("cls");
			break;
		case 2:
			if (l_dw < 3)
				wstaw_dwojke(KO);
			else
				cout << "Brak dostepnych statkow" << endl;
			system("cls");
			break;
		case 3:
			if (l_tr < 2)
				wstaw_trojke(KO);
			else
				cout << "Brak dostepnych statkow" << endl;
			system("cls");
			break;
		case 4:
			if (l_czw < 1)
				wstaw_czworke(KO);
			else
				cout << "Brak dostepnych statkow" << endl;
			system("cls");
			break;
		default:
			cout << "error" << endl;
			break;
		}
	}
}
void Plansza::generuj_plansze_rand()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			pola[i][j] = new Pole;
		}
	}
	wstaw_czworke_rand();
	wstaw_trojke_rand();
	wstaw_trojke_rand();
	wstaw_dwojke_rand();
	wstaw_dwojke_rand();
	wstaw_dwojke_rand();
	wstaw_jedynke_rand();
	wstaw_jedynke_rand();
	wstaw_jedynke_rand();
	wstaw_jedynke_rand();
}
void Plansza::wstaw_jedynke(int &KO)
{
	int nr_statku = 6 + l_j;
	int tabx[1];
	int taby[1];
	string iks;
	cout << "Podaj wspolrzedna statku: ";
	do
	{
		while (1) {
			getline(cin >> ws, iks);
			if (iks.length() == 2)
			{
				tabx[0] = int(iks[0]) - 96;
				taby[0] = atoi(iks.substr(1, 2).c_str());
				break;
			}
			else if (iks.length() == 3)
			{
				tabx[0] = int(iks[0]) - 96;
				taby[0] = atoi(iks.substr(1, 3).c_str());
				break;
			}
			else
			{
				cout << "Zle wspolrzedne! Podaj jeszcze raz: ";
			}
		}
	} while (is_jedynka(tabx, taby) == false);
	statki[nr_statku]->set(tabx, taby);
	pola[tabx[0]][taby[0]]->statek = statki[nr_statku];
	pola[tabx[0]][taby[0]]->set();
	KO++;
	l_j++;
}
void Plansza::wstaw_dwojke(int &KO)
{
	int nr_statku = 3 + l_dw;
	int tabx[2];
	int taby[2];
	string iks;
	cout << "Podaj wspolrzedna statku: ";
	do
	{
		for (int i = 0; i < 2; i++) {
			while (1) {
				getline(cin >> ws, iks);
				if (iks.length() == 2)
				{
					tabx[i] = int(iks[0]) - 96;
					taby[i] = atoi(iks.substr(1, 2).c_str());
					break;
				}
				else if (iks.length() == 3)
				{
					tabx[i] = int(iks[0]) - 96;
					taby[i] = atoi(iks.substr(1, 3).c_str());
					break;
				}
				else
				{
					cout << "Zle wspolrzedne! Podaj jeszcze raz: ";
				}
			}
		}
	} while (is_dwojka(tabx,taby) == false);
	statki[nr_statku]->set(tabx, taby);
	for (int i = 0; i < 2; i++)
	{
		pola[tabx[i]][taby[i]]->statek = statki[nr_statku];
		pola[tabx[i]][taby[i]]->set();
	}
	KO += 2;
	l_dw++;
}
void Plansza::wstaw_trojke(int &KO)
{
	int nr_statku = 1 + l_tr;
	int tabx[3];
	int taby[3];
	string iks;
	cout << "Podaj wspolrzedna statku: ";
	do {
		for (int i = 0; i < 3; i++) {
			while (1) {
				getline(cin >> ws, iks);
				if (iks.length() == 2)
				{
					tabx[i] = int(iks[0]) - 96;
					taby[i] = atoi(iks.substr(1, 2).c_str());
					break;
				}
				else if (iks.length() == 3)
				{
					tabx[i] = int(iks[0]) - 96;
					taby[i] = atoi(iks.substr(1, 3).c_str());
					break;
				}
				else
				{
					cout << "Zle wspolrzedne! Podaj jeszcze raz: ";
				}
			}
		}
	} while (is_trojka(tabx, taby) == false);
	statki[nr_statku]->set(tabx, taby);
	for (int i = 0; i < 3; i++)
	{
		pola[tabx[i]][taby[i]]->statek = statki[nr_statku];
		pola[tabx[i]][taby[i]]->set();
	}
	KO += 3;
	l_tr++;
}
void Plansza::wstaw_czworke(int &KO)
{
	int nr_statku = 0;
	int tabx[4];
	int taby[4];
	string iks;
	cout << "Podaj wspolrzedna statku: ";
	do {
		for (int i = 0; i < 4; i++) {
			while (1) {
				getline(cin >> ws, iks);
				if (iks.length() == 2)
				{
					tabx[i] = int(iks[0]) - 96;
					taby[i] = atoi(iks.substr(1, 2).c_str());
					break;
				}
				else if (iks.length() == 3)
				{
					tabx[i] = int(iks[0]) - 96;
					taby[i] = atoi(iks.substr(1, 3).c_str());
					break;
				}
				else
				{
					cout << "Zle wspolrzedne! Podaj jeszcze raz: ";
				}
			}
		}
	} while (is_czworka(tabx, taby) == false);
	statki[nr_statku]->set(tabx, taby);
	for (int i = 0; i < 4; i++)
	{
		pola[tabx[i]][taby[i]]->statek = statki[nr_statku];
		pola[tabx[i]][taby[i]]->set();
	}
	KO += 4;
	l_czw++;
}
void Plansza::wstaw_jedynke_rand()
{
	int nr_statku = 6 + l_j;
	int tabx[1];
	int taby[1];
	do
	{
		tabx[0] = rand() % 10 + 1;
		taby[0] = rand() % 10 + 1;
	} while (is_jedynka_rand(tabx, taby) == false);
	statki[nr_statku]->set(tabx, taby);
	pola[tabx[0]][taby[0]]->statek = statki[nr_statku];
	pola[tabx[0]][taby[0]]->set();
	l_j++;
}
void Plansza::wstaw_dwojke_rand()
{
	int nr_statku = 3 + l_dw;
	int tabx[2];
	int taby[2];
	do
	{
		tabx[0] = rand() % 10 + 1;
		taby[0] = rand() % 10 + 1;
		int temp = rand() % 4;
		if (temp == 0)
		{
			tabx[1] = tabx[0];
			taby[1] = taby[0] - 1;
		}
		else if (temp == 1)
		{
			tabx[1] = tabx[0] - 1;
			taby[1] = taby[0];
		}
		else if (temp == 2)
		{
			tabx[1] = tabx[0];
			taby[1] = taby[0] + 1;
		}
		else
		{
			tabx[1] = tabx[0] + 1;
			taby[1] = taby[0];
		}

	} while (is_dwojka_rand(tabx, taby) == false);
	statki[nr_statku]->set(tabx, taby);
	for (int i = 0; i < 2; i++)
	{
		pola[tabx[i]][taby[i]]->statek = statki[nr_statku];
		pola[tabx[i]][taby[i]]->set();
	}
	l_dw++;
}
void Plansza::wstaw_trojke_rand()
{
	int nr_statku = 1 + l_tr;
	int tabx[3];
	int taby[3];
	do
	{
		tabx[0] = rand() % 10 + 1;
		taby[0] = rand() % 10 + 1;
		int temp = rand() % 4;
		if (temp == 0)
		{
			tabx[1] = tabx[0];
			taby[1] = taby[0] - 1;
			tabx[2] = tabx[0];
			taby[2] = taby[0] - 2;
		}
		else if (temp == 1)
		{
			tabx[1] = tabx[0] - 1;
			taby[1] = taby[0];
			tabx[2] = tabx[0] - 2;
			taby[2] = taby[0];
		}
		else if (temp == 2)
		{
			tabx[1] = tabx[0];
			taby[1] = taby[0] + 1;
			tabx[2] = tabx[0];
			taby[2] = taby[0] + 2;
		}
		else
		{
			tabx[1] = tabx[0] + 1;
			taby[1] = taby[0];
			tabx[2] = tabx[0] + 2;
			taby[2] = taby[0];
		}

	} while (is_trojka_rand(tabx, taby) == false);
	statki[nr_statku]->set(tabx, taby);
	for (int i = 0; i < 3; i++)
	{
		pola[tabx[i]][taby[i]]->statek = statki[nr_statku];
		pola[tabx[i]][taby[i]]->set();
	}
	l_tr++;
}
void Plansza::wstaw_czworke_rand()
{
	int nr_statku = 0;
	int tabx[4];
	int taby[4];
	do
	{
		tabx[0] = rand() % 10 + 1;
		taby[0] = rand() % 10 + 1;
		int temp = rand() % 4;
		if (temp == 0)
		{
			tabx[1] = tabx[0];
			taby[1] = taby[0] - 1;
			tabx[2] = tabx[0];
			taby[2] = taby[0] - 2;
			tabx[3] = tabx[0];
			taby[3] = taby[0] - 3;
		}
		else if (temp == 1)
		{
			tabx[1] = tabx[0] - 1;
			taby[1] = taby[0];
			tabx[2] = tabx[0] - 2;
			taby[2] = taby[0];
			tabx[3] = tabx[0] - 3;
			taby[3] = taby[0];
		}
		else if (temp == 2)
		{
			tabx[1] = tabx[0];
			taby[1] = taby[0] + 1;
			tabx[2] = tabx[0];
			taby[2] = taby[0] + 2;
			tabx[3] = tabx[0];
			taby[3] = taby[0] + 3;
		}
		else
		{
			tabx[1] = tabx[0] + 1;
			taby[1] = taby[0];
			tabx[2] = tabx[0] + 2;
			taby[2] = taby[0];
			tabx[3] = tabx[0] + 3;
			taby[3] = taby[0];
		}

	} while (is_czworka_rand(tabx, taby) == false);
	statki[nr_statku]->set(tabx, taby);
	for (int i = 0; i < 4; i++)
	{
		pola[tabx[i]][taby[i]]->statek = statki[nr_statku];
		pola[tabx[i]][taby[i]]->set();
	}
	l_czw++;
}
void Plansza::wypisz()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j == 0)
				cout << "   ";
			else if (j != 0 && i == 0)
				cout << "| " << j<<" ";
			else if (j == 0  && i != 0)
				cout <<" "<< char(i + 96) <<" |";
			else if (j != 0 && i != 0)
			{
				if (pola[i][j]->val == 0)
					cout << "   |";
				else if(pola[i][j]->val == 2)
					cout << " "<<"X"<<" |";
				else if (pola[i][j]->val == 3)
					cout << " " << char(250) << " |";
				else
					cout <<char(219)<<char(219)<<char(219)<<"|";
			}
		}
		cout << endl;
		cout << "---+---+---+---+---+---+---+---+---+---+---+" << endl;
	}

}
bool Plansza::is_jedynka(int *x, int *y)
{
	int temp = 0;
	if (x[0] < 1 || x[0]>10 || y[0] < 1 || y[0]>10)
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
	for (int j = x[0] - 1; j <= x[0] + 1; j++)
	{
		for (int k = y[0] - 1; k <= y[0] + 1; k++)
		{
			if (j < 0 || k < 0 || j>10 || k>10)
				continue;
			if (pola[j][k]->val == 1)
				temp++;
		}
	}
	if (temp == 0)
		return true;
	else
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
}
bool Plansza::is_jedynka_rand(int *x, int *y)
{
	int temp = 0;
	if (x[0] < 1 || x[0]>10 || y[0] < 1 || y[0]>10)
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
	for (int j = x[0] - 1; j <= x[0] + 1; j++)
	{
		for (int k = y[0] - 1; k <= y[0] + 1; k++)
		{
			if (j < 0 || k < 0 || j>10 || k>10)
				continue;
			if (pola[j][k]->val == 1)
				temp++;
		}
	}
	if (temp == 0)
		return true;
	else
	{
		return false;
	}
}
bool Plansza::is_dwojka(int *x, int *y)
{
	for (int i = 0; i < 2; i++)
	{
		if (x[i] < 1 || x[i]>10 || y[i] < 1 || y[i]>10)
		{
			cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
			return false;
		}
	}
	if (abs(x[0] - x[1]) == 1 && abs(y[0] - y[1]) == 1)
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
	else if (abs(x[0] - x[1]) > 1 || abs(y[0] - y[1]) > 1)
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
	else if(pola[x[0]][y[0]]->val==1 || pola[x[1]][y[1]]->val==1)
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
	else
	{
		int temp = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = x[i] - 1; j <= x[i] + 1; j++)
			{
				for (int k = y[i] - 1; k <= y[i] + 1; k++)
				{
					if (j < 0 || k < 0 || j>10 || k>10)
						continue;
					if (pola[j][k]->val == 1)
						temp++;
				}
			}
		}
		if (temp==0)
			return true;
		else 
		{
			cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
			return false;
		}
	}
}
bool Plansza::is_dwojka_rand(int *x, int *y)
{
	for (int i = 0; i < 2; i++)
	{
		if (x[i] < 1 || x[i]>10 || y[i] < 1 || y[i]>10)
		{
			return false;
		}
	}
	if (abs(x[0] - x[1]) == 1 && abs(y[0] - y[1]) == 1)
	{
		return false;
	}
	else if (abs(x[0] - x[1]) > 1 || abs(y[0] - y[1]) > 1)
	{
		return false;
	}
	else if (pola[x[0]][y[0]]->val == 1 || pola[x[1]][y[1]]->val == 1)
	{
		return false;
	}
	else
	{
		int temp = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = x[i] - 1; j <= x[i] + 1; j++)
			{
				for (int k = y[i] - 1; k <= y[i] + 1; k++)
				{
					if (j < 0 || k < 0 || j>10 || k>10)
						continue;
					if (pola[j][k]->val == 1)
						temp++;
				}
			}
		}
		if (temp == 0)
			return true;
		else
		{
			return false;
		}
	}
}
bool Plansza::is_trojka(int *x, int *y)
{
	for (int i = 0; i < 3; i++)
	{
		if (x[i] < 1 || x[i]>10 || y[i] < 1 || y[i]>10)
		{
			cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
			return false;
		}
	}
	if (abs(x[0] - x[1]) > 2 || abs(x[0] - x[2]) > 2 || abs(x[1] - x[2]) > 2 || abs(y[0] - y[1]) > 2 || abs(y[0] - y[2]) > 2 || abs(y[1] - y[2]) > 2)
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
	else if((x[0]==x[1] && x[1]==x[2]) || (y[0] == y[1] && y[1] == y[2]))
	{
		int temp = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = x[i] - 1; j <= x[i] + 1; j++)
			{
				for (int k = y[i] - 1; k <= y[i] + 1; k++)
				{
					if (j < 0 || k < 0 || j>10 || k>10)
						continue;
					if (pola[j][k]->val == 1)
						temp++;
				}
			}
		}
		if (temp == 0)
			return true;
		else
		{
			cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
			return false;
		}
	}
	else
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
}
bool Plansza::is_trojka_rand(int *x, int *y)
{
	for (int i = 0; i < 3; i++)
	{
		if (x[i] < 1 || x[i]>10 || y[i] < 1 || y[i]>10)
		{
			return false;
		}
	}
	if (abs(x[0] - x[1]) > 2 || abs(x[0] - x[2]) > 2 || abs(x[1] - x[2]) > 2 || abs(y[0] - y[1]) > 2 || abs(y[0] - y[2]) > 2 || abs(y[1] - y[2]) > 2)
	{
		return false;
	}
	else if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2]))
	{
		int temp = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = x[i] - 1; j <= x[i] + 1; j++)
			{
				for (int k = y[i] - 1; k <= y[i] + 1; k++)
				{
					if (j < 0 || k < 0 || j>10 || k>10)
						continue;
					if (pola[j][k]->val == 1)
						temp++;
				}
			}
		}
		if (temp == 0)
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Plansza::is_czworka(int *x, int *y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x[i] < 1 || x[i]>10 || y[i] < 1 || y[i]>10)
		{
			cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
			return false;
		}
	}
	if (abs(x[0] - x[1]) > 3 || abs(x[0] - x[2]) > 3 || abs(x[0] - x[3]) > 3 || abs(x[1] - x[2]) > 3 || abs(x[1] - x[3]) > 3 || abs(x[2] - x[3]) > 3 || abs(y[0] - y[1]) > 3 || abs(y[0] - y[2]) > 3 || abs(y[0] - y[3]) > 3 || abs(y[1] - y[2]) > 3 || abs(y[1] - y[3]) > 3 || abs(y[2] - y[3]) > 3)
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
	else if ((x[0] == x[1] && x[1] == x[2] && x[2]==x[3]) || (y[0] == y[1] && y[1] == y[2] && y[2]==y[3]))
	{
		int temp = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = x[i] - 1; j <= x[i] + 1; j++)
			{
				for (int k = y[i] - 1; k <= y[i] + 1; k++)
				{
					if (j < 0 || k < 0 || j>10 || k>10)
						continue;
					if (pola[j][k]->val == 1)
						temp++;
				}
			}
		}
		if (temp == 0)
			return true;
		else
		{
			cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
			return false;
		}
	}
	else
	{
		cout << "Zle wprzolrzedne podaj jeszcze raz: " << endl;
		return false;
	}
}
bool Plansza::is_czworka_rand(int *x, int *y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x[i] < 1 || x[i]>10 || y[i] < 1 || y[i]>10)
		{
			return false;
		}
	}
	if (abs(x[0] - x[1]) > 3 || abs(x[0] - x[2]) > 3 || abs(x[0] - x[3]) > 3 || abs(x[1] - x[2]) > 3 || abs(x[1] - x[3]) > 3 || abs(x[2] - x[3]) > 3 || abs(y[0] - y[1]) > 3 || abs(y[0] - y[2]) > 3 || abs(y[0] - y[3]) > 3 || abs(y[1] - y[2]) > 3 || abs(y[1] - y[3]) > 3 || abs(y[2] - y[3]) > 3)
	{
		return false;
	}
	else if ((x[0] == x[1] && x[1] == x[2] && x[2] == x[3]) || (y[0] == y[1] && y[1] == y[2] && y[2] == y[3]))
	{
		int temp = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = x[i] - 1; j <= x[i] + 1; j++)
			{
				for (int k = y[i] - 1; k <= y[i] + 1; k++)
				{
					if (j < 0 || k < 0 || j>10 || k>10)
						continue;
					if (pola[j][k]->val == 1)
						temp++;
				}
			}
		}
		if (temp == 0)
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Plansza::traf(int x, int y)
{
	if (pola[x][y]->val == 1)
	{
		if (pola[x][y]->statek->traf() == true)
		{
			hp--;
			pola[x][y]->kill();
			int *tabx = pola[x][y]->statek->get_tabx();
			int *taby = pola[x][y]->statek->get_taby();
			int size = pola[x][y]->statek->get_size();
			cout << "Trafiony zatopiony!" << endl;
			for (int i = 0; i < size; i++)
			{
				for (int j = tabx[i] - 1; j <= tabx[i] + 1; j++)
				{
					for (int k = taby[i] - 1; k <= taby[i] + 1; k++)
					{
						if (j < 0 || k < 0 || j>10 || k>10)
							continue;
						if (pola[j][k]->val == 2 || pola[j][k]->val == 2)
							continue;
						pola[j][k]->miss();
					}
				}
			}
		}
		else
		{
			hp--;
			cout << "Trafiony niezatopiony!" << endl;
			pola[x][y]->kill();
		}
		return true;
	}
	else if (pola[x][y]->val == 2 || pola[x][y]->val == 3)
	{
		cout << "Już tu strzelales, sprobuj jeszcze raz!" << endl;;
		return true;
	}
	else if (pola[x][y]->val == 0)
	{
		cout << "Pudlo!" << endl;
		pola[x][y]->miss();
		return false;
	}
}
bool Plansza::traf(int x, int y, bool &z, int &g, bool &t, int &t2)
{
	if (pola[x][y]->val == 1)
	{
		if (pola[x][y]->statek->traf() == true)
		{
			hp--;
			pola[x][y]->kill();
			int *tabx = pola[x][y]->statek->get_tabx();
			int *taby = pola[x][y]->statek->get_taby();
			int size = pola[x][y]->statek->get_size();
			z = false;
			t = true;
			t2 = 0;
			for (int i = 0; i < size; i++)
			{
				for (int j = tabx[i] - 1; j <= tabx[i] + 1; j++)
				{
					for (int k = taby[i] - 1; k <= taby[i] + 1; k++)
					{
						if (j < 0 || k < 0 || j>10 || k>10)
							continue;
						if (pola[j][k]->val == 2 || pola[j][k]->val == 2)
							continue;
						pola[j][k]->miss();
					}
				}
			}
			
		}
		else
		{
			hp--;
			pola[x][y]->kill();
			z = true;
			t = true;
			t2++;
		}
		return true;
	}
	else if (pola[x][y]->val == 2 || pola[x][y]->val == 3)
	{
		if (t == true && t2>1)
		{
			g += 2;
			return true;
		}
		else if (t == true)
		{
			g++;
			return true;
		}
		else
			return true;
	}
	else if (pola[x][y]->val == 0)
	{
		pola[x][y]->miss();
		if (t2>1)
			g += 2;
		else
			g++;
		t = false;
		return false;
	}
}
Pole* Plansza::get_pole(int x, int y)
{
	return pola[x][y];
}
int Plansza::get_hp()
{
	return hp;
}



