#include "Kom�rka.h"


Kom�rka::Kom�rka()
{
	status = 0;
	czasStatusu = 0;
	id = 0;
}
void Kom�rka::ustawId(int id)
{
	this->id = id;
}
int Kom�rka::Status()const
{
	return status;
}
void Kom�rka::ustawStatus(int status, int czas)
{
	this->status = status;
	czasStatusu = czas;
}

int Kom�rka::odliczCzas()
{
	czasStatusu--;
	return czasStatusu;
}
