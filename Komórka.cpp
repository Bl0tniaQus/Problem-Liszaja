#include "Komórka.h"


Komórka::Komórka()
{
	status = 0;
	czasStatusu = 0;
	id = 0;
}
void Komórka::ustawId(int id)
{
	this->id = id;
}
int Komórka::Status()const
{
	return status;
}
void Komórka::ustawStatus(int status, int czas)
{
	this->status = status;
	czasStatusu = czas;
}

int Komórka::odliczCzas()
{
	czasStatusu--;
	return czasStatusu;
}
