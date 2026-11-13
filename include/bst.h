#ifndef BST_H
#define BST_H

typedef struct {
    int id;
    char titulo[80];
    char autor[80];
    int ano;
} Livro;

typedef struct NoBST {
    Livro livro;
    struct NoBST* esq;
    struct NoBST* dir;
} NoBST;

NoBST* inserirBST(NoBST* raiz, Livro l);
void listarEmOrdem(NoBST* raiz);
void buscarBST(NoBST* raiz, int id);
NoBST* removerBST(NoBST* raiz, int id);
void liberarBST(NoBST* raiz);

#endif