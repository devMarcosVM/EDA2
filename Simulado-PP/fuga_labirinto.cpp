#include <bits/stdc++.h>
using namespace std;

int M, N;
char labirinto[105][105];
int dist[105][105];

// Direções: cima, baixo, esquerda, direita
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ehBorda(int x, int y) {
    return x == 0 || x == M - 1 || y == 0 || y == N - 1;
}

bool ehValido(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int bfs(int inicioX, int inicioY) {
    // Inicializa distâncias com -1 (não visitado)
    memset(dist, -1, sizeof(dist));
    
    queue<pair<int, int>> fila;
    fila.push({inicioX, inicioY});
    dist[inicioX][inicioY] = 0;
    
    while (!fila.empty()) {
        auto [x, y] = fila.front();
        fila.pop();
        
        // Verifica se chegou em uma saída (borda) diferente da posição inicial
        if (ehBorda(x, y) && dist[x][y] > 0) {
            return dist[x][y];
        }
        
        // Explora vizinhos
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (ehValido(nx, ny) && labirinto[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                fila.push({nx, ny});
            }
        }
    }
    
    return -1; // Não encontrou saída
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int X, Y;
    
    cin >> M >> N;
    
    for (int i = 0; i < M; i++) {
        cin >> labirinto[i];
    }
    
    cin >> X >> Y;
    
    // Verifica se a posição inicial é válida
    if (labirinto[X][Y] == '+') {
        cout << -1 << endl;
        return 0;
    }
    
    int resultado = bfs(X, Y);
    cout << resultado << endl;
    
    return 0;
}
