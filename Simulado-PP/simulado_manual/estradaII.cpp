#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 1505;
bool tem_estrada[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    for(int i = 0; i<M ; i++){
        int u,v;
        cin >> u >> v;
        tem_estrada[u][v] = true;
        tem_estrada[v][u] = true;
    }

    for(int i = 1; i <= N; i++){ // cidade 1 a N
        for(int j = i+1; j<=N; j++){
            if(tem_estrada[i][j] == false){
                cout << i << " " << j << "\n";
            }
        }
    }
    return 0;
}