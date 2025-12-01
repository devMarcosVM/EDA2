#include <bits/stdc++.h>
using namespace std;

// Ordenação topológica com min-heap (Kahn's algorithm)
// Retorna vetor vazio se há ciclo
vector<int> topologicalSort(vector<vector<int>>& adj, vector<int> inDegree, int K) {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    vector<int> result;
    
    // Adiciona todos os nós com grau de entrada 0
    for (int i = 1; i <= K; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }
    
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);
        
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    
    // Se não processou todos os nós, há ciclo
    if ((int)result.size() != K) {
        return {};
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K, L, C;
    cin >> K;
    
    // Grafos para restrições de linha e coluna
    vector<vector<int>> rowAdj(K + 1), colAdj(K + 1);
    vector<int> rowInDegree(K + 1, 0), colInDegree(K + 1, 0);
    
    // Lê restrições de latitude (linhas)
    cin >> L;
    for (int i = 0; i < L; i++) {
        int acima, abaixo;
        cin >> acima >> abaixo;
        rowAdj[acima].push_back(abaixo);
        rowInDegree[abaixo]++;
    }
    
    // Lê restrições de longitude (colunas)
    cin >> C;
    for (int i = 0; i < C; i++) {
        int esquerda, direita;
        cin >> esquerda >> direita;
        colAdj[esquerda].push_back(direita);
        colInDegree[direita]++;
    }
    
    // Ordena topologicamente para linhas e colunas
    vector<int> rowOrder = topologicalSort(rowAdj, rowInDegree, K);
    vector<int> colOrder = topologicalSort(colAdj, colInDegree, K);
    
    if (rowOrder.empty() || colOrder.empty()) {
        cout << "IMPOSSIVEL" << endl;
    } else {
        // Mapeia cada ilha para sua linha e coluna
        vector<int> islandRow(K + 1), islandCol(K + 1);
        
        for (int i = 0; i < K; i++) {
            islandRow[rowOrder[i]] = i;
            islandCol[colOrder[i]] = i;
        }
        
        // Constrói a grade KxK
        vector<vector<int>> grid(K, vector<int>(K, 0));
        
        for (int island = 1; island <= K; island++) {
            int r = islandRow[island];
            int c = islandCol[island];
            grid[r][c] = island;
        }
        
        // Imprime a grade
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (j > 0) cout << " ";
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
    
    return 0;
}
