#include <bits/stdc++.h> // 1. O "include" mágico que carrega tudo
using namespace std;

const int MAXN = 3005; // Defina um tamanho um pouco maior que o N máximo do problema (3000)

// 2. A LISTA DE ADJACÊNCIA
// Criamos um array onde cada posição tem um vetor (uma lista dinâmica).
vector<int> adj[MAXN]; 

int main() {
    // Otimização de leitura (padrão em C++)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    
    // 3. LER N E M
    // O problema diz: "A primeira linha contém dois inteiros N e M"
    if (cin >> N >> M) {
        
        // Antes de começar, é bom limpar o grafo (boa prática se tiver múltiplos casos de teste)
        for(int i = 0; i <= N; i++) {
            adj[i].clear();
        }

        // 4. O LOOP DE LEITURA DAS ARESTAS
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v; // Lê a conexão entre cidade 'u' e 'v'

            // 5. GUARDAR NOS VETORES
            // Como é mão dupla (bidirecional):
            // O vizinho de 'u' é 'v'
            adj[u].push_back(v); 
            
            // E o vizinho de 'v' é 'u'
            adj[v].push_back(u); 
        }

        // --- FIM DA MONTAGEM ---
        
        // TESTE (Só para você visualizar o que aconteceu):
        cout << "Grafo montado! Vamos ver os vizinhos:" << endl;
        for (int i = 1; i <= N; i++) {
            cout << "Cidade " << i << " está conectada a: ";
            for (int vizinho : adj[i]) { // "Para cada vizinho na lista de i"
                cout << vizinho << " ";
            }
            cout << endl;
        }
    }

    return 0;
}