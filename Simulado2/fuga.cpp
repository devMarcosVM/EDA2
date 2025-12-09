#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, T;
    cin >> N >> M >> T;
    
    vector<string> mapa(N);
    for (int i = 0; i < N; i++) {
        cin >> mapa[i];
    }
    
    // BFS para encontrar o menor caminho
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> fila;
    
    // Começa em (0,0) - índice 0-based
    if (mapa[0][0] == '.') {
        dist[0][0] = 0;
        fila.push({0, 0});
    }
    
    // Direções: cima, baixo, esquerda, direita
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!fila.empty()) {
        auto [x, y] = fila.front();
        fila.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // Verifica se está dentro dos limites
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                // Verifica se é corredor livre e não foi visitado
                if (mapa[nx][ny] == '.' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    fila.push({nx, ny});
                }
            }
        }
    }
    
    // Destino é (N-1, M-1) em índice 0-based
    int custoMinimo = dist[N-1][M-1];
    
    if (custoMinimo == -1) {
        // Não existe caminho
        cout << "IMPOSSIVEL" << endl;
    } else if (custoMinimo <= T) {
        // Existe caminho e cabe no tempo
        cout << "POSSIVEL" << endl;
    } else {
        // Existe caminho mas não cabe no tempo
        cout << "NEM A PAU JUVENAL" << endl;
    }
    
    return 0;
}
