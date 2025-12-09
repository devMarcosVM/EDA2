#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 18;

int sparse[LOG][MAXN];
int logTable[MAXN];

void buildSparseTable(int n) {
    // Pré-computa log2
    logTable[1] = 0;
    for (int i = 2; i <= n; i++) {
        logTable[i] = logTable[i / 2] + 1;
    }
    
    // Constrói a sparse table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            sparse[j][i] = min(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int queryMin(int l, int r) {
    int k = logTable[r - l + 1];
    return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, t;
    cin >> n >> q >> t;
    
    for (int i = 1; i <= n; i++) {
        cin >> sparse[0][i];
    }
    
    buildSparseTable(n);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int minVal = queryMin(l, r);
        
        if (minVal >= t) {
            cout << "Estou pronto, estou pronto, estou pronto!\n";
        } else {
            cout << "Ah, mexilhoes!\n";
        }
    }
    
    return 0;
}
