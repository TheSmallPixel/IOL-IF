// Definizione della classe Complex

#include <iostream>
using namespace std;

// definizione delle costanti
const float PI = 3.141592;
const float RAD = PI/180;

enum Boolean {FALSO=0, VERO=1};


// Classe Complex
class Complex
{
	float reale,compl;         // formato algebrico
	float arg; float modulo;   // formato polare

	float calcArg    (float a,float b);
	float calcModulo (float a,float b);
	float calcReale  (float a,float b);
	float calcCompl  (float a,float b);

public:
	Complex(float a,float b);  // costruttore ALGEBRICO
	Complex(float a,int b);    // costruttore POLARE
	void algPrint();
	void polPrint();
	Complex operator*(const Complex altroNum);
	Complex operator+(const Complex altroNum);
	Complex operator=(const Complex altroNum);
	Boolean operator==(const Complex altroNum);
};


Complex::Complex(float a,float b) // costruttore ALGEBRICO 
{
	reale=a; compl=b;
	modulo=calcModulo(reale,compl);
	arg=calcArg(reale,compl);
}


Complex::Complex(float a,int b) // costruttore POLARE 
{
	modulo=a;
	arg=(float)b*RAD;
	reale=calcReale(modulo,arg);
	compl=calcCompl(modulo,arg);
}


/* funzioni di calcolo dei vari componenti di un numero 
complesso INIZIO */

float Complex::calcArg(float a,float b)
{
	float f;

	if (a!=0)
	{
		if (b==0)
		{
			if (a>=0)
				f=0;
			else
				f=PI;
		}
		else
		{
			f=atan(b/a);
			if (b<0 && a<0) //se il punto e' nel 3 quadrante
				f+=PI;
			if (b<0 && a>0) //se il punto e' nel 4 quadrante
				f+=PI;
		}
	}
	else //a=0
	{
		if (b>=0)
			f=PI/2;
		else
			f=-PI/2;
	}
	return f;
}


float Complex::calcModulo(float a,float b)
{
	return sqrt(a*a+b*b);
}

float Complex::calcReale(float a,float b)
{
	return (a*cos(b));
}

float Complex::calcCompl(float a,float b)
{
	return (a*sin(b));
}

/* funzioni di calcolo dei vari componenti di un numero 
complesso FINE */

// funzioni di stampa INIZIO

void Complex::algPrint()
{
	cout << "il numero in forma algebrica e': (" << reale 
		<< ") + (" << compl << ")*i" << endl;
}

void Complex::polPrint()
{
	cout << "il numero in forma polare ha modulo " << modulo 
		<< " e argomento " << arg << endl;
}

// funzioni di stampa FINE


// overloading operatori INIZIO

Complex Complex::operator*(const Complex altroNum)
{
	Complex k(0.0,(int)0);
	k.modulo=modulo*altroNum.modulo;
	k.arg=arg+altroNum.arg;
	k.reale=calcReale(k.modulo,k.arg);
	k.compl=calcCompl(k.modulo,k.arg);
	return k;
}

Complex Complex::operator+(const Complex altroNum)
{
	Complex k(0.0,(float)0.0);
	k.reale=reale+altroNum.reale;
	k.compl=compl+altroNum.compl;
	k.modulo=calcModulo(k.reale,k.compl);
	k.arg=calcArg(k.reale,k.compl);
	return k;
}

Complex Complex::operator=(const Complex altroNum)
{
	reale = altroNum.reale;
	compl = altroNum.compl;
	modulo= altroNum.modulo;
	arg   = altroNum.arg;
	return *this;
}

Boolean Complex::operator==(const Complex altroNum)
{
	return Boolean(reale==altroNum.reale &&
				compl==altroNum.compl);
}

// overloading operatori FINE

// fine della dichiarazione della classe Complex


// main per provare ad utilizzare la classe ed i suoi servizi
int main()
{

	// prove con il costruttore ALGEBRICO
	Complex a(1.0,(float)1.0);
	Complex b(2.0,(float)0.0);
	Complex c=b;

	cout << "numeri creati con il costruttore algebrico\n";

	cout << "numero a" << endl;
	a.algPrint();
	a.polPrint();
	cout << "numero b" << endl;
	b.algPrint();
	b.polPrint();
	cout << "numero c" << endl;
	c.algPrint();
	c.polPrint();

	cout << "a=b " << (a==b) << endl;
	cout << "c=b " << (c==b) << endl;
	cout << "numero c=a+b" << endl;
	c=a+b;
	c.algPrint();
	c.polPrint();
	cout << "numero c=a*b" << endl;
	c=a*b;
	c.algPrint(); c.polPrint();

	cout << endl << "premere Invio per continuare" << endl;
	cin.get();

	// prove con il costruttore POLARE
	Complex a1(1.0,150);
	Complex b1(2.0,30);
	Complex c1=b1;

	cout << "numeri creati con il costruttore polare" << endl;

	cout << "numero a" << endl;
	a1.algPrint();
	a1.polPrint();
	cout << "numero b" << endl;
	b1.algPrint();
	b1.polPrint();
	cout << "numero c" << endl;
	c1.algPrint();
	c1.polPrint();

	cout << "a=b " << (a1==b1) << endl;
	cout << "c=b " << (c1==b1) << endl;
	cout << "numero c=a+b" << endl;
	c1=a1+b1;
	c1.algPrint(); c1.polPrint();
	cout << "numero c=a*b" << endl;
	c1=a1*b1;
	c1.algPrint(); c1.polPrint();

	return 0;
}
