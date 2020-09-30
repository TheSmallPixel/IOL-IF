/*
SPECIFICHE

Si realizzi in C++ una classe che gestisca vettori di 5 elementi e che consenta 
le seguenti operazioni:

* Costruire un vettore nuovo di ordine uguale a 5 avente gli elementi inizia-
lizzati al valore 0.

* Costruire un vettore come copia di un vettore dato.

* Costruire un vettore a partire dai valori interi passati come parametri.

* Costruire un vettore a partire da una stringa passata come parametro con le 
regole seguenti. La stringa contiene solo cifre e virgole. Data la stringa 
"1,2,34,7,12," il vettore da creare conterrà i valori:
1 2 34 7 12

* Si supponga che la stringa possa non specificare le componenti del vettore in 
modo completo, ovvero che la stringa specifichi solo i primi elementi del 
vettore. Si intenderà per convenzione che gli elementi non specificati siano 
nulli. 
Ad esempio, data la stringa 4,2,38, il vettore da creare conterrà i valori:
4 2 38 0 0
Si supponga comunque che la stringa non possa contenere più di 5 valori e che 
sia scritta correttamente.

* Estrarre un elemento del vettore, specificato tramite il suo numero di 
componente.

* Modificare un elemento del vettore, specificato tramite il suo numero di 
componente.

* Sommare due vettori. La somma A+B è il vettore C di 5 componenti in cui 
C[i]=A[i]+B[i] per ogni i.

* Eseguire il prodotto scalare di due vettori. Il prodotto A*B è il numero 
intero num che si ottiene come la somma dei prodotti dei valori degli elementi 
di A per i corrispondenti elementi di B, ovvero 
num = A[0]*B[0] + A[1]*B[1] + ... + A[4]*B[4].

* Eseguire il prodotto di un vettore per un numero intero. Il prodotto A*b dove 
A è un vettore e b è un numero intero è il vettore C con C[i]=A[i]*b per ogni i.

* Effettuare l'assegnamento tra due vettori. A seguito dell'assegnamento, si ha 
che A[i] è uguale a B[i] per ogni i.

* Eseguire il confronto tra due vettori. Due vettori A e B risultano uguali se 
A[i] è uguale a B[i] per ogni i.

* Stampare a video il vettore.

*/



// SOLUZIONE

#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>


const int FALSO = 0;
const int VERO = 1;

const int ORDINE = 5;

class Vettore
{
  friend Vettore operator+(const Vettore &v1, const Vettore &v2);
  friend int operator*(const Vettore &v1, const Vettore &v2);
  friend Vettore operator*(const Vettore &v1, int fattore);
  friend int operator==(const Vettore &v1, const Vettore &v2);
  friend ostream& operator<<(ostream &out, const Vettore &v1);
  friend istream& operator>>(istream &in, Vettore &v1);

private:
  int isValid(int componente) const;
  int vet[ORDINE];

public:

  // Costruttori
  Vettore();
  Vettore(const Vettore &altroVettore);
  Vettore(int dato1, int dato2, int dato3, int dato4, int dato5);
  Vettore(const char stringa[]);
  
  // Metodi di accesso (get e set)
  void set(int componente, int valore, int &ok);
  void get(int componente, int& valore, int &ok) const;
  
  // Metodi 
  Vettore& operator=(const Vettore &v1);
};


Vettore::Vettore()
{
  for(int i = 0; i < ORDINE; i++)
    vet[i] = 0;
}


Vettore::Vettore(const Vettore& altroVettore)
{
  for(int i = 0; i <ORDINE; i++)
    vet[i] = altroVettore.vet[i];
}


Vettore::Vettore(int dato1, int dato2, int dato3, int dato4, int dato5)
{ 
  vet[0] = dato1;
  vet[1] = dato2;
  vet[2] = dato3;
  vet[3] = dato4;
  vet[4] = dato5;
}


Vettore::Vettore(const char stringa[])
{
  //Si suppone che i numeri che compongono il vettore abbiano al piu'
  //5 cifre e un eventuale segno

  char numero[7];
  int i, j, pos;
  for(i = 0; i < ORDINE; i++)
    vet[i] = 0;
  i = j = pos = 0;
  while(stringa[j] != '\0')
  {
    if(stringa[j] == ',')
	{
      numero[pos] = '\0';
      //atoi e' una funzione che converte una stringa composta di cifre
      //in un numero
      vet[i] = atoi(numero);
      i++;
      pos = 0;
    }
    else 
	{
      numero[pos] = stringa[j];
      pos++;
    }
    j++;
  }
}


int Vettore::isValid(int componente) const
{
  if(componente < 1 || componente > ORDINE)
    return FALSO;
  else
    return VERO;
}


void Vettore::get(int componente, int& valore, int &ok) const
{
  if(!isValid(componente)){
    ok = FALSO;
    valore = 0;
  }
  else {
    ok = VERO;
    valore = vet[componente-1];
  }
}


void Vettore::set(int componente, int valore, int &ok)
{
  if(!isValid(componente))
    ok = FALSO;
  else {
    vet[componente-1] = valore;
    ok = VERO;
  }
}


Vettore operator+(const Vettore &v1, const Vettore &v2)
{
  Vettore tempVet;

  for(int i = 0; i < ORDINE; i++)
    tempVet.vet[i] = v1.vet[i] + v2.vet[i];
  return tempVet;
}


int operator*(const Vettore &v1, const Vettore &v2)
{
  int risultato = 0;

  for(int i = 0; i < ORDINE; i++)
    risultato += v1.vet[i] * v2.vet[i];
  return risultato;
}


Vettore operator*(const Vettore &v1, int fattore)
{
  Vettore tempVet;

  for(int i = 0; i < ORDINE; i++)
    tempVet.vet[i] = v1.vet[i] * fattore;
  return tempVet;
}


Vettore& Vettore::operator=(const Vettore &v1)
{
  for(int i = 0; i < ORDINE; i++)
    vet[i] = v1.vet[i];
  return *this;
}


int operator==(const Vettore &v1, const Vettore &v2)
{
  for(int i = 0; i < ORDINE; i++)
    if(v1.vet[i] != v2.vet[i]) 
      return FALSO;
  return VERO;
}


ostream& operator<<(ostream &out, const Vettore &v1)
{
  for(int i = 0; i < ORDINE; i++)
    out << setw(4) << v1.vet[i];
  out << endl << endl;
  return out;
}


istream& operator>>(istream &in, Vettore &v1)
{
  cout << "Inserisci valore 1: ";
  in >> v1.vet[0];
  cout << "Inserisci valore 2: ";
  in >> v1.vet[1];
  cout << "Inserisci valore 3: ";
  in >> v1.vet[2];
  cout << "Inserisci valore 4: ";
  in >> v1.vet[3];
  cout << "Inserisci valore 5: ";
  in >> v1.vet[4];
  return in;
}


void main()
{
	Vettore vet1, vet2="1,2,3,4,", vet3=vet2, vet4(5,4,3,2,1);
	int valore, ok, risultato;

	cout << "Vettore 1 - costruttore di default" << endl;
	cout << vet1;
	cout << "Vettore 2 - costruttore con parametro stringa" << endl;
	cout << vet2;
	cout << "Vettore 3 - costruttore per copia" << endl;
	cout << vet3;
	cout << "Vettore 4 - costruttore con parametri interi" << endl;
	cout << vet4;

	cout << "Estrazione di un componente di un vettore: vettore 2, componente 4" << endl;
	vet2.get(4, valore, ok);
	if (ok)
		cout << "Il componente 4 ha valore " << valore << endl << endl;
	else
		cout << "ERRORE nell'estrazione del valore di un componente";

	cout << "Assegnamento di valore ad un componente di un vettore: vettore 2, componente 5" << endl;
	valore = 5;
	vet2.set(5, valore, ok);
	if (ok)
		cout << "Il componente 5 ha valore " << valore << endl;
	else
		cout << "ERRORE nell'estrazione del valore di un componente" << endl;
	cout << "Vettore 2 - assegnamento di valore ad un componente" << endl;
	cout << vet2;

	//Overloading degli operatori

	cout << "Somma di due vettori" << endl;
	vet1 = vet2+vet3;
	cout << "Risultato della somma di vet2 e vet3" << endl;
	cout << vet1;

	cout << "Prodotto di due vettori" << endl;
	risultato=0;
	risultato = vet2*vet3;
	cout << "Risultato del prodotto di vet2 e vet3" << endl;
	cout << risultato << endl << endl;

	cout << "Prodotto di un vettore per un intero" << endl;
	valore=4;
	vet1 = vet2*valore;
	cout << "Risultato del prodotto di vet2 per " << valore << endl;
	cout << vet1;

	cout << "Assegnamento di vet2 a vet1" << endl;
	vet1=vet2;
	cout << vet1;

	cout << "Verifica dell'uguaglianza di vet1 e vet2" << endl;
	if (vet1==vet2)
		cout << "I due vettori sono uguali " << endl << endl;
	else
		cout << "I due vettori sono diversi" << endl << endl; 

	cout << "Stampa del vettore vet1" << endl << vet1;

	cout << "Lettura dei dati del vettore" << endl;
	cin >> vet4;
	cout << vet4;

	return;
}
