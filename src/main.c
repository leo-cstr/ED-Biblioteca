#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    int opcao = -1;
    NoBST* raiz = NULL; 

    while (opcao != 0) {
        printf("==========================================\n");
        printf("SISTEMA DE ESTRUTURA DE DADOS\n");
        printf("==========================================\n");
        printf("1 - Cadastrar registro na BST\n");
        printf("2 - Buscar registro por ID na BST\n");
        printf("3 - Remover registro da BST\n");
        printf("4 - Listar registros em-ordem\n");
        printf("5 - Inserir ID na estrutura linear\n");
        printf("6 - Remover da estrutura linear\n");
        printf("7 - Exibir estrutura linear\n");
        printf("0 - Encerrar\n");
        printf("==========================================\n")
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
        }
    }
    return 0;
}
