#include <iostream>
#include <string.h>
#include "Locatie.h";
#include "Eveniment.h";
#include "Bilet.h";

int main()
{
	Locatie locatii[100];
	Eveniment evenimente[100];
	Bilet bilete[100];
	int nrLoc=0, nrEv=0, nrB=0;
	int loc, ev;
	int x;
	do
	{
		cout << endl;
		cout << "Alegeti o actiune:" << endl;
		cout << "1. Adaugare bilet." << endl;
		cout << "2. Adaugare eveniment." << endl;
		cout << "3. Adaugare locatie." << endl;
		cout << "4. Inchide" << endl;
		cin >> x;
		if (x == 1)
		{
			Bilet b;
			cout << "Pentru ce eveniment doriti sa cumparati bilet?"<<endl;
			cout << "Numele evenimentului: ";
			string denumire;
			cin >> denumire;
			ev = -1;
			for (int i = 0; i < nrEv; i++)
			{
				if (denumire == evenimente[i].getDenumire())ev = i;
			}
			if (ev == -1)cout << "Evenimentul nu exista.";
			else
			{
				cout << endl;
				cin >> b;
				//locatii[loc].evenimente[ev].setBilete(b, 1);
				bilete[nrB] = b;
				nrB++;
			}
			
		}
		else if (x == 2)
		{
			Eveniment e;
			cout << "In ce locatie se afla evenimentul?" << endl;
			cout << "Numar locatie: ";
			cin >> loc;
			if (loc<nrLoc || loc>nrLoc)cout << "Locatia nu exista." << endl;
			else
			{
				cout << endl;
				cin >> e;
				//locatii[loc].setEv(e, 1);
				evenimente[nrEv] = e;
				nrEv++;
			}
		}
		else if (x == 3)
		{
			Locatie l;
			cin >> l;
			locatii[nrLoc] = l;
			nrLoc++;
		}
		else if (x == 4)
		{
			cout << "Programul s-a finalizat."<<endl;
			break;
		}
		else
		{
			cout << "Va rugam sa alegeti una dintre optiunele puse la dispozitie." << endl;
		}
	} while (x != 4);
	return 0;
}