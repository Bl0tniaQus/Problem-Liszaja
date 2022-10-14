#pragma once
class Ustawienia
{
private:
	int wymiar;
	int czasChoroby;
	int czasOdpornoœci;
	int czasOdœwie¿ania;
	int prawdopodobieñstwo;
public:
	Ustawienia(int n=11, int cch=6, int codp=4, int codœ=500, int p=50);
	Ustawienia(const Ustawienia& ust);
	int Wymiar()const {return wymiar;}
	int CzasChoroby()const {return czasChoroby;}
	int CzasOdpornoœci()const {return czasOdpornoœci;}
	int CzasOdœwie¿ania()const {return czasOdœwie¿ania;}
	int Prawdopodobieñstwo()const {return prawdopodobieñstwo;}
	void ustawWymiar(int x) {  if(x>0) wymiar = x; }
	void ustawCzasChoroby(int x) { if(x>0)czasChoroby = x; }
	void ustawCzasOdpornoœci(int x) { if(x>=0) czasOdpornoœci = x; }
	void ustawCzasOdœwie¿ania(int x) { if(x>0) czasOdœwie¿ania = x; }
	void ustawPrawdopodobieñstwo(int x) { if(x>0) prawdopodobieñstwo = x; }
};

