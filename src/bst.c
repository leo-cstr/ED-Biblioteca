#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

NoBST* inserirBST(NoBST* raiz, Livro l) {
    if (raiz == NULL) {
        NoBST* novo = (NoBST*)malloc(sizeof(NoBST));
        novo->livro = l;
        novo->esq = NULL; novo->dir = NULL;
        printf("Registro cadastrado com sucesso\n\n");
        return novo;
    }
    if (l.id < raiz->livro.id) {
        raiz->esq = inserirBST(raiz->esq, l);
    } else if (l.id > raiz->livro.id) {
        raiz->dir = inserirBST(raiz->dir, l);
    } else {
        printf("ERRO: ID ja existente na BST.\n");
    }
    return raiz;
}

void listarEmOrdem(NoBST* raiz) {
    if (raiz != NULL) {
        listarEmOrdem(raiz->esq);
        printf("ID: %d | Titulo: %s | Autor: %s | Ano: %d\n",
               raiz->livro.id, raiz->livro.titulo, raiz->livro.autor, raiz->livro.ano);
        listarEmOrdem(raiz->dir);
    }
}

void buscarBST(NoBST* raiz, int id) {
    if (raiz == NULL) {
        printf("Registro com ID %d nao encontrado.\n", id);
        return;
    }
    if (id == raiz->livro.id) {
        printf("Encontrado -> ID: %d | Titulo: %s | Autor: %s | Ano: %d\n",
               raiz->livro.id, raiz->livro.titulo, raiz->livro.autor, raiz->livro.ano);
    } else if (id < raiz->livro.id) {
        buscarBST(raiz->esq, id);
    } else {
        buscarBST(raiz->dir, id);
    }
}

NoBST* encontrarMinimo(NoBST* raiz) {
    while (raiz->esq != NULL) raiz = raiz->esq;
    return raiz;
}

NoBST* removerBST(NoBST* raiz, int id) {
    if (raiz == NULL) {
        printf("Erro: Registro nao encontrado para remocao.\n");
        return raiz;
    }
    if (id < raiz->livro.id) {
        raiz->esq = removerBST(raiz->esq, id);
    } else if (id > raiz->livro.id) {
        raiz->dir = removerBST(raiz->dir, id);
    } else {
        if (raiz->esq == NULL) {
            NoBST* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            NoBST* temp = raiz->esq;
            free(raiz);
            printf("Registro removido com sucesso.\n");
            return temp;
        }

        NoBST* temp = encontrarMinimo(raiz->dir);
        raiz->livro = temp->livro;
        raiz->dir = removerBST(raiz->dir, temp->livro.id);
    }
    return raiz;
}

void liberarBST(NoBST* raiz) {
    if (raiz != NULL) {
        liberarBST(raiz->esq);
        liberarBST(raiz->dir);
        free(raiz);
    }
}
