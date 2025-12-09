#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

// Variáveis Globais (para serem vistas por todas as funções)
int N, M, T;
char prisao[MAXN][MAXN];
int dist[MAXN][MAXN]; // Substitui o 'visited' e guarda o tempo

// Direções: cima, baixo, esquerda, direita
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ehValido(int x, int y) {
    // Verifica limites do mapa
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs() {
    queue<pair<int,int>> fila;
    // Começa na posição (0,0) 
    fila.push({0,0});
    dist[0][0] = 0; // Tempo inicial é 0

    while(!fila.empty()){
        auto [x,y] = fila.front();
        fila.pop();

        // 2. Verifica se chegou ao destino (N-1, M-1)
        if(x == N-1 && y == M-1){   
            return dist[x][y]; // Retorna o tempo que levou pra chegar aqui
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 3. Regras de Movimento:
            if(ehValido(nx,ny) && prisao[nx][ny] == '.' && dist[nx][ny] == -1){
                
                // A distância do vizinho é a minha distância + 1 minuto 
                dist[nx][ny] = dist[x][y] + 1;
                fila.push({nx,ny});
            }
        }
    }
    
    return -1; // Se a fila esvaziar e não chegarmos, é impossível
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;

    for(int i = 0; i < N; i++){
        cin >> prisao[i];
        for(int j=0; j<M; j++){
            dist[i][j] = -1;
        }
    }

    int tempo_gasto = bfs();

    // Lógica de Saída conforme o PDF 
    if (tempo_gasto == -1) {
        // Não existe caminho (paredes bloqueiam tudo)
        cout << "IMPOSSIVEL" << '\n';
    } 
    else if (tempo_gasto <= T) {
        // Existe caminho e dá tempo
        cout << "POSSIVEL" << '\n';
    } 
    else {
        // Existe caminho, mas demora demais (tempo_gasto > T)
        cout << "NEM A PAU JUVENAL" << '\n';
    }

    return 0;
}