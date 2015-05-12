#include "stdafx.h"
#include "Book.h"
#include "Plik.h"



///////////////////////////////////////////////////////////////////////////////////////////////////////////
// usuwa lista, kterej glowa znajduje sie w lista.glowa
void dane_listy::usun()
{
	if (glowa == NULL)
	{
		cout << "--------------------------------------\nNie zwalniam pamieci, gdyz lista jest pusta.\n\n";
	}
	else {
		cout << "--------------------------------------\nZwalniam pamieci [czas]: ";

		Book *del = NULL;

		while (glowa != NULL)
		{
			del = glowa;
			glowa = glowa->nast;
			cout << del->czas << " ";
			free(del);
		}

		ogon = NULL;

		cout << "\n\n";
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////
// przyjmuje dane do nowego elementu i wkleja go jako ogon
void dane_listy::dodaj_element_na_koncu(double wynik)
{
	Book *nowy = (Book*)malloc(sizeof(Book));
	nowy->nast = NULL;

	if (glowa == NULL) //lista jest pusta
	{
		nowy->poprz = NULL;
		glowa = ogon = nowy;
	}
	else {
		ogon->nast = nowy;
		nowy->poprz = ogon;
		ogon = nowy;
	}

	//tu do dostosowania w
	nowy->czas = wynik;
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////
// przyjmuje plik i drukuje do pliku
void dane_listy::wypisz_do_pliku(char nazwa[])
{
	FILE *plik = otworz_plik(nazwa, false);
	Book *wsk = glowa;
	cout << "--------------------------------------\nZapisalem do pliku.\n\n";
	while (wsk != NULL)
	{
		fprintf(plik, "%lf", wsk->czas);
		if (wsk->nast != NULL) //nie wstawiam nowej linii na koncu pliku
			fprintf(plik, "\n");
		wsk = wsk->nast;
	}
	fclose(plik);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////

double dane_listy::wylicz_srednia()
{
	Book *wsk = glowa;
	int suma = 0;
	double srednia = 0;

	while (wsk != NULL)
	{
		srednia += wsk->czas;
		suma++;
		wsk = wsk->nast;
	}

	srednia = srednia / suma;

	return srednia;
}