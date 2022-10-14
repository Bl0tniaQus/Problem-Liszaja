#include "Symulacja.h"

Symulacja::Symulacja(const Ustawienia& ust) :ustawienia(ust), powierzchnia(ust.Wymiar())
{
	int n = ust.Wymiar();
	pole = n * n;
	czasSymulacji = 0;
	n_zdrowych = pole - 1;
	n_chorych = 1;
	n_odpornych = 0;
	powierzchnia.Tablica()[(n*n - 1) / 2].ustawStatus(1, ust.CzasChoroby());
	n_doZara�enia = 0;
	n_doOdporno�ci = 0;
	n_doWyzdrowienia = 0;
	choreKom�rki = new int[n_chorych];
	odporneKom�rki = new int[n_odpornych];
	choreKom�rki[0] = (n*n - 1) / 2;
	odporneKom�rki = new int[0];
}

int Symulacja::czyOdporna(int id)const
{
	for (int i = 0; i < n_odpornych; i++)
	{
		if (odporneKom�rki[i] == id) { return i; }
	}
	return -1;
}

int Symulacja::czyChora(int id)const
{
	for (int i = 0; i < n_chorych; i++)
	{
		if (choreKom�rki[i] == id) { return i; }
	}
	return -1;
}
void Symulacja::wybierzZara�one(int id)
{
	
	int s�siedzi[8];
	int n = ustawienia.Wymiar();
	int x = id%n + 1;
	int y = id/n + 1;

	int xl = x - 1;
	int xp = x + 1;
	int yd = y + 1;
	int yg = y - 1;
	if (xl == 0) { xl = n; }
	if (xp == n + 1) { xp = 1; }
	if (yg == 0) { yg = n; }
	if (yd == n +1) { yd = 1; }

	s�siedzi[0] = (n * (yg - 1)) + xl -1;
	s�siedzi[1] = (n * (yg - 1)) + x - 1;
	s�siedzi[2] = (n * (yg - 1)) + xp - 1;
	s�siedzi[3] = (n * (y - 1)) + xl - 1;
	s�siedzi[4] = (n * (y - 1)) + xp - 1;
	s�siedzi[5] = (n * (yd - 1)) + xl - 1;
	s�siedzi[6] = (n * (yd - 1)) + x - 1;
	s�siedzi[7] = (n * (yd - 1)) + xp - 1;



	for (int i = 0; i < 8; i++)
	{
		int losowanie = rand() % 100 + 1;
		if (losowanie <= ustawienia.Prawdopodobie�stwo())
		{ 
			if (!czyWybrana(s�siedzi[i])&&(czyChora(s�siedzi[i])==-1)&&(czyOdporna(s�siedzi[i])==-1))
			{
				n_doZara�enia++;
				int *nowy = new int[n_doZara�enia];
				for (int i = 0; i < n_doZara�enia - 1; i++)
				{
					nowy[i] = doZara�enia[i];
				}
				delete[] doZara�enia;
				doZara�enia = nowy;
				doZara�enia[n_doZara�enia - 1] = s�siedzi[i];
			}
			
		}
	}
}
bool Symulacja::czyWybrana(int id)const
{
	for (int i = 0; i < n_doZara�enia; i++)
	{
		if (doZara�enia[i] == id) { return true; }
	}
	return false;
}
void Symulacja::Zara�enie()
{
	for (int i = 0; i < n_doZara�enia; i++)
	{
		powierzchnia.Tablica()[doZara�enia[i]].ustawStatus(1, ustawienia.CzasChoroby());
		n_chorych++;
		int *nowy = new int[n_chorych];
		for (int i = 0; i < n_chorych - 1; i++)
		{
			nowy[i] = choreKom�rki[i];
		}
		delete [] choreKom�rki;
		choreKom�rki = nowy;
		choreKom�rki[n_chorych - 1] = doZara�enia[i];
	}

	n_doZara�enia = 0;
	delete[] doZara�enia;
	doZara�enia = new int[n_doZara�enia];
}
void Symulacja::Odporno��()
{
	for (int i = 0; i < n_doOdporno�ci; i++)
	{
		powierzchnia.Tablica()[doOdporno�ci[i]].ustawStatus(2, ustawienia.CzasOdporno�ci());
		n_odpornych++;
		int *nowy = new int[n_odpornych];
		for (int j = 0; j < n_odpornych - 1; j++)
		{
			nowy[j] = odporneKom�rki[j];
		}
		delete[] odporneKom�rki;
		odporneKom�rki = nowy;
		odporneKom�rki[n_odpornych - 1] = doOdporno�ci[i];
		int *nowy2 = new int[n_chorych-1];
		int przes=0;
		for (int j = 0; j < n_chorych; j++)
		{
			if (czyChora(doOdporno�ci[i])==j) { przes = 1; }
			nowy2[j] = choreKom�rki[j + przes];
		}
		n_chorych--;
		delete[] choreKom�rki;
		choreKom�rki = new int[n_chorych];
		choreKom�rki = nowy2;
		
	}
	delete[] doOdporno�ci;
	n_doOdporno�ci = 0;
	doOdporno�ci = new int[n_doOdporno�ci];
}
void Symulacja::Wyzdrowienie()
{
	for (int i = 0; i < n_doWyzdrowienia; i++)
	{
		powierzchnia.Tablica()[doWyzdrowienia[i]].ustawStatus(0);

		int *nowy = new int[n_odpornych - 1];
		int przes = 0;
		for (int j = 0; j < n_odpornych; j++)
		{
			if (czyOdporna(doWyzdrowienia[i])==j) { przes = 1; }
			nowy[j] = odporneKom�rki[j + przes];
		}
		n_odpornych--;
		delete[] odporneKom�rki;
		odporneKom�rki = new int[n_odpornych];
		odporneKom�rki = nowy;

	}
	delete[] doWyzdrowienia;
	n_doWyzdrowienia = 0;
	doWyzdrowienia = new int[n_doWyzdrowienia];
}


void Symulacja::jednostkaCzasu()
{
	for (int i = 0; i < n_chorych; i++)
	{
		wybierzZara�one(choreKom�rki[i]);
	}
	for (int i = 0; i < n_chorych; i++)
	{
		if (powierzchnia.Tablica()[choreKom�rki[i]].odliczCzas() == 0)
		{
			n_doOdporno�ci++;
			int *tab = new int[n_doOdporno�ci];
			for (int j = 0; j < n_doOdporno�ci - 1; j++)
			{
				tab[j] = doOdporno�ci[j];
			}
			delete[] doOdporno�ci;
			doOdporno�ci = tab;
			doOdporno�ci[n_doOdporno�ci - 1] = choreKom�rki[i];
		}
	}

	for (int i = 0; i < n_odpornych; i++)
	{
		if (powierzchnia.Tablica()[odporneKom�rki[i]].odliczCzas() == 0)
		{
			n_doWyzdrowienia++;
			int *tab = new int[n_doWyzdrowienia];
			for (int j = 0; j < n_doWyzdrowienia - 1; j++)
			{
				tab[j] = doWyzdrowienia[j];
			}
			delete[] doWyzdrowienia;
			doWyzdrowienia = tab;
			doWyzdrowienia[n_doWyzdrowienia - 1] = odporneKom�rki[i];
		}
	}
}

void Symulacja::Symuluj()
{
	
	while (true)
	{
		
		std::cout << std::flush;
		system("cls");
		powierzchnia.Wyswietl();
		std::cout << "Czas: " << czasSymulacji << "j.\n";
		std::cout << "Chore: " << n_chorych << " Odporne: " << n_odpornych<<" Zdrowe: "<<n_zdrowych;
		jednostkaCzasu();
		Zara�enie();
		Odporno��();
		Wyzdrowienie();
		
		czasSymulacji++;
		Sleep(ustawienia.CzasOd�wie�ania());
		if ((n_zdrowych == pole) || (n_chorych == pole)) { break; }
		n_zdrowych = pole - (n_chorych + n_odpornych);
	}
	std::cout << "\n\nNacisnij enter aby wrocic do menu...";
	std::cin.ignore(1);
	std::cin.get();
	
}
