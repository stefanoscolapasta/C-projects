#ifndef MYLIBRAY_H_INCLUDED
#define MYLIBRAY_H_INCLUDED

struct cella{
    int valore;             //Definisico la struttura cella
    struct cella *next;
};

struct cella *testa;        //Puntatore "globale" alla testa
//Prototipi delle funzioni
void inserimentoInTesta(struct cella**);
void inserimentoInCoda(struct cella**);
void inserimentoDopoElemento(struct cella**);
void cancellaTesta(struct cella**);
void cancellaCoda(struct cella**);
void cancellaPrimaOccorrenza(struct cella**);
void stampaLista(struct cella*);
void svuotaLista(struct cella**);

#endif // MYLIBRAY_H_INCLUDED
