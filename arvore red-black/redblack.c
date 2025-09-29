#include <stdio.h>
#include <stdlib.h>
/*

Conceito:
1- Todo nó é vermelho ou preto
2- A raiz é preta
3- As folhas são NULL e da cor preta
4- Se um nó é vermelho
    -> é filho esquerdo de um nó preto
    -> seus filhos são pretos
    
5- Todo caminho de um nó às suas folhas descedentes possui a mesma quantidade de nós pretos - altura negra do nó

Condições de Correção:
1- Se o filho esquerdo e o filho direito de X forem vermelhos, subida de cor
2- Se o filho esquerdo for preto e o direito, vermelho, ROTAÇÃO À ESQUERDA
3- Se o filho esquerdo for vermelho e o filho esquerdo do filho esquerdo também, ROTAÇÃO A DIREITA.
*/

enum cor{VERM,PRETO};

typedef struct celula{
    int chave;
    enum cor cor;
    struct celula *esq, *dir;
} celula;

/*
 * Função: ehVerm
 * Propósito: Verifica se um nó é da cor vermelha
 * Parâmetro: a - ponteiro para o nó a ser verificado
 * Retorno: 1 se o nó for vermelho, 0 caso contrário
 */
int ehVerm(celula *a){
    if (a == NULL) return 0; // NULL é considerado preto
    if (a->cor == VERM) return 1;
    return 0;
}

/*
 * Função: ehPreto
 * Propósito: Verifica se um nó é da cor preta
 * Parâmetro: a - ponteiro para o nó a ser verificado
 * Retorno: 1 se o nó for preto ou NULL, 0 caso contrário
 */
int ehPreto(celula *a){
    if (a == NULL) return 1; // NULL é considerado preto
    if (a->cor == PRETO) return 1;
    return 0;
}

/*
 * Função: rotacao_direita
 * Propósito: Realiza rotação à direita para balancear a árvore Red-Black
 * Parâmetro: a - nó que será rotacionado (antiga raiz da subárvore)
 * Retorno: nova raiz da subárvore após a rotação
 * Funcionamento: O filho esquerdo de 'a' torna-se a nova raiz
 */
celula *rotacao_direita(celula *a){
    celula *b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    b->cor = a->cor;
    a->cor = VERM;
    return b;
}

/*
 * Função: rotacao_esquerda
 * Propósito: Realiza rotação à esquerda para balancear a árvore Red-Black
 * Parâmetro: a - nó que será rotacionado (antiga raiz da subárvore)
 * Retorno: nova raiz da subárvore após a rotação
 * Funcionamento: O filho direito de 'a' torna-se a nova raiz
 */
celula *rotacao_esquerda(celula *a){
    celula *b = a->dir;
    celula *beta = b->esq;
    b->esq = a;
    a->dir = beta;
    b->cor = a->cor;
    a->cor = VERM;
    return b;
}

/*
 * Função: subida_cor
 * Propósito: Realiza "subida de cor" quando ambos os filhos são vermelhos
 * Parâmetro: a - nó pai cujos filhos são vermelhos
 * Funcionamento: Troca as cores - pai fica vermelho, filhos ficam pretos
 * Isso mantém a altura negra e as propriedades da árvore Red-Black
 */
void subida_cor(celula *a){
    a->cor = VERM;
    a->esq->cor = a->dir->cor = PRETO;
}

/*
 * Função: insere
 * Propósito: Insere um novo elemento na árvore Red-Black (função recursiva interna)
 * Parâmetros: raiz - raiz da subárvore, x - valor a ser inserido
 * Retorno: raiz da subárvore após inserção e balanceamento
 * Funcionamento: Inserção recursiva com correções de balanceamento
 */
celula *insere(celula *raiz, int x){
    if(raiz != NULL){
        if(x < raiz->chave) raiz->esq = insere(raiz->esq, x);
        if(x > raiz->chave) raiz->dir = insere(raiz->dir, x);
        
        // Correções de balanceamento
        if (ehPreto(raiz->esq) && ehVerm(raiz->dir))
            raiz = rotacao_esquerda(raiz);
        if(ehVerm(raiz->esq) && ehVerm(raiz->esq) && ehVerm(raiz->esq->esq))
            raiz = rotacao_direita(raiz);
        if(ehVerm(raiz->esq) && ehVerm(raiz->dir))
            subida_cor(raiz);
        return raiz;
    }else{ // se raiz é == NULL
        celula *novo = malloc(sizeof(celula));
        novo->chave = x;
        novo->cor = VERM;
        novo->esq = novo->dir = NULL;
        return novo;
    }
}

/*
 * Função: insere_abb_rne
 * Propósito: Interface pública para inserção na árvore Red-Black
 * Parâmetros: raiz - raiz da árvore, x - valor a ser inserido
 * Retorno: nova raiz da árvore após inserção
 * Funcionamento: Chama a função insere e garante que a raiz seja preta
 */
celula *insere_abb_rne(celula *raiz, int x){
    raiz = insere(raiz, x);
    if(raiz != NULL) raiz->cor = PRETO; // A raiz sempre deve ser preta
    return raiz;
}

/*
 * Função: imprime_arvore
 * Propósito: Imprime a árvore em ordem (in-order traversal)
 * Parâmetro: raiz - raiz da árvore ou subárvore
 * Funcionamento: Percorre a árvore em ordem e exibe chave e cor de cada nó
 */
void imprime_arvore(celula *raiz){
    if(raiz != NULL){
        imprime_arvore(raiz->esq);
        printf("Chave: %d, Cor: %s\n", raiz->chave, 
               (raiz->cor == VERM) ? "VERMELHO" : "PRETO");
        imprime_arvore(raiz->dir);
    }
}

/*
 * Função: libera_arvore
 * Propósito: Libera toda a memória alocada para a árvore
 * Parâmetro: raiz - raiz da árvore a ser liberada
 */
void libera_arvore(celula *raiz){
    if(raiz != NULL){
        libera_arvore(raiz->esq);
        libera_arvore(raiz->dir);
        free(raiz);
    }
}

/*
 * Função: main
 * Propósito: Demonstra o uso da árvore Red-Black
 * Funcionamento: Cria uma árvore, insere valores e exibe o resultado
 */
int main(){
    celula *arvore = NULL;
    
    printf("=== Demonstração da Árvore Red-Black ===\n\n");
    
    // Inserindo valores na árvore
    int valores[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    printf("Inserindo valores: ");
    int teste = 3;
    for(int i = 0; i < n; i++){
        if(i%teste==0){
            printf("\n\nÁrvore atualmente\n");
            imprime_arvore(arvore);
            printf("\n");
        }
        printf("%d ", valores[i]);
        arvore = insere_abb_rne(arvore, valores[i]);
    }
    printf("\n\n");
    
    printf("Árvore Red-Black resultante (em ordem):\n");
    imprime_arvore(arvore);
    
    printf("\nInserção concluída com sucesso!\n");
    
    // Liberando memória
    libera_arvore(arvore);
    
    return 0;
}