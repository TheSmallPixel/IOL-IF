/*Differenza tra reference e puntatore
Si stampano valori assegnati e indirizzi della locazione di memoria della
singola variabile per verificare che il reference e' di fatto un alias della
variabile originale, avente medesimo indirizzo di memoria e quindi valore della
variabile stessa. */

#include <iostream>
using namespace std;

//Inverte i valori di due variabili utilizzando i puntatori
void swap(int *x, int *y);
//Inverte i valori di due variabili utilizzando i reference
void swap(int &x, int &y);

int main()
{
	int a=12;
	int &b=a;  // b e' un reference di a
	int *c=&a; // c e' un puntatore che punta ad a
	int *d=&b; // d e' un puntatore che punta ad b

	cout<<"int a=12;"<<endl;
	cout<<"int &b=a; // b e' un reference di a"<<endl;
	cout<<"int *c=&a; // c e' un puntatore che punta ad a"<<endl;
	cout<<"int *d=&b; // d e' un puntatore che punta ad b"<<endl;
	cout<<"-------------------------------------------"<<endl;

	cout<<"a="<<a<<" - &a="<<&a<<endl;

	//verifichiamo che la "cella di memoria b" ha il medesimo indirizzo di a: e' un alias di a
	cout<<"b="<<b<<" - &b="<<&b<<endl;  
	
	//a differenza dell'alias il puntatore c ha un proprio indirizzo differente dall'elemento puntato
	cout<<"c="<<c<<" - &c="<<&c<<" - *c="<<*c<<endl; 

	//anche d come c ha un proprio indirizzo differente dall'elemento puntato, ovviamente
	//differente da c
	cout<<"d="<<d<<" - &d="<<&d<<" - *d="<<*d<<endl;

	//l'assegnamento di b equivale a quello di a
	b=15;
	cout<<endl;
	cout<<"Nuovo assegnamento di b: b=15"<<endl<<endl;
	cout<<"a="<<a<<" - &a="<<&a<<endl;
	cout<<"b="<<b<<" - &b="<<&b<<endl;

	cout<<"-------------------------------------------"<<endl;
	cout<<"Parametri puntatore e parametri reference"<<endl;
	int e=2;
	cout<<"Valori iniziali a="<<a<<" e="<<e<<endl;
	cout<<"swap(&a,&e) - si passano ai parametri puntatore gli indirizzi di a e di e"<<endl;
	swap(&a,&e);
	cout<<"Valori invertiti a="<<a<<" e="<<e<<endl;

	cout<<"-------------------------------------------"<<endl;
	cout<<"Valori iniziali a="<<a<<" e="<<e<<endl;
	cout<<"swap(a,e) - i parametri della funzione saranno reference di a e di e"<<endl;
	swap(a,e);
	cout<<"Valori invertiti a="<<a<<" e="<<e<<endl;



	return 0;
}

void swap(int *x, int *y)
{
	int temp;
	
	temp=*x;
	*x=*y;
	*y=temp;
	
	return;
}

void swap(int &x, int &y)
{
	int temp;
	
	temp=x;
	x=y;
	y=temp;

	return;
}