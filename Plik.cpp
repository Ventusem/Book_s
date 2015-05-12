#include "stdafx.h"
#include "Plik.h"



///////////////////////////////////////////////////////////////////////////////////////////////////////////
// przyjmuje plik, zwraca true je�li pusty, false je�li pe�ny
bool czy_pusty_plik(FILE * plik)
{
	int przesuniecie = ftell(plik);
	fseek(plik, 0, SEEK_END);
	if (ftell(plik) == 0)
		return true;

	fseek(plik, przesuniecie, SEEK_SET);
	return false;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////
// przyjmuje nazw� pliku i zwraca info czy istnieje
bool czy_plik_istnieje(char nazwa[])
{
	if (FILE *plik = fopen(nazwa, "r")) {
		fclose(plik);
		return true;
	}
	else {
		return false;
	}
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////
// przyjmuje nazw� i info odczyt(true)/zapis(false), zwraca wska�nik na plik lub ko�czy program gdy b��d
FILE *otworz_plik(char nazwa[], bool odczyt) //true- otw�rz do odczytu, false- otw�rz do zapisu
{
	FILE * plik;

	if (odczyt)
		plik = fopen(nazwa, "r+");
	else
		plik = fopen(nazwa, "w+");

	if (plik == NULL)
	{
		fputs("\nNie mog� otworzy� tego pliku, ko�cz� dzia�anie.\n\n", stderr);
		exit(0);
	}

	if (czy_pusty_plik(plik) && odczyt)
	{
		fputs("\nPlik jest pusty, ko�cz� dzia�anie.\n\n", stderr);
		exit(0);
	}

	return plik;
}