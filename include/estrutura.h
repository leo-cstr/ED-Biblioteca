#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct NoFila {
    int id;
    struct NoFila* prox;
} NoFila;

typedef struct {
    NoFila* inicio;
    NoFila* fim;
} Fila;

void inicializarFila(Fila* f);
void inserirFila(Fila* f, int id);
void removerFila(Fila* f);
void exibirFila(Fila* f);
void liberarFila(Fila* f);

#endif