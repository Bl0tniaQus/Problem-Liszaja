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
	n_doZara¿enia = 0;
	n_doOdpornoœci = 0;
	n_doWyzdrowienia = 0;
	choreKomórki = new int[n_chorych];
	odporneKomórki = new int[n_odpornych];
	choreKomórki[0] = (n*n - 1) / 2;
	odporneKomórki = new int[0];
}

int Symulacja::czyOdporna(int id)const
{
	for (int i = 0; i < n_odpornych; i++)
	{
		if (odporneKomórki[i] == id) { return i; }
	}
	return -1;
}

int Symulacja::czyChora(int id)const
{
	for (int i = 0; i < n_chorych; i++)
	{
		if (choreKomórki[i] == id) { return i; }
	}
	return -1;
}
void Symulacja::wybierzZara¿one(int id)
{
	
	int s¹siedzi[8];
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

	s¹siedzi[0] = (n * (yg - 1)) + xl -1;
	s¹siedzi[1] = (n * (yg - 1)) + x - 1;
	s¹siedzi[2] = (n * (yg - 1)) + xp - 1;
	s¹siedzi[3] = (n * (y - 1)) + xl - 1;
	s¹siedzi[4] = (n * (y - 1)) + xp - 1;
	s¹siedzi[5] = (n * (yd - 1)) + xl - 1;
	s¹siedzi[6] = (n * (yd - 1)) + x - 1;
	s¹siedzi[7] = (n * (yd - 1)) + xp - 1;



	for (int i = 0; i < 8; i++)
	{
		int losowanie = rand() % 100 + 1;
		if (losowanie <= ustawienia.Prawdopodobieñstwo())
		{ 
			if (!czyWybrana(s¹siedzi[i])&&(czyChora(s¹siedzi[i])==-1)&&(czyOdporna(s¹siedzi[i])==-1))
			{
				n_doZara¿enia++;
				int *nowy = new int[n_doZara¿enia];
				for (int i = 0; i < n_doZara¿enia - 1; i++)
				{
					nowy[i] = doZara¿enia[i];
				}
				delete[] doZara¿enia;
				doZara¿enia = nowy;
				doZara¿enia[n_doZara¿enia - 1] = s¹siedzi[i];
			}
			
		}
	}
}
bool Symulacja::czyWybrana(int id)const
{
	for (int i = 0; i < n_doZara¿enia; i++)
	{
		if (doZara¿enia[i] == id) { return true; }
	}
	return false;
}
void Symulacja::Zara¿enie()
{
	for (int i = 0; i < n_doZara¿enia; i++)
	{
		powierzchnia.Tablica()[doZara¿enia[i]].ustawStatus(1, ustawienia.CzasChoroby());
		n_chorych++;
		int *nowy = new int[n_chorych];
		for (int i = 0; i < n_chorych - 1; i++)
		{
			nowy[i] = choreKomórki[i];
		}
		delete [] choreKomórki;
		choreKomórki = nowy;
		choreKomórki[n_chorych - 1] = doZara¿enia[i];
	}

	n_doZara¿enia = 0;
	delete[] doZara¿enia;
	doZara¿enia = new int[n_doZara¿enia];
}
void Symulacja::Odpornoœæ()
{
	for (int i = 0; i < n_doOdpornoœci; i++)
	{
		powierzchnia.Tablica()[doOdpornoœci[i]].ustawStatus(2, ustawienia.CzasOdpornoœci());
		n_odpornych++;
		int *nowy = new int[n_odpornych];
		for (int j = 0; j < n_odpornych - 1; j++)
		{
			nowy[j] = odporneKomórki[j];
		}
		delete[] odporneKomórki;
		odporneKomórki = nowy;
		odporneKomórki[n_odpornych - 1] = doOdpornoœci[i];
		int *nowy2 = new int[n_chorych-1];
		int przes=0;
		for (int j = 0; j < n_chorych; j++)
		{
			if (czyChora(doOdpornoœci[i])==j) { przes = 1; }
			nowy2[j] = choreKomórki[j + przes];
		}
		n_chorych--;
		delete[] choreKomórki;
		choreKomórki = new int[n_chorych];
		choreKomórki = nowy2;
		
	}
	delete[] doOdpornoœci;
	n_doOdpornoœci = 0;
	doOdpornoœci = new int[n_doOdpornoœci];
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
			nowy[j] = odporneKomórki[j + przes];
		}
		n_odpornych--;
		delete[] odporneKomórki;
		odporneKomórki = new int[n_odpornych];
		odporneKomórki = nowy;

	}
	delete[] doWyzdrowienia;
	n_doWyzdrowienia = 0;
	doWyzdrowienia = new int[n_doWyzdrowienia];
}


void Symulacja::jednostkaCzasu()
{
	for (int i = 0; i < n_chorych; i++)
	{
		wybierzZara¿one(choreKomórki[i]);
	}
	for (int i = 0; i < n_chorych; i++)
	{
		if (powierzchnia.Tablica()[choreKomórki[i]].odliczCzas() == 0)
		{
			n_doOdpornoœci++;
			int *tab = new int[n_doOdpornoœci];
			for (int j = 0; j < n_doOdpornoœci - 1; j++)
			{
				tab[j] = doOdpornoœci[j];
			}
			delete[] doOdpornoœci;
			doOdpornoœci = tab;
			doOdpornoœci[n_doOdpornoœci - 1] = choreKomórki[i];
		}
	}

	for (int i = 0; i < n_odpornych; i++)
	{
		if (powierzchnia.Tablica()[odporneKomórki[i]].odliczCzas() == 0)
		{
			n_doWyzdrowienia++;
			int *tab = new int[n_doWyzdrowienia];
			for (int j = 0; j < n_doWyzdrowienia - 1; j++)
			{
				tab[j] = doWyzdrowienia[j];
			}
			delete[] doWyzdrowienia;
			doWyzdrowienia = tab;
			doWyzdrowienia[n_doWyzdrowienia - 1] = odporneKomórki[i];
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
		Zara¿enie();
		Odpornoœæ();
		Wyzdrowienie();
		
		czasSymulacji++;
		Sleep(ustawienia.CzasOdœwie¿ania());
		if ((n_zdrowych == pole) || (n_chorych == pole)) { break; }
		n_zdrowych = pole - (n_chorych + n_odpornych);
	}
	std::cout << "\n\nNacisnij enter aby wrocic do menu...";
	std::cin.ignore(1);
	std::cin.get();
	
}
