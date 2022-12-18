#include <iostream>
#include <string.h>
#include "Eveniment.h";

using namespace std;

int Eveniment::evTot = 0;

Eveniment::Eveniment()
{
	denumire = "";
	data.an = 0;
	data.luna = 0;
	data.zi = 0;
	data.ora = 0;
	data.minut = 0;
	bilete = nullptr;
	nrBilete = 0;
	evTot++;
}

Eveniment::Eveniment(string denumire, Data data)
{
	this->denumire = denumire;
	this->data.an = data.an;
	this->data.luna = data.luna;
	this->data.zi = data.zi;
	this->data.ora = data.ora;
	this->data.minut = data.minut;
	bilete = nullptr;
	nrBilete = 0;
	evTot++;
}

Eveniment::Eveniment(const Eveniment& e)
{
	denumire = e.denumire;
	data.an = e.data.an;
	data.luna = e.data.luna;
	data.zi = e.data.zi;
	data.ora = e.data.ora;
	data.minut = e.data.minut;
	if (bilete != nullptr)
	{
		for (int i = 0; i < nrBilete; i++)
		{
			delete[]bilete[i];//problemo
		}
		delete[]bilete;
	}
	nrBilete = e.nrBilete;
	bilete = new Bilet * [nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		bilete[i] = e.bilete[i];
	}
	evTot = e.evTot;
}

Eveniment::~Eveniment()
{
	if (bilete != nullptr)
	{
		for (int i = 0; i < nrBilete; i++)
		{
			delete[]bilete[i];
		}
		delete[]bilete;
	}
	nrBilete = 0;
}

int Eveniment::validareData(Data x)
{
	if (x.luna == 2)
	{
		if ((x.an >= 2022 && x.an <= 2023) && (x.zi >= 1 && x.zi <= 29) && (x.ora >= 0 && x.ora <= 24) && (x.minut >= 0 && x.minut <= 59))
		{
			return 1;
		}
	}
	else if (x.luna == 4 || x.luna == 6 || x.luna == 9 || x.luna == 11)
	{
		if ((x.an >= 2022 && x.an <= 2023) && (x.zi >= 1 && x.zi <= 30) && (x.ora >= 0 && x.ora <= 24) && (x.minut >= 0 && x.minut <= 59))
		{
			return 1;
		}
	}
	else if (x.luna == 1 || x.luna == 3 || x.luna == 5 || x.luna == 7 || x.luna == 8 || x.luna == 10 || x.luna == 12)
	{
		if ((x.an >= 2022 && x.an <= 2023) && (x.zi >= 1 && x.zi <= 31) && (x.ora >= 0 && x.ora <= 24) && (x.minut >= 0 && x.minut <= 59))
		{
			return 1;
		}
	}
	else return 0;
}

int Eveniment::bileteRamase(Bilet** bilete)
{
	int cont=0;
	for (int i = 0; i < nrBilete; i++)
	{
		if (bilete[i]->getRez() == 0)cont++;
	}
	return cont;
}

//setteri

void Eveniment::setDenumire(string denumire)
{
	this->denumire = denumire;
}

void Eveniment::setData(Data data)
{
	this->denumire = denumire;
	this->data.an = data.an;
	this->data.luna = data.luna;
	this->data.zi = data.zi;
	this->data.ora = data.ora;
	this->data.minut = data.minut;
}

void Eveniment::setBilete(Bilet** bilete, int nrBilete)
{
	if (this->bilete != nullptr)
	{
		for (int i = 0; i < this->nrBilete; i++)delete[]this->bilete[i];
		delete[]this->bilete;
		this->bilete = nullptr;
	}
	this->nrBilete = nrBilete;
	this->bilete = new Bilet*[nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		this->bilete[i] = bilete[i];
	}
}

void Eveniment::setNrBilete(int nrBilete)
{
	this->nrBilete = nrBilete;
}

void Eveniment::setEvTot(int evTot)
{
	Eveniment::evTot = evTot;
}

//getteri

string Eveniment::getDenumire()
{
	return denumire;
}

Eveniment::Data Eveniment::getData()
{
	return data;
}

Bilet** Eveniment::getBilete()
{
	Bilet** copie;
	copie = new Bilet * [nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		copie[i] = bilete[i];
	}
	return copie;
}

int Eveniment::getNrBilete()
{
	return nrBilete;
}

int Eveniment::getEvTot()
{
	return evTot;
}

//supraincarcari

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	denumire = e.denumire;
	data.an = e.data.an;
	data.luna = e.data.luna;
	data.zi = e.data.zi;
	data.ora = e.data.ora;
	data.minut = e.data.minut;
	nrBilete = e.nrBilete;
	if (bilete != nullptr)
	{
		for (int i = 0; i < nrBilete; i++)
		{
			bilete[i] = e.bilete[i];
		}
	}
	evTot = e.evTot;
	return *this;
}

ostream& operator<<(ostream& out, Eveniment e)
{
	out << "Numele evenimentului este: " << e.denumire<<endl;
	out << "Data la care va avea loc este: " << e.data.zi << "/" << e.data.luna << "/" << e.data.an << ", la ora " << e.data.ora << ":" << e.data.minut << endl;
	out << "Biletele cumparate sunt: " << endl;
	for (int i = 0; i < e.nrBilete; i++)
	{
		out << e.bilete[i] << endl;
	}
	out << "Numarul total de evenimente este: " << e.evTot;
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	//validari!!!
	cout << "Introduceti numele evenimentului: ";
	in >> e.denumire;
	cout << "Introduceti data si ora de forma zi/luna/an ora:minut: ";
	in >> e.data.zi >> e.data.luna >> e.data.an >> e.data.ora >> e.data.minut;
	return in;
}

Eveniment& Eveniment::operator++()//revizuit
{
	data.zi++;
	if (validareData(data) == 0)//validareData functioneaza?
	{
		data.zi = 1;
		data.luna++;
		if (validareData(data) == 0)
		{
			data.luna = 1;
			data.an++;
		}
	}
	return *this;
}

Eveniment& Eveniment::operator++(int i)
{
	Eveniment copie = *this;
	copie.data.zi++;
	if (validareData(copie.data) == 0)//validareData functioneaza?
	{
		copie.data.zi = 1;
		copie.data.luna++;
		if (validareData(copie.data) == 0)
		{
			copie.data.luna = 1;
			copie.data.an++;
		}
	}
	return *this;
}

bool Eveniment::operator<=(const Eveniment& e)
{
	if (nrBilete <= e.nrBilete)return true;
	else return false;
}