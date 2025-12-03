#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin >> N >> M;

    for(int i = 0; i<M; i++){
        int u,v;
        cin >> u >> v;
    }

    int soma, solucao;

    soma = (N*(N-1))/2;
    solucao = soma - M;

    cout << solucao << "\n";

    // Grafo completo tem N*(N-1)/2 arestas
    // Estradas faltantes = total possível - estradas existentes

    return 0;
}