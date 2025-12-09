#include <bits/stdc++.h>
using namespace std;

/*
Pintura Rubro-Negra

N e M -> NUMEROS DE SETORES E O NUMERO DE PASSAGENS ENTRE ELES
S REPRESENTA O SETOR INICIAL
C A COR DESSE SETOR
T O SETOR QUE QUEREMOS DESCOBRIR
*/
const int MAXN = 100005;

vector<int> adj[MAXN];

int cor[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;

    cin >> N >> M;

    for(int i = 1; i<=N;i++){
        cor[i] = -1;
    }

    for(int i = 0; i < M;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int S,T;
    string C;

    cin >> S >> C >> T;

    int corInicial = (C == "PRETA" ? 0 : 1);

    queue<int> fila;

    fila.push(S);
    cor[S] = corInicial;
    while(!fila.empty()){
        auto valor = fila.front();
        fila.pop();

        for(int v : adj[valor]){
            if(cor[v] == -1){
                cor[v] = 1 - cor[valor];
                fila.push(v);  // Só adiciona se ainda não foi visitado
            }
        }
    }
    
    if(cor[T] == 0){
        cout << "PRETA" << '\n';
    } else {
        cout << "VERMELHA" << '\n';
    }

    return 0;
}