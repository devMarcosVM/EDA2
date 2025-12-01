#include <iostream>
using namespace std;

const int MAXN = 105;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // Inicializa: cada vértice é seu próprio pai
    for (int i = 1; i <= N; i++) {
        pai[i] = i;
    }
    
    // Lê as arestas e une os vértices
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        unir(u, v);
    }
    
    // Conta quantos componentes conexos existem
    int componentes = 0;
    for (int i = 1; i <= N; i++) {
        if (find(i) == i) {
            componentes++;
        }
    }
    
    cout << componentes << endl;
    
    return 0;
}
