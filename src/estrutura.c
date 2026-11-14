#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserirFila(Fila* f, int id) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }
    novo->id = id;
    novo->prox = NULL;
    
    // Se a fila estiver vazia, inicio e fim apontam para o novo no
    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    printf("ID %d inserido na estrutura linear com sucesso.\n", id);
}

void removerFila(Fila* f) {
    if (f->inicio == NULL) {
        printf("Lista vazia, nenhuma remocao efetuada.\n");
        return;
    }
    
    NoFila* temp = f->inicio;
    int idRemovido = temp->id;
    
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
    printf("ID %d removido da estrutura linear.\n", idRemovido);
}

void exibirFila(Fila* f) {
    if (f->inicio == NULL) {
        printf("A estrutura linear esta vazia.\n");
        return;
    }
    
    printf("\n--- Estrutura Linear (Fila) ---\n");
    printf("Inicio -> ");
    NoFila* atual = f->inicio;
    while (atual != NULL) {
        printf("[%d] ", atual->id);
        atual = atual->prox;
    }
    printf("<- Fim\n\n");
}

void liberarFila(Fila* f) {
    NoFila* atual = f->inicio;
    while (atual != NULL) {
        NoFila* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
}