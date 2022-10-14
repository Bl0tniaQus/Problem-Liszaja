#pragma once
class Ustawienia
{
private:
	int wymiar;
	int czasChoroby;
	int czasOdporno�ci;
	int czasOd�wie�ania;
	int prawdopodobie�stwo;
public:
	Ustawienia(int n=11, int cch=6, int codp=4, int cod�=500, int p=50);
	Ustawienia(const Ustawienia& ust);
	int Wymiar()const {return wymiar;}
	int CzasChoroby()const {return czasChoroby;}
	int CzasOdporno�ci()const {return czasOdporno�ci;}
	int CzasOd�wie�ania()const {return czasOd�wie�ania;}
	int Prawdopodobie�stwo()const {return prawdopodobie�stwo;}
	void ustawWymiar(int x) {  if(x>0) wymiar = x; }
	void ustawCzasChoroby(int x) { if(x>0)czasChoroby = x; }
	void ustawCzasOdporno�ci(int x) { if(x>=0) czasOdporno�ci = x; }
	void ustawCzasOd�wie�ania(int x) { if(x>0) czasOd�wie�ania = x; }
	void ustawPrawdopodobie�stwo(int x) { if(x>0) prawdopodobie�stwo = x; }
};

