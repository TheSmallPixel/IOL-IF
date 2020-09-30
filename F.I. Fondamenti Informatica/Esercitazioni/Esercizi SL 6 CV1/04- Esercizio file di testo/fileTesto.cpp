/*
E' dato un file salti.txt contenente, in ogni sua riga, il cognome di un atleta
e sei numeri decimali corrispondenti alle prove di salto in lungo da lui
effettuate (lo 0 indica un salto nullo).
Si realizzi un programma, in linguaggio C, che leggendo i dati da tale file
salti.txt riporti in un nuovo file classifica.txt, per ogni riga, il cognome
dell'atleta ed il valore della sua migliore prova. Tenendo conto che nel file 
salti.txt potranno comparire al più 12 atleti, si faccia in modo che i dati che 
compaiono nel file classifica.txt siano ordinati in modo decrescente rispetto 
al miglior salto effettuato (per semplicità si supponga che non ci siano mai 
due atleti che realizzano la stessa misura).
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const int NUMATLETI=12;
	const int NUMSALTI=6;
	const int LUNGNOME=20;

	struct atleta{
		char cognome[LUNGNOME];
		float salto;
	};
	
	float salto;
	int i, saltatore=0;
	atleta atleti[NUMATLETI], temp;

	ifstream in("salti.txt");
	if(!in)
	{
		cout<<"Impossibile aprire il file salti.txt. "<<endl;
		return 1;
	}

	while(!in.eof())
	{
		in >> atleti[saltatore].cognome;
		atleti[saltatore].salto = 0;
		for (i=0; i<NUMSALTI; i++)
		{
			in >> salto;
			if (salto > atleti[saltatore].salto)
				atleti[saltatore].salto = salto;
		}
		saltatore++;
	}
	in.close();

	// Ordinamento dei dati
	for (i=0; i<saltatore; i++)
		for(int j=i; j<saltatore; j++)
			if (atleti[i].salto < atleti[j].salto)
			{
				temp = atleti[i];
				atleti[i] = atleti[j];
				atleti[j] = temp;
			}
	// Creazione del file classifica.txt
	ofstream out("classifica.txt");
	if(!out)
	{
		cout<<"Impossibile aprire il file classifica.txt. "<<endl;
		return 1;
	}
	for (i=0; i<saltatore; i++)
		out << atleti[i].cognome << " " << atleti[i].salto << endl;
	
	out.close();

	return 0;
}