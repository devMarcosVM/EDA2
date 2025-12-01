#include <stdio.h>

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    
    // Ler as M estradas (não precisamos armazenar, só consumir a entrada)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
    }
    
    // Grafo completo tem N*(N-1)/2 arestas
    // Estradas faltantes = total possível - existentes
    long long total = (n * (n - 1)) / 2;
    long long faltantes = total - m;
    
    printf("%lld\n", faltantes);
    
    return 0;
}
