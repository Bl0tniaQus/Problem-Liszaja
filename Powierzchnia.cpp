#include "Powierzchnia.h"
#include <iostream>
Powierzchnia::Powierzchnia(int n)
{
	wymiar = n;
	tablica = new Komórka[n*n];

	for (int i = 0; i < n*n; i++)
	{
		tablica[i].ustawId(i);
	}
}
void Powierzchnia::Wyswietl()const
{
	for (int i = 0; i < wymiar*wymiar; i++)
	{
		std::cout << symbole[tablica[i].Status()];
		if ((i + 1) % wymiar == 0) { std::cout << std::endl; }
	}
}
Komórka* Powierzchnia::Tablica()const
{
	return tablica;
}
