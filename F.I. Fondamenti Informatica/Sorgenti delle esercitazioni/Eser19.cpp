//ESERCIZIO 2
#include <iostream>
using namespace std;

struct Tree {
	int info;
	Tree *rightptr;
	Tree *leftptr;
};

void Cammini(Tree *&radice, int &Camminoest, int &Camminoint, int Curr=-1)
{
	//static int Curr=-1;     //il primo puntatore non va contato

	if (radice!=0)
	{
		Curr++;

		if ( ((radice->leftptr) == 0 ) && ((radice->rightptr) == 0) )
		{
			Camminoest+=Curr;
		}
		if /*(
		( ((radice->leftptr) != 0 ) && ((radice->rightptr) != 0) ) ||
		( ((radice->leftptr) != 0 ) && ((radice->rightptr) == 0) ) ||
		( ((radice->leftptr) == 0 ) && ((radice->rightptr) != 0) )     )
		*/
		(((radice->leftptr) != 0 ) || ((radice->rightptr) != 0) )
		{
			Camminoint+=Curr;
		}
		Cammini(radice->leftptr, Camminoest, Camminoint, Curr);
		Cammini(radice->rightptr, Camminoest, Camminoint, Curr);
		// Curr--;
	}
}

void main()
{
	Tree *albero;
	Tree *tmp,*tmp1,*tmp2,*tmp3,*tmp4,*tmp5,*tmp6;
	int In=0, Out=0;
	
	cout << "Inizio ad inserire una struttura ad albero" << endl;
	albero = new Tree;
	albero->info = 0;
	albero->leftptr = new Tree;
	tmp = albero->leftptr;
	tmp->info = 1;
	albero->rightptr=new Tree;
	tmp1 = albero->rightptr;
	tmp1->info = 1;
	tmp->leftptr = new Tree;
	tmp2 = tmp->leftptr;
	tmp2->info = 2;
	tmp2->leftptr = 0;
	tmp2->rightptr = new Tree;
	tmp3 = tmp2->rightptr;
	tmp3->info = 3;
	tmp3->rightptr = 0;
	tmp3->leftptr = 0;
	tmp->rightptr = new Tree;
	tmp4 = tmp->rightptr;
	tmp4->info = 2;
	tmp4->leftptr = 0;
	tmp4->rightptr = 0;
	tmp1->leftptr = 0;
	tmp1->rightptr = new Tree;
	tmp5 = tmp1->rightptr;
	tmp5->leftptr = 0;
	tmp5->rightptr = new Tree;
	tmp5->info = 2;
	tmp6 = tmp5->rightptr;
	tmp6->leftptr = 0;
	tmp6->rightptr = 0;
	tmp6->info = 3;
	Cammini(albero, Out, In);
	cout << "Cammino esterno " << Out << endl;
	cout << "cammino interno " << In << endl;
}

