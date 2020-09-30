/*Si scriva un programma che consenta di gestire l’insieme dei nickname di un 
sistema di messaggistica istantanea.
Ogni nickname è caratterizzato da: 
Nome in codice 
Nominativo reale 
Indirizzo di posta elettronica 
Il programma deve gestire i nickname utilizzando una struttura dati a lista. 
Gli elementi della lista non devono essere ordinati.

Deve essere previsto un menù che consentirà di aggiungere  i dati di un nuovo 
nickname, cancellare i dati di tutti i nickname, cancellare un particolare nickname, 
stampare tutti i dati di un nickname , stampare tutti i dati di tutti i nickname.

Il programma deve essere scritto utilizzando intelligentemente le funzioni.*/

#include <iostream>
#include <string.h>

using namespace std;

struct NICK {
    char nickname[20];
    char nome [20];
    char email [20];
    struct NICK *next;
};
struct NICK *head=NULL;
char nick[20];

/*funzione per inserire in testa*/

void instesta (){
    struct NICK *p;
    p=new struct NICK;
    cout<<"Inserire il nuovo nickname"<<endl;
    cin>>p->nickname;
    cout<<"Inserire il nominativo"<<endl;
    cin.ignore();
    cin.getline( p->nome,20);
    cout<<"Inserire l'indirizzo internet"<<endl;
    cin>>p->email;
    p->next=head;
    head=p;
}

/*funzione per cancellare un elemento dato il nick*/

void cancelemento (){
    struct NICK *p;
    struct NICK *prec;
    if(head==NULL)cout<<"Lista vuota"<<endl;
    else if(strcmp(head->nickname,nick)==0){
        p=head;
        head=p->next;
        delete p;
    }else{
        prec=head;
        p=head->next;
        while(p!=NULL){
            if(strcmp(p->nickname,nick)==0){
                prec->next=p->next;
                delete p;
                cout<<"Elemento cancellato"<<endl;
            }
            p=p->next;
            prec=prec->next;
        }
    }
}

/*funzione per cancellare tutta la lista*/

void canclista (){
    struct NICK *p;
    struct NICK *prec;
    if(head==NULL)cout<<"Lista vuota"<<endl;
    else{
    prec=head;
    p=head->next;
    while(head!=NULL){
        head=p;
        delete prec;
        prec=head;
        if (p!=NULL) p=p->next;
    }
    cout<<"Lista cancellata"<<endl;
}    
}

/*funzione per stampare tutta la lista*/

void stamplista (){
    struct NICK *p;
    p=head;
    if(head==NULL)cout<<"Lista vuota"<<endl;
    while(p!=NULL){
        cout<<"Nick: "<<p->nickname<<endl<<"Nominativo :"<<p->nome<<endl<<"Indirizzo internet: "<<p->email<<endl;
        cout<<endl;
        p=p->next;
    }
}

/*funzione per stampare un elemento della lista*/

void stampnick (){
    struct NICK *p;
    int i=0;
    p=head;
    while (p!=NULL){
        if (strcmp(p->nickname,nick)==0){
            cout<<"Nick: "<<p->nickname<<endl<<"Nominativo :"<<p->nome<<endl<<"Indirizzo internet: "<<p->email<<endl;
            i++;
        }
        p=p->next;
    }
    if (i==0)cout<<"Elemento non trovato"<<endl;
}

int main(){
    int scelta=0;
    
    do{
        cout<<"1 aggiungi dati nickname"<<endl<<"2 cancella tutti nickname"<<endl;
        cout<<"3 cancella un nickname"<<endl<<"4 stampa i dati relativi a un nickname"<<endl;
        cout<<"5 stampa i dati relativi a tutti i nickname"<<endl<<"6 esci"<<endl;
        cin>>scelta;
        if(scelta==1){
            instesta();
        }else if (scelta==2){
            canclista();
        }else if (scelta==3){
            cout<<"Inserire il nickname da cancellare"<<endl;
            cin>>nick;
            cancelemento ();
        }else if (scelta==4){
            cout<<"Inserire il nickname che si vuole visualizzare"<<endl;
            cin>>nick;
            stampnick ();
        }else if (scelta==5){
            stamplista();
        }else cout<<"Ridigitare la scelta"<<endl;
    }while (scelta!=6);
}    
                
        
           
        
