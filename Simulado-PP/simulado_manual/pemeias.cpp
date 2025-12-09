#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        int modelo_meia;
        int resposta = 0; // 0 não altera o XOR

        // 2. Lemos os N números um por um
        for (int i = 0; i < N; i++) {
            cin >> modelo_meia;
            
            // 3. Aplicamos o XOR acumulativo
            // Se o número já apareceu antes, ele se anula.
            // Se é a primeira vez, ele é "registrado".
            resposta = resposta ^ modelo_meia;
        }

        // 4. O que sobrou na variável 'resposta' é o único sem par
        cout << resposta << "\n";
    }

    return 0;
}