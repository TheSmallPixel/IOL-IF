//
//  main.c
//  forkFile
//
//  Created by Andrea on 19/01/16.
//  Copyright © 2016 Andrea. All rights reserved.
//

// TERZA PROVA IN ITINERE //


//#include<stdio.h>
//#include<sys/types.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_CHILDREN 5
#define MAX_LEN_FNAME 50


int main(int argc,char **argv){
    
    char buff[MAX_LEN_FNAME];
    char *file_array[]={"dati_1","dati_2.txt","dati_3.txt","dati_4.txt","dati_5.txt"};
    char *file_out_array[]={"out_1.txt","out_2.txt","out_3.txt","out_4.txt","out_5.txt"};
    char *nomefile;
    FILE *dati_stream, *out_stream;
    int valore=0,status=0,count=0,counter=0;
    int i,c;
    float media=0;
    pid_t pid,c_pid;
    
    
    for (i=0;i<5;i++){
        // Procedo con la fork e ne verifico l'esito.
        int pid=fork();
        if(pid < 0){
            fprintf(stderr,"Errore in creazione child\n");
            exit(EXIT_FAILURE);
        }
        
        // Verifico di essere nel figlio e ne eseguo il codice.
        
        if(pid==0)
        {
            // Apro il file con i dati.
            nomefile = file_array[i];
            dati_stream=fopen(nomefile,"r");
            
            if(dati_stream==NULL){
                fprintf(stderr,"Errore in apertura file %s\n",file_array[i]);
                exit(1);
            }
            counter = 0;
            // Prelevo i valori contenuti nel file uno a uno,
            // li sommo e incremento il contatore del numero
            // di elementi.
            while(!(feof(dati_stream))){
                fscanf(dati_stream,"%d\n",&valore);
                media += (float)valore;
                counter++;
            }
            
            
            if(counter > 0){
                // Se nel file era presente almeno un elemento posso
                // procedere con il calcolo della media.
                fprintf(stdout,"[PID_%d]Media file (%d/%d) ",getpid(),(int)media,counter);
                media /= (float)counter;
                fprintf(stdout,"%s :%.2f\n",file_array[i],media);
            }else{
                fprintf(stdout,"[Errore Processo %d]: Non ho trovato valori nel file indicato %s\n",getpid(),file_array[i]);
            }
            
            // Apro il file che conterra' il nome del file ed il numero di elementi superiori alla media.
            if((out_stream=fopen(file_out_array[i],"w"))==NULL){
                fprintf(stderr,"Errore in apertura file %s\n",file_out_array[i]);
                exit(EXIT_FAILURE);
            }
            
            count =  0;
            // Riporto l'indicatore di posizione del file all'inizio.
            fseek(dati_stream,0L,SEEK_SET);
            
            // Scrivo il nome del file dati nel file di output che sara' letto dal processo padre.
            fprintf(out_stream,"%s: ",file_array[i]);
            
            // Rileggo il file dati e per ogni elemento superiore alla media
            // incremento un contatore.
            while(!(feof(dati_stream))){
                fscanf(dati_stream,"%d\n",&valore);
                if(valore > media){
                    count++;
                    //fprintf(out_stream,"%d\n",valore);
                }
            }
            fprintf(out_stream,"%d\n",count);
            
            // Chiudo i due stream
            fclose(dati_stream);
            fclose(out_stream);
            
            // TERMINO IL FIGLIO e come valore di uscita ritorno il numero di
            // elementi superiori alla media
            exit(count);
        }
    }
    
    // Il padre attende la terminazione dei propri figli, scrive in output il pid
    // del figlio terminato ed il numero di elementi superiori alla media
    while((c_pid=wait(&status))>0){
        fprintf(stdout,"Terminato processo %d, num elem. superiori media: %d\n",c_pid,(status/256));
    }
    
    for (c=0;c<MAX_CHILDREN;c++){
        
        // Per ogni processo il padre apre il file con i dati in output
        if((out_stream=fopen(file_out_array[c],"r"))==NULL){
            fprintf(stderr,"Errore apertura file %s\n",file_out_array[c]);
            exit(EXIT_FAILURE);
        }
        
        // Scrivo il nome del file di output
        fscanf(out_stream,"%s %d\n",buff,&valore);
        fprintf(stdout,"%s %d\n",buff,valore);
        
        // Chiudo lo stream
        fclose(out_stream);
    }
    
    return(0);
}
