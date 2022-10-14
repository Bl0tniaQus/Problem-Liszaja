#include "Program.h"
Program::Program():ustawienia()
{
	srand(time(NULL)); 
}
void Program::Uruchom()
{
	
	Menu();
}

void Program::Menu()
{
	while (true)
	{ 
	
		int wybor;
		system("cls");
		std::cout << "PROBLEM LISZAJA\n\n";
		std::cout << "1. Zmien ustawienia\n";
		std::cout << "2. Symuluj\n";
		std::cout << "0. Zakoncz\n\n";
		std::cout << "Podaj opcje: ";
		std::cin >> wybor;

		switch (wybor)
		{
		case 1:
			{
				zmienUstawienia();
				break;
			}
		case 2:
			{
				Symulacja symul(ustawienia);
				symul.Symuluj();
				break;
			}
		case 0:
			{
				return;
			}
		}
	
	}
	


}

void Program::zmienUstawienia()
{
	while (true)
	{

		int wybor;
		int wartosc;
		system("cls");
		std::cout << "OPCJE\n\n";
		std::cout << "1. Rozmiar planszy("<<ustawienia.Wymiar()<<")\n";
		std::cout << "2. Czas choroby(" << ustawienia.CzasChoroby() << "j. czasu)\n";
		std::cout << "3. Czas odpornosci(" << ustawienia.CzasOdpornoœci() << "j. czasu)\n";
		std::cout << "4. Prawdopodobienstwo(" << ustawienia.Prawdopodobieñstwo() << "%)\n";
		std::cout << "5. Czas odswiezania ekranu(" << ustawienia.CzasOdœwie¿ania() << "ms)\n";
		std::cout << "0. Powrot\n\n";
		std::cout << "Podaj opcje: ";
		std::cin >> wybor;

		switch (wybor)
		{
		case 1:
		{
			std::cout << "Podaj rozmiar: ";
			std::cin >> wartosc;
			ustawienia.ustawWymiar(wartosc);
			break;
		}
		case 2:
		{
			std::cout << "Podaj czas choroby: ";
			std::cin >> wartosc;
			ustawienia.ustawCzasChoroby(wartosc);
			break;
		}
		case 3:
		{
			std::cout << "Podaj czas odpornosci: ";
			std::cin >> wartosc;
			ustawienia.ustawCzasOdpornoœci(wartosc);
			break;
		}
		case 4:
		{
			std::cout << "Podaj prawdopodobienstwo(w procentach): ";
			std::cin >> wartosc;
			ustawienia.ustawPrawdopodobieñstwo(wartosc);
			break;
		}
		case 5:
		{
			std::cout << "Podaj czas odswiezania(w ms): ";
			std::cin >> wartosc;
			ustawienia.ustawCzasOdœwie¿ania(wartosc);
			break;
		}
		case 0:
		{
			return;
		}
		}


	}



}
