#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyLibray.h"

void inserimentoInTesta(struct cella **t){
    int inserimento, verifica;
    struct cella *nuovo = (struct cella*)malloc(sizeof(struct cella));      //Alloco spazio e controllo non vi siano errrori

    if(nuovo == NULL){
        printf("ERRORE! USCITA DAL PROGRAMMA.\n");
        exit(EXIT_FAILURE);
    }

    do{
        printf("Inserisci elem da mettere in testa: ");
        verifica = scanf("%d", &inserimento);
        fflush(stdin);
    }while(verifica != 1);
    nuovo->valore = inserimento;        //Inserisco il nuovo in testa
    nuovo->next = *t;
    *t = nuovo;
}
void inserimentoInCoda(struct cella **t){
    int inserimento, verifica;
    struct cella *temp = *t;            //Puntatore temporaneo per scalare fino all'ultimo
    struct cella *nuovo = (struct cella*)malloc(sizeof(struct cella));  //alloco spazio per il nuovo
     if(nuovo == NULL){
        printf("ERRORE! USCITA DAL PROGRAMMA.\n");
        exit(EXIT_FAILURE);
    }
    do{
        printf("Inserisci elem da mettere in coda: ");  //Chiedo che elemtno voglia inserire
        verifica = scanf("%d", &inserimento);
        fflush(stdin);
    }while(verifica != 1);
    nuovo->valore = inserimento;

    if(*t == NULL){
        *t = nuovo;         //Se lista è vuota non devo scalare ed inserisco direttamente il nuovo in testa
        nuovo->next = NULL;
    }else{
        while(temp->next != NULL){  //Sclao fino all'ultima posizione della lista
            temp = temp->next;
        }
        temp->next = nuovo;         //Inserisco in coda
        nuovo->next = NULL;
    }


}

void inserimentoDopoElemento(struct cella**t){
    bool trovato = false;
    int inserimento, elementoPrima, verifica;
    struct cella *temp = *t;
    struct cella *paux;
    struct cella *nuovo = (struct cella*)malloc(sizeof(struct cella));

        if(nuovo == NULL){
            printf("ERRORE! USCITA DAL PROGRAMMA.\n");
            exit(EXIT_FAILURE);
        }
        do{
            printf("Elemento da inserire: ");
            verifica = scanf("%d", &inserimento);
            fflush(stdin);
        }while(verifica != 1);
            nuovo->valore = inserimento;

        if(*t != NULL){                                     //Controllo sia diverso da null
            do{
                do{
                    printf("Dopo che elemento: ");
                    verifica = scanf("%d", &elementoPrima);
                    fflush(stdin);
                }while(verifica != 1);
                    while(temp != NULL){
                        if(temp->valore == elementoPrima){      //Scalo finchè non trovo l'elemento dopo il quale inserire
                            paux = temp->next;
                            temp->next = nuovo;                 //Uso sia un puntatore aux sia il temp
                            nuovo->next = paux;                 //Inserisco il nuovo dopo l'elemento trovato
                            trovato = true;
                            break;
                        }
                    temp = temp->next;
                }
            }while(trovato == false);
        }else{
            printf("LISTA VUOTA. DEVO INSERIMENTO IN TESTA\n\n");         //Se è vuota la lista lo inserisco in testa
            nuovo->next = *t;
            *t = nuovo;
        }
}

void cancellaTesta(struct cella **t){                           //Semplicemento scalo la testa in avanti e cancello la cella precedente
    struct cella *elim = *t;
    if(*t != NULL){
        *t = (*t)->next;
        free(elim);
    }else{
        printf("LISTA VUOTA. NULLA DA ELIMINARE\n");            //Se lista vuota non faccio nulla
    }
}

void cancellaCoda(struct cella **t){
    struct cella *temp = *t;
    if(*t == NULL){
        printf("LISTA VUOTA. NULLA DA ELIMINARE\n");
        return;
    }
    if(temp->next == NULL){                                     //Se la coda coincide con la testa elimino la testa e faccio puntare a null il puntatore
        free(temp);
        *t = NULL;
        return;
    }

    while(temp->next->next != NULL){                            //Scalo fino a trovare l'ultimo elemento con un puntatore temp e lo elimino
        temp = temp->next;
        }
    free(temp->next);
    temp->next = NULL;
    }

void cancellaPrimaOccorrenza(struct cella **t){
    int daElim, verifica;
    struct cella *temp = *t;
    struct cella *prec = NULL;
    do{
        printf("Cancella prima occorrenza di che elemento: ");
        verifica = scanf("%d", &daElim);
        fflush(stdin);
    }while(verifica != 1);

    if(*t != NULL){
            while(temp != NULL){
                if(temp->valore == daElim){
                        if(prec == NULL){                   //Scalo fino a trovare l'occorrenza e poi elimino l'elemento selezionato con una free
                            *t = (*t)->next;
                            free(temp);
                            break;
                        }
                    prec->next = temp->next;                //Collego le due celle adiacenti
                    free(temp);
                    break;
                }
                prec = temp;
                temp = temp->next;
            }
    }else{
        printf("LISTA VUOTA. NULLA DA ELIMINARE\n");
    }
}
void stampaLista(struct cella *t){
    struct cella* tmp = t;
    int i = 0;
    printf("\n\n");
    if(t == NULL){
        printf("LISTA VUOTA\n");                    //Stampo seplicemente la situazione attuale ad ogni iterazione
    }
    while(tmp != NULL){
        printf("Elemento%d: %d\n",i , tmp->valore);
        tmp = tmp->next;
        i++;
    }
    printf("\n\n");
}

void svuotaLista(struct cella **t){
    struct cella *temp = *t;
    if(temp == NULL){
        printf("LISTA VUOTA. NULLA DA SVUOTARE");
        return;
    }
    while(*t != NULL){
        printf("ELEMENTO %d ELIMINATO DALLA PILA\n", (*t)->valore);   //Scalo la testa edelimino il precedente puntato da temp
        temp = *t;
        *t = (*t)->next;
        free(temp);
    }
}
