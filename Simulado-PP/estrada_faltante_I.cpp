#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N, M;
    cin >> N >> M;
    
    // Ler as M estradas existentes (não precisamos armazená-las)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
    }
    
    // Grafo completo tem N*(N-1)/2 arestas
    // Estradas faltantes = total possível - estradas existentes
    long long total_possivel = (N * (N - 1)) / 2;
    long long faltantes = total_possivel - M;
    
    cout << faltantes << endl;
    
    return 0;
}
