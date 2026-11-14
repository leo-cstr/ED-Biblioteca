#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "estrutura.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcao = -1;
    NoBST* raiz = NULL;
    Fila filaIds;
    Livro l;
    int idAux;

    inicializarFila(&filaIds);

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
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("ID (inteiro positivo): ");
                scanf("%d", &l.id);
                limparBuffer();
                if (l.id <= 0) {
                    printf("ERRO: ID deve ser positivo.\n");
                    break;
                }
                
                printf("Titulo: ");
                fgets(l.titulo, 80, stdin);
                l.titulo[strcspn(l.titulo, "\n")] = 0;
                
                printf("Autor: ");
                fgets(l.autor, 80, stdin);
                l.autor[strcspn(l.autor, "\n")] = 0;
                
                if (strlen(l.titulo) == 0 || l.titulo[0] == ' ' || strlen(l.autor) == 0) {
                    printf("ERRO: Textos nao podem ser vazios ou espacos.\n");
                    break;
                }

                printf("Ano (1 a 2026): ");
                scanf("%d", &l.ano);
                limparBuffer();
                if (l.ano < 1 || l.ano > 2026) {
                    printf("ERRO: Ano invalido.\n");
                    break;
                }

                raiz = inserirBST(raiz, l);
                break;

            case 2:
                printf("ID para busca: ");
                scanf("%d", &idAux);
                limparBuffer();
                buscarBST(raiz, idAux);
                break;

            case 3:
                printf("ID para remocao: ");
                scanf("%d", &idAux);
                limparBuffer();
                raiz = removerBST(raiz, idAux);
                break;

            case 4:
                printf("\n=== Registros na BST (Em-Ordem) =\n");
                listarEmOrdem(raiz);
		        printf("===================================\n");
                break;

            case 5:
                printf("ID para inserir na estrutura linear (inteiro positivo): ");
                scanf("%d", &idAux);
                limparBuffer();
                if (idAux <= 0) {
                    printf("Erro: ID deve ser positivo.\n");
                } else {
                    inserirFila(&filaIds, idAux);
                }
                break;

            case 6:
                removerFila(&filaIds);
                break;

            case 7:
                exibirFila(&filaIds);
                break;

            case 0:
                printf("Encerrando.\n");
                liberarBST(raiz);
                liberarFila(&filaIds);
                break;

            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}