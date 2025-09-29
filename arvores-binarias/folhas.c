/*
    Escreva uma função que calcula o número de folhas em uma árvore dada.
*/

int folhas(p_no raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    return folhas(raiz->esq) + folhas(raiz->dir);
}
