#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream out("test.txt");
	if(!out)
	{
		cout<<"Impossibile aprire il file. "<<endl;
		return 1;
	}

	out<< 10 << " " << 123.23 << " " << "\n";
	out << "Breve file di testo.";

	out.close();

	return 0;
}