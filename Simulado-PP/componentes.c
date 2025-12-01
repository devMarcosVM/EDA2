#include <stdio.h>

#define MAXN 105

int pai[MAXN];

// Encontra o representante do conjunto (com compressão de caminho)
int find(int x) {
    if (pai[x] != x) {
        pai[x] = find(pai[x]);
    }
    return pai[x];
}

// Une dois conjuntos
void unir(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) {
        pai[pa] = pb;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // Inicializa: cada vértice é seu próprio pai
    for (int i = 1; i <= N; i++) {
        pai[i] = i;
    }
    
    // Lê as arestas e une os vértices
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        unir(u, v);
    }
    
    // Conta quantos componentes conexos existem
    int componentes = 0;
    for (int i = 1; i <= N; i++) {
        if (find(i) == i) {
            componentes++;
        }
    }
    
    printf("%d\n", componentes);
    
    return 0;
}
