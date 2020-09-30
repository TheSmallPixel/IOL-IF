//
//  main.c
//  forkSimple
//
//  Created by Andrea on 19/01/16.
//  Copyright © 2016 Andrea. All rights reserved.
//

/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2001 Author                                                          */
/*                                                                            */
/*   Description
 Si crei il programma "fork example" in
 modo che possa ricevere come input un numero
 intero immesso da tastiera. A tale numero, il
 processo figlio creato somma 15, mentre il
 processo padre somma 10
 Esecuzione: $ esempioBfork.out <valore>
 Output:
 Processo padre Pid: numPid valore = <valore> + 10
 Processo figlio Pid: numPid valore = <valore> + 15
 */
/* ========================================================================== */


/* necessari per fork() */
//#include <sys/types.h>
#include <unistd.h>
/* necessario per atoi() */
#include <stdlib.h>
/* necessario per printf() */
#include <stdio.h>


int main(int argc,char **argcv)
{ int valore = 0;
    if ( 1 < argc )
        valore = atoi( argcv[ 1 ] );
    printf("Unico processo con PID %d.\n",getpid());
    int pid = fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();

    if (pid == 0)
    {/* codice eseguito dal figlio */
        printf( "figlio [pid: %d]> valore iniziale= %d\n", getpid(), valore );
        valore += 15;
        printf( "figlio [pid: %d]> valore finale= %d\n", getpid(), valore );
    }
    
    else if (pid > 0)
    {
        
        /* codice eseguito dal padre */
        printf("padre [pid: %d]> generato un figlio; il suo pid e' %d\n",getpid(),
               pid);
        printf( "padre [pid: %d]> valore = %d\n", getpid(), valore );
        valore += 10;
        printf( "padre [pid: %d]> valore finale= %d\n", getpid(), valore );
        
    }
    else
    {
        /* codice eseguito dal padre in caso di errore */
        printf("padre [pid: %d]> problemi durante creazione delfiglio.\n",getpid());
               exit(1);
               }
exit(0);
}
