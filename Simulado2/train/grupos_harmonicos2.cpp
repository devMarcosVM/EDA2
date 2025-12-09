#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int cor[100005]; // -1 = não visitado, 0 ou 1 = cor atribuída

bool bfs(int inicio) {
    queue<int> fila;
    fila.push(inicio);
    cor[inicio] = 0;
    
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        
        for (int v : adj[u]) {
            if (cor[v] == -1) {
                // Vizinho não visitado, atribui cor oposta
                cor[v] = 1 - cor[u];
                fila.push(v);
            } else if (cor[v] == cor[u]) {
                // Conflito: vizinho tem a mesma cor
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // Inicializa cores como não visitadas
    memset(cor, -1, sizeof(cor));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool bipartido = true;
    
    // Verifica cada componente conexa (grafo pode ser desconexo)
    for (int i = 0; i < n && bipartido; i++) {
        if (cor[i] == -1) {
            bipartido = bfs(i);
        }
    }
    
    if (bipartido) {
        cout << "Sim" << endl;
    } else {
        cout << "Nao" << endl;
    }
    
    return 0;
}
