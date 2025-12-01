#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    
    // grau_entrada[i] = quantos agentes confiam em i
    // grau_saida[i] = em quantos agentes i confia
    int *grau_entrada = (int *)calloc(N + 1, sizeof(int));
    int *grau_saida = (int *)calloc(N + 1, sizeof(int));
    
    for (int i = 0; i < T; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        // A confia em B (A envia informação para B)
        grau_saida[A]++;
        grau_entrada[B]++;
    }
    
    int agente_duplo = -1;
    
    for (int i = 1; i <= N; i++) {
        // Agente duplo: não confia em ninguém (saída = 0)
        // e todos os outros confiam nele (entrada = N-1)
        if (grau_saida[i] == 0 && grau_entrada[i] == N - 1) {
            agente_duplo = i;
            break;
        }
    }
    
    printf("%d\n", agente_duplo);
    
    free(grau_entrada);
    free(grau_saida);
    
    return 0;
}
