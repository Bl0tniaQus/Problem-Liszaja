#pragma once
#include "Kom�rka.h"
class Powierzchnia
{
private:
	Kom�rka *tablica;
	int wymiar;
public:
	Powierzchnia(int n);
	void Wyswietl()const;
	Kom�rka* Tablica()const;
};

