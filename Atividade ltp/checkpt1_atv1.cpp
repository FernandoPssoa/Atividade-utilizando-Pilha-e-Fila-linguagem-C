#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef enum {
    FUNCAO1,
    FUNCAO2,
    FUNCAO3
} Funcao;

typedef struct {
    Funcao funcao;
    int valorN;
} Dado;

typedef struct {
    Dado dado[MAX_SIZE];
    int topo;
} Pilha;

void init(Pilha* pilha) {
    pilha->topo = -1;
}

int is_empty(Pilha* pilha) {
    return pilha->topo == -1;
}

int is_full(Pilha* pilha) {
    return pilha->topo == MAX_SIZE - 1;
}

void push(Pilha* pilha, Dado item) {
    if (is_full(pilha)) {
        printf("Erro: pilha cheia\n");
        return;
    }
    pilha->dado[++pilha->topo] = item;
}

Dado pop(Pilha* pilha) {
    if (is_empty(pilha)) {
        printf("Erro: pilha vazia\n");
        return (Dado) {FUNCAO1, 0};
    }
    return pilha->dado[pilha->topo--];
}

Dado peek(Pilha* pilha) {
    if (is_empty(pilha)) {
        printf("Erro: pilha vazia\n");
        return (Dado) {FUNCAO1, 0};
    }
    return pilha->dado[pilha->topo];
}

int main() {
    Pilha pilha;
    init(&pilha);

    int opcao;
    do {
        printf("Digite a acao desejada:\n");
        printf("1. Y = X + 3\n");
        printf("2. y = 2 * (x + 8)\n");
        printf("3. Y = (X + 1)*(x - 1)\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        if (opcao >= 1 && opcao <= 3) {
            int valorN;
            printf("Digite o valor de X:\n");
            scanf("%d", &valorN);
            Dado dado = {(Funcao) (opcao-1), valorN};
            push(&pilha, dado);
        } else if (opcao != 0) {
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    printf("Deseja exibir os resultados? (S/N)\n");
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 'S' || resposta == 's') {
        while (!is_empty(&pilha)) {
            Dado dado = pop(&pilha);
            switch (dado.funcao) {
                case FUNCAO1:
                    printf("Y = %d + 3 = %d\n", dado.valorN, dado.valorN + 3);
                    break;
                case FUNCAO2:
                    printf("y = 2 * (%d + 8) = %d\n", dado.valorN, 2 * (dado.valorN + 8));
                    break;
                case FUNCAO3:
                    printf("Y = (%d + 1)*(%d - 1) = %d\n", dado.valorN, dado.valorN, (dado.valorN + 1) * (dado.valorN-1));
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
            }
        }
    }
    return 0;

}
