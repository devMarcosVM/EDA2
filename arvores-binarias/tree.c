#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *esq;
    struct celula *dir;
} celula;

celula *treeInitializer(){
    return NULL;
}

// Para insercao basta inserir o valor no seu local adequado, respeitando as regras de uma arvore binaria
celula *insert(celula *raiz, int ch){
    if(raiz!=NULL){
        if(ch < raiz -> dado){
            raiz -> esq = insert(raiz -> esq,ch);
            printf("inseriu %d a esquerda de %d\n",ch,raiz->dado);
        } else if(ch > raiz -> dado){
            printf("inseriu %d a direita de %d\n",ch,raiz->dado);
            raiz -> dir = insert(raiz -> dir,ch);
        }
        return raiz;
    } else{
        celula *novo = malloc(sizeof(celula));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->dado = ch;
        return novo;
    }
}

/*
Para a remoção de uma celula na árvore, tem que seguir alguns criterios:
1 - se for folha basta remover!
2 - Se tiver só uma subávore (esquerda ou direita), basta conectar a subárovre no pai
3 - Se houver subárvores esquerda e direita, troca o valor do nó com seu antecessor e remove o nó que era antecessor pelos casos 1 ou 2.

*/
void remover_antecessor(celula *raiz){
    celula *pai = raiz;
    celula *max = raiz->esq;
    while (max -> dir != NULL){
        pai = max;
        max = max -> dir;
    }
    raiz->dado = max->dado;
    if (max == pai -> esq){
        pai -> esq = max -> esq;
    }else{
        pai -> dir = max -> esq;
    }
    free(max);
}
celula *remover(celula *raiz, int ch){
    if(raiz == NULL){
        return NULL; // Elemento não encontrado
    }
    
    if(ch < raiz->dado){ 
        raiz->esq = remover(raiz->esq, ch);
    }
    else if(ch > raiz->dado){
        raiz->dir = remover(raiz->dir, ch);
    }
    else{ // Encontrou o nó a ser removido
        printf("removido %d\n", ch);
        
        if(raiz->esq == NULL){ 
            celula *ret = raiz->dir; 
            free(raiz); 
            return ret;
        }
        else if (raiz->dir == NULL){
            celula *ret = raiz->esq;
            free(raiz);
            return ret;
        }
        else{
            remover_antecessor(raiz);
        }
    }
    return raiz;
}

celula *buscaABB(celula *raiz, int ch){
    if(raiz != NULL){
        if(ch < raiz->dado){
            return buscaABB(raiz->esq, ch); 
        }
        else if(ch > raiz->dado){
            return buscaABB(raiz->dir, ch);
        }
        else { // ch == raiz->dado - ENCONTROU!
            return raiz;
        }
    }
    return NULL; // Elemento não encontrado
}

int altura(celula *raiz){
    if(raiz!=NULL){
        int he = altura(raiz->esq);
        int hd = altura(raiz->dir);
        if(he>hd){
            return he+1;
        }
        else{
            return hd+1;
        }
    }else{
        return -1;
    }
}

celula *maximo(celula *raiz){
    if(raiz != NULL){
        while(raiz -> dir != NULL){
            raiz = raiz->dir;
        }
        return raiz;
    }
    return NULL;
}

void treePrint(celula *raiz){
    if(raiz != NULL){
        printf("%d",raiz->dado);
        printf("\n");
        treePrint(raiz->esq);
        treePrint(raiz ->dir);
    }
}

void treeFree(celula *raiz){
    if(raiz != NULL){
        treeFree(raiz->esq);
        treeFree(raiz->dir);
        free(raiz);
    }
}

int main(){
    celula *raiz = treeInitializer();
    raiz = insert(raiz, 10); 
    raiz = insert(raiz, 5);
    raiz = insert(raiz, 15);
    raiz = insert(raiz, 26);
    raiz = insert(raiz, 555555);
    raiz = insert(raiz, 1);

    raiz = remover(raiz,26);
    raiz = insert(raiz, 222);
    treePrint(raiz);
    int caso = 100;
    celula *resultado = buscaABB(raiz, caso);
    if (resultado != NULL) {
        printf("Elemento %i encontrado!\n",caso);
    } else {
        printf("Elemento %i não encontrado!\n", caso);
    }
    int valor = altura(raiz);
    printf("altura da árvore: %i\n", valor);
    treePrint(raiz);
    celula *valorMaximo = maximo(raiz);
    if(valorMaximo != NULL){
        printf("O valor mais alto da árvore é %i\n", valorMaximo->dado); 
    }
    treeFree(raiz);
    return 0;
}