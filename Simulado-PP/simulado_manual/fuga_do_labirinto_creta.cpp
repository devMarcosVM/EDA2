#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105; 

string labirinto[MAXN];
int dist[MAXN][MAXN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int M, N;
    if (cin >> M >> N) {
        
        // 1. Ler o Labirinto
        for (int i = 0; i < M; i++) {
            cin >> labirinto[i]; 

            for (int j = 0; j < N; j++) {
                dist[i][j] = -1;
            }
        }

        int startX, startY;
        cin >> startX >> startY;
        queue<pair<int, int>> q;
        
        q.push({startX, startY});
        dist[startX][startY] = 0;

        int resposta = -1;

        while (!q.empty()) {
            pair<int, int> atual = q.front();
            q.pop();

            int x = atual.first;
            int y = atual.second;

            bool naBorda = (x == 0 || x == M-1 || y == 0 || y == N-1);
            bool ehInicio = (x == startX && y == startY);

            if (naBorda && !ehInicio) {
                resposta = dist[x][y];
                break;
            }

            // 3. Tenta andar para as 4 direções
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i]; 
                int ny = y + dy[i]; 
                // a) Está dentro do mapa?
                if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                    // b) Não é parede ('+')?
                    if (labirinto[nx][ny] != '+') {
                        // c) Ainda não foi visitado (distancia é -1)?
                        if (dist[nx][ny] == -1) {
                            
                            // Se passou em tudo, dá o passo!
                            dist[nx][ny] = dist[x][y] + 1; // Distância anterior + 1
                            q.push({nx, ny}); // Adiciona na fila para processar depois
                        }
                    }
                }
            }
        }

        cout << resposta << "\n";
    }

    return 0;
}