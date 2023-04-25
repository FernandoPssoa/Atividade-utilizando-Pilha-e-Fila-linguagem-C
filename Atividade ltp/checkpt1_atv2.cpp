#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int dado[MAX_SIZE];
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

void push(Pilha* pilha, int item) {
    if (is_full(pilha)) {
        printf("Erro: pilha cheia\n");
        return;
    }
    pilha->dado[++pilha->topo] = item;
}

int pop(Pilha* pilha) {
    if (is_empty(pilha)) {
        printf("Erro: pilha vazia\n");
        return 0;
    }
    return pilha->dado[pilha->topo--];
}

int peek(Pilha* pilha) {
    if (is_empty(pilha)) {
        printf("Erro: pilha vazia\n");
        return 0;
    }
    return pilha->dado[pilha->topo];
}

void mesclar_pilhas_ord(Pilha* p1, Pilha* p2, Pilha* res) {
    int i = p1->topo, j = p2->topo;
    while (i >= 0 && j >= 0) {
        if (p1->dado[i] > p2->dado[j]) {
            push(res, p1->dado[i]);
            i--;
        } else {
            push(res, p2->dado[j]);
            j--;
        }
    }
    while (i >= 0) {
        push(res, p1->dado[i]);
        i--;
    }
    while (j >= 0) {
        push(res, p2->dado[j]);
        j--;
    }
}

int eh_primo(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void mesclar_pilhas_primos(Pilha* p1, Pilha* p2, Pilha* res) {
    int i = p1->topo, j = p2->topo;
    while (i >= 0 && j >= 0) {
        if (eh_primo(p1->dado[i])) {
            push(res, p1->dado[i]);
        }
        i--;
        if (eh_primo(p2->dado[j])) {
            push(res, p2->dado[j]);
        }
        j--;
    }
    while (i >= 0) {
        if (eh_primo(p1->dado[i])) {
            push(res, p1->dado[i]);
        }
        i--;
    }
    while (j >= 0) {
        if (eh_primo(p2->dado[j])) {
            push(res, p2->dado[j]);
        }
        j--;
    }
}

void imprimir_pilha(Pilha* pilha) {
    while (!is_empty(pilha)) {
        printf("%d ", pop(pilha));
    }
    printf("\n");
}
int main() {
    Pilha p1, p2, res;
    int op, item;

    init(&p1);
    init(&p2);
    init(&res);

    printf("Preencha a primeira pilha:\n");
    do {
        printf("Digite o valor (ou -1 para sair): ");
        scanf("%d", &item);
        if (item != -1) {
            push(&p1, item);
        }
    } while (item != -1);

    printf("Preencha a segunda pilha:\n");
    do {
        printf("Digite o valor (ou -1 para sair): ");
        scanf("%d", &item);
        if (item != -1) {
            push(&p2, item);
        }
    } while (item != -1);

    printf("Escolha a acao desejada:\n");
    printf("1 - Mesclar as duas pilhas ordenadamente\n");
    printf("2 - Mesclar as duas pilhas com os numeros primos\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            mesclar_pilhas_ord(&p1, &p2, &res);
            printf("Pilha mesclada ordenada:\n");
            imprimir_pilha(&res);
            break;
        case 2:
            mesclar_pilhas_primos(&p1, &p2, &res);
            printf("Pilha mesclada com numeros primos:\n");
            imprimir_pilha(&res);
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }

    return 0;
}
