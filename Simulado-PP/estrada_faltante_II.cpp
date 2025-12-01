#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // Usar um set para armazenar as estradas existentes
    set<pair<int, int>> estradas;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // Garantir que o menor vem primeiro
        if (u > v) swap(u, v);
        estradas.insert({u, v});
    }
    
    // Listar todos os pares faltantes (a, b) com a < b
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            if (estradas.find({a, b}) == estradas.end()) {
                cout << a << " " << b << "\n";
            }
        }
    }
    
    return 0;
}
