#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 105

char labirinto[MAX][MAX];
int dist[MAX][MAX];
int M, N;

// Direções: cima, baixo, esquerda, direita
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

typedef struct {
    int x, y;
} Ponto;

Ponto fila[MAX * MAX];
int inicio, fim;

void inicializaFila() {
    inicio = fim = 0;
}

void enfileira(int x, int y) {
    fila[fim].x = x;
    fila[fim].y = y;
    fim++;
}

Ponto desenfileira() {
    return fila[inicio++];
}

bool filaVazia() {
    return inicio == fim;
}

bool ehBorda(int x, int y) {
    return x == 0 || x == M - 1 || y == 0 || y == N - 1;
}

bool ehValido(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int bfs(int inicioX, int inicioY) {
    // Inicializa distâncias com -1 (não visitado)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = -1;
        }
    }
    
    inicializaFila();
    enfileira(inicioX, inicioY);
    dist[inicioX][inicioY] = 0;
    
    while (!filaVazia()) {
        Ponto atual = desenfileira();
        int x = atual.x;
        int y = atual.y;
        
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
                enfileira(nx, ny);
            }
        }
    }
    
    return -1; // Não encontrou saída
}

int main() {
    int X, Y;
    
    scanf("%d %d", &M, &N);
    
    for (int i = 0; i < M; i++) {
        scanf("%s", labirinto[i]);
    }
    
    scanf("%d %d", &X, &Y);
    
    // Verifica se a posição inicial é válida
    if (labirinto[X][Y] == '+') {
        printf("-1\n");
        return 0;
    }
    
    int resultado = bfs(X, Y);
    printf("%d\n", resultado);
    
    return 0;
}
