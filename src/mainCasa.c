#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    struct no *prox;
    int num;
} No;

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

    if( lista->inicio == NULL ) {
        lista->inicio = novo;
        novo->prox = novo; 
    } else {
        aux = lista->inicio;
        while( aux->prox != lista->inicio ) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = lista->inicio;
    }
    lista->tam++;
}

int Maior(No *no, int tam) {

    No *aux = no->prox;

    for(int i = 0; i < tam - 1; i++) {

        if( aux->num > no->num ) {
            return aux->num;
        }
        aux = aux->prox;
    }

    return -1;
}

void FreeLista(Lista *lista) {

    if(lista->inicio == NULL) {
        return;
    }

    No *aux = lista->inicio->prox;

    while(aux != lista->inicio) {

        No *temp = aux;
        aux = aux->prox;

        free(temp);
    }

    free(lista->inicio);

    lista->inicio = NULL;
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {

    Lista lista;
    CriarLista(&lista);
    *returnSize = numsSize;

    for(int i = 0; i < numsSize; i++) {
        Inserir(&lista, nums[i]);
    }

    int *novoNums = (int*)malloc(sizeof(int) * numsSize);

    No *aux = lista.inicio;

    for(int i = 0; i < numsSize; i++) {

        novoNums[i] = Maior(aux, lista.tam);

        aux = aux->prox;
    }

    FreeLista(&lista);
    return novoNums;
}


int main() {

    int nums[] = {1, 2, 1};

    int returnSize;

    int *resultado = nextGreaterElements(nums, 3, &returnSize);

    printf("Resultado: ");

    for(int i = 0; i < returnSize; i++) {
        printf("%d ", resultado[i]);
    }

    printf("\n");

    free(resultado);

    return 0;
}