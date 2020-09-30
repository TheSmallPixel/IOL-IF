/*Si scriva un programma per la gestione di un report di pagelle scolastiche. 
Si rappresenti il report con una matrice: ad ogni studente corrisponde una riga,
ad ogni materia corrisponde una colonna e all’intersezione si trova il voto di un certo studente in una certa materia. 

 

a)      Il programma deve avere le seguenti funzionalità accessibili tramite menù:
creazione del report e visualizzazione del report. La creazione avviene chiedendo 
per prima cosa il numero di studenti da inserire, e poi per ogni studente il voto 
di ognuna delle materie (per ora gli studenti e le materie vengono solo identificati 
attraverso il numero di riga e di colonna). La visualizzazione stampa a video i voti 
in forma matriciale.

*/


#include <iostream>

using namespace std;

int main (){
    
    const int materie=5;
    float* v1 [materie];
    int i,j,n,scelta;
    
    cout<<"Inserire il numero di studenti"<<endl;
    cin>>n;
    
    for(i=0;i<materie;i++){
        v1[i]=new float [n];
    }    
    
    for(i=0;i<n;i++){
        for(j=0;j<materie;j++){
            v1[i][j]=0;
        }
    } 
    do{
    cout<<"Scegliere una delle seguenti opzioni: creazione del report(1); visualizzazione del report(2)."<<endl;
    cin>>scelta;
    
           
                 
    if (scelta==1){
        for(i=0;i<n;i++){
            cout<<"Inserire i voti dello studente "<<i<<endl;
            for(j=0;j<materie;j++){
                cin>>v1[i][j];
            }
        }
    }
    if (scelta==2){
        for(i=0;i<n;i++){
            for(j=0;j<materie;j++){
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
        }  
    }
    }while((scelta==2)||(scelta==1));    
    system ("PAUSE");
}        
        
    
    
