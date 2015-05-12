
#include "stdafx.h"
#ifndef _BOOK_H
#define _BOOK_H

#include "Libr.h"


class Book
{
public:
	int ID;
	string Dla_kogo;
	string Title;
	string Author;
	bool Znacznik;

	double czas;
	Book *nast;
	Book *poprz;
};




///////////////////////////////////////////////////////////////////////////////////////////////////////////
// struktura przechowuje dane nt. listy.
class dane_listy
{
private:
	Book *glowa;
	Book *ogon;
public:
	dane_listy() : glowa(NULL), ogon(NULL) {} //konstruktor
	~dane_listy(){} //destruktor

	void usun();
	void wypisz_do_pliku(char[]);
	void dodaj_element_na_koncu(double);
	double wylicz_srednia();
};


#endif