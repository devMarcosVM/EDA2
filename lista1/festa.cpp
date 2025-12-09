#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> gerente(n + 1);  // gerente[i] = gerente imediato de i
    
    for (int i = 1; i <= n; i++) {
        cin >> gerente[i];
    }
    
    // Calcular a profundidade de cada funcionário
    // Profundidade = quantos superiores ele tem + 1
    vector<int> profundidade(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        int prof = 1;
        int atual = i;
        
        // Subir na hierarquia contando os níveis
        while (gerente[atual] != -1) {
            prof++;
            atual = gerente[atual];
        }
        
        profundidade[i] = prof;
    }
    
    // A resposta é a profundidade máxima
    int resposta = *max_element(profundidade.begin(), profundidade.end());
    
    cout << resposta << "\n";
    
    return 0;
}
