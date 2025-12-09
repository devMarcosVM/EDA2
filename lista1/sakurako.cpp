#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    // Lendo a permutação (usaremos base 0 para facilitar)
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; // Ajustando para índice 0 (o problema dá de 1 a N)
    }
    // Lendo as cores
    string s;
    cin >> s;
    // Vetor para guardar a resposta final
    vector<int> resultado(n);
    // Vetor para marcar quem já visitamos para não processar o mesmo ciclo duas vezes
    vector<bool> visitado(n, false);
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            // Encontramos um novo ciclo!
            vector<int> ciclo_atual;
            int curr = i;
            // 1. Percorrer e mapear o ciclo inteiro
            while (!visitado[curr]) {
                visitado[curr] = true;
                ciclo_atual.push_back(curr);
                curr = p[curr]; // Move para o próximo
            }
            // 2. Contar quantos pretos ('0') existem neste ciclo
            int contagem_pretos = 0;
            for (int membro : ciclo_atual) {
                if (s[membro] == '0') {
                    contagem_pretos++;
                }
            }
            // 3. A resposta para TODOS os membros do ciclo é a mesma
            for (int membro : ciclo_atual) {
                resultado[membro] = contagem_pretos;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << resultado[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}