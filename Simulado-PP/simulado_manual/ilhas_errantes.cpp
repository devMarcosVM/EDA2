#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;

// Função que resolve a ordem para UMA dimensão (seja linhas ou colunas)
// Retorna um vetor onde vetor[i] é a posição da ilha 'i+1'
vector<int> resolverOrdem(int K, int numRegras, vector<pair<int, int>>& regras) {
    
    // 1. Montar o Grafo e contar Graus de Entrada
    vector<int> adj[MAXN];
    vector<int> grau_entrada(K + 1, 0);

    for (auto p : regras) {
        int u = p.first;
        int v = p.second;
        adj[u].push_back(v); // u deve vir antes de v
        grau_entrada[v]++;   // v tem uma dependência
    }

    // 2. Fila de Prioridade (Min-Heap)
    // Guarda quem tem Grau 0 (livres para serem colocados). 
    // O "greater" faz o menor número sair primeiro 
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= K; i++) {
        if (grau_entrada[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> resultado; // Guarda a ordem: quem ficou na posição 0, 1, 2...
    // 3. Processar (Kahn's Algorithm)
    while (!pq.empty()) {
        int u = pq.top(); // Pega a ilha disponível com menor ID
        pq.pop();
        resultado.push_back(u);
        // "Remove" essa ilha e avisa os vizinhos
        for (int v : adj[u]) {
            grau_entrada[v]--; // Uma dependência a menos
            if (grau_entrada[v] == 0) {
                pq.push(v); // Agora v está livre!
            }
        }
    }

    // Se não conseguimos colocar todas as K ilhas, houve um ciclo (impossível)
    if (resultado.size() < K) return {}; 

    // O vetor 'resultado' diz: "Na posição 0 está a ilha X".
    // Mas nós queremos saber: "A ilha X está em qual posição?"
    // Vamos inverter esse mapa para facilitar o preenchimento da matriz.
    vector<int> posicaoReal(K + 1);
    for (int i = 0; i < K; i++) {
        int ilha = resultado[i];
        posicaoReal[ilha] = i; // A 'ilha' ficou no índice 'i'
    }
    
    return posicaoReal;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int K;
    if (cin >> K) { // Lê o número de ilhas
        
        // --- LEITURA DAS REGRAS DE LINHA (NORTE) ---
        int L; cin >> L;
        vector<pair<int, int>> regrasNorte;
        for(int i=0; i<L; i++) {
            int u, v; cin >> u >> v;
            regrasNorte.push_back({u, v});
        }

        // --- LEITURA DAS REGRAS DE COLUNA (OESTE) ---
        int C; cin >> C;
        vector<pair<int, int>> regrasOeste;
        for(int i=0; i<C; i++) {
            int u, v; cin >> u >> v;
            regrasOeste.push_back({u, v});
        }

        // --- RESOLVER AS DUAS DIMENSÕES SEPARADAMENTE ---
        vector<int> linhas = resolverOrdem(K, L, regrasNorte);
        vector<int> colunas = resolverOrdem(K, C, regrasOeste);

        // Se alguma deu errado (ciclo), é impossível
        if (linhas.empty() || colunas.empty()) {
            cout << "IMPOSSIVEL\n";
        } else {
            // --- MONTAR A GRADE FINAL ---
            // Criamos uma matriz K x K preenchida com 0
            vector<vector<int>> grid(K, vector<int>(K, 0));

            for (int i = 1; i <= K; i++) {
                int r = linhas[i];  // Qual linha a ilha 'i' ficou?
                int c = colunas[i]; // Qual coluna a ilha 'i' ficou?
                grid[r][c] = i;     // Coloca a ilha lá
            }

            // Imprimir a matriz
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    cout << grid[i][j] << (j == K-1 ? "" : " ");
                }
                cout << "\n";
            }
        }
    }
    return 0;
}