#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, T;
    cin >> N >> T;
    
    // grauEntrada[i] = quantos agentes confiam no agente i
    // grauSaida[i] = em quantos agentes o agente i confia
    vector<int> grauEntrada(N + 1, 0);
    vector<int> grauSaida(N + 1, 0);
    
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        // A confia em B (A envia informações para B)
        grauSaida[A]++;
        grauEntrada[B]++;
    }
    
    int agenteDuplo = -1;
    
    for (int i = 1; i <= N; i++) {
        // O Agente Duplo:
        // 1. Não confia em ninguém (grauSaida = 0)
        // 2. Todos os outros N-1 agentes confiam nele (grauEntrada = N-1)
        if (grauSaida[i] == 0 && grauEntrada[i] == N - 1) {
            agenteDuplo = i;
            break;
        }
    }
    
    cout << agenteDuplo << endl;
    
    return 0;
}
