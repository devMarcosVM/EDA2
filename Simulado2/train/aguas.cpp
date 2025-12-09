#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int acumulado[MAXN]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q, T;
    if (cin >> N >> Q >> T) {
        acumulado[0] = 0; 
        for (int i = 1; i <= N; i++) {
            int forca;
            cin >> forca;
            int ehRuim = 0;
            if (forca < T) {
                ehRuim = 1;
            }
            acumulado[i] = acumulado[i-1] + ehRuim;
        }
        for (int i = 0; i < Q; i++) {
            int L, R;
            cin >> L >> R;
            int qtdRuins = acumulado[R] - acumulado[L-1];
            if (qtdRuins == 0) {
                cout << "Estou pronto, estou pronto, estou pronto!" << "\n";
            } else {
                cout << "Ah, mexilhoes!" << "\n";
            }
        }
    }

    return 0;
}