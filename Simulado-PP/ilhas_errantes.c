#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXK 405

// Estruturas para o grafo (lista de adjacência)
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

// Min-Heap para ordenação topológica com prioridade
typedef struct {
    int* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->data[parent] > heap->data[idx]) {
            swap(&heap->data[parent], &heap->data[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    while (1) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        
        if (left < heap->size && heap->data[left] < heap->data[smallest])
            smallest = left;
        if (right < heap->size && heap->data[right] < heap->data[smallest])
            smallest = right;
        
        if (smallest != idx) {
            swap(&heap->data[smallest], &heap->data[idx]);
            idx = smallest;
        } else {
            break;
        }
    }
}

void heapPush(MinHeap* heap, int val) {
    heap->data[heap->size] = val;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int heapPop(MinHeap* heap) {
    int val = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return val;
}

int heapEmpty(MinHeap* heap) {
    return heap->size == 0;
}

void freeHeap(MinHeap* heap) {
    free(heap->data);
    free(heap);
}

// Adiciona aresta ao grafo
void addEdge(AdjList* adj, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = adj[src].head;
    adj[src].head = newNode;
}

// Ordenação topológica com min-heap (Kahn's algorithm)
// Retorna 1 se sucesso, 0 se há ciclo
int topologicalSort(AdjList* adj, int* inDegree, int K, int* result) {
    MinHeap* heap = createHeap(K + 1);
    int count = 0;
    
    // Adiciona todos os nós com grau de entrada 0
    for (int i = 1; i <= K; i++) {
        if (inDegree[i] == 0) {
            heapPush(heap, i);
        }
    }
    
    while (!heapEmpty(heap)) {
        int u = heapPop(heap);
        result[count++] = u;
        
        Node* curr = adj[u].head;
        while (curr != NULL) {
            int v = curr->dest;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                heapPush(heap, v);
            }
            curr = curr->next;
        }
    }
    
    freeHeap(heap);
    return count == K;
}

void freeGraph(AdjList* adj, int K) {
    for (int i = 1; i <= K; i++) {
        Node* curr = adj[i].head;
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main() {
    int K, L, C;
    
    scanf("%d", &K);
    
    // Grafos para restrições de linha e coluna
    AdjList* rowAdj = (AdjList*)calloc(K + 1, sizeof(AdjList));
    AdjList* colAdj = (AdjList*)calloc(K + 1, sizeof(AdjList));
    int* rowInDegree = (int*)calloc(K + 1, sizeof(int));
    int* colInDegree = (int*)calloc(K + 1, sizeof(int));
    
    // Lê restrições de latitude (linhas)
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        int acima, abaixo;
        scanf("%d %d", &acima, &abaixo);
        addEdge(rowAdj, acima, abaixo);
        rowInDegree[abaixo]++;
    }
    
    // Lê restrições de longitude (colunas)
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        int esquerda, direita;
        scanf("%d %d", &esquerda, &direita);
        addEdge(colAdj, esquerda, direita);
        colInDegree[direita]++;
    }
    
    // Ordena topologicamente para linhas e colunas
    int* rowOrder = (int*)malloc((K + 1) * sizeof(int));
    int* colOrder = (int*)malloc((K + 1) * sizeof(int));
    
    int rowOk = topologicalSort(rowAdj, rowInDegree, K, rowOrder);
    int colOk = topologicalSort(colAdj, colInDegree, K, colOrder);
    
    if (!rowOk || !colOk) {
        printf("IMPOSSIVEL\n");
    } else {
        // Mapeia cada ilha para sua linha e coluna
        int* islandRow = (int*)malloc((K + 1) * sizeof(int));
        int* islandCol = (int*)malloc((K + 1) * sizeof(int));
        
        for (int i = 0; i < K; i++) {
            islandRow[rowOrder[i]] = i;
            islandCol[colOrder[i]] = i;
        }
        
        // Constrói e imprime a grade
        int** grid = (int**)malloc(K * sizeof(int*));
        for (int i = 0; i < K; i++) {
            grid[i] = (int*)calloc(K, sizeof(int));
        }
        
        for (int island = 1; island <= K; island++) {
            int r = islandRow[island];
            int c = islandCol[island];
            grid[r][c] = island;
        }
        
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (j > 0) printf(" ");
                printf("%d", grid[i][j]);
            }
            printf("\n");
        }
        
        // Libera memória da grade
        for (int i = 0; i < K; i++) {
            free(grid[i]);
        }
        free(grid);
        free(islandRow);
        free(islandCol);
    }
    
    // Libera memória
    freeGraph(rowAdj, K);
    freeGraph(colAdj, K);
    free(rowAdj);
    free(colAdj);
    free(rowInDegree);
    free(colInDegree);
    free(rowOrder);
    free(colOrder);
    
    return 0;
}
