#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int s, t;
    string cor;
    cin >> s >> cor >> t;
    
    // Se distância for par, mesma cor; se ímpar, cor oposta
    vector<int> dist(n + 1, -1);
    queue<int> fila;
    
    fila.push(s);
    dist[s] = 0;
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
    if (dist[t] % 2 == 0) {
        cout << cor << endl;
    } else {
        // Cor oposta
        if (cor == "PRETA") {
            cout << "VERMELHA" << endl;
        } else {
            cout << "PRETA" << endl;
        }
    }
    
    return 0;
}
