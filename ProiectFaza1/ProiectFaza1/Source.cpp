
//locatie:
//va retine toate locatiile care exista
//tipul: film, meci, piesa teatru
//nr de locuri si randuri, zone, locuri/rand etc, ore de functionare?
//tipul sala normala/VIP, tribuna 1, 2, 3, categ 1, 2 sau loja//NU

//ex: sala 12, film, VIP, care are 20 de randuri, 15*20 locuri, 15 locuri/rand
//ex: stadion 3, meci, tribuna 2, 20 randuri, 20*20 locuri, 20 locuri/rand
//ex: sala de teatru 5, teatru, categoria 3, 30 randuri, 30*20 locuri, 20 locuri/rand

//eveniment:
//va retine fiecare eveniment
//tipul: film, meci, piesa teatru
//data, ora, denumire, durata in fct de tip
//locatia

//ex: spider-man no way home, film, 12.12.12, ora 12.12, sala 12

//bilet:
//va retine toate biletele
//tipul: film, meci, piesa teatru
//evenimentul, locatia, data, ora, denumire, rand, loc, sala/loja/tribuna/VIP etc
//id unic!!

//ex: bilet pentru spider-man no way home, film, sala 12, 12.12.12, 12.12, rand 20, loc 15

//+++++++

//o structura pentru data
//liste pentru validare intrari (ex lista cu zone viabile; daca se introduce o zona care nu se afla in lista
// intrarea nu este acceptata)
//+-generator uid

//vector dinamic char x
//vector dinamic numere x
//atribut const x
//atribut static x
//metoda statica

#include <iostream>
#include <string.h>
#include "Locatie.h";
#include "Eveniment.h";
#include "Bilet.h";

int main()
{
	//citire/scriere locatie
	//citire/scriere eveniment
	//generare bilete
	//verificare bilete
	//meniu utilizator
	//fara erori indiferent de input

	int cnp[13];
	cnp[0] = 5;
	cnp[1] = 2;
	cnp[2] = 3;
	cnp[3] = 1;
	cnp[4] = 2;
	cnp[5] = 1;
	cnp[6] = 7;
	cnp[7] = 1;
	cnp[8] = 2;
	cnp[9] = 3;
	cnp[10] = 4;
	cnp[11] = 5;
	cnp[12] = 6;

	//Bilet b("film", cnp);
	//cout << "nr bilete total: " << b.getBileteTot() << endl;
	//cout << b;//whar
	//cout << endl;
	//cout <<"nr bilete total: "<< b.getBileteTot() << endl;

	/*int copie[7];
	copie[0] = 1;
	copie[1] = 1;
	copie[2] = 7;
	copie[3] = 1;
	copie[4] = 2;
	copie[5] = 2;
	copie[6] = 3;

	cout << b.validareUid(copie)<<endl;*/

	//Bilet c;
	//cout << endl;
	//cout << b.getBileteTot() << endl;
	//cout << c.getBileteTot();

	//Bilet b;
	//cout << b.getBileteTot()<<endl;
	//Bilet c;
	//cout << b.getBileteTot()<<endl;
	//cout << c.getBileteTot()<<endl;

	/*bool rez = !b;
	cout << endl;
	cout << "b.rez =" << b.getRez() << endl;
	cout << "rez= " << rez;*/

	Eveniment e;
	cout << e;

	return 0;

}