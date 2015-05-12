// PO_BIBLIOTEKA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Book.h"
#include "Libr.h"
#include "Plik.h"

int main()
{
	setlocale(LC_CTYPE, "");
	char nazwa[CHARSIZE], stara_nazwa[CHARSIZE];
	FILE *plik;
	bool plik_istnieje = true;

	do{
		if (!plik_istnieje)
		{
			plik_istnieje = false;
			perror("Blad odczytu pliku");
			cout << "Podaj inna nazwe: ";
		}
		else{
			cout << "Podaj nazwe pliku do odczytu: ";
		}


		cin >> nazwa;
		plik_istnieje = czy_plik_istnieje(nazwa);
	} while (!plik_istnieje);


	plik = otworz_plik(nazwa, true); //otwarcie i sprawdzenie poprawnosci pliku
	//fscanf(plik, "%d", &ilosc_powtorzen);
	fclose(plik);











	plik_istnieje = false;
	do{
		if (plik_istnieje)
		{
			if (!strcmp(nazwa, stara_nazwa)) //nadpisanie
				break;

			strcpy(stara_nazwa, nazwa);
			plik_istnieje = false;
			fputs("Taki plik juz istnieje,\npodaj inna nazwe, lub powtorz abu nadpisac: ", stderr);
		}
		else{
			cout << "Podaj nazwe pliku do zapisu: ";
		}


		cin >> nazwa;
		plik_istnieje = czy_plik_istnieje(nazwa);
	} while (plik_istnieje);

}
