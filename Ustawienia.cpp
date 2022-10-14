#include "Ustawienia.h"

Ustawienia::Ustawienia(int n, int cch, int codp, int codœ, int p)
{
	wymiar = n;
	czasChoroby = cch;
	czasOdpornoœci = codp;
	czasOdœwie¿ania = codœ;
	prawdopodobieñstwo = p;
}

Ustawienia::Ustawienia(const Ustawienia& ust)
{
	this->wymiar = ust.wymiar;
	this->czasChoroby = ust.czasChoroby;
	this->czasOdpornoœci = ust.czasOdpornoœci;
	this->czasOdœwie¿ania = ust.czasOdœwie¿ania;
	this->prawdopodobieñstwo = ust.prawdopodobieñstwo;
}
