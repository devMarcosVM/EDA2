#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    // N = número de agentes, T = número de relações de confiança
    if (cin >> N >> T) {
        
        // Criamos dois vetores para contar os graus.
        // Tamanho N+1 para usar índices de 1 a N.
        // Inicializamos com 0.
        vector<int> grau_entrada(N + 1, 0); // Quantos confiam nele (in-degree)
        vector<int> grau_saida(N + 1, 0);   // Em quantos ele confia (out-degree)

        for (int i = 0; i < T; i++) {
            int a, b;
            cin >> a >> b; // "a" confia em "b" (a -> b)

            // 'a' está emitindo confiança (seta saindo)
            grau_saida[a]++;
            
            // 'b' está recebendo confiança (seta entrando)
            grau_entrada[b]++;
        }

        int agente_duplo = -1; // Começa com -1 (caso não encontre ninguém)

        // Verifica cada agente de 1 a N
        for (int i = 1; i <= N; i++) {
            // Regra 1: Todos os outros (N-1) confiam nele
            // Regra 2: Ele confia em 0 pessoas
            if (grau_entrada[i] == N - 1 && grau_saida[i] == 0) {
                agente_duplo = i;
                break; // Achamos! Podemos parar.
            }
        }

        cout << agente_duplo << "\n";
    }

    return 0;
}