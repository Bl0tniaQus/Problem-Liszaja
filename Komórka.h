#pragma once

const char symbole[3] = { char(176), char(178), char(177) };

class Kom�rka
{
private:
	int id;
	int status; //0 - zdrowa, 1 - chora, 2 - odporna
	int czasStatusu;
public:
	Kom�rka();
	void ustawId(int id);
	int Status()const;
	void ustawStatus(int status, int czas=0);
	int odliczCzas();
};

