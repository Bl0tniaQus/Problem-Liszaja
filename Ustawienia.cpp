#include "Ustawienia.h"

Ustawienia::Ustawienia(int n, int cch, int codp, int cod�, int p)
{
	wymiar = n;
	czasChoroby = cch;
	czasOdporno�ci = codp;
	czasOd�wie�ania = cod�;
	prawdopodobie�stwo = p;
}

Ustawienia::Ustawienia(const Ustawienia& ust)
{
	this->wymiar = ust.wymiar;
	this->czasChoroby = ust.czasChoroby;
	this->czasOdporno�ci = ust.czasOdporno�ci;
	this->czasOd�wie�ania = ust.czasOd�wie�ania;
	this->prawdopodobie�stwo = ust.prawdopodobie�stwo;
}
