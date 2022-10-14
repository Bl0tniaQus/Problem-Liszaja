#pragma once
#include "Powierzchnia.h"
#include "Ustawienia.h"
#include "Windows.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
class Symulacja
{
private:
	int czasSymulacji;
	int n_zdrowych;
	int n_chorych;
	int n_odpornych;
	int n_doZara�enia;
	int n_doOdporno�ci;
	int n_doWyzdrowienia;
	int *doZara�enia;
	int *choreKom�rki;
	int *odporneKom�rki;
	int *doOdporno�ci;
	int *doWyzdrowienia;
	int pole;
	Ustawienia ustawienia;
	Powierzchnia powierzchnia;
public:
	Symulacja(const Ustawienia& ust);
	int czyChora(int id)const;
	int czyOdporna(int id)const;
	void wybierzZara�one(int id);
	bool czyWybrana(int id)const;
	void Zara�enie();
	void Odporno��();
	void Wyzdrowienie();
	void Symuluj();
	void jednostkaCzasu();
};

