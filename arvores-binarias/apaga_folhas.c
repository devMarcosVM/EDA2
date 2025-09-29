/*
    Escreva uma função recursiva que apaga todas as folhas de uma árvore que tenham a chave igual a um valor dado.
*/

#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} no, *p_no;

p_no apaga_folhas(p_no raiz, int x) {
    if (raiz == NULL)
        return NULL;
    if (raiz->esq == NULL && raiz->dir == NULL && 
        raiz->dado == x) {
        free(raiz);
        return NULL;
    }
    raiz->esq = apaga_folhas(raiz->esq, x);
    raiz->dir = apaga_folhas(raiz->dir, x);
    return raiz;
}
