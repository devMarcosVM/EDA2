#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    if (cin >> N) {
        //<Valor da Soma, Quantas vezes apareceu>
        map<long long, int> frequencia;
    
        frequencia[0] = 1;
        long long soma_atual = 0;
        long long contador_portais = 0;
        int valor_rua;
        for (int i = 0; i < N; i++) {
            cin >> valor_rua;
            // 1. Atualiza a soma acumulada
            soma_atual += valor_rua;
            // 2. A Mágica: Procuramos o complemento
            // Queremos: soma_atual - X = 11
            // Logo: X = soma_atual - 11
            long long alvo = soma_atual - 11;
            // Se esse 'alvo' já apareceu no passado, somamos quantas vezes ele apareceu
            if (frequencia.count(alvo)) {
                contador_portais += frequencia[alvo];
            }
            // 3. Registra a soma atual no mapa para o futuro
            frequencia[soma_atual]++;
        }

        cout << contador_portais << endl;
    }

    return 0;
}