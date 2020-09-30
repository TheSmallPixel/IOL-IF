//Cognome: Petralia
//Nome: Valerio
//Matricola:835656
//Calsse Virtuale: Classe virtuale 2
#include <iostream.h>


void risolvi(char**,int,int);                                   

int main()
{
int R,C;                                                                        //variabili numeri interi righe e colonne

cout << "Inserire il numero R di righe (o la lunghezza delle colonne): ";
cin >> R;                                                                       //determina grandezza di R tramite immissione da tastiera
cout << "Inserire il numero C di colonne (o la lunghezza delle righe): ";
cin >> C;                                                                       //determina grandezza di C tramite immissione da tastiera


char* cruciverba [R];                                                           //Inserisci dati nella matrice cruciverba tramite i e j
cout << "L'inserimento dei caratteri nel cruciverba deve seguire un ordine per righe.\nPremere un tasto per continuare.\n\n" << endl;

for (int i = 0; i < R; i++){
    cruciverba[i]= new char [C];
for (int j = 0; j < C; j++){
cout << "\nInserire il carattere che andra' in posizione riga "<< i << " e colonna " << j << ": ";
cin >> cruciverba [i] [j];
}
}

cout << "\n\nPremere un tasto per visualizzare il cruciverba inserito." << endl;
system("pause>nul");
for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
        cout <<"  "<< cruciverba [i] [j];
        }
    cout<<endl;
    }

cout << "\n\nPremere un tasto per visualizzare l'elenco delle parole e la loro rispettiva posizione.\n" << endl;
system("pause>nul");
risolvi(cruciverba,R,C);
return 0;
}

void risolvi(char** cruciverba,int R, int C){
int count;                                                                      
int max;                                              
int indice;
int o;
int v;
int riga;
int colonna;
char orizzontale[100];
char verticale[100];
int posizione;

count=0;                  
max=R*C;                 //calcola valore massimo di count, numero totali celle                                        
posizione=0;             //contatore posizione
while (count<max) {
      char orizzontale[C];
      char verticale[R];
      indice=count;
      o=0;
      v=0;
      riga=0;
      colonna=indice;
      while (indice>=C){                             
            indice=indice-C;
            riga=riga+1;
            colonna=indice;
            }
      count=count+1;
      if ((cruciverba[riga][colonna])=='*'){                                             //se il carattere è un asterisco non fare nulla
                                            count=count;
                                            }
      if ((colonna==0)&&((cruciverba[riga][colonna])!='*')){                             //se sei sulla prima colonna e non c'è un asterisco
                                                            for (int k=colonna;k<C;k++){
                                                                if ((cruciverba[riga][k])!='*'){  //riga fissa colonna che aumenta
                                                                                                orizzontale[o]=cruciverba[riga][k];    //scrive la parola orizzontale
                                                                                                o++;
                                                                                                }
                                                                else {
                                                                     break;
                                                                     }
                                                                }
                                                            }
      if ((colonna>0)&&((cruciverba[riga][colonna-1])=='*')){                            //se non sei sulla prima colonna e nella colonna precedente c'è un asterisco
                                                             for (int k=colonna;k<C;k++){
                                                                 if ((cruciverba[riga][k])!='*'){  //riga fissa colonna che aumenta
                                                                                                 orizzontale[o]=cruciverba[riga][k];    //scrive la parola orizzontale
                                                                                                 o++;
                                                                                                 }
                                                                 else {
                                                                      break;
                                                                      }
                                                                 }
                                                             }
      if ((riga==0)&&((cruciverba[riga][colonna])!='*')){                                 //se sei sulla prima riga non c'è un asterisco
                                                         for (int k=riga;k<R;k++){        
                                                             if ((cruciverba[k][colonna])!='*'){  //riga che aumenta  colonna fissa
                                                                                                verticale[v]=cruciverba[k][colonna];    //scrive la parola verticale
                                                                                                v++;
                                                                                                }
                                                             else {
                                                                  break;
                                                                  }
                                                             }
                                                         }
      if ((riga>0)&&((cruciverba[riga-1][colonna])=='*')){                                //se non sei sulla prima riga e nella riga precedente c'è un asterisco
                                                          for (int k=riga;k<R;k++){
                                                              if ((cruciverba[k][colonna])!='*'){  //riga che aumenta  colonna fissa
                                                                                                 verticale[v]=cruciverba[k][colonna];    //scrive la parola verticale
                                                                                                 v++;
                                                                                                 }
                                                              else {
                                                                   break;
                                                                   }
                                                              }
                                                          }
      else {
           count=count;                                                                   //se no non fare nulla
           }
           
      if ((o>=2)||(v>=2)){                                                                //se uno dei due contatori delle parole è maggiore di 2
                          posizione++;                                                    //aumenta di 1 la posizione (che era a 0)
                          cout <<"Posizione "<<posizione<<": riga "<<riga<<", colonna "<<colonna;    //e scrivi:
                          if (v>=2){                                                      //se v è maggiore di 2 scrivi anche verticale
                                    cout <<" verticale ";
                                    for (int k = 0; k < v; k++){                          //scrivi finche non arrivi alla lunghezza di v
                                        cout << verticale [k];
                                        }
                                    }
                          if (o>=2){                                                      //se v è maggiore di 2 scrivi anche orizzontale
                                    cout <<" orizzontale ";
                                    for (int k = 0; k < o; k++){                          //scrivi finche non arrivi alla lunghezza di o
                                        cout << orizzontale [k];
                                        }
                                    }
                          cout<<endl;
                          }                     
      }
 system("pause>nul");
}
