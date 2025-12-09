#include <stdio.h>   // Biblioteca para funções de entrada e saída (printf, scanf)
#include <stdlib.h>  // Biblioteca para alocação de memória (malloc, free)

// Estrutura que representa um heap máximo (priority queue)
typedef struct Heap {
    int size;  // Número atual de elementos no heap
    int* v;    // Ponteiro para array que armazena os elementos do heap (índice 0 não é usado)
} Heap;

/*
 * Função que cria e inicializa um novo heap vazio
 * Parâmetro: capacity - capacidade máxima do heap
 * Retorna: ponteiro para o heap criado na memória
 */
Heap* createHeap(int capacity) {
    Heap* heap = malloc(sizeof(Heap));                    // Aloca memória para a estrutura Heap
    heap->size = 0;                                       // Inicializa o tamanho como 0 (heap vazio)
    heap->v = malloc((capacity + 1) * sizeof(int));       // Aloca array com capacity+1 posições (índice 0 não usado)

    return heap;                                          // Retorna ponteiro para o heap criado
}

/*
 * Função recursiva que mantém a propriedade de heap máximo "subindo" um elemento
 * Usado após inserção para garantir que o pai seja sempre maior que os filhos
 * Parâmetros: h - ponteiro para o heap, i - índice do elemento a ser ajustado
 */
void fixUp(Heap* h, int i) {
    if (i <= 1) return;                                   // Caso base: se chegou na raiz (índice 1) ou inválido, para a recursão
    int parent = i/2;                                     // Calcula índice do pai (i/2 em heap baseado em array)
    if (h->v[parent] < h->v[i]) {                        // Se pai é menor que filho atual, viola propriedade do heap máximo
        int tmp = h->v[parent];                          // Armazena valor do pai temporariamente
        h->v[parent] = h->v[i];                          // Move valor do filho para posição do pai
        h->v[i] = tmp;                                   // Move valor do pai para posição do filho (troca completa)
    }
    fixUp(h, parent);                                     // Chama recursivamente para verificar o pai (sobe na árvore)
}

/*
 * Versão iterativa da função fixUp (mesmo comportamento, mas sem recursão)
 * Mais eficiente em termos de memória por não usar pilha de chamadas
 * Parâmetros: h - ponteiro para o heap, i - índice do elemento a ser ajustado
 */
void fixUpIterativo(Heap* h, int i) {
    while (i > 1 && h->v[i/2] < h->v[i]) {              // Enquanto não chegou na raiz E pai é menor que filho
        int tmp = h->v[i/2];                             // Armazena valor do pai temporariamente
        h->v[i/2] = h->v[i];                             // Move valor do filho para posição do pai
        h->v[i] = tmp;                                   // Move valor do pai para posição do filho (troca completa)

        i /= 2;                                          // Move para o pai (sobe um nível na árvore)
    }
}

/*
 * Função que insere um novo elemento no heap
 * Mantém a propriedade de heap máximo após a inserção
 * Parâmetros: h - ponteiro para o heap, x - valor a ser inserido
 */
void insert(Heap* h, int x) {
    h->v[++h->size] = x;                                 // Incrementa tamanho e insere elemento na última posição
    fixUp(h, h->size);                                   // Ajusta heap subindo o elemento recém-inserido se necessário
}

/*
 * Função que mantém a propriedade de heap máximo "descendo" um elemento
 * Usado após remoção do elemento raiz para rebalancear o heap
 * Parâmetros: h - ponteiro para o heap, i - índice do elemento a ser ajustado
 */
void fixDown(Heap* h, int i) {
    int child;                                           // Variável para armazenar índice do filho
    while(i * 2 <= h->size) {                          // Enquanto o nó atual tem pelo menos um filho (filho esquerdo)
        child = i * 2;                                   // Filho esquerdo está no índice 2*i
        if (child != h->size && h->v[child] < h->v[child +1]) {  // Se existe filho direito E filho esquerdo < filho direito
            child++;                                     // Escolhe o filho direito (maior dos dois filhos)
        }
        if (h->v[i] < h->v[child]) {                    // Se pai atual é menor que o maior filho
            int tmp = h->v[i];                           // Armazena valor do pai temporariamente
            h->v[i] = h->v[child];                       // Move valor do filho para posição do pai
            h->v[child] = tmp;                           // Move valor do pai para posição do filho (troca completa)
            i = child;                                   // Move para posição do filho (desce um nível na árvore)
        } else return;                                   // Se propriedade está satisfeita, termina
    }
}

/*
 * Função que remove o elemento de maior prioridade (raiz) do heap
 * Move o último elemento para a raiz e rebalanceia o heap
 * Parâmetro: h - ponteiro para o heap
 */
void pop(Heap* h) {
    int tmp = h->v[1];                                   // Armazena o elemento raiz (maior prioridade) que será removido
    h->v[1] = h->v[h->size];                            // Move último elemento para a raiz
    h->v[h->size] = tmp;                                // Move elemento removido para última posição (opcional)
    h->size--;                                          // Diminui o tamanho do heap (remove logicamente o último elemento)
    fixDown(h,1);                                       // Rebalanceia heap descendo o novo elemento raiz
    printf("%d was removed from pq\n", tmp);           // Informa qual elemento foi removido
}

/*
 * Função que retorna o elemento de maior prioridade sem removê-lo
 * Em um heap máximo, este é sempre o elemento raiz (índice 1)
 * Parâmetro: h - ponteiro para o heap
 * Retorna: valor do elemento de maior prioridade
 */
int peek(Heap* h) {
    return h->v[1];                                     // Retorna elemento na posição raiz (maior elemento)
}

/*
 * Função principal que demonstra o uso da estrutura heap
 * Cria um heap, insere elementos, mostra operações de peek e pop
 */
int main() {
    Heap* pq = createHeap(100);                         // Cria um heap com capacidade para 100 elementos
    insert(pq, 10);                                     // Insere elemento 10 no heap
    insert(pq, 20);                                     // Insere elemento 20 no heap
    insert(pq, 30);                                     // Insere elemento 30 no heap
    insert(pq, 40);                                     // Insere elemento 40 no heap (será a nova raiz - maior elemento)
    printf("%d has the highest priority\n", peek(pq)); // Mostra o elemento de maior prioridade (40)
    pop(pq);                                            // Remove elemento de maior prioridade (40)
    pop(pq);                                            // Remove próximo elemento de maior prioridade (30)
    printf("%d has the highest priority\n", peek(pq)); // Mostra novo elemento de maior prioridade (20)

    return 0;                                           // Indica execução bem-sucedida do programa
}