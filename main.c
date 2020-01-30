//GROUP PROJECT DESCRIPTION: LISTA CON STRUTTURE COLLEGATE
//GROUP AUTHORS: STEFANO SCOLARI, ALESSANDRO ZANZI, FEDERICO BRUNELLI, LEON BAIOCCHI
//DATE: 20191221
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyLibray.h"

int main()
{
    bool esci;                              //Var bool per poter decidere quando uscire dalla selezione e chiudere il programma
    int opzioneInserimento, verifica;
    testa = NULL;
    do{

            puts("MENU");
            puts("[1] Inserisci in testa");
            puts("[2] Inserisci in coda");
            puts("[3] Inserisci dopo elemento selezionato");
            puts("[4] Cancella testa");
            puts("[5] Cancella coda");
            puts("[6] Cancella prima occorrenza");
            puts("[7] Svuota lista");
            puts("[8] Esci");
            stampaLista(testa);
        do{
            printf("Scegli cosa fare: ");
            verifica = scanf("%d", &opzioneInserimento);
            fflush(stdin);
        }while(verifica != 1 || opzioneInserimento < 1 || opzioneInserimento > 8);

    switch(opzioneInserimento){                     //Selezione con switch()
        case 1: inserimentoInTesta(&testa);
            break;
        case 2: inserimentoInCoda(&testa);
            break;
        case 3: inserimentoDopoElemento(&testa);
            break;
        case 4: cancellaTesta(&testa);
            break;
        case 5: cancellaCoda(&testa);
            break;
        case 6: cancellaPrimaOccorrenza(&testa);
            break;
        case 7: svuotaLista(&testa);
            break;
        case 8: esci = true;
                printf("EXIT. ");
                svuotaLista(&testa);            //Invece che fare una free sfrutto la funzione creata per svuotare la lista che ha lo stesso effetto
            break;
        default:
            break;
        }
    }while(esci == false);

    return 0;
}

