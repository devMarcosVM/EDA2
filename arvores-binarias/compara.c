/*
    Escreva uma função que compara se duas árvores binárias são iguais.
*/

int iguais(p_no arvore1, p_no arvore2) {
    if (arvore1 == NULL && arvore2 == NULL)
        return 1;
    if (arvore1 == NULL || arvore2 == NULL)
        return 0;
    return arvore1->dado == arvore2->dado && 
           iguais(arvore1->esq, arvore2->esq) && 
           iguais(arvore1->dir, arvore2->dir);
}