//
//  main.cpp
//  Rubrica
//
//  Created by Andrea on 15/12/15.
//  Copyright © 2015 Andrea. All rights reserved.
//
//
//Compilatore utilizzato: Visual C++
//Elenco telefonico


#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>

using namespace std;

//Definizione struttura
struct ElencoTelefonico
{
    char Nome[20];
    char Cognome[20];
    char Numero[12];
    ElencoTelefonico *NextPtr;
    ElencoTelefonico *prevPtr;
};

//Variabili globali
ElencoTelefonico *Inizio;
ElencoTelefonico *Fine;
int contatore=0;

//Header di funzioni
int StampaMenu();
void Inizializza();
void InserisciNominativo();
ElencoTelefonico *CercaNominativo(bool cerca);
bool EliminaNodo(bool cerca);
void CalcolaMediana();
bool StampaRisultatoCrescente();
bool StampaRisultatoDecrescente();
void Distruggi();
bool ControllaSeEguale(char *nome1, char *nome2, int Lung);
bool ControllaSeMaggiore(char *nomeInput, char *nome, int Lung);
bool ApriDaFile();
bool SalvaSuFile();

//programma principale
int main()
{
    int scelta;
    
    //Inizializzo il puntatore
    Inizializza();
    while (scelta!=8)
    {
        //Stampo il menu
        scelta=StampaMenu();
        switch (scelta)
        {
            case 1:	ApriDaFile();
                break;
            case 2: SalvaSuFile();
                break;
            case 3: InserisciNominativo();
                break;
            case 4: EliminaNodo(false);
                break;
            case 5: StampaRisultatoCrescente();
                break;
            case 6: StampaRisultatoDecrescente();
                break;
            case 7: CercaNominativo(true);
                break;
        }//fine switch
    }//fine while
    //Distruggo il puntatore
    Distruggi();
    return 0;
}


//Funzione per la stampa di un menu
int StampaMenu()
{
    char Scelta[20];
    bool continua;
    
    continua=true;
    
    while (continua)
    {
        cout << endl;
        cout << "------------- ELENCO TELEFONICO ------------" << endl << endl;
        cout << "1 - Apri elenco da file" << endl;
        cout << "2 - Salva elenco su file" << endl;
        cout << "3 - Inserisci nominativo" << endl;
        cout << "4 - Elimina nominativo" << endl;
        cout << "5 - Visualizza elenco dal primo nominativo" << endl;
        cout << "6 - Visualizza elenco dall'ultimo nominativo" << endl;
        cout << "7 - Cerca nominativo" << endl;
        cout << "8 - Esci" << endl << endl;
        cout << "Scegli un comando inserendo il numero corrispondente" << endl << endl;
        cin >> Scelta;
        if (strlen(Scelta)>1)
        {
            cin.clear();
            cout << endl << "Comando errato" << endl;
            continue;
        }
        //Controllo l'input
        switch (*Scelta)
        {
            case '1': return 1;
                break;
            case '2': return 2;
                break;
            case '3': return 3;
                break;
            case '4': return 4;
                break;
            case '5': return 5;
                break;
            case '6': return 6;
                break;
            case '7': return 7;
                break;
            case '8': return 8;
                break;
            default:
                cout << endl << "Comando errato" << endl;
                break;
        }
    }
    return 0;
}


//IMPLEMENTAZIONE DI FUNZIONI
//Inizializza il puntatore
void Inizializza()
{
    Inizio=new ElencoTelefonico;
    Inizio=Fine=NULL;
}

//Funzione per inserire un nodo
void InserisciNominativo()
{
    //variabili locali
    ElencoTelefonico *nuovo_numero, *temp;
    bool PrimoONelMezzo=false;
    int LunghezzaMin;
    
    //Inizializzo il nuovo nodo
    nuovo_numero=new ElencoTelefonico;
    nuovo_numero->NextPtr=NULL;
    nuovo_numero->prevPtr=NULL;
    //richiesta input
    cout << "Inserisci il nome, dopo l'inserimento premi Invio";
    cout << endl;
    cin >> nuovo_numero->Nome;
    cout << endl;
    cout << "Inserisci il cognome, dopo l'inserimento premi Invio";
    cout << endl;
    cin >> nuovo_numero->Cognome;
    cout << endl;
    cout << "Inserisci il numero di telefono : " << endl;
    cin >> nuovo_numero->Numero;
    //Caso 1 - Non ci sono elementi nella lista
    if (Inizio==NULL)
    {
        Inizio=Fine=nuovo_numero;
        
    }
    //Caso 2 - C'Ë un solo elemento nella lista
    else if ((Inizio!=NULL) && (Inizio->NextPtr==NULL))
    {
        //Controllo se l'elemento nuovo Ë pi˘ grande
        //Prima trovo la lunghezza min tra il dato memorizzato e quello in ingresso
        LunghezzaMin=strlen(nuovo_numero->Cognome);
        if (LunghezzaMin > strlen(Inizio->Cognome))
            LunghezzaMin=strlen(Inizio->Cognome);
        
        if (!ControllaSeMaggiore(nuovo_numero->Cognome, Inizio->Cognome, LunghezzaMin))
        {
            nuovo_numero->NextPtr=Inizio;
            Inizio->prevPtr=nuovo_numero;
            Inizio=nuovo_numero;
        }
        else
        {
            Inizio->NextPtr=nuovo_numero;
            nuovo_numero->prevPtr=Inizio;
        }
    }
    //Caso 3 - Ci sono due o pi˘ elementi nella lista
    else if (Inizio->NextPtr!=NULL)
    {
        //Pongo all'inizio il puntatore
        Fine=Inizio;
        //Lo muovo fino al primo elemento utile
        while (Fine->NextPtr!=NULL)
        {
            //Controllo se l'elemento va inserito nel mezzo
            //In caso negativo stiamo sull'ultimo elemento
            LunghezzaMin=strlen(nuovo_numero->Cognome);
            if (LunghezzaMin > strlen(Fine->Cognome))
                LunghezzaMin=strlen(Fine->Cognome);
            if (ControllaSeMaggiore(nuovo_numero->Cognome, Fine->Cognome, LunghezzaMin))
                Fine=Fine->NextPtr;
            else
            {
                //caso accodamento nel mezzo (potrebbe essere il primo o nel mezzo)
                PrimoONelMezzo=true;
                break;
            }
        }
        //l'elemento Ë primo o nel mezzo (escludo l'ultimo)
        if (PrimoONelMezzo)
        {
            //Siamo nel mezzo
            if (Fine->prevPtr!=NULL)
            {
                temp=Fine->prevPtr;
                Fine->prevPtr->NextPtr=nuovo_numero;
                nuovo_numero->NextPtr=Fine;
                nuovo_numero->prevPtr=temp;
                Fine->prevPtr=nuovo_numero;
            }
            else
            {
                //stiamo sul primo elemento
                Fine->prevPtr=nuovo_numero;
                nuovo_numero->NextPtr=Fine;
                Inizio=nuovo_numero;
            }
        }
        //l'elemento Ë l'ultimo (potrebbe essere penultimo o ultimo)
        else
        {
            //Devo distinguere deu casi
            //1 - va messo come penultimo
            LunghezzaMin=strlen(nuovo_numero->Cognome);
            if (LunghezzaMin > strlen(Fine->Cognome))
                LunghezzaMin=strlen(Fine->Cognome);
            if (!ControllaSeMaggiore(nuovo_numero->Cognome, Fine->Cognome, LunghezzaMin))
            {
                temp=Fine->prevPtr;
                Fine->prevPtr->NextPtr=nuovo_numero;
                nuovo_numero->NextPtr=Fine;
                nuovo_numero->prevPtr=temp;
                Fine->prevPtr=nuovo_numero;
            }
            else
                //2 - va messo come ultimo
            {
                Fine->NextPtr=nuovo_numero;
                nuovo_numero->prevPtr=Fine;
            }
        }
        
    }
    
}

//Stampa risultato in ordine crescente
bool StampaRisultatoCrescente()
{
    if (!Inizio)
    {
        cout << endl << "Non vi sono elementi nella lista" << endl;
        return false;
    }
    Fine=Inizio;
    cout << endl << "Elementi nell'elenco telefonico dal primo" << endl;
    cout << endl;
    cout.setf(ios::left);
    cout <<setw(20) << "COGNOME" << setw(20) << "NOME" << setw(12)
    << "N. TELEFONO";
    cout << endl;
    while (Fine!=NULL)
    {
        cout << setw(20) << Fine->Cognome << setw(20) << Fine->Nome
        << setw(12) << Fine->Numero << endl;
        Fine=Fine->NextPtr;
    }
    Fine=Inizio;
    return true;
}
//Stampa risultato in ordine decrescente
bool StampaRisultatoDecrescente()
{
    if (!Inizio)
    {
        cout << endl << "Non vi sono elementi nella lista" << endl;
        return false;
    }
    Fine=Inizio;
    cout << endl << "Elementi nella lista dall'ultimo" << endl;
    cout << endl;
    cout.setf(ios::left);
    cout <<setw(20) << "COGNOME" << setw(20) << "NOME" << setw(12)
    << "N. TELEFONO";
    cout << endl;
    //Porto il puntatore sull'ultimo elemento
    while (Fine->NextPtr!=NULL)
    {
        Fine=Fine->NextPtr;
    }
    while (Fine)
    {
        cout <<setw(20) << Fine->Cognome << setw(20) << Fine->Nome
        << setw(12) << Fine->Numero << endl;
        Fine=Fine->prevPtr;
    }
    return true;
}

//elimina nodo
bool EliminaNodo(bool cerca)
{
    //variabili locali
    ElencoTelefonico *curr_ptr;
    
    if (!Inizio)
    {
        cout << endl << "Non vi sono nominativi nella lista" << endl;
        return false;
    }
    //ricerca dell'elemento da eliminare e ritorna il puntatore cercato
    curr_ptr=CercaNominativo(cerca);
    if (curr_ptr!=NULL)
    {
        //Devo distinguere i casi che si possono presentare
        //1 caso - Vi Ë un solo nominativo nell'elenco
        if ((curr_ptr==Inizio) && (curr_ptr->NextPtr==NULL))
        {
            cout << endl << "Ho cancellato: " << curr_ptr->Cognome << endl;
            cout << "L'elenco e' vuoto" << endl;
            Inizio=NULL;
            return true;
        }
        //2 caso - E' il primo elemento dell'elenco
        if (curr_ptr==Inizio)
        {
            Inizio=Inizio->NextPtr;
            return true;
        }
        //3 caso - Il nominativo da eliminare Ë l'ultimo dell'elenco e vi sono solo due nominativi
        if ((curr_ptr->prevPtr==Inizio) && (curr_ptr->NextPtr==NULL))
        {
            cout << endl << "Ho cancellato: " << curr_ptr->Cognome << endl;
            Inizio->NextPtr=NULL;
            return true;
        }
        //4 caso - L'elemento da eliminare sta nel mezzo tra il primo Ë l'ultimo
        if ((curr_ptr!=Inizio) && (curr_ptr->NextPtr!=NULL))
        {
            cout << endl << "Ho cancellato: " << curr_ptr->Cognome << endl;
            
            curr_ptr->prevPtr->NextPtr=curr_ptr->NextPtr;
            curr_ptr->NextPtr->prevPtr=curr_ptr->prevPtr;
            curr_ptr=NULL;
            return true;
        }
        //5 caso - L'elemento da cancellare Ë l'ultimo e vi sono pi˘ di due elementi
        if (curr_ptr->NextPtr==NULL)
        {
            cout << endl << "Ho cancellato: " << curr_ptr->Cognome << endl;
            curr_ptr=curr_ptr->prevPtr;
            curr_ptr->NextPtr=NULL;
        }
        
    }
    return false;
}
//Funzione per la ricerca del nominativo
ElencoTelefonico *CercaNominativo(bool cerca)
{
    //variabili locali
    char cognome[30];
    int Lunghezza;
    //puntatori locali
    ElencoTelefonico *curr_ptr;
    
    //ricerca dell'elemento
    if (cerca)
    {
        cout << endl << "Inserisci il cognome da cercare: " << endl;
    }
    else
    {
        cout << endl << "Inserisci il cognome da eliminare: " << endl;
    }
    cin >> cognome;
    curr_ptr=Inizio;
    
    while (curr_ptr)
    {
        Lunghezza=strlen(curr_ptr->Cognome);
        if (ControllaSeEguale(curr_ptr->Cognome, cognome, Lunghezza))
            break;
        curr_ptr=curr_ptr->NextPtr;
    }
    if (curr_ptr) //ho trovato l'elemento cercato
    {
        if (cerca)
        {
            cout << endl << "La persona cercata e' :" << endl;
            cout <<setw(20) << "COGNOME" << setw(20) << "NOME" << setw(12)
            << "N. TELEFONO";
            cout << endl;
            cout <<setw(20) << curr_ptr->Cognome << setw(20) << curr_ptr->Nome
            << setw(12) << curr_ptr->Numero << endl;
            
        }
        else
            cout << endl << "Il cognome da eliminare e' :" << curr_ptr->Cognome << endl;
        return curr_ptr;
    }
    else
    {
        if (cerca)
            cout << endl << "Il cognome cercato non esiste" << endl;
        else
            cout << endl << "Il cognome da elimare non esiste" << endl;
        return NULL;
    }
}//Chiuso CercaElemento
bool ControllaSeEguale(char *nome1, char *nome2, int Lung)
{
    bool Risultato;
    
    for (int i=0; i < Lung; i++)
    {
        if (nome1[i]!=nome2[i])
        {
            Risultato=false;
            break;
        }
        else
            //La prima parte delle due stringhe Ë eguale
        {
            //stiamo sull'ultimo carattere
            if ((i==(Lung-1)) && (strlen(nome1)==strlen(nome2)))
                Risultato=true;
            else
                Risultato=false;
            
        }
    }//chisuo for
    if (Risultato)
        return true;
    else
        return false;
}
//Funzione che controlla l'ordine alfabetico dei nominativi
bool ControllaSeMaggiore(char *nomeInput, char *nome, int LungMin)
{
    bool risultato;
    int LunghezzaInput;
    
    //Trasformo i caratteri in un formato omogeneo
    LunghezzaInput=strlen(nomeInput);
    for (int x=0; x < LunghezzaInput; x++)
    {
        //Il primo carattere sempre in maiuscolo
        if (x==0)
        {
            if ((nomeInput[x] >= 97) && (nomeInput[x]<=122))
                nomeInput[x]=nomeInput[x]-32;
        }
        else
            //Dal secondo in poi sempre minuscolo
        {
            if ((nomeInput[x] >= 65) && (nomeInput[x]<=90))
                nomeInput[x]=nomeInput[x]+32;
        }
    }
    for(int i=0; i < LungMin ; i++)
    {
        
        if (nomeInput[i] > nome[i])
        {
            risultato=true;
            break;
        }
        
        else if(nomeInput[i] < nome[i])
        {
            risultato=false;
            break;
        }
        else
        {
            //Siamo arrivati alla fine, in questo caso la maggiore Ë la pi˘ lunga
            if ((i==LungMin-1) && (strlen(nomeInput) > strlen(nome)))
                risultato=true;
            else
                risultato=false;
            continue;
        }
    }
    if (risultato)
        return true;
    else
        return false;
}
//Funzione per salvare su file l'elenco
bool SalvaSuFile()
{
    ofstream out("ELENCO.TXT");
    
    if (!out)
    {
        cout << "Inpossibile creare il file" << endl;
        return false;
    }
    if (!Inizio)
    {
        cout << "Non vi sono nominativi nell'elenco" << endl;
        return false;
    }
    //scrittura su file
    Fine=Inizio;
    while (Fine)
    {
        if (Fine->NextPtr!=NULL)
            out << Fine->Cognome << "," << Fine->Nome << "," << Fine->Numero << '\n';
        else
            out << Fine->Cognome << "," << Fine->Nome << "," << Fine->Numero;
        Fine=Fine->NextPtr;
        
    }
    out.close();
    cout << "L'elenco e' stato salvato nel file ELENCO.TXT" << endl;
    return true;
}
//Funzione per aprire da file
bool ApriDaFile()
{
    ElencoTelefonico *nuovo_numero;
    int index=0;
    
    ifstream in("ELENCO.TXT");
    
    if (!in)
    {
        cout << "Inpossibile aprire il file" << endl;
        return false;
    }
    //Leggo i dati
    Inizio=new ElencoTelefonico;
    
    while (!in.eof())
    {
        if (index==0)
            
        {
            in.getline(Inizio->Cognome, 30, ',');;
            in.getline(Inizio->Nome,30,',');
            in.getline(Inizio->Numero,12);
            Inizio->NextPtr=NULL;
            Inizio->prevPtr=NULL;
            Fine=Inizio;
            
        }
        else
        {
            //Inizializzo il nuovo nodo
            nuovo_numero=new ElencoTelefonico;
            Fine->NextPtr=nuovo_numero;
            nuovo_numero->prevPtr=Fine;
            nuovo_numero->NextPtr=NULL;
            Fine=Fine->NextPtr;
            
            in.getline(Fine->Cognome, 30, ',');;
            in.getline(Fine->Nome,30,',');
            in.getline(Fine->Numero,12);
        }
        index++;
        
    }
    Fine=Inizio;
    in.close();
    cout << "Ho aperto ELENCO.TXT" << endl;
    StampaRisultatoCrescente();
    return true;	
}
//Distruzione
void Distruggi()
{
    if (Inizio)
    {
        delete [] Inizio;
        Inizio=NULL;
    }
}

