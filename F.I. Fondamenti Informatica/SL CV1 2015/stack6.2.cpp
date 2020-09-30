/*Gestione di una pila di elementi interi (stack). 
Il programma dovrà presentare a video un menù con le seguenti funzioni: 
1.      inserisci elemento nella pila (push)

2.      preleva elemento dalla pila  (pop)

3.      mostra lo stato della pila. 

La prima opzione dovrà leggere da tastiera un numero intero e lo dovrà inserire 
nello stack, si ricorda che lo stack ha una gestione di tipo lifo (last  in first out). 
La seconda opzione dovrà estrarre l’elemento in cima alla pila e visualizzarlo a video, 
mentre la terza ed ultima opzione dovrà mostrare a video il contenuto di tutta la pila 
senza però estrarne gli elementi.
*/

#include <iostream>

using namespace std;

struct ELEMENTO {
    int numero;
    struct ELEMENTO *next;
};

struct ELEMENTO *head=NULL;

/*funzione per inserire un elemento in testa alla pila*/

void push (int num){
    struct ELEMENTO *p;
    p=new struct ELEMENTO;
    p->numero=num;
    p->next=head;
    head=p;
}  

/*funzione per estrarre l'elemento in cima alla pila*/ 

void pop (){
    struct ELEMENTO *p;
    p=head;
    if (head==NULL)cout<<"pila vuota"<<endl;
    else{
       head=head->next;
       cout<<"elemento in cima alla pila: "<<p->numero<<endl;
       delete p;
   }    
}  

/*funzione per mostrare lo stato della pila*/

void stampapila (){
    struct ELEMENTO *p;
    p=head;
    if(head==NULL)cout<<"Pila vuota"<<endl;
    else {
        cout<<endl;
        while(p!=NULL){
             cout<<p->numero<<endl;
             p=p->next;
        }
        cout<<endl;
    }    
} 

int main (){
    int scelta;
    int num;
    do{
         cout<<"1 Inserisci elemento nella pila"<<endl<<"2 Preleva elemento dalla pila"<<endl;
         cout<<"3 Mostra lo stato della pila"<<endl<<"4 Esci"<<endl;
         cin>>scelta;
         if (scelta==1){
             cout<<"Digitare l'elemento da inserire nella pila"<<endl;
             cin>>num;
             push (num);
         }else if (scelta==2){
             pop();
         }else if (scelta==3){
             stampapila();
         }else cout<<"ridigitare la scelta"<<endl;
     }while (scelta!=4);
 }    
                     
    
