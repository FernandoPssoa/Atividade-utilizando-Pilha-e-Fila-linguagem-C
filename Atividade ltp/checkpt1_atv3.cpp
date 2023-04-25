#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int idade;
    int prioridade;
} Pessoa;

typedef struct {
    Pessoa dados[MAX_SIZE];
    int inicio, fim;
} Fila;

void init(Fila *fila) {
    fila->inicio = 0;
    fila->fim = -1;
}

int is_empty(Fila *fila) {
    return (fila->fim < fila->inicio);
}

int is_full(Fila *fila) {
    return (fila->fim - fila->inicio + 1) == MAX_SIZE;
}

void enqueue(Fila *fila, Pessoa psa) {
    if (is_full(fila)) {
        printf("Erro: fila cheia\n");
        return;
    }
    if (psa.idade >= 60) {
        psa.prioridade = 1;
    } else {
        psa.prioridade = 0;
    }
    fila->fim++;
    fila->dados[fila->fim] = psa;
}

Pessoa dequeue(Fila *fila) {
    Pessoa vazia = {0, 0};
    if (is_empty(fila)) {
        printf("Erro: fila vazia\n");
        return vazia;
    }
    Pessoa psa = fila->dados[fila->inicio];
    fila->inicio++;
    return psa;
}

void print_fila(Fila *fila) {
    if (is_empty(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Pessoas na fila:\n");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        Pessoa psa = fila->dados[i];
        printf("Idade: %d - Prioridade: %s\n", psa.idade, psa.prioridade ? "alta" : "normal");
    }
}

int main() {
    Fila fila;
    Pessoa psa;
    int escolha = 0;
    init(&fila);
    
    do {
    	printf("\nEscolha uma Acao: \n");
        printf("\n1 - Adicionar pessoa na fila\n");
        printf("2 - Proxima pessoa\n");
        printf("3 - Listar pessoas na fila\n");
        printf("0 - Sair\n");
        scanf("%d", &escolha);
        
        switch(escolha) {
            case 1:
                printf("Digite a idade da pessoa: ");
                scanf("%d", &psa.idade);
                enqueue(&fila, psa);
                printf("Pessoa adicionada na fila!\n");
                break;
            case 2:
                psa = dequeue(&fila);
                if (psa.idade == 0) {
                    break;
                }
                printf("Proxima pessoa:\nIdade: %d - Prioridade: %s\n", psa.idade, psa.prioridade ? "alta" : "normal");
                break;
            case 3:
                print_fila(&fila);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida, tente novamente!\n");
        }
    } while (escolha != 0);
    
    return 0;
}
