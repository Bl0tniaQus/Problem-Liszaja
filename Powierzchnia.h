#pragma once
#include "Komórka.h"
class Powierzchnia
{
private:
	Komórka *tablica;
	int wymiar;
public:
	Powierzchnia(int n);
	void Wyswietl()const;
	Komórka* Tablica()const;
};

