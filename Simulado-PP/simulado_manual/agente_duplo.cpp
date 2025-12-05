#include <iostream>
#include <vector>

using namespace std;

/*
N AGENTES - ENUMERADOS DE 1 A N

O agente duplo: 
- ele nao envia relatorio em nenhum outro agente
- todos os outros agentes enviam para o agente duplo

se nao encaixar resultado return -1

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,T;
    cin >> N >> T;

    vector<int> grauEntrada(N + 1, 0);
    vector<int> grauSaida(N + 1, 0);
    
    for(int i = 0; i<T;i++){
        int u,v;

        cin >> u >> v;
        if(u == v){
            cout << "Um agente nao pode confiar nele mesmo";
        }
        
        
        
    }

}