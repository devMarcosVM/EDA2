#include <bits/stdc++.h>

using namespace std;

int H, W;
char conexo[55][55];
bool visited[105][105];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ehValido(int x, int y){
    return x>=0 && x<H && y>=0 && y < W;
}

int bfs(int x,int y){
    int contagem = 0;
    queue<pair<int, int>> fila;
    
    fila.push({x,y});
    contagem++;
    visited[x][y] = true;
     
    while(!fila.empty()){
        auto [x,y] = fila.front();
        fila.pop();
        
        for(int i = 0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ehValido(nx,ny) && conexo[nx][ny] == '.' && visited[nx][ny] == false){
                visited[nx][ny] = true;
                fila.push({nx,ny});
                contagem++;
            }
        }
    }
    return contagem;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total_livres = 0;

    int startX = -1;
    int startY = -1;

    cin >> H >> W;
    for(int i = 0; i < H;i++){
        cin >> conexo[i];
        for(int j = 0; j < W;j++){
            if (conexo[i][j]== '.'){
                total_livres++;

                if(startX == -1){
                    startX = i;
                    startY = j;
                }
            }
        }
    }
    if(total_livres == 0){
        cout << "Sim" << '\n';
        return 0;
    }

    int alcancados = bfs(startX,startY);

    int resultado = total_livres - alcancados;

    if(resultado == 0){
        cout << "Sim" << '\n';
    }else{
        cout << "Não" << '\n';
    }
    return 0;
}
