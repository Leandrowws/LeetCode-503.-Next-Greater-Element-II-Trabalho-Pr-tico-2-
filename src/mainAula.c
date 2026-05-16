#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    struct no *prox;
    int num;
}No;

typedef struct {
    int tam;
    No *inicio;
} Lista;

void CriarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}

void Inserir(Lista *lista, int num) {
    No *aux, *novo = (No*)malloc(sizeof(No));
    novo->num = num;
    novo->prox = NULL;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux = novo;
    }
}

int Maior(No *no, int num, int tam) {
    No *aux = no;
    int maior = -1;

    for(int i = 0; i < tam - 1; i++) {
        aux = aux->prox;
        if(aux->num > num) maior = num;
    }

    return maior;
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {

    Lista *lista = NULL;
    CriarLista(lista);
    *returnSize = numsSize;

    for(int i = 0; i < numsSize - 1; i++) {
        Inserir(lista, nums[i]);
    }

    No *aux1 = lista->inicio;
    No *aux2 = lista->inicio;

    while(aux1->prox != NULL) {
        aux1 = aux1->prox;
    }

    aux1->prox = lista->inicio;

    int *novoNums = (int*)malloc(sizeof(int) * numsSize);

    for(int i = 0; i < numsSize - 1; i++) {
        novoNums[i] = Maior(aux2, aux2->num, lista->tam);
        aux1 = aux1->prox;
    }
    return novoNums;
}

int main() {

    int *nums = (int*)malloc(sizeof(int)*5);
    int *returnSize = 0;

    for(int i = 0; i < 5; i++) {
        nums[i] = i;
    }

    int *novoNums = nextGreaterElements(nums, 5, returnSize);

    for(int i = 0; i < 5; i++) {
        printf("%d ", novoNums[i]);
    }

    return 0;
}

