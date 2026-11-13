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

#endif
