#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char ch;
	int i;
	float f;
	char str[80];

	ifstream in("sorgente.txt");
	if(!in)
	{
		cout<<"Impossibile aprire il file. "<<endl;
		return 1;
	}

	in >> i;
	in >> f;
	//in >> str; // interrompe la lettura al primo spazio
	in.getline(str, 80); //Legge l'intera riga

	cout << i << " " << f << " " <<"\n";
	cout << str <<"\n";

	in.close();
	 return 0;
}