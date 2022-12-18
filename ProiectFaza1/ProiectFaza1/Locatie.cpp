#include <iostream>
#include <string.h>
#include "Locatie.h";

using namespace std;

int Locatie::locTot = 0;

Locatie::Locatie():nrLocMax(0)
{
	tip = "";
	nrZone = 0;
	zone = nullptr;
	nrLocTot = 0;
	nrRanduriTot = 0;
	nrLocZona = 0;
	nrRanduriZona = 0;
	ev = nullptr;
	nrEv = 0;
	preturi = nullptr;
}

Locatie::Locatie(string tip, int nrZone, char** zone, int nrLocTot, int nrRanduriTot, int nrLocZona, int nrRanduriZona, float* preturi):nrLocMax(nrLocMax)
{
	this->tip = tip;
	this->nrZone = nrZone;
	this->zone = new char* [nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		this->zone[i] = new char[strlen(zone[i]) + 1];
		strcpy_s(this->zone[i], strlen(zone[i]) + 1, zone[i]);
	}
	this->nrLocTot = nrLocTot;
	this->nrRanduriTot = nrRanduriTot;
	this->nrLocZona = nrLocZona;
	this->nrRanduriZona = nrRanduriZona;
	ev = nullptr;
	nrEv = 0;
	for (int i = 0; i < nrZone; i++)
	{
		this->preturi[i] = preturi[i];
	}
}

Locatie::Locatie(const Locatie& l):nrLocMax(l.nrLocMax)
{
	tip = l.tip;
	nrZone = l.nrZone;
	zone = new char* [nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		zone[i] = new char[strlen(l.zone[i]) + 1];
		strcpy_s(zone[i], strlen(l.zone[i]) + 1, l.zone[i]);
	}
	nrLocTot = l.nrLocTot;
	nrRanduriTot = l.nrRanduriTot;
	nrLocZona = l.nrLocZona;
	nrRanduriZona = l.nrRanduriZona;
	if (ev != nullptr)
	{
		for (int i = 0; i < nrEv; i++)
		{
			delete[]ev[i];
		}
		delete[]ev;
		ev = nullptr;
	}
	nrEv = l.nrEv;
	ev = new Eveniment ** [nrEv];
	for (int i = 0; i < nrEv; i++)
	{
		ev[i] = l.ev[i];
	}
	if (preturi != nullptr)delete[]preturi;
	preturi = nullptr;
	for (int i = 0; i < nrZone; i++)preturi[i] = l.preturi[i];
	locTot = l.locTot;
}

Locatie::~Locatie()
{
	if (ev != nullptr)
	{
		for (int i = 0; i < nrEv; i++)
		{
			delete[]ev[i];
		}
		delete[]ev;
		ev = nullptr;
	}
	nrEv = 0;
	if (preturi != nullptr)delete[]preturi;
	preturi = nullptr;
}

float Locatie::pretMediu(float* preturi)
{
	float medie=0;
	for (int i = 0; i < nrZone; i++)
	{
		medie += preturi[i];
	}
	medie /= nrZone;
	return medie;
}

//setteri

void Locatie::setTip(string tip)
{
	this->tip = tip;
}

void Locatie::setNrZone(int nrZone)
{
	this->nrZone = nrZone;
}

void Locatie::setZone(char** zone, int nrZone)
{
	if (zone != nullptr && nrZone > 0)
	{
		if (this->zone != nullptr)
		{
			for (int i = 0; i < this->nrZone; i++) delete[]this->zone[i];
			delete[]this->zone;
			this->nrZone = 0;
		}
		this->nrZone = nrZone;
		this->zone = new char* [nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			this->zone[i] = new char[strlen(zone[i]) + 1];
			strcpy_s(this->zone[i], strlen(zone[i]) + 1, zone[i]);
		}
	}
}

void Locatie::setNrLocTot(int nrLocTot)
{
	this->nrLocTot = nrLocTot;
}

void Locatie::setNrRanduriTot(int nrRanduriTot)
{
	this->nrRanduriTot = nrRanduriTot;
}

void Locatie::setNrLocZona(int nrLocZona)
{
	this->nrLocZona = nrLocZona;
}

void Locatie::setNrRanduriZona(int nrRanduriZona)
{
	this->nrRanduriZona = nrRanduriZona;
}

void Locatie::setEv(Eveniment*** ev, int nrEv)
{
	if (this->ev != nullptr)
	{
		for (int i = 0; i < nrEv; i++)
		{
			delete[]this->ev[i];
		}
		delete[]this->ev;
		this->ev = nullptr;
	}
	this->nrEv = nrEv;
	this->ev = new Eveniment **[nrEv];
	for (int i = 0; i < nrEv; i++)
	{
		this->ev[i] = ev[i];
	}
}

void Locatie::setNrEv(int nrEv)
{
	this->nrEv = nrEv;
}

void Locatie::setPreturi(float* preturi, int nrZone)
{
	if (this->preturi != nullptr)delete[]this->preturi;
	this->preturi = nullptr;
	this->nrZone = nrZone;
	for (int i = 0; i < nrZone; i++)this->preturi[i] = preturi[i];
}

void Locatie::setLocTot(int locTot)
{
	Locatie::locTot = locTot;
}

//getteri

string Locatie::getTip()
{
	return tip;
}

int Locatie::getNrZone()
{
	return nrZone;
}

char** Locatie::getZone()
{
	char** copie;
	copie = new char* [nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		copie[i] = new char[strlen(zone[i]) + 1];
		strcpy_s(copie[i], strlen(zone[i]) + 1, zone[i]);
	}
	return copie;
}

int Locatie::getNrLocTot()
{
	return nrLocTot;
}

int Locatie::getNrRanduriTot()
{
	return nrRanduriTot;
}

int Locatie::getNrLocZona()
{
	return nrLocZona;
}

int Locatie::getNrRanduriZona()
{
	return nrRanduriZona;
}

Eveniment*** Locatie::getEv()
{
	Eveniment*** copie;
	copie = new Eveniment * *[nrEv];
	for (int i = 0; i < nrEv; i++)
	{
		copie[i] = ev[i];
	}
	return copie;
}

int Locatie::getNrEv()
{
	return nrEv;
}

float* Locatie::getPreturi()
{
	float* copie;
	copie = new float[nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		copie[i] = preturi[i];
	}
	return copie;
}

int Locatie::getLocTot()
{
	return locTot;
}

//supraincarcari

Locatie& Locatie::operator=(const Locatie& l)
{
	tip = l.tip;
	nrZone = l.nrZone;
	zone = new char* [nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		zone[i] = new char[strlen(l.zone[i]) + 1];
		strcpy_s(zone[i], strlen(l.zone[i]) + 1, l.zone[i]);
	}
	nrLocTot = l.nrLocTot;
	nrRanduriTot = l.nrRanduriTot;
	nrLocZona = l.nrLocZona;
	nrRanduriZona = l.nrRanduriZona;
	if (ev != nullptr)
	{
		for (int i = 0; i < nrEv; i++)
		{
			delete[]ev[i];
		}
		delete[]ev;
		ev = nullptr;
	}
	nrEv = l.nrEv;
	ev = new Eveniment * *[nrEv];
	for (int i = 0; i < nrEv; i++)
	{
		ev[i] = l.ev[i];
	}
	if (preturi != nullptr)delete[]preturi;
	preturi = nullptr;
	for (int i = 0; i < nrZone; i++)preturi[i] = l.preturi[i];
	locTot = l.locTot;
	return *this;
}

ostream& operator<<(ostream& out, Locatie l)
{
	out << "Tipul locatiei este: " << l.tip;
	out << "Numarul de zone al locatiei este: " << l.nrZone;
	out << "Acestea sunt: ";
	for (int i = 0; i < l.nrZone; i++)
	{
		out << l.zone[i] << " ";
	}
	out << endl;
	out << "Numarul total de locuri al locatiei este: " << l.nrLocTot;
	out << "Numarul total de randuri al locatiei este: " << l.nrRanduriTot;
	out << "Numarul de locuri al fiecarei zone este: " << l.nrLocZona;
	out << "Numarul de randuri al fiecarei zone este: " << l.nrRanduriZona;
	out << "Evenimentele existente sunt: " << endl;
	for (int i = 0; i < l.nrEv; i++)
	{
		out << l.ev[i] << endl;
	}
	out << "Preturile biletelor sunt: " << endl;
	for (int i = 0; i < l.nrZone; i++)
	{
		out << l.preturi[i] << " pentru zona " << l.zone[i]<<endl;
	}
	out << "Numarul total de locatii este: " << l.locTot<<endl;
	out << "Numarul maxim de locuri al locatiei este: " << l.nrLocMax << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	cout << "Introduceti tipul locatiei: ";
	in >> l.tip;
	cout << "Introduceti numarul de zone: ";
	in >> l.nrZone;
	cout << "Introduceti zonele: ";
	for (int i = 0; i < l.nrZone; i++)
	{
		in >> l.zone[i];
	}
	cout << "Introduceti numarul total de locuri al locatiei: ";
	in >> l.nrLocTot;
	cout << "Introduceti numarul total de randuri al locatiei: ";
	in >> l.nrRanduriTot;
	cout << "Introduceti numarul de locuri al fiecarei zone: ";
	in >> l.nrLocZona;
	cout << "Introduceti numarul de randuri al fiecarei zone: ";
	in >> l.nrRanduriZona;
	cout << "Introduceti preturile biletelor pentru fiecare zona:";
	for (int i = 0; i < l.nrZone; i++)
	{
		cout << endl;
		cout << "Pentru zona " << l.zone[i] << ": ";
		in >> l.preturi[i];
	}
	cout << endl;
	return in;
}

Locatie& Locatie::operator+(const Locatie& l)
{
	Locatie copie = *this;
	for (int i = 0; i < copie.nrZone; i++)
	{
		copie.preturi[i] = preturi[i] + l.preturi[i];
	}
	return copie;
}

float Locatie::operator[](int index)
{
	if (index >= 0 && index <= nrZone)
	{
		return preturi[index];
	}
	else return 0;
}