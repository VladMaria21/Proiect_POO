#pragma once
#include <iostream>
#include <string.h>
#include "Bilet.h";

using namespace std;

class Eveniment
{
private:
	string denumire;

	typedef struct Data
	{
		int an, luna, zi;
		int ora, minut;
	};

	Data data;
	Bilet** bilete;
	int nrBilete;
	static int evTot;//numarul de evenimente care exista

public:
	friend class Bilet;

	Eveniment();
	Eveniment(string denumire, Data data);
	Eveniment(const Eveniment& e);
	~Eveniment();

	int validareData(Data x);
	int bileteRamase(Bilet** bilete);

	void setDenumire(string denumire);
	void setData(Data data);
	void setBilete(Bilet** bilete, int nrBilete);
	void setNrBilete(int nrBilete);
	void setEvTot(int evTot);

	string getDenumire();
	Data getData();
	Bilet** getBilete();
	int getNrBilete();
	static int getEvTot();

	Eveniment& operator=(const Eveniment& e);
	friend ostream& operator<<(ostream& out, Eveniment e);
	friend istream& operator>>(istream& in, Eveniment& e);

	Eveniment& operator++();//amana data evenimentului pentru o zi
	Eveniment& operator++(int i);
	bool operator<=(const Eveniment& e);//compara nr de bilete vandute pentru evenimentele date
};