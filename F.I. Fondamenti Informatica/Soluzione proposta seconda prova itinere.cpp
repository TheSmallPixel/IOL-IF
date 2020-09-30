//29 novembre – 2 dicembre 2019 Seconda prova in itinere
/*Il Banco Alimentare vuole realizzare un software per la gestione dei prodotti donati,
che arrivano a magazzino e vengono poi distribuiti alle persone in difficoltà.
L’archivio sarà organizzato come lista di tipologia di prodotti (riso, pasta, olio,
ecc., ognuno con la rispettiva unità di misura) e ad ogni prodotto saranno associati 
tutti i lotti presenti a magazzino, caratterizzati dal quantitativo e dalla data di 
scadenza. I lotti di un determinato prodotto dovranno essere ordinati in base alla data
di scadenza.
Si chiede di implementare la funzione inserisciLottoProdotto che registri l’arrivo di
un lotto di un certo tipo di prodotto in magazzino, inserendolo nella corrispondente
lista che, come detto, sarà ordinata in funzione della data di scadenza. Se la tipologia
di prodotto non dovesse essere tra quelle già presenti in archivio, dovrà essere
aggiunta e ad essa dovrà essere collegato il lotto in ingresso.
Si implementi anche una funzione prelievoProdotto che registri l’uscita di un certo
quantitativo di un determinato prodotto; nello specifico dovranno essere prelevati i
lotti con la data di scadenza più ravvicinata, eliminando dall’archivio i lotti
completamente esauriti ed aggiornando i quantitativi di quelli che ancora non lo sono.
Infine si realizzino anche la funzione statoMagazzino, che stampa la lista, ed un
breve main per testare le varie funzione prodotte.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

	struct data{
		int giorno;
		int mese;
		int anno;
	};

	struct lotto{
		int qta;
		data scadenza;
		lotto *nextL;
	};

	struct prodotto{
		string nome;
		string unitaM;
		prodotto *nextP;
		lotto *nextL;
	};
	

//Funzione richiesta per inserire un nuovo lotto di prodotti nel magazzino
void inserisciLottoProdotto(prodotto * &lista, string nProdotto, string uMisura, int qta, data scadenza);
//Funzione richiesta per prelevare un quantitativo di un determinato prodotto
void prelievoProdotto(prodotto * &lista, string nProdotto,int qta);

//Restituisce il puntatore al prodotto se questo esiste altrimenti NULL
prodotto *cercaProdotto(prodotto *lista, string nProd);

//Inserisce un prodotto collegandolo all'elemento puntato da prec
void inserisciProdotto(prodotto *prec, string nProdotto, string uMisura);

//Riceve il link al prodotto e restituisce il link dell'elemento a cui collegare il 
//lotto *cercaPosLotto();

//Riceve il link al prodotto, ricerca se esiete un lotto con la medesima data
//di scadenza ed in caso aggiorna le quantita', altrimenti inserisce il nuovo lotto
void inserisciLotto(prodotto *prod,data scadenza, int qta);

//Confronta due date e restituisce rispettivamente +1, 0, -1 a seconda  
//che la prima sia maggiore, uguale o minore alla seconda
int confrontaData(data d1, data d2);

//Stampa l'intero contenuto del magazzino
void statoMagazzino(prodotto *);
void stampaData(data scadenza);


int main()
{	
	prodotto *prodotti=NULL;
	string nomeProdotto;
	string unitaM;
	int quantita;
	data scadenza;

	/*
	cout<<"Inserire i dati relativi al nuovo lotto arrivato\n";
	cout<<"Tipo Prodotto: ";
	cin>>nomeProdotto;
	cout<<"Unita di musura: "; cin>>unitaM;
	cout<<"Quantita': "; cin>>quantita;
	cout<<"Data di scadenza (gg mm aa): ";
		cin>>scadenza.giorno>>scadenza.mese>>scadenza.anno;
		//cin>>scadenza.mese;
		//cin>>scadenza.anno;
		*/
	nomeProdotto="Pasta";
	unitaM="Kg";
	quantita=12;
	scadenza.giorno=4;
	scadenza.mese=7;
	scadenza.anno=23;
	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Pasta";
	unitaM="Kg";
	quantita=12;
	scadenza.giorno=12;
	scadenza.mese=10;
	scadenza.anno=19;
	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Pasta";
	unitaM="Kg";
	quantita=8;
	scadenza.giorno=12;
	scadenza.mese=10;
	scadenza.anno=19;
	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Pasta";
	unitaM="Kg";
	quantita=7;
	scadenza.giorno=13;
	scadenza.mese=12;
	scadenza.anno=19;

	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Pasta";
	unitaM="Kg";
	quantita=7;
	scadenza.giorno=10;
	scadenza.mese=10;
	scadenza.anno=19;

	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Riso";
	unitaM="Kg";
	quantita=7;
	scadenza.giorno=13;
	scadenza.mese=12;
	scadenza.anno=17;

	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Riso";
	unitaM="Kg";
	quantita=15;
	scadenza.giorno=13;
	scadenza.mese=10;
	scadenza.anno=19;

	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Pasta";
	unitaM="Kg";
	quantita=7;
	scadenza.giorno=13;
	scadenza.mese=12;
	scadenza.anno=25;

	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;

	nomeProdotto="Olio";
	unitaM="l";
	quantita=7;
	scadenza.giorno=6;
	scadenza.mese=7;
	scadenza.anno=22;

	inserisciLottoProdotto(prodotti, nomeProdotto, unitaM, quantita, scadenza);
	cout<<"------ Inserito "<<nomeProdotto<<" "<<quantita<<" "<<unitaM<<
		" scadenza "<<scadenza.giorno<<"\\"<<scadenza.mese<<"\\"<<scadenza.anno<<endl;
	
	statoMagazzino(prodotti);

	cout<<"\n****** Prelievo 12Kg Biscotti"<<endl;
	prelievoProdotto(prodotti, "Biscotti", 12);

	cout<<"\n****** Prelievo 9l Olio"<<endl;
	prelievoProdotto(prodotti, "Olio", 9);
	//statoMagazzino(prodotti);

	cout<<"\n****** Prelievo 9Kg Riso"<<endl;
	prelievoProdotto(prodotti, "Riso",9);
	//statoMagazzino(prodotti);

	cout<<"\n****** Prelievo 2l Olio"<<endl;
	prelievoProdotto(prodotti, "Olio", 2);
	//statoMagazzino(prodotti);

	cout<<"\n****** Prelievo 32Kg Pasta"<<endl;
	prelievoProdotto(prodotti, "Pasta", 32);
	statoMagazzino(prodotti);

	return 0;
}

void inserisciLottoProdotto(prodotto * &lista, string nProdotto, string uMisura, int qta, data scadenza)
{
	prodotto *tempP;
	//lotto *tempL;

	tempP=cercaProdotto(lista, nProdotto);
	if(!tempP){ //Se non e' stato trovato il prodotto
	//iserisce prodotto in testa alla lista per poi inserire il lotto
		tempP=new prodotto;
		tempP->nome=nProdotto;
		tempP->unitaM=uMisura;
		tempP->nextL=NULL;

		tempP->nextP=lista;
		lista=tempP;
	}

	inserisciLotto(tempP, scadenza, qta);

	return;
}

void stampaData(data scadenza)
{
	cout<<scadenza.giorno<<"/"<<scadenza.mese<<"/"<<scadenza.anno<<endl;
	return;
}

void statoMagazzino(prodotto *lista)
{
	prodotto *tempP=lista;
	lotto *tempL;
	cout<<setw(10)<<"\n*** CONTENUTO DEL MAGAZZINO ***"<<endl;
	if(!lista)
		cout<<setw(10)<<"\nIL MAGAZZINO E' VUOTO"<<endl;
	else
	while(tempP!=NULL){
		if(tempP->nextL!=NULL){ //Se ci sono lotti del prodotto ...
			cout<<tempP->nome<<endl; //Stampa il nome del prodotto
			tempL=tempP->nextL;
			while(tempL!=NULL){
				cout<<setw(5)<<tempL->qta<<tempP->unitaM<<"  Scadenza: ";
				stampaData(tempL->scadenza);
				//cout<<endl;

				tempL=tempL->nextL;
			}
		}
		//Finita la stampa dei lotti o se non ci sono lotti del prodotto ...
		//si passa al prodotto successivo
		tempP=tempP->nextP;
		cout<<endl;
	}
	return;
}

prodotto *cercaProdotto(prodotto *lista, string nProd)
{
	prodotto *tempP=lista;
	if(!lista) //se la lisgta e' vuota
		return lista;
	while(tempP->nome!=nProd && tempP!=NULL){
		tempP=tempP->nextP;
		if(tempP==NULL)
			return tempP;
	}
	return tempP;
}

int confrontaData(data d1, data d2)
{
	if(d1.anno > d2.anno)
		return 1;
	else
		if(d1.anno<d2.anno)
			return -1;
		else
			if(d1.mese>d2.mese)
				return 1;
			else
				if(d1.mese<d2.mese)
					return -1;
				else
					if(d1.giorno>d2.giorno)
						return 1;
					else
						if(d1.giorno<d2.giorno)
							return -1;
						else
							return 0;
}

void inserisciLotto(prodotto *prod, data scadenza, int qta)
{
	lotto *tempL=prod->nextL, *precL=NULL;
	lotto *tempN; //Puntatore al nuovo lotto (New)
	int confrontoD; //Confronto Data

	if(tempL==NULL){ //Se non ci sono lotti collegati a prodotto
		tempL=new lotto;
		tempL->qta=qta;
		tempL->scadenza=scadenza;
		tempL->nextL=NULL;

		prod->nextL=tempL; //Collega prodotto a lotto
	}
	else{
		confrontoD=confrontaData(tempL->scadenza, scadenza);

		while(tempL!=NULL && confrontoD!=1){
			if(confrontoD==0){ //Se esiste un lotto con stessa scadenza si aggiorna quantita'
				tempL->qta+=qta;
				return;
			}
			else{
				precL=tempL;
				tempL=tempL->nextL;
			}
			if(tempL!=NULL){
				confrontoD=confrontaData(tempL->scadenza, scadenza);
			}
		}
		tempN=new lotto;
		tempN->qta=qta;
		tempN->scadenza=scadenza;
		if(precL==NULL){ //Il punto di inserimento e' il primo della lista
			tempN->nextL=prod->nextL;
			prod->nextL=tempN;
		}
		else{
			tempN->nextL=precL->nextL;
			precL->nextL=tempN;
		}
	}

	return;
}

void prelievoProdotto(prodotto * &lista, string nProdotto,int qta)
{
	prodotto *tempP;
	lotto *tempL;
	int tempQta=qta; //per tener traccia della quantita' richiesta

	tempP=cercaProdotto(lista, nProdotto);
	if(tempP==NULL || tempP->nextL==NULL) //Non esiste il prodotto o non ci sono lotti
		cout<<"IL PRODOTTO "<<nProdotto<<" NON ESISTE A MAGAZZINO"<<endl;
	else{
		tempL=tempP->nextL;
		while(tempQta>0 && tempL!=NULL){
			if(tempQta<=tempL->qta){ //Si aggiornano solo i quantitativi
				tempL->qta-=tempQta;
				tempQta=0;  //Si azzera qta per indicare il prelievo completo
				if(tempL->qta==0){
					tempP->nextL=tempL->nextL;
					delete tempL;
				}		
			}
			else{ //Il quantitativo da prelevare e' > a quello del lotto considerato
				tempQta-=tempL->qta; //Si svuota il lotto considerato
				tempP->nextL=tempL->nextL;//Si elimina il lotto svuotato
				delete tempL;
				tempL=tempP->nextL;
			} 
		}
		if(tempQta>0)
			cout<<"MANCANO "<<tempQta<<tempP->unitaM<<" di "<<tempP->nome<<" A MAGAZZINO PER COMPLETARE LA RICHIESTA"<<endl;
		cout<<"SONO STATI PRELEVATI "<<qta-tempQta<<tempP->unitaM<<" di "<<tempP->nome<<endl;
	}
	return;
}
