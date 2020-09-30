#include<iostream>
using namespace std;

//enum Boolean {FALSO, VERO};

class Polinomio
{
	friend class Termine;
	Termine *primoTermine;
public:
	Polinomio() {primoTermine = 0;};
	void aggiungi(int coeff, int degree);
	void aggiungiPol(const Polinomio &altroPol);
	double valorePol(double valx) const;
	Polinomio operator=(const Polinomio &altroPol);
	bool operator==(const Polinomio &altroPol) const;
	int gradoMax() const;
	void prodotto(const Termine &t);
	Polinomio operator*(const Polinomio &altroPol) const;
	void stampa() const;
	void svuota();
};

class Termine
{
	friend class Polinomio;
	int coefficiente;
	int grado;
	Polinomio   termsucc;
public:
	Termine(int coeff, int degree)
	{
		coefficiente = coeff;
		grado = degree;
	};
	double valore(double valx) 
	{return coefficiente * pow(valx,grado);};
};

void  Polinomio::aggiungi(int coeff, int degree)
{
	if ((primoTermine != 0) && (primoTermine->grado > degree))
		primoTermine->termsucc.aggiungi(coeff,degree);
	else
		if ((primoTermine != 0) && (primoTermine->grado==degree))
		{
			primoTermine->coefficiente += coeff;
			if (primoTermine->coefficiente==0)
			{
				Termine *temp;
				temp = primoTermine;
				primoTermine=primoTermine->termsucc.primoTermine;
				delete temp;
			}
		}
		else  //primoTermine==0 || primoTermine->grado<degree
		{
			Termine *nuovoterm;
			nuovoterm = new Termine(coeff,degree);
			nuovoterm->termsucc.primoTermine=primoTermine;
			primoTermine = nuovoterm;
		}
}

void  Polinomio::aggiungiPol(const Polinomio &altroPol)
{
	if (altroPol.primoTermine != 0)
	{
		aggiungi(altroPol.primoTermine->coefficiente,
						altroPol.primoTermine->grado);
		aggiungiPol(altroPol.primoTermine->termsucc);
	}
}

double Polinomio::valorePol(double valx) const
{
	if (primoTermine != 0)
	{
		return primoTermine->valore(valx) +
				primoTermine->termsucc.valorePol(valx);
	}
	else
	{
		return (double) 0;
	}
}

Polinomio Polinomio::operator=(const Polinomio &altroPol)
{
	svuota();
	if (altroPol.primoTermine != 0)
	{
//		Termine *copia;
		primoTermine = new Termine(
					altroPol.primoTermine->coefficiente,
					altroPol.primoTermine->grado);
		primoTermine->termsucc=
					altroPol.primoTermine->termsucc;
	}
	else
	{
		primoTermine = 0;
	}
	return *this;
}

bool Polinomio::operator==(const Polinomio &altroPol) const
{
	if ((primoTermine==0) || (altroPol.primoTermine==0))
	{
		return primoTermine==altroPol.primoTermine;
	}
	else
	{
		return (primoTermine->coefficiente ==
				altroPol.primoTermine->coefficiente) &&
				(primoTermine->grado ==
				altroPol.primoTermine->grado) &&
				(primoTermine->termsucc ==
				altroPol.primoTermine->termsucc);
	}
}

int Polinomio::gradoMax() const
{
	if (primoTermine != 0)
	{
		return primoTermine->grado;
	}
	else
	{
		cout << endl << "Attenzione, si e` chiesto il grado di un polinomio vuoto";
		return -1;
    }
}

void Polinomio::prodotto(const Termine &t)
{
	if (primoTermine != 0)
	{
		primoTermine->coefficiente *= t.coefficiente;
		primoTermine->grado += t.grado;
		primoTermine->termsucc.prodotto(t);
    }
}

Polinomio Polinomio::operator*(const Polinomio &altroPol) const
{
	Polinomio originale = *this;
	Polinomio parziale;
	Polinomio risultato;
	Termine *fattore;
	fattore = altroPol.primoTermine;
	while (fattore != 0)
	{
		parziale = originale;
		parziale.prodotto(*fattore);
		risultato.aggiungiPol(parziale);
		fattore = fattore->termsucc.primoTermine;
	}
	return risultato;
}

void Polinomio::stampa() const
{
	if (primoTermine != 0)
	{
		cout << primoTermine->coefficiente << " * x^"
				<< primoTermine->grado;
		if (primoTermine->termsucc.primoTermine != 0)
		{
			cout << " + ";
		}
		primoTermine->termsucc.stampa();
	}
	else
	{
		cout << endl;
	}
}

void Polinomio::svuota()
{
	if (primoTermine != 0)
	{
		primoTermine->termsucc.svuota();
		delete primoTermine;
		primoTermine = 0;
	}
}
  
int main()
{
	Polinomio p1,p2;
	p1.aggiungi(1,2);
	p1.aggiungi(2,1);
	p1.aggiungi(1,3);
	cout << "Stampa del polinomio" << endl;
	p1.stampa();
	cout << "stampa del valore polinomio quando x=3" << endl;
	cout << p1.valorePol(3) << endl;
	cout << "Aggiunta di polinomi" << endl;
	p2.aggiungi(1,0);
	p2.aggiungi(1,2);
	p2.stampa();
	cout << "Somma di polinomi" << endl;
	p1.aggiungiPol(p2);
	p1.stampa();
	cout << "stampa del valore del polinomio quando x=3" << endl;
	cout << p1.valorePol(3) << endl;
	cout << "Confronto fra due polinomi" << endl;
	p1.stampa();
	p2.stampa();
	if (p1 == p2)
	{
		cout << " i due polinomi sono uguali" << endl;
	}
	else
	{
		cout << "i due polinomi sono diversi" << endl;
	}
	cout << "Prodotto fra i due polinomi" << endl;
	Polinomio p3;
	p3 = p1 * p2;
	p3.stampa();
	return 0;
}

