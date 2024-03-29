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
	int n_doZarażenia;
	int n_doOdporności;
	int n_doWyzdrowienia;
	int *doZarażenia;
	int *choreKomórki;
	int *odporneKomórki;
	int *doOdporności;
	int *doWyzdrowienia;
	int pole;
	Ustawienia ustawienia;
	Powierzchnia powierzchnia;
public:
	Symulacja(const Ustawienia& ust);
	int czyChora(int id)const;
	int czyOdporna(int id)const;
	void wybierzZarażone(int id);
	bool czyWybrana(int id)const;
	void Zarażenie();
	void Odporność();
	void Wyzdrowienie();
	void Symuluj();
	void jednostkaCzasu();
};

